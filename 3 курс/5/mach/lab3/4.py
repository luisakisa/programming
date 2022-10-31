import pandas as pd

polit = pd.read_csv("polit.csv").dropna()

print(polit[(polit['afri'] == 1) & (polit['fparl08'] > 30)])

print(polit[((polit['afri'] == 1) | (polit['lati'] ==1))&(polit['polity09'] >= 8)])

polit['corr_round'] = polit['corr0509'].round(2)
print(polit)

def func(x):
    if((x >= 1) and (x <= 2.5)):
        return "Free"
    elif ((x >= 3) and (x <= 5)):
        return "Partly Free"
    elif ((x >= 5.5) and (x <= 7)):
        return "Not Free"
polit["fh_status"] = polit["fh09"].apply(func)
print(polit)

grp = polit.groupby(["fh_status"])
print(grp.min()['gini'])
print(grp.mean()['gini'])
print(grp.max()['gini'])

for name, status in grp:
    status.to_csv(f"{name}.csv")