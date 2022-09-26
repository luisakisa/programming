import random
import timeit
import matplotlib.pyplot as plt
from random import randint

def quicksort(nums):
   #n*log(n)
   if len(nums) <= 1:
       return nums
   else:
       q = random.choice(nums)
   l_nums = [n for n in nums if n < q]
 
   e_nums = [q] * nums.count(q)
   b_nums = [n for n in nums if n > q]
   return quicksort(l_nums) + e_nums + quicksort(b_nums)


def selection_sort(alist):
  #n^2
    for i in range(0, len(alist) - 1):
        smallest = i
        for j in range(i + 1, len(alist)):
            if (alist[j] < alist[smallest]):
                smallest = j
        alist[i], alist[smallest] = alist[smallest], alist[i]
    return alist
 
 
testquick = timeit.Timer("quicksort(x)", globals = globals())
testselection = timeit.Timer("selection_sort(y)", globals = globals()) 

plt_x = []
plt_testquick = []
plt_testselection = []

for i in range(10000, 100001, 1000):
  plt_x.append(i)
  
  x = list(range(i))
  x = [randint(-1000,1000) for j in range(i)]
  #x = quicksort(x) - строка для создания отсортированных элементов
  #x.sort(reverse=True) - строка для создания элементов отсортированных в обратном порядке
  pt = testquick.timeit(number=5) 
  plt_testquick.append(pt)


  y = list(range(i))
  y = [randint(-1000,1000) for j in range(i)]
  #y = selection_sort(y) - строка для создания отсортированных элементов
  #y.sort(reverse=True) - строка для создания элементов отсортированных в обратном порядке
  pz = testselection.timeit(number=5) 
  plt_testselection.append(pz)

plt.plot(plt_x, plt_testquick, "-r")
plt.plot(plt_x, plt_testselection, "-g")
plt.show()