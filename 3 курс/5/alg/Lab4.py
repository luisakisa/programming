import numpy as np
import sympy as sp
from floc_simhash import SimHash
import os
import uuid
import hashlib

# №1

class HashTable:
    def __init__(self):
        self.size = 11
        self.slots = [None] * self.size
        self.data = [None] * self.size

    def put(self, key, data):
        hashvalue = self.hashfunction(key, len(self.slots))

        if self.slots[hashvalue] == None:
            self.slots[hashvalue] = key
            self.data[hashvalue] = data
        else:
            if self.slots[hashvalue] == key:
                self.data[hashvalue] = data  # replace
            else:
                tr = 1
                nextslot = self.rehash(hashvalue, len(self.slots), tr)
                while self.slots[nextslot] != None and \
                        self.slots[nextslot] != key:
                    tr = tr + 1
                    nextslot = self.rehash(nextslot, len(self.slots), tr)

                if self.slots[nextslot] == None:
                    self.slots[nextslot] = key
                    self.data[nextslot] = data
                else:
                    self.data[nextslot] = data  # replace
        # Переделайте метод put таким образом, чтобы таблица автоматически меняла размер, когда загрузочный фактор становится больше значения 0.7. 
        if (self.size - self.slots.count(None))/self.size > 0.7:
            self.size = sp.nextprime(self.size*2)
            slots = self.slots.copy()
            data = self.data.copy()
            self.slots = [None] * self.size
            self.data = [None] * self.size
            while slots.count(None) != 0:
                slots.remove(None)
                data.remove(None)
            for i in range(len(slots)):
                self.put(slots[i], data[i])

    def hashfunction(self, key, size):
        return key % size

    def rehash(self, oldhash, size, tr):
      
        #Реализуйте квадратичное пробирование как технику повторного хеширования
        return (oldhash + 1*tr + 2*tr**2) % size

    def get(self, key):
        startslot = self.hashfunction(key, len(self.slots))
        tr = 1
        data = None
        stop = False
        found = False
        position = startslot
        while self.slots[position] != None and \
                not found and not stop:
            if self.slots[position] == key:
                found = True
                data = self.data[position]
            else:
                position = self.rehash(position, len(self.slots), tr)
                tr = tr + 1
                if position == startslot:
                    stop = True
        return data

    def __getitem__(self, key):
        return self.get(key)

    def __setitem__(self, key, data):
        self.put(key, data)

    def __len__(self):
        #Реализуйте работу с функцией len
        return self.size;

    def __contains__(self, element):
        #Реализуйте работу оператора in
        return element in self.data
        
    def __str__():
        s = self.size
        string = "{"
        for i in range(s):
            if self.slots[i] != None:
                string = string + str(self.slots[i]) + ": " + self.data[i] + ", "
            else: 
                string = string + "None: None, "
        string = string + "}"
        return string

    def __delitem__(self, element):
        #Реализуйте работу оператора del
        self.data[self.data.index(self.get(element))] = None
        self.slots[self.slots.index(element)] = None
        if (self.size - self.slots.count(None))/self.size < 0.2:
            self.size = sp.nextprime(self.size/2)
            self.size = int(self.size)
            slots = self.slots.copy()
            data = self.data.copy()
            self.slots = [None] * self.size
            self.data = [None] * self.size
            while slots.count(None) != 0:
                slots.remove(None)
                data.remove(None)
            for i in range(len(slots)):
                self.put(slots[i], data[i])

H = HashTable()
H[54] = "cat"
H[26] = "dog"
H[93] = "lion"
H[17] = "tiger"
H[77] = "bird"
H[31] = "cow"
H[44] = "goat"
print(len(H))
print(H.slots)
print(H.data)
H[55] = "pig"
H[20] = "chicken"
H[2] = "jaguar"
print(len(H))
print(H.slots)
print(H.data)
print("goat" in H)
del H[54]
del H[44]
del H[31]
del H[77]
del H[17]
del H[93]
print(H.slots)
print(H.data)

#№2

class HashTable:
    def __init__(self):
        self.size = 11
        self.slots = [None] * self.size
        self.data = [None] * self.size

    def add_elem(self):
        if len(self) / self.size > 0.7:
            while not self.prime_number(self.size) or len(self) / self.size > 0.5:
                self.size += 1

        keep_data = list((k, v) for k, v in zip(self.slots, self.data) if k is not None)
        self.slots = [None] * self.size
        self.data = [None] * self.size

        for k, v in keep_data:
            while not k.isEmpty():
                self.put(k.pop(), v.pop())

    def del_elem(self):
        if len(self) / self.size < 0.25:
            while not self.prime_number(self.size) or len(self) / self.size < 0.4:
                self.size -= 1

            keep_data = list((k, v) for k, v in zip(self.slots, self.data) if k is not None)
            self.slots = [None] * self.size
            self.data = [None] * self.size

            for k, v in keep_data:
                while not k.isEmpty():
                    self.put(k.pop(), v.pop())

    def prime_number(self, number):
        for i in range(2, int(number ** 1 / 2) + 1):
            if number % i == 0:
                return False
        return True

    def put(self, key, data):
        hashvalue = self.hashfunction(key, len(self.slots))

        if (self.slots[hashvalue] == None):
            self.slots[hashvalue] = UnorderedList()
            self.slots[hashvalue].add(key)
            self.data[hashvalue] = UnorderedList()
            self.data[hashvalue].add(data)
            return
        elif self.slots[hashvalue].search(key):
            self.data[hashvalue].pop(self.slots[hashvalue].index(key))
            self.data[hashvalue].insert(self.slots[hashvalue].index(key), data)
            return
        else:
            self.slots[hashvalue].append(key)
            self.data[hashvalue].append(data)

    def hashfunction(self, key, size):
        return key % size

    def get(self, key):
        hashvalue = self.hashfunction(key, len(self.slots))

        while self.slots[hashvalue] != None:
            if self.slots[hashvalue].search(key):
                return self.data[hashvalue][self.slots[hashvalue].index(key)]

    def __getitem__(self, key):
        return self.get(key)

    def __setitem__(self, key, data):
        self.add_elem()
        self.put(key, data)

    def __len__(self):
        count = 0
        for i in range(len(self.data)):
            if self.data[i]:
                count += self.data[i].size()
        return count

    def __contains__(self, key):
        hashvalue = self.hashfunction(key, len(self.slots))
        if self.slots[hashvalue] and self.slots[hashvalue].search(key):
            return True

    def __delitem__(self, key):
        hashvalue = self.hashfunction(key, len(self.slots))
        if self.slots[hashvalue] and self.slots[hashvalue].search(key):
            self.data[hashvalue].pop(self.slots[hashvalue].index(key))
            self.slots[hashvalue].pop(self.slots[hashvalue].index(key))

        self.del_elem()

    def __str__(self):
        s = self.size
        string = "{"
        for i in range(s):
            if self.slots[i] != None:
                string = string + self.slots[i].__str__() + ": " + self.data[i].__str__() + ", "
            else: 
                string = string + "None: None, "
        string = string + "}"
        return string




H = HashTable()
H[54] = "cat"
H[26] = "dog"
H[93] = "lion"
H[17] = "tiger"
H[77] = "bird"
H[31] = "cow"
H[44] = "goat"
print("len: ", len(H))
print("print H: ", H)
H[55] = "pig"
H[20] = "chicken"
H[2] = "jaguar"
print("Размер изменился, т.к. загрузочный фактор стал больше 0.7: ", len(H))
print(H)
print("44 in H: ", 44 in H)
del H[54]
del H[44]
del H[31]
del H[77]
del H[17]
del H[93]
print("H after del: ", H)

#№ 3
# Для того, чтобы условие задания выполнялось, в классе HashTable из первого задания нужно поменять метод hashfunction(self, key, size) на:
def hashfunction(self, key, size):
        if isinstance(key, int):
            return key % size
        sum = 0
        for l in key:
            sum += ord(l)
        return sum % size


H = HashTable()
H["cat"] = "cat"
H["dog"] = "dog"
H["lion"] = "lion"
print(H)

# №4

lst = input("Введите строку: ").split()
hTable = HashTable()
for i in range(len(lst)):
    if hTable.haskey(lst[i]):
        hTable[lst[i]] = hTable[lst[i]] + 1
        print(hTable[lst[i]], end=' ')
    else:
        hTable[lst[i]] = 1
        print("1", end=' ')
		


# № 6

diretory = input("Path: ")
fileCount = {}
files = {}
for root, dirs, fileName in os.walk(diretory):
    for i in fileName:
        with open(os.path.join(root, i), 'b+r') as file:
            data = file.read()
            files[i] = SimHash(n_bits=128).hash(str(data))
val = list(files.values())

print("Same hashes: ")
for i in val:
    fileCount[i] = fileCount.get(i, 0) + 1
for i, j in fileCount.items():
    if j > 1:
        for k, v in files.items():
            if v == i:
                print(k)
