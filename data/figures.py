import json, numpy as np, matplotlib
matplotlib.use('Agg'); import matplotlib.pyplot as plt
R=json.load(open('results.json'))['res']; D=np.load('idx.npz')
C={'BB':'#2a78d6','PCB':'#eb6834'}; LAB={'BB':'Breadboard (n = 7)','PCB':'PCB platform (n = 7)'}
MK={'BB':dict(marker='o',mfc='white'),'PCB':dict(marker='s')}
INK='#3a3a38'; GRID='#e4e3df'
plt.rcParams.update({'font.family':'DejaVu Sans','font.size':8,'axes.edgecolor':INK,'axes.labelcolor':INK,'xtick.color':INK,'ytick.color':INK,'axes.linewidth':0.6})
def style(ax):
    for s in ['top','right']: ax.spines[s].set_visible(False)
    ax.yaxis.grid(True,color=GRID,lw=0.6); ax.set_axisbelow(True)
# Fig 5: individual overall indices + mean and 95% CI
fig,ax=plt.subplots(figsize=(3.5,2.6),dpi=300); style(ax)
rng=np.random.default_rng(3)
for i,g in enumerate(['BB','PCB']):
    v=D['Overall'][D['grp']==g]; x=i+rng.uniform(-.09,.09,len(v))
    ax.plot(x,v,ls='none',ms=6,mec=C[g],mew=1.4,color=C[g],alpha=.85,**MK[g])
    m=R['Overall']['m'+g]; ci=R['Overall']['ci'+g]
    ax.errorbar(i+.28,m,yerr=ci,fmt='none',ecolor=INK,elinewidth=1.4,capsize=4)
    ax.plot([i+.20,i+.36],[m,m],color=INK,lw=2)
    ax.text(i+.42,m,f'{m:.2f}',va='center',ha='left',color=INK,fontsize=7.5)
ax.set_xticks([0,1]); ax.set_xticklabels([LAB['BB'],LAB['PCB']]); ax.set_xlim(-.4,1.75)
ax.set_ylim(1,5); ax.set_yticks([1,2,3,4,5]); ax.set_ylabel('Overall index (1–5)')
fig.tight_layout(); fig.savefig('fig-05.png'); plt.close(fig)
# Fig 6: domain means with 95% CI
doms=['CI','CE','PE','SI','MI','Overall']; names=['CI','CE','PE','SI','MI','Overall']
fig,ax=plt.subplots(figsize=(3.5,2.7),dpi=300); style(ax)
x=np.arange(len(doms))
for g,off in [('BB',-.14),('PCB',.14)]:
    m=[R[d]['m'+g] for d in doms]; ci=[R[d]['ci'+g] for d in doms]
    ax.errorbar(x+off,m,yerr=ci,fmt='none',ecolor=C[g],elinewidth=1.4,capsize=2.5)
    ax.plot(x+off,m,ls='none',ms=6,mec=C[g],mew=1.4,color=C[g],label=LAB[g],**MK[g])
for xi,d in zip(x,doms):
    if d!='Overall' and R[d]['pholm']<.05: ax.text(xi,5.08,'*',ha='center',color=INK)
ax.axvline(4.5,color=GRID,lw=0.8)
ax.set_xticks(x); ax.set_xticklabels(names,fontsize=7.5); ax.set_ylim(1,5.15); ax.set_yticks([1,2,3,4,5])
ax.set_ylabel('Mean index (1–5), 95% CI')
ax.legend(loc='lower center',bbox_to_anchor=(.5,1.0),ncol=2,frameon=False,fontsize=7,handletextpad=.3)
fig.tight_layout(); fig.savefig('fig-06.png'); plt.close(fig)
