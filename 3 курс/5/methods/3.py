import math
import matplotlib.pyplot as plt

x = []
y = []
x_poz = [-2, -1.75, -1.5, -1.25, -1, -0.75, -0.5, -0.25, 0]
y_poz = []
a = -2.0
h = x_poz[1] - x_poz[0]
alpha_i = h
betta_i = 4 * h
gamma_i = h
fi_i = []
a_i = []
p_i = [0]
q_i = [0]
c_i = [0, 0, 0, 0, 0, 0, 0, 0, 0]
b_i = []
d_i = []
s3_x = []
pogr = []

for i in x_poz:
    y_poz.append(math.cos(math.sin(i * i)))
    a_i.append(math.cos(math.sin(i * i)))

for i in range(1, 8):
    fi_i.append(6 * ((a_i[i + 1] - a_i[i]) / h - (a_i[i] - a_i[i - 1]) / h))

for i in range(1, 8):
    p_i.append(-gamma_i / (betta_i + alpha_i * p_i[i - 1]))

for i in range(1, 8):
    q_i.append((fi_i[i - 1] - alpha_i * q_i[i - 1]) / (betta_i + alpha_i * p_i[i - 1]))

for i in range(7, 0, -1):
    c_i[i] = p_i[i] * c_i[i+1] + q_i[i]

for i in range(1, 9):
    d_i.append((c_i[i-1]-c_i[i])/h)


for i in range(1, 9):
    b_i.append((a_i[i-1]-a_i[i])/h-c_i[i]*h/2-(c_i[i-1]-c_i[i])*h/6)

for i in range(81):
    x.append(a)
    a = a + 0.025

for i in x:
    y.append(math.cos(math.sin(i * i)))

for i in range(len(x_poz) - 1):
    for element in x:
        if x_poz[i] <= element < x_poz[i + 1]:
            s3_x.append(a_i[i+1] + b_i[i]*(x_poz[i+1]-element)+(c_i[i+1]*(x_poz[i+1]-element)*(x_poz[i+1]-element))/2+(d_i[i]*(x_poz[i+1]-element)*(x_poz[i+1]-element)*(x_poz[i+1]-element))/6)

for i in range(len(y)):
    pogr.append(abs(y[i] - s3_x[i]))

fig = plt.figure(figsize=(15, 3))

ax = fig.add_subplot(1, 2, 1)
ax2 = fig.add_subplot(1, 2, 2)

ax.plot(x, y, color='blue')
ax.plot(x, s3_x, color='red')

ax2.plot(x, pogr, color='black')

plt.show()

