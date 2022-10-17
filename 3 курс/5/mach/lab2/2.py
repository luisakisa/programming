import numpy as np
#1
x=np.array([0,10,20,40,60])
x1=np.array([10,30,40])
print(x[np.in1d(x,x1)])
#2
x = np.array([10, 10, 20, 20, 30, 30])
print(np.unique(x))
x = np.array([[1, 1], [2, 3]])
print(np.unique(x))
#3
arr = np.array([10, 10, 20, 10, 20, 20, 20, 30, 30, 50, 40, 40])
uniq, count = np.unique(arr, return_counts=True)
print(uniq, count)
#4
a = [1, 2, 3, 4]
print(a)
x = np.tile(a, 2)
print(x)
x = np.tile(a, 3)
print(x)
#5
x = np.array([200, 300, np.nan, np.nan, np.nan ,700])
result = x[np.logical_not(np.isnan(x))]
print(result)
y = np.array([[1, 2, 3], [np.nan, 0, np.nan] ,[6,7,np.nan]] )
result = y[np.logical_not(np.isnan(y))]
print(result)
#6
array1 = np.array([1, 7, 8, 2, 0.1, 3, 15, 2.5])
print(array1)
k = 4
result = np.argpartition(array1, k)
print(array1[result[:k]])
#7
arr = np.array([0.5, 1.8, 2.1, 3.5, 4.87, 5.13, 6.49])
num = 3.09066280756759
index = (np.abs(arr - num).argmin())
print(arr[index])
#8
a = np.array(['Python', 'PHP'])
b = np.array([' Java', ' C ++'])
new_array = np.char.add(a,b)
print(new_array)
#9
arr = np.char.array(["Python", "PHP", "JS", "examples", "html"])
count = np.char.count(arr, "P")
print(count)
#10
coeff1 = [1, -4, 7]
coeff2 = [1, -11, 9, 11, -10]
print(np.roots(coeff1))
print(np.roots(coeff2))