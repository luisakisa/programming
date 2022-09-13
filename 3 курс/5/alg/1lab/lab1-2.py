import timeit
import matplotlib.pyplot as plt

alg1 = timeit.Timer("foo1()", globals=globals())
alg2 = timeit.Timer("foo2()", globals=globals())
plt_time1 = []
plt_time2 = []
plt_x = []
n=1
def foo2():
    
    lst2 = [] 
    for i in lst: 
        if i not in lst2: 
            lst2.append(i)
            
def foo1():
    lst1 = set(lst)

while n<10000:
    lst = list(range(n))
    pt1 = alg1.timeit(number=10)
    plt_x.append(n)
    plt_time1.append(pt1)
    pt2 = alg2.timeit(number=10)
    plt_time2.append(pt2)
    n+=1000
plt.xlabel("n") # ось абсцисс
plt.ylabel("time") 
plt.plot(plt_x, plt_time1, plt_x, plt_time2)
plt.show()