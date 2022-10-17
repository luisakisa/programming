import numpy as np
a11 = int(input("a11 "))
a12 = int(input("a12 "))
a21 = int(input("a21 "))
a22 = int(input("a22 "))

b1 = int(input("b1 "))
b2 = int(input("b2 "))

arr = np.array([[a11,a12],[a21,a22]])
arr2 = np.array([b1,b2])

if np.linalg.det(arr) == 0:
    print("нет решений")
else:
    print(np.linalg.solve(arr,arr2))