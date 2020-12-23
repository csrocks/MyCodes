from queue import Queue

q = Queue()
q = Queue(maxsize=10)

q.put('a')
q.put('b')
q.get()
q.qsize()
q.empty()
q.full()