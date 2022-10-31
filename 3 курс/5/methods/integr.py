import math
a, b = 1, 3
n = int(input('Введите чётное n: '))
while n % 2 != 0:
    n = int(input('Введите чётное n: '))

h = (b - a) / n # шаг
xi = [] # диапазон интегрирования
f_xi = [] # Значения функции

def into_fun():
    diff_mass = []
    k = 0
    for i in range(n+1):
        x = round(a + (h * i), 4)
        xi.append(x)
        #temp = round(((x/2)+1)*math.sin(x/2), 4)
        temp = x ** 3
        #temp = 1
        f_xi.append(temp)
    temp = 0
    for j in range(1, len(f_xi), 2):
        temp += f_xi[j]
    for j in range(2, len(f_xi) - 1, 2):
        k += f_xi[j]
    fun_v = (h/3)*(f_xi[0]+4*temp+2*k+f_xi[-1])
    for i in range(len(xi)):
        diff_4 = (xi[i]*math.sin(xi[i]/2))/32 + (math.sin(xi[i]/2))/16 - (math.cos(xi[i]/2))/4
        diff_mass.append(round(diff_4, 6))
    diff_4 = max(diff_mass)
    return round(fun_v, 6), diff_4
    
value, diff_4 = into_fun()
R_h = (-(b - a) / 180) * diff_4 * h ** 4
print('Метод формулы Симпсона')
print('Значение интеграла:', value, '|', 'Значение остаточного члена:', diff_4)