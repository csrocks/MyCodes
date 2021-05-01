from sys import maxsize
import heapq

def dijkstra(graph):
  dist = [maxsize] * len(graph)
  dist[0] = 0
  visited = [False] * len(graph)
  pq = [[0, 0]]

  while len(pq):
    dx, x = heapq.heappop(pq)
    if visited[x]: continue
    visited[x] = True

    for dy, y in graph[x]:
      if dx + dy < dist[y]:
        dist[y] = dx + dy
        heapq.heappush(pq, [dist[y], y])

  return dist



graph = [ [[4,1],[1,3],[1,2]], [[4,0],[3,2]], [[1,0],[3,1],[2,3],[2,4]], [[1,0],[2,2]], [[2,2]] ] # [weight, y]
dist = dijkstra(graph)
print(dist)
