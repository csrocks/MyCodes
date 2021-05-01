class PriorityQueue:
  def __init__(self):
    self.pqueue = []

  def max_heapify(self, i):
    n = len(self.pqueue)
    left = 2*i
    right = left + 1
    largest = i

    if left < n and self.pqueue[i] < self.pqueue[left]: largest = left
    if right < n and self.pqueue[largest] < self.pqueue[right]: largest = right

    if largest != i:
      self.pqueue[largest], self.pqueue[i] = self.pqueue[i], self.pqueue[largest]
      self.max_heapify(largest)

  def build_current(self, i, item):
    if self.pqueue[i] > item: return
    self.pqueue[i] = item

    while i > 0 and self.pqueue[i] > self.pqueue[i//2]:
      self.pqueue[i], self.pqueue[i//2] = self.pqueue[i//2], self.pqueue[i]
      i = i//2

  def push(self, item):
    self.pqueue.append(-1)
    self.build_current(self.size()-1, item)

  def pop(self):
    if self.empty(): return

    max = self.pqueue[0]
    self.pqueue[0] = self.pqueue[-1]
    self.max_heapify(0)

    return max

  def top(self):
    return -1 if self.empty() else self.pqueue[0]

  def size(self):
    return len(self.pqueue)

  def empty(self):
    return len(self.pqueue) == 0

pq = PriorityQueue()
pq.push(2)
pq.push(8)
pq.push(5)
print('Pop', pq.pop())
print('Top', pq.top())
print('Size', pq.size())
print('Empty', pq.empty())
