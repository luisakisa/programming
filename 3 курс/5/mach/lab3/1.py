import pandas as pd
s = pd.Series([1,2,3,4,5], index=['a','b','c','d', 'e'])
print(s['d'])
print(s[1])
s['f']=6
print(s)
print(s[2:5])
d = pd.DataFrame([[1, 2], [5, 3], [3.7, 4.8]],columns=[
"col1","col2"])
print(d)
print(d["col1"][2])
d["col2"][1]=9
print(d)
print(d[1:3])
d["col3"]=d['col1'].multiply(d['col2'], axis=0)
print(d)