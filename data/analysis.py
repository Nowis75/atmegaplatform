"""Analysis of the student-perception questionnaire (anonymized responses, 1 = strongly disagree ... 5 = strongly agree).
Usage: python analysis.py questionnaire_responses.csv  -> results.json, idx.npz; then python figures.py"""
import csv, sys, json, numpy as np
from scipy import stats
rows=list(csv.reader(open(sys.argv[1] if len(sys.argv)>1 else 'questionnaire_responses.csv',encoding='utf-8')))
body=rows[1:]
grp=np.array([r[1] for r in body])
X=np.array([[float(v) for v in r[2:29]] for r in body])
print('responses',len(body))
doms={'CI':range(0,5),'CE':range(5,10),'PE':range(10,15),'SI':range(15,20),'MI':range(20,25)}
idx={k:X[:,list(v)].mean(1) for k,v in doms.items()}; idx['Overall']=np.mean([idx[k] for k in doms],0)
def alpha(M): k=M.shape[1]; return k/(k-1)*(1-M.var(0,ddof=1).sum()/M.sum(1).var(ddof=1))
rng=np.random.default_rng(1)
def g_of(a,b):
    n1,n2=len(a),len(b); sp=np.sqrt(((n1-1)*a.var(ddof=1)+(n2-1)*b.var(ddof=1))/(n1+n2-2))
    return (b.mean()-a.mean())/sp*(1-3/(4*(n1+n2)-9))
res={}
for k,v in idx.items():
    a,b=v[grp=='BB'],v[grp=='PCB']
    t=stats.ttest_ind(b,a,equal_var=False); mw=stats.mannwhitneyu(b,a,alternative='two-sided')
    boot=[g_of(rng.choice(a,len(a)),rng.choice(b,len(b))) for _ in range(5000)]
    al=alpha(X[:,list(doms[k])]) if k in doms else alpha(X[:,:25])
    res[k]=dict(nBB=len(a),nPCB=len(b),mBB=a.mean(),sBB=a.std(ddof=1),mPCB=b.mean(),sPCB=b.std(ddof=1),
        t=t.statistic,df=t.df,p=t.pvalue,pmw=mw.pvalue,g=g_of(a,b),gl=np.percentile(boot,2.5),gh=np.percentile(boot,97.5),alpha=al,
        ciBB=stats.t.ppf(.975,len(a)-1)*a.std(ddof=1)/np.sqrt(len(a)),ciPCB=stats.t.ppf(.975,len(b)-1)*b.std(ddof=1)/np.sqrt(len(b)))
ks=sorted(doms,key=lambda k:res[k]['p']);prev=0
for i,k in enumerate(ks): prev=max(prev,min(1,(5-i)*res[k]['p'])); res[k]['pholm']=prev
def pw_(d,n,a=.05):
    df=2*n-2; nc=d*np.sqrt(n/2); tc=stats.t.ppf(1-a/2,df)
    return stats.nct.sf(tc,df,nc)+stats.nct.cdf(-tc,df,nc)
def n_for(d,target=.8):
    n=2
    while pw_(d,n)<target: n+=1
    return n
power={'n_for_g1.3':n_for(1.3),'n_for_g0.8':n_for(.8),'n_for_g0.5':n_for(.5),'power_n7_g1.3':pw_(1.3,7),'power_n14_g1.3':pw_(1.3,14)}
for k,r in res.items(): print(k,' '.join(f'{a}={v:.3f}' for a,v in r.items()))
print(power)
json.dump({'res':{k:{a:float(v) for a,v in r.items()} for k,r in res.items()},'power':power},open('results.json','w'),indent=1)
np.savez('idx.npz',grp=grp,**idx)
