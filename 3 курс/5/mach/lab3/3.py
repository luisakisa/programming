import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("crimes.csv") 

print("rows:", len(df.index), "columns:", len(df.columns))

print(df.info())

print(df. nunique())

print(df.isna().sum())

F = (df["Victim Sex"] == "F").value_counts()
M = (df["Victim Sex"] == "M").value_counts()
print("female:",F[0]," male:",M[0])

crimes = df["Crime Code"].value_counts()
plt.bar(list(map(str, crimes[:10].index)), crimes[:10].values)
plt.title("10 popular crimes")
plt.xlabel("crime code")
plt.ylabel("count of crime")
plt.show()

f = df[df["Victim Sex"] == "F"]["Crime Code"].value_counts()
m = df[df["Victim Sex"] == "M"]["Crime Code"].value_counts()
print("female: ", df[df["Crime Code"] == f.index[0]]["Crime Code Description"].values[0],
"male: ", df[df["Crime Code"] == m.index[0]]["Crime Code Description"].values[0])

print(df["Victim Descent"].value_counts())

area = df["Area Name"].value_counts()
print(df["Area Name"].value_counts())
name_dangerous= area.index[0]
value_dangerous = area.values[0]
name_safety = area.index[-1]
value_safety= area.values[-1]
plt.bar([name_safety, name_dangerous], [value_safety, value_dangerous])
plt.show()