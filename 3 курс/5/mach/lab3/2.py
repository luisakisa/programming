import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
data = [["Вжик", "Zipper the Fly", "fly", "0.7"], ["Гайка", "Gadget Hackwrench", "mouse", None], ["Дейл", "Dale", "chipmunk", "1"],
["Рокфор", "Monterey Jack", "mouse", "0.8"],
["Чип", "Chip", "chipmunk", "0.2"]]

df = pd.DataFrame(data, columns=['ru_name', 'en_name', 'class', 'cheer'])
df.cheer = df.cheer.astype(np.float64)
print(df)
print(df.cheer)
print(len(df.index))
print(df.cheer.count())
print(df['en_name'][2])
df1 =df.loc[[2,3,4],["ru_name","en_name","class"]]
print(df1)
df["logcheer"]=np.log(df.cheer)
print(df)

df2 = df['class'].value_counts()
x = df2.index
y= df2.values
plt.bar(x,y)
print(df2)
plt.title("frequency of class")
plt.xlabel("classes")
plt.ylabel("count")
plt.show()