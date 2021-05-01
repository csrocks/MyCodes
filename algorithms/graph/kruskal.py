import heapq

def root(id, x):
  while id[x] != x:
    id[x] = id[id[x]]
    x = id[x]

  return x

def union(id, x, y):
  print(id)
  id[root(id, x)] = id[root(id, y)]

def kruskal(graph):
  id = list(range(len(graph)))
  graph.sort(key=lambda g: g[0])
  mst = 0 # minimum spanning tree
  for d, x, y in graph:
    if root(id, x) != root(id, y):
      mst += d
      union(id, x, y)

  return mst

graph =[ [4,0,1], [1,0,3], [3,1,2], [2,3,2], [2,2,4]] # [weight, x, y]
mst = kruskal(graph)
print(mst)
