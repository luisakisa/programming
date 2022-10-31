import math
import matplotlib.pyplot as plt
import numpy as np


xnew = []
ynew = []
S = []
pogr = []


def y(xi):
    yi= np.exp(xi+np.sin(xi))
    return yi

def splain(x,y):
    for i in range(0,7):
        t = np.linspace(x[i],x[i+1],200)
        for j in t:
            i+=1
            h=x[i]-x[i-1]
            s=y[i]+(x[i]-j)*((y[i-1]-y[i])/h)
            i-=1
            S.append(s)

# for i in range(21):
#     pogr.append(abs(S[i] - y[i]))
    
A=0 #начало диапозона по х
B = 2#конец диапозона по х
n = 8 #начальное кол-во узлов
H = 1400
p=1
X = np.linspace(A,B,H)
Y = [y(i) for i in X]
xnew = np.linspace(A,B,n)
ynew = [y(i) for i in xnew]

print(xnew)

fig = plt.figure(figsize=(15, 3))

ax = fig.add_subplot(1, 2, 1)
ax2 = fig.add_subplot(1, 2, 2)

splain(xnew,ynew)
for i in range(H):
    pogr.append(abs(Y[i]-S[i]))

print(len(S))
ax.plot(X, Y, color='green')
ax.plot(X, S, color='orange')
ax2.plot(X, pogr)

plt.show()
