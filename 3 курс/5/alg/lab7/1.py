from ppbtree import *


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


class BinaryTree:
    def __init__(self, rootObj):
        self.key = rootObj
        self.leftChild = None
        self.rightChild = None

    def insertLeft(self, newNode):
        if self.leftChild == None:
            self.leftChild = BinaryTree(newNode)
        else:
            t = BinaryTree(newNode)
            t.leftChild = self.leftChild
            self.leftChild = t

    def insertRight(self, newNode):
        if self.rightChild == None:
            self.rightChild = BinaryTree(newNode)
        else:
            t = BinaryTree(newNode)
            t.rightChild = self.rightChild
            self.rightChild = t

    def getRightChild(self):
        return self.rightChild

    def getLeftChild(self):
        return self.leftChild

    def setRootVal(self, obj):
        self.key = obj

    def getRootVal(self):
        return self.key


def buildParseTree(fpexp):
    fplist = fpexp.split()
    pStack = Stack()
    eTree = BinaryTree('')
    pStack.push(eTree)
    currentTree = eTree
    for i in fplist:
        # print_tree(currentTree, nameattr='key', left_child='leftChild', right_child='rightChild')
        if i == '(':
            currentTree.insertLeft('')
            pStack.push(currentTree)
            currentTree = currentTree.getLeftChild()
        elif i not in ['+', '-', '*', '/', ')', '&', '|', '!', 'False', 'True']:
            currentTree.setRootVal(int(i))
            parent = pStack.pop()
            currentTree = parent
        elif i in ['False', 'True']:
            currentTree.setRootVal(i)
            parent = pStack.pop()
            currentTree = parent
        elif i in ['+', '-', '*', '/', '&', '|', '!']:
            currentTree.setRootVal(i)
            currentTree.insertRight('')
            pStack.push(currentTree)
            currentTree = currentTree.getRightChild()
        elif i == ')':
            currentTree = pStack.pop()
        else:
            raise ValueError
    return eTree


def evaluate(parseTree):
    opers = {'+': lambda x, y: x + y, '-': lambda x, y: x - y,
             '*': lambda x, y: x * y, '/': lambda x, y: x / y,
             '&': lambda x, y: str(bool(x) & bool(y)), '|': lambda x, y: str(bool(x) | bool(y)),
             '!': lambda x: str(not bool(x))}

    leftC = parseTree.getLeftChild()
    rightC = parseTree.getRightChild()

    if leftC and not rightC:
        fn = opers[parseTree.getRootVal()]
        return fn(evaluate(leftC))    
    if leftC and rightC:
        fn = opers[parseTree.getRootVal()]
        return fn(evaluate(leftC),evaluate(rightC))
    else:
        return parseTree.getRootVal()

# pt = buildParseTree("( ( 10 + 5 ) * 3 )")
pt = buildParseTree("( ! ( True & False ) )")
# pt = buildParseTree("( True & ! ( True & False ) )")
print_tree(pt, nameattr='key', left_child='leftChild', right_child='rightChild')

print(evaluate(pt))