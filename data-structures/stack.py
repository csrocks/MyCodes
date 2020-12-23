from queue import LifoQueue

s = LifoQueue()
s = LifoQueue(maxsize=10)

s.put('a')
s.put('b')
s.get()
s.qsize()
s.empty()
s.full()