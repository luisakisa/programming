import numpy as np
import sympy as sp
import matplotlib.pyplot as plt

a, b = 0.4, 1.2
n = int(input('Введите чётное n: '))
while n % 2 != 0:
    n = int(input('Введите чётное n: '))

h = (b - a) / n



xi = []
yi = []


def into_xi():
    xi.append(a)
    y = (np.cos(xi[0]))/(xi[0]+2)
    yi.append(y)
    for i in range(1,n-1):
        x = xi[0]+i*h
        xi.append(x)
        y = (np.cos(x))/(x+2)
        yi.append(y)
    xi.append(b)
    y = (np.cos(xi[n-1]))/(xi[n-1]+2)
    yi.append(y)
into_xi()
def integ_trap():
    sum_y1_yn_1 = 0 
    for i in range(1,n-1):
        sum_y1_yn_1 +=  yi[i]
    integ = h*((yi[0]+yi[n-1])/2+sum_y1_yn_1)
    return integ
def R():
    R = -((b-a)/12)*M(2,xi)*h**2
    return R
def M(step,xi):
    yprime = dif(step)
    x = sp.symbols('x')
    res=-100
    for i in xi:
        if(yprime.subs({x: i})>res):
            res = yprime.subs({x: i})
    return res
def dif(i):
	x = sp.symbols('x')
	func = sp.cos(x)/(x+2)
	yprime = sp.diff(func, x, i)
	return yprime
    
print("формула трапеции: ",integ_trap())
print("остаточный член: ", R())

#симпсона

def simpson():
    sum = 0
    for i in range(1,n-1):
        if(i%2==1):
            sum += 4*yi[i]
        else: sum += 2*yi[i]
    S = h/3+yi[0]+yi[n-1]+sum
    return S
def R2():
    R = -((b-a)/180)*M(4,xi)*(h**4)
    return R
print("формула симпсона: ",simpson())
print("остаточный член: ", R2())   

#3/8
def three_eight():
    chet=yi[1]
    nechet = 0
    for i in range(2,n-1,2):
        chet+=yi[i]
    for i in range(3,n-1,2):
        nechet += yi[i]
    t = (3*h/8)*(yi[0]+yi[n-1]+3*(chet)+2*(nechet))
    return t
def R3():
    R = -((b-a)/80)*M(4,xi)*(h**4)
    return R
print("формула трех восьмых: ",three_eight())
print("остаточный член: ", R3())   
#прямоугольников
# def square():
#     fo
#гаусса 7
A = [0.12948496, 0.27970540, 0.38183006, 0.41795918, 0.38183006, 0.27970540, 0.12948496]
def gauss():
    n = 7
    into_xi()
    sum = 0
    for i in range(n):
        sum += A[i]*yi[i]
    g = ((b-a)/2)+sum
    return g
def R5():
    R7 = 2.17*10**(-15)
    f = (np.cos(0))/(0+2)
    R = ((b-a)/2)**(2*n)*R7*f
    return R
print("формула гаусса: ",gauss())
print("остаточный член: ", R5())   