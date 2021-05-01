from queue import Queue

def bfs(graph):
  q = Queue()
  q.put(0)
  visited = [False] * len(graph)
  visited[0] = True

  while not q.empty():
    i = q.get()
    print(i)

    for j in graph[i]:
      if not visited[j]:
        q.put(j)
        visited[j] = True


graph = [[1,3],[0,2],[1,3,4],[0,2],[2]]
bfs(graph)
