# Lab 3 № 1
import numpy as np


class Node:
    def __init__(self, initdata):
        self.data = initdata
        self.next = None

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def setData(self, newdata):
        self.data = newdata

    def setNext(self, newnext):
        self.next = newnext

class UnorderedList:

    def __init__(self):
        self.head = None

    def isEmpty(self):
        return self.head == None

    def add(self, item):
        temp = Node(item)
        temp.setNext(self.head)
        self.head = temp

    def size(self):
        current = self.head
        count = 0
        while current != None:
            count = count + 1
            current = current.getNext()

        return count

    def search(self, item):
        current = self.head
        found = False
        while current != None and not found:
            if current.getData() == item:
                found = True
            else:
                current = current.getNext()

        return found

    def remove(self, item):
        current = self.head
        previous = None
        found = False
        while not found:
            if current.getData() == item:
                found = True
            else:
                previous = current
                current = current.getNext()

        if previous == None:
            self.head = current.getNext()
        else:
            previous.setNext(current.getNext())

    def append(self, item):
      last = self.head
      s = self.size()
      for i in range(s - 1):
        last = last.getNext()
      last.setNext(Node(item))

    def index(self, item):
      indexes = list()
      count = 0
      s = self.size()
      elem = self.head
      for i in range(s):
        if elem.getData() == item:
          indexes.append(count)
        count += 1
        elem = elem.getNext()
      return indexes

    def insert(self, pos, item):
      s = self.size()
      elem = self.head
      if pos > s-1:
        return "can't insert"
      else: 
        for i in range(pos-1):
          elem = elem.getNext()
        temp = elem.getNext()
        elem.setNext(Node(item))
        elem = elem.getNext()
        elem.setNext(temp)

    def pop(self):
      last = self.head
      s = self.size()
      for i in range(s-2):
        last = last.getNext()
      n = last.getNext().getData()
      last.setNext(None)
      return n

    def pop_pos(self, pos):
      s = self.size()
      elem = self.head
      if pos > s-1:
        return "can't pop"
      else: 
        if pos == 0:
          n = self.head.getData()
          self.head = self.head.getNext()
        else:
          for i in range(pos):
            elem = elem.getNext()
          n = elem.getData()
          temp = elem.getNext()
          elem = self.head
          for i in range(pos-1):
            elem = elem.getNext()
          elem.setNext(temp)
        return n

    def __str__(self):
      s = self.size()
      elem = self.head
      string = "["
      for i in range(s-1):
        string = string + str(elem.getData()) + ", "
        elem = elem.getNext()
      string = string + str(elem.getData()) + "]"
      return string

    def slice_unord(self, start, stop):
      s = self.size()
      elem = self.head
      sl = []
      if start > s-1 or np.abs(stop) > s or start < 0 or start > np.abs(stop):
        return "error"
      else: 
        if stop > 0:
          if start == 0:
            sl.append(elem.getData())
          else:
            for i in range(start):
              elem = elem.getNext()
            sl.append(elem.getData())
          for i in range(start, stop-1):
            elem = elem.getNext()
            sl.append(elem.getData())
        else: 
          if start == 0:
            sl.append(elem.getData())
          else:
            for i in range(start):
              elem = elem.getNext()
            sl.append(elem.getData())
          for i in range(start, s - 1 + stop):
            elem = elem.getNext()
            sl.append(elem.getData())
      return sl

mylist = UnorderedList()
mylist.add(31)
mylist.add(77)
mylist.add(17)
mylist.add(93)
mylist.add(17)
print("my list: ", mylist)
print("my list size: ", mylist.size())
mylist.append(22)
print("my list after append element (22): ", mylist)
print("my list size after append element: ", mylist.size())
print("index of element: ", mylist.index(17))
mylist.insert(3, 80)
print("my list after append element (80) in position (3): ", mylist)
print("my list size after append element in position: ", mylist.size())
print("index of inserted element (80): ", mylist.index(80))
mylist.pop()
print("my list after pop element: ", mylist)
print("my list size after pop element: ", mylist.size())
print("index of poped element: ", mylist.index(22))
mylist.pop_pos(3)
print("my list after pop element in position(3): ", mylist)
print("my list size after pop element in position: ", mylist.size())
print("index of poped in position element: ", mylist.index(80))
print("slice (1, -2): ", mylist.slice_unord(1, -2))
print("slice (1, 4): ", mylist.slice_unord(1, 4))


# № 2

def move_to_front(unord):
  n = input("Input quantity of strings: ")
  for i in range(int(n)):
    sting = input()
    if unord.search(sting):
      unord.remove(sting)
    unord.add(sting)
  print(unord)

unord = UnorderedList()
move_to_front(unord)

# № 3

def rev(head): 
  unord = UnorderedList()
  while head != None:
    unord.add(head.getData())
    head = head.getNext()
  return unord

def rev_rec(head, l):
  if head != None:
    l.add(head.getData())
    rev_rec(head.getNext(), l)
    return l
    
     

mylist = UnorderedList()
l = UnorderedList()
mylist.add(31)
mylist.add(77)
mylist.add(17)
mylist.add(93)
print(mylist)
print(rev(mylist.head))
print(rev_rec(mylist.head, l))


# № 4.1 (Ревлизация классов)
class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[-1]

    def size(self):
        return len(self.items)

class StackL:
    def __init__(self):
        self.items = UnorderedList()

    def isEmpty(self):
        return self.items.isEmpty()

    def push(self, item):
        self.items.add(item)

    def pop(self):
        return self.items.pop_pos(0)

    def peek(self):
        last = self.items.head
        return last.getData()

    def size(self):
        return self.items.size()

    def __str__(self):
      return self.items.__str__()

class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0, item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

class QueueL:
    def __init__(self):
        self.items = UnorderedList()

    def isEmpty(self):
        return self.items.isEmpty()

    def enqueue(self, item):
        self.items.add(item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return self.items.size()
        
    def __str__(self):
      return self.items.__str__()

class Deque:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addFront(self, item):
        self.items.append(item)

    def addRear(self, item):
        self.items.insert(0, item)

    def removeFront(self):
        return self.items.pop()

    def removeRear(self):
        return self.items.pop(0)

    def size(self):
        return len(self.items)

class DequeL:
    def __init__(self):
        self.items = UnorderedList()

    def isEmpty(self):
        return self.items.isEmpty()

    def addRear(self, item):
        if self.items.size() == 0:
          self.items.add(item)
        else:
          self.items.append(item)

    def addFront(self, item):
        self.items.add(item)

    def removeFront(self):
        return self.items.pop()

    def removeRear(self):
        return self.items.pop_pos(0)

    def size(self):
        return self.items.size()

    def __str__(self):
      return self.items.__str__()

print("Stack: ")
s = StackL()
print("Empty: ", s.isEmpty())
s.push(22)
s.push(13)
s.push(18)
s.push(9)
print(s)
print("Empty: ", s.isEmpty())
print("Size: ", s.size())
print("Pop: ", s.pop())
print("Size: ", s.size())
print("Peek: ", s.peek())

print("\nQueue:")
q = QueueL()
print("Empty: ", q.isEmpty())
q.enqueue(12)
q.enqueue(18)
q.enqueue(55)
print(q)
print("Empty: ", q.isEmpty())
print("Size: ", q.size())
print("Dequeue: ", q.dequeue())
print("Size: ", q.size())

print("\nDeque:")
d = DequeL()
print("Empty: ", d.isEmpty())
d.addFront(44)
d.addFront(18)
d.addFront(24)
d.addRear(92)
d.addRear(103)
print(d)
print("Size: ", d.size())
print("Empty: ", d.isEmpty())
print("Remove front: ", d.removeFront())
print("Remove rear: ", d.removeRear())
print("Size: ", d.size())
print(d)

# № 4.2 (тест времени)


import timeit
import matplotlib.pyplot as plt
from random import randint

test_in_list = timeit.Timer("x.addFront(5)", globals = globals()) 
test_in_unord = timeit.Timer("y.addFront(5)", globals = globals())

plt_x = []
plt_test_in_list = []
plt_test_in_unord = []

for i in range(1000, 10001, 100):
  plt_x.append(i)
  
  x = Deque()
  for j in range(i):
    x.addRear(randint(0, 1000))
  pt = test_in_list.timeit(number=25) 
  plt_test_in_list.append(pt)

  y = DequeL()
  for j in range(i):
    y.addRear(randint(0, 1000))
  pz = test_in_unord.timeit(number=25) 
  plt_test_in_unord.append(pz)

plt.plot(plt_x, plt_test_in_list, "-r")
plt.plot(plt_x, plt_test_in_unord, "-g")
plt.show()


# № 5

class Node:
    def __init__(self, newdata):
        self.data = newdata
        self.next = None
        self.prev = None

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def getPrev(self):
        return self.prev

    def setData(self, newdata):
        self.data = newdata

    def setNext(self, newnext):
        self.next = newnext

    def setPrev(self, newprev):
        self.prev = newprev


class DoubleLinkedList:
    def __init__(self):
        self.head = None

    def isEmpty(self):
        return self.head == None

    def size(self):
        current = self.head
        count = 0
        while current != None:
            count = count + 1
            current = current.getNext()
        return count

    def search(self, item):
        current = self.head
        found = False
        while current != None and not found:
            if current.getData() == item:
                found = True
            else:
                current = current.getNext()
        return found

    def addStart(self, data):
        if self.head == None:
            temp = Node(data)
            self.head = temp
        else:
            temp = Node(data)
            temp.next = self.head
            self.head.prev = temp
            self.head = temp
    
    def addEnd(self, data):
        if self.head == None:
            temp = Node(data)
            self.head = temp
        else:
            n = self.head
            while n.next != None:
                n = n.next
            temp = Node(data)
            n.next = temp
            temp.pref = n

    def insertAfterItem(self, x, data):
        if self.size() == 0:
            print("List is empty")
        else:
            n = self.head
            while n != None:
                if n.data == x:
                    break
                n = n.next
            if n == None:
                print("item not in the list")
            else:

                temp = Node(data)
                temp.prev = n
                temp.next = n.next
                if n.next != None:
                    n.next.prev = temp
                n.next = temp

    def insertBeforeItem(self, x, data):
        if self.head == None:
            print("List is empty")
        else:
            n = self.head
            while n != None:
                if n.data == x:
                    break
                n = n.next
            if n == None:
                print("item not in the list")
            else:
                if x == self.head.getData():
                    self.addStart(data)
                else:
                    temp = Node(data)
                    temp.next = n
                    temp.prev = n.prev
                    if n.prev != None:
                        n.prev.next = temp
                    n.prev = temp

    def remove(self, x):
        if self.head == None:
            print("The list has no element to delete")
            return 
        if self.head.next == None:
            if self.head.data == x:
                self.head = None
            else:
                print("Item not found")
            return 

        if self.head.data == x:
            self.head = self.head.next
            self.head.prev = None
            return

        n = self.head
        while n.next != None:
            if n.data == x:
                break;
            n = n.next
        if n.next != None:
            n.prev.next = n.next
            n.next.prev = n.prev
        else:
            if n.data == x:
                n.prev.next = None
            else:
                print("Element not found")

    def deleteAtStart(self):
        if self.head == None:
            print("The list has no element to delete")
        else:
            if self.head.next == None:
                self.head = None
            else:
                self.head = self.head.next
                self.prev = None;

    def deleteAtEnd(self):
        if self.head == None:
            print("The list has no element to delete")
        else:
            if self.head.next == None:
                self.head = None
            else:
                n = self.head
                while n.next != None:
                    n = n.next
                n.prev.next = None

    def __str__(self):
      s = self.size()
      elem = self.head
      string = "["
      for i in range(s-1):
        string = string + str(elem.getData()) + ", "
        elem = elem.getNext()
      string = string + str(elem.getData()) + "]"
      return string

linkedList = DoubleLinkedList()
print("Is empty: ", linkedList.isEmpty())
linkedList.addStart(50)
print("Output: ", linkedList)
print("Size: ", linkedList.size())
print("Is empty: ", linkedList.isEmpty())
print("Search element(50): ", linkedList.search(50))
linkedList.addEnd(49)
print("Output after addEnd: ", linkedList)
print("Size: ", linkedList.size())
linkedList.insertAfterItem(50, 57)
print("Output after insertAfterItem (50): ", linkedList)
linkedList.insertBeforeItem(50, 18)
print("Output after insertBeforeItem (50): ", linkedList)
linkedList.insertAfterItem(49, 22)
print("(again)Output after insertAfterItem (49):  ", linkedList)
linkedList.remove(22)
print("Output after remove element(22): ", linkedList)
linkedList.deleteAtEnd()
print("Output after deleteAtEnd: ", linkedList)
linkedList.deleteAtStart()
print("Output after deleteAtStart: ", linkedList)


# № 7

def Priority(token):
  if token == '*' or token == '/':
    return 3
  elif token == '+' or token == '-':
    return 2
  elif token == '(':
	  return 1
  elif token == ')':
	  return -1
  else:
	  return 0

def ReverseMinus(expr):
  rightExpression = []
  for i in range(len(expr)): 
    symbol = expr[i]
    if symbol == '-':
      if i == 0:
        rightExpression.append('0')
      elif expr[i - 1] == '(': 
        rightExpression.append('0')
    rightExpression.append(symbol)
  exp = "".join(rightExpression).split()
  return exp[0]


def ExprToPostFix(expr):
  current = []
  st = Stack()
  for i in range(len(expr)):
    if Priority(expr[i]) == 0:
      current.append(expr[i])
    elif Priority(expr[i]) == 1:
      st.push(expr[i])
    elif Priority(expr[i]) > 1:
      current.append(' ')
      while st.isEmpty() == False:
        if Priority(st.peek()) >= Priority(expr[i]):
          current.append(st.pop())
        else: 
          break
      st.push(expr[i])
    elif Priority(expr[i]) == -1:
      while Priority(st.peek()) != 1:
        current.append(st.pop())
      st.pop()
  while st.isEmpty() == False:
    current.append(st.pop())
  indexes = []
  for i in range(len(current)):
    if current[i] in ['+', '-', '*', '/']:
      indexes.append(' ')
      indexes.append(current[i])
      indexes.append(' ')
    else:
      indexes.append(current[i])
  cur = "".join(indexes)
  return cur

def Answer(line):
  stack = Stack()
  for i in line:
    if stack.isEmpty() or i not in ['+', '-', '*', '/']:
      stack.push(i)
    elif i in ['+', '-', '*', '/']:
      b = stack.pop()
  
      a = stack.pop()
      stack.push(str(eval(a+i+b)))
  if stack.size() != 1:
    return None
  else:
    return stack.pop()

expr = input()
print("Answer: ", Answer(ExprToPostFix(expr).split()))

# № 8 1 вариант
import random

class CarWash:
    def __init__(self, cph):
        self.carrate = cph
        self.currentTask = None
        self.timeRemaining = 0

    def tick(self):
        if self.currentTask != None:
            self.timeRemaining = self.timeRemaining - 1
            if self.timeRemaining <= 0:
                self.currentTask = None

    def busy(self):
        if self.currentTask != None:
            return True
        else:
            return False

    def startNext(self, newtask):
        self.currentTask = newtask
        self.timeRemaining = newtask.getCars() * 60 / self.carrate


class Task:
    def __init__(self, time):
        self.timestamp = time
        self.cars = random.randrange(1, 5) # 1 - 4

    def getStamp(self):
        return self.timestamp

    def getCars(self):
        return self.cars

    def waitTime(self, currenttime):
        return currenttime - self.timestamp


def simulation(numHours, carsPerHour):
    numHours *= 3600
    carsPerHour /= 60
    carWash = CarWash(carsPerHour)
    washQueue = Queue()
    waitingtimes = []

    for currentHour in range(numHours):

        if newWashTask():
            task = Task(currentHour)
            washQueue.enqueue(task)

        if (not carWash.busy()) and (not washQueue.isEmpty()):
            nexttask = washQueue.dequeue()
            waitingtimes.append(nexttask.waitTime(currentHour))
            carWash.startNext(nexttask)

        carWash.tick()

    averageWait = sum(waitingtimes) / len(waitingtimes)
    print("Average Wait %.2f hours %3d cars remaining." % (averageWait/3600, washQueue.size()))


def newWashTask():
    num = random.randrange(1, 7201)
    if num == 7200:
        return True
    else:
        return False


for i in range(10):
    simulation(24, 2)