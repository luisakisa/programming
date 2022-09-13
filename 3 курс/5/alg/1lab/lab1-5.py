import timeit
import matplotlib.pyplot as plt


in_list = timeit.Timer("'test' in x", globals=globals())
in_set = timeit.Timer("'test' in x", globals=globals())

plt_x = []
plt_list = []
plt_set = []

print("pop()   pop()")
for i in range(1000000,10000001,1000000):
    plt_x.append(i)

    x = list(range(i))
    pt = in_list.timeit(number=100)
    plt_list.append(pt)

    x = set(range(i))
    pz = in_set.timeit(number=100)
    plt_set.append(pz)

    print("%15.5f, %15.5f" %(pz,pt))


plt.plot(plt_x, plt_list, plt_x, plt_set)
plt.show()
