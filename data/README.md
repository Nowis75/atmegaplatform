# Questionnaire data

`questionnaire_responses.csv` contains the anonymized answers of the 14 students who completed the student-perception questionnaire: 7 from the breadboard cohort (`BB`) and 7 from the PCB cohort (`PCB`), January 2026. Timestamps have been removed.

- Columns A1–E5: 25 Likert items, 1 = strongly disagree … 5 = strongly agree
  - Cognitive Index (CI): A1–A5
  - Construction Efficiency (CE): B1–B5
  - Process Efficiency (PE): C1–C5
  - STEM Integration (SI): D1–D5
  - Motivation (MI): E1–E5
- F1, F2: supplementary items
- G1, G2: open answers (Czech)

The English wording of all items is given in the appendix of the paper.

Reproduce the statistics and figures (requires Python 3, numpy, scipy and matplotlib):

```bash
python analysis.py questionnaire_responses.csv   # writes results.json
python figures.py                                # writes fig-05.png, fig-06.png
```
