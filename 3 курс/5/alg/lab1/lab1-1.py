import timeit
import matplotlib.pyplot as plt

in_list = timeit.Timer("foo(i)", globals=globals())
plt_time = []
plt_x = []
count=0
def foo(i): # i - число 
        digits = "0123456789" 
        if i == 0:
            return "0" 
        result = "" 
        while i > 0:
            result = digits[i%10] + result 
            i = i // 10
        return result
i=1
while i!=pow(10,1500):
    count+=1
    plt_x.append(count)
    pt = in_list.timeit(number=100)
    plt_time.append(pt)
    i*=10
    
plt.xlabel("n - кол-во знаков") # ось абсцисс
plt.ylabel("time") 
plt.plot(plt_x, plt_time)
plt.show()