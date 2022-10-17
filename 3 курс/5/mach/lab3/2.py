import pandas as pd
import numpy as np
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