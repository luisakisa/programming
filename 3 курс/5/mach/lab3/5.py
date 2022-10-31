import pandas as pd
df = pd.read_csv("vgsales.csv")

print(df["Platform"].unique())


rating = pd.read_csv("metacritic_games.csv", usecols=['name', 'rating', 'platform'])
rating.rename(columns = {'name' : 'Name', 'rating': 'metacritic_rating', 'platform': 'Platform'}, inplace = True)
df2 = df.copy(deep=True)
df2 = df2.merge(rating, how='left')
print(df2)

print(df2[(df2["metacritic_rating"] == "M") & (df2["Year"] >= 2012)])
print(df2[(df2["metacritic_rating"] == "M") & (df2["Year"] >= 2012)].describe())

genre = pd.unique(df['Genre'])
target = []
for g in genre:
    count = 0
    for a in g:
        a = a.lower()
        if a in 'aeiouy':
            count += 1
    if count >= 3:
        target.append(g)

for t in target:
    count = df['Genre'].value_counts()[t]
    print(t, count, sep=' - ')