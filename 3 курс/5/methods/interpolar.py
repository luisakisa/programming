import numpy as np
import matplotlib.pyplot as plt
import sympy as sp
x=np.arange(-2,1.1,1)
y=lambda x:np.exp(x+np.sin(x))
def lagranz(x,y,t):
         z=0
         for j in range(len(x)):
             p1=1; p2=1
             for i in range(len(x)):
                 if i==j:
                     p1=p1*1; p2=p2*1   
                 else: 
                     p1=p1*(t-x[i])
                     p2=p2*(x[j]-x[i])
             z=z+y[j]*p1/p2
         return z
def diff4(i):
	x = sp.symbols('x')
	func = sp.exp(x+sp.sin(x))
	yprime = sp.diff(func, x, 4)
	yprime = yprime.subs({x: i})
	return yprime.n()
R_teor = []
xnew =np.linspace(np.min(x),np.max(x),124)
ynew=[lagranz(x,y(x),i) for i in xnew]

for i in xnew:
		R_teor.append(abs(diff4(i) / 24 * (i-x[0]) * (i-x[1]) * (i-x[2]) * (i-x[3])))
figure, axis = plt.subplots(3)
axis[0].plot(x,y(x),'o',xnew,ynew)
x=np.arange(-2,1.1,0.025)
y=lambda x:np.exp(x+np.sin(x))
print(y(x))
print(ynew)
axis[0].plot(x,y(x))
axis[1].plot(x,abs(np.array(y(x))-np.array(ynew)))

axis[2].plot(x,R_teor)

plt.show()