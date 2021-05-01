from queue import LifoQueue

def dfs(graph):
  s = LifoQueue()
  s.put(0)
  visited = [False] * len(graph)
  visited[0] = True

  while not s.empty():
    i = s.get()
    print(i)

    for j in reversed(graph[i]):
      if not visited[j]:
        s.put(j)
        visited[j] = True

def dfs_recursive(graph):
  visited = [False] * len(graph)
  _dfs_recursive(graph, visited, 0)

def _dfs_recursive(graph, visited, i):
  if visited[i]: return
  visited[i] = True
  print(i)
  for j in graph[i]: _dfs_recursive(graph, visited, j)

graph = [[1,3],[0,2],[1,3,4],[0,2],[2]]
dfs(graph)
print()
dfs_recursive(graph)
