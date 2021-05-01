import heapq

def prim(graph):
  visited = [False] * len(graph)
  mst = 0 # minimum spanning tree
  pq = [[0, 0]]

  while len(pq):
    dx, x = heapq.heappop(pq)
    if visited[x]: continue
    visited[x] = True
    mst += dx

    for dy, y in graph[x]:
      heapq.heappush(pq, [dy, y])

  return mst

graph = [ [[4,1],[1,3]], [[4,0],[3,2]], [[3,1],[2,3],[2,4]], [[1,0],[2,2]], [[2,2]] ] # [weight, y]
mst = prim(graph)
print(mst)
