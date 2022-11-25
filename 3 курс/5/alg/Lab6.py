#Лабораторная работа №6
# № 1 Вариант 1

stuff = {"книга": [1,3], "камера": [1, 6], "еда": [2, 6], "куртка": [2, 5], "вода":[3, 5]} 
w = [1, 1, 2, 2, 3]
p = [3, 6, 6, 5, 5]
n = 5
A = 6
V = [[0 for a in range(A+1)] for i in range(n+1)]

for i in range(n+1):
  for j in range(A+1):
    if i == 0 or j == 0:
        V[i][j] = 0
    elif w[i-1] <= j:
          V[i][j] = max(p[i-1] + V[i-1][j-w[i-1]], V[i-1][j])
    else:
          V[i][j] = V[i-1][j]
for i in V:
  print(i, "\n")

# № 2
from random import randint
import timeit
import matplotlib.pyplot as plt

def getStuff(n):
  stuff = [[str(i), randint(1, 5), randint(1,7)]for i in range(n)]
  return stuff

def copy(ceil):
  return {'cost': ceil['cost'], 'weight': ceil['weight'], 'items': ceil['items'].copy()}

def update(ceil, add):
  ceil['cost'] += add['cost']
  ceil['weight'] += add['weight']
  ceil['items'].update(add['items'])

#O(n!)
def fullIteration(items, limit, backpack=None):
  if not backpack:
    backpack = {'cost': 0, 'items': set(), 'weight': 0}
  max_cost = copy(backpack)
  for i in range(len(items)):
    if items[i][0] not in backpack['items'] and items[i][1] + backpack['weight'] <= limit:
      temp = copy(backpack)
      temp['cost'] += items[i][2]
      temp['weight'] += items[i][1]
      temp['items'].add(items[i][0])
      temp = fullIteration(items, limit, temp)
      if temp['cost'] > max_cost['cost']:
        max_cost = temp
  return max_cost

#O(n*w)
def dynamic(stuff, w, n):
  V = [[0 for a in range(w+1)] for i in range(n+1)]
  items = [['' for a in range(w+1)] for i in range(n+1)]
  for i in range(n+1):
    for j in range(w+1):
      if i == 0 or j == 0:
        V[i][j] = 0
        items[i][j] = ''
      elif stuff[i-1][1] <= j:
        V[i][j] = max(stuff[i-1][2] + V[i-1][j-stuff[i-1][1]], V[i-1][j])
        if stuff[i-1][2] + V[i-1][j-stuff[i-1][1]] > V[i-1][j]:
          items[i][j] = stuff[i-1][0] + ', ' + items[i-1][j-stuff[i-1][1]]
        else:
          items[i][j] = items[i-1][j]
      else:
        V[i][j] = V[i-1][j]
        items[i][j] = items[i-1][j]
  return items[-1][-1], V[-1][-1]

#O(n*n)
def greedy(stuff, w):
  stuffCopy = stuff.copy()
  items = []
  weights = []
  potentials = []
  stuffCopy.sort(key=lambda x: x[2])
  while stuffCopy and sum(weights)<w:
    currentitem = stuffCopy.pop()
    weights.append(currentitem[1])
    potentials.append(currentitem[2])
    items.append(currentitem[0])
  return items, sum(potentials)


testGreed = timeit.Timer("greedy(stuff, w)", globals = globals()) 
testDynamic = timeit.Timer("dynamic(stuff, w, n)", globals = globals())
testFullIt = timeit.Timer("fullIteration(stuff, w)", globals = globals())

plt_x = []
plt_testGreed = []
plt_testDynamic = []
plt_testFullIt = []

w = 8
for i in range(5, 25, 5):
    plt_x.append(i)

    n=i

    stuff = getStuff(i)
    pt = testGreed.timeit(number=25) 
    plt_testGreed.append(pt)

    pz = testDynamic.timeit(number=25) 
    plt_testDynamic.append(pz)

    pr = testFullIt.timeit(number=5) 
    plt_testFullIt.append(pr)

plt.plot(plt_x, plt_testGreed, 'red')
plt.plot(plt_x, plt_testDynamic, 'green')
plt.plot(plt_x,  plt_testFullIt, 'blue')
plt.show()

#stuff = [["книга",1,3], ["камера", 1, 6], ["еда", 2, 6], ["куртка", 2, 5], ["вода", 3, 5]]
#w = 6

n = int(input('Введите кол-во вещей: '))
w = int(input('Введите максимальный вес рюкзака: '))
stuff = [[0 for i in range(3)] for a in range(n)] 
for i in range(n):
  stuff[i][0] = input('Введите название вещи: ')
  stuff[i][1] = int(input('Введите вес вещи: '))
  stuff[i][2] = int(input('Введите ценность вещи: '))

print("Жадный:", greedy(stuff, w))
print("Динамическое программирование:", dynamic(stuff, w, n))
print("Полный перебор:", fullIteration(stuff, w).get('items'))

# № 4

def find_lcsubstr(s1, s2):
  m = [[0 for i in range(len(s2) + 1)] for j in range(len(s1) + 1)]
  mmax = 0
  p = 0
  for i in range(len(s1)):
    for j in range(len(s2)):
      if s1[i] == s2[j]:
        m[i + 1][j + 1] = m[i][j] + 1
        if m[i + 1][j + 1] > mmax:
          mmax = m[i + 1][j + 1]
          p = i + 1
  return s1[p - mmax:p], mmax

#words = ["fish", "vista", "mishap", "flush", "blush", "blushing"] #hish
word = input('Введите слово: ')
n = int(input('Введите кол-во слов в словаре: '))
words = []
for i in range(n):
  words.append(input("Введите слово: "))

same = ["", 0]
for i in words:
  if find_lcsubstr(word, i)[1] >= same[1]:
    same = find_lcsubstr(word, i)
    similar = i
print("Самое похожее слово:fl", similar)

# № 5

def lcs(s1, s2):
    m = [[0 for i in range(len(s2) + 1)] for j in range(len(s1) + 1)]
    for i in range(len(s1) + 1):
      for j in range(len(s2) + 1):
        if i == 0 or j == 0 :
          m[i][j] = 0
        elif s1[i-1] == s2[j-1]:
          m[i][j] = m[i-1][j-1]+1
        else:
          m[i][j] = max(m[i-1][j], m[i][j-1])
    return m[len(s1)][len(s2)]

#words = ["fish", "fort", "dirt", "flush", "blush"] #fosh
word = input('Введите слово: ')
n = int(input('Введите кол-во слов в словаре: '))
words = []
for i in range(n):
  words.append(input("Введите слово: "))


same = 0
for i in words:
  if lcs(word, i) >= same:
    same = lcs(word, i)
    similar = i
print('Самое похожее слово:', similar)


# №6

import random as rnd

def greedyOne(items):
  boxes = [0]
  for i in items:
    for j in range(len(boxes)):
      if i + boxes[j] <= 1:
        boxes[j] += i
        break
      if j == len(boxes) - 1:
        boxes.append(i)
  return len(boxes)


def greedyTwo(items):
  boxes = [0]
  for i in items:
    boxes.sort(reverse=True)
    for j in range(len(boxes)):
      if i + boxes[j] <= 1:
        boxes[j] += i
        break
      if j == len(boxes) - 1:
        boxes.append(i)
  return len(boxes)


def greedyThree(items):
  boxes = [0]
  j = 0
  for i in items:
    if i + boxes[j] <= 1:
      boxes[j] += i
    else:
      j += 1
      boxes.append(i)
  return len(boxes)


def greedyFour(items):
  boxes = [0]
  for i in items:
    boxes.sort()
    for j in range(len(boxes)):
      if i + boxes[j] <= 1:
        boxes[j] += i
        break
      if j == len(boxes) - 1:
        boxes.append(i)
  return len(boxes)

rand50 = [round(rnd.random(), 1) for a in range(50)]
rand100 = [round(rnd.random(), 1) for a in range(100)]
rand200 = [round(rnd.random(), 1) for a in range(200)]
rand500 = [round(rnd.random(), 1) for a in range(500)]

randoms = [rand50, rand100, rand200, rand500]

for i in randoms:
  print('Задача о ящиках для', len(i), 'предметов')
  print('Первый алгоритм:', greedyOne(i))
  print('Второй алгоритм:', greedyTwo(i))
  print('Третий алгоритм:', greedyThree(i))
  print('Четвёртый алгоритм:', greedyFour(i))

# № 7

def dynamicAlg(nominal, S):
  F = []
  F.append(0)
  for m in range(1, S+1):
    F.insert(m, float("+inf"))
    for i in range(len(nominal)):
      if m >= nominal[i] and F[m-nominal[i]] + 1 < F[m]:
        F[m] = F[m - nominal[i]] + 1
  return F[S]


def greedAlg(nominal, S):
  F=[]
  while S != 0:
    for i in nominal:
      if S//i > 0:
        F.append(i)
        S -= i
        break
  return len(F)

nominal = [100, 50, 10, 4, 3, 1]
S = int(input("Введите сумму: "))

print("Методом динамического программирования:", dynamicAlg(nominal, S), "купюры")
print("Методом динамического жадного алгоритма:",greedAlg(nominal, S), "купюры")
