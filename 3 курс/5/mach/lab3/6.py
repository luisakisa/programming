import pandas as pd

df = pd.read_table("weather.txt", sep=';', names=['index', 'year', 'month', 'day', 'min_t', 'average_t', 'max_t', 'rainfall'])
cols = ['min_t', 'average_t', 'max_t', 'rainfall']
df[cols] = df[cols].apply(lambda x: x.str.strip())
df[cols] = df[cols].apply(lambda x: pd.to_numeric(x))
print(df)
df = df.drop('index', axis=1)
print(df)

print(df.info())

nans = {}
for y in df['year'].unique():
    nans[y] = df[df['year'] == y].isna().sum().sum()
print(f"{max(nans, key=nans.get)}: {nans[max(nans, key=nans.get)]} пропуска")

df['date'] = pd.to_datetime(df[['year', 'month', 'day']])
print(df)

df['temp range'] = abs(df['min_t'] - df['max_t'])
count = 0
maxcount = 0
df['no rain'] = df['rainfall']
for idx, d in enumerate(df['no rain']):
    df['no rain'][idx] = count
    if d == 0:
        count += 1
    else:
        count = 0
    if maxcount < count:
        maxcount = count
print(df)
print(maxcount)

temp = df.groupby(['year'])['average_t'].mean()
rain = df.groupby(['year'])['rainfall'].sum()

print(f"самый теплый год: {temp.idxmax()}")
print(f"самый холодный год: {temp.idxmin()}")
print(f"наибольшее кол-во осадков: {rain.idxmax()}")
print(f"наименьшее кол-во осадков: {rain.idxmin()}")

print(df[df['average_t'] < -30])
print(df[(df['average_t'] > 27) & (df['no rain'] > 3)])