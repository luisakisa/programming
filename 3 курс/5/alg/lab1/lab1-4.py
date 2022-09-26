import timeit
import matplotlib.pyplot as plt
from random import randint


test_in_list = timeit.Timer("del x[int(len(x)/2)]", globals = globals()) 
test_in_dict = timeit.Timer("del y[randint(0,len(y))]", globals = globals())

plt_x = []
plt_test_in_list = []
plt_test_in_dict = []

for i in range(1000000,10000001,1000000):
  plt_x.append(i)
  
  x = list(range(i))
  pt = test_in_list.timeit(number=15) 
  plt_test_in_list.append(pt)

  y = {j: None for j in range(i)}
  pz = test_in_dict.timeit(number=15) 
  plt_test_in_dict.append(pz)

plt.plot(plt_x, plt_test_in_list)
plt.plot(plt_x, plt_test_in_dict)
plt.show()

