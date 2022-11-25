from collections import deque


# №1
class Vertex:
    def __init__(self, key):
        self.id = key
        self.connectedTo = {}

    def addNeighbor(self, nbr, weight=0):
        self.connectedTo[nbr] = weight

    def __str__(self):
        return str(self.id) + ' connectedTo: ' + str([x.id for x in self.connectedTo])

    def getConnections(self):
        return self.connectedTo.keys()

    def getId(self):
        return self.id

    def getWeight(self, nbr):
        return self.connectedTo[nbr]


class Graph:
    def __init__(self):
        self.vertList = {}
        self.numVertices = 0

    def addVertex(self, key):
        self.numVertices = self.numVertices + 1
        newVertex = Vertex(key)
        self.vertList[key] = newVertex
        return newVertex

    def getVertex(self, n):
        if n in self.vertList:
            return self.vertList[n]
        else:
            return None

    def __contains__(self, n):
        return n in self.vertList

    def addEdge(self, f, t, cost=0):
        if f not in self.vertList:
            self.addVertex(f)
        if t not in self.vertList:
            self.addVertex(t)
        self.vertList[f].addNeighbor(self.vertList[t], cost)

    def getVertices(self):
        return self.vertList.keys()


    def dijkstra(self, start_node):
      unvisited_nodes = list(self.getVertices())
      shortest_path = {}
      previous_nodes = {} 
      max_value = float("inf")
      for node in unvisited_nodes:
          shortest_path[node] = max_value 
      shortest_path[start_node] = 0
      while unvisited_nodes:
          current_min_node = None
          for node in unvisited_nodes:
              if current_min_node == None:
                  current_min_node = node
              elif shortest_path[node] < shortest_path[current_min_node]:
                  current_min_node = node   
          neighbors = self.vertList[current_min_node].getConnections()
          for neighbor in neighbors:
              tentative_value = shortest_path[current_min_node] + self.vertList[current_min_node].getWeight(neighbor)
              if tentative_value < shortest_path[neighbor.getId()]:
                  shortest_path[neighbor.getId()] = tentative_value
                  previous_nodes[neighbor.getId()] = current_min_node
          unvisited_nodes.remove(current_min_node)
      return shortest_path

        
    def __iter__(self):
        return iter(self.vertList.values())

    def __str__(self):
        string = "{"
        for i in self.vertList:
          if isinstance(self.vertList[i], str):
            string += self.vertList[i] + ", "
          else:
            string += str(self.vertList[i]) + ", "
        string += "}"
        return string

def person_is_seller(name):
      return name[0] == 'a'

G = Graph()
G.addVertex("you")
G.addVertex("bob")
G.addVertex("alice")
G.addVertex("claire")
G.addVertex("anuj")
G.addVertex("peggy")
G.addVertex("thom")
G.addVertex("jonny")

G.addEdge("you", "bob")
G.addEdge("you", "claire")
G.addEdge("bob", "anuj")
G.addEdge("bob", "peggy")
G.addEdge("alice", "peggy")
G.addEdge("claire", "thom")
G.addEdge("claire", "jonny")

def search(name):
    search_queue = deque()
    search_queue += [x.id for x in G.vertList[name].connectedTo]
    searched = set()
    while search_queue:
        person = search_queue.popleft()
        if person not in searched:
            if person_is_seller(person):
                print(person + " is a mango seller!")
                return True
            else:
                search_queue += [x.id for x in G.vertList[person].connectedTo]
                searched.add(person)
    return False

search("you")

# №2

def reverse_Graph(graph):
  keys = graph.getVertices()
  rev = Graph()
  for i in keys:
    if i not in rev:
      rev.addVertex(i)
    con = [x.id for x in G.vertList[i].connectedTo]
    for j in con:
      if j not in rev:
        rev.addVertex(j)
      rev.addEdge(j, i)
  #print([x.id for x in rev.vertList[3].connectedTo])
  return rev

G = Graph()
G.addVertex(0)
G.addVertex(1)
G.addVertex(2)
G.addVertex(3)

G.addEdge(0, 1)
G.addEdge(0, 2)
G.addEdge(2, 1)
G.addEdge(1, 3)
G.addEdge(2, 3)

print("G: ", G)
reverse = reverse_Graph(G)
print("Reversed G: ", reverse)

# №4

G = Graph()
G.addVertex("Белово")
G.addVertex("Ленинск-Кузнецкий")
G.addVertex("Киселевск")
G.addVertex("Гурьевск")
G.addVertex("Мыски")
G.addVertex("Кемерово")
G.addVertex("Новосибирск")

G.addEdge("Белово", "Ленинск-Кузнецкий", 31)
G.addEdge("Ленинск-Кузнецкий", "Киселевск", 79)
G.addEdge("Белово", "Киселевск", 51)
G.addEdge("Белово", "Гурьевск", 33)
G.addEdge("Гурьевск", "Киселевск", 55)
G.addEdge("Ленинск-Кузнецкий", "Мыски", 150)
G.addEdge("Киселевск", "Кемерово", 154)
G.addEdge("Кемерово", "Новосибирск", 204)
G.addEdge("Мыски", "Новосибирск", 348)

G.dijkstra("Гурьевск")