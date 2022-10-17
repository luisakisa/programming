import numpy as np
X = np.array([1, 7, 13, 105])
print("Массив:")
print(X)
print("Размер памяти:")
print("%d bytes" % (X.size * X.itemsize))

np.savetxt('1.txt',X)
txt = np.loadtxt('1.txt',dtype=int)
print(txt)

X.tofile('1.bin')
bin = np.fromfile('1.bin',dtype=int)
print(bin)

#2
array=np.zeros(10)
print(array)
array=np.ones(10)
print(array)
array=np.ones(10)*5
print(array)

#3

array=np.arange(30,71,2)
print(array) 

#4
v = np.linspace(10, 49, 5)
print(v)

#5
x = (101 - 1) * np.random.random((3,3,3)) +1
print(x)

#6
m= np.arange(30,42).reshape((3, 4))
print(m)

#7
x = np.ones((10, 10))
x[1:-1, 1:-1] = 0
print(x)

#8
x = np.diag([1, 2, 3, 4, 5])
print(x)

#9
x = np.zeros((4, 4))
x[::2, 1::2] = 1
x[1::2, ::2] = 1
print(x)

#10
x =  np.arange('2017-03-01', '2017-04-01', dtype='datetime64[D]')
print(x)