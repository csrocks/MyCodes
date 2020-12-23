class Node:
  def __init__(self, key):
    self.key = key
    self.next = None 

class LinkedList:
  def __init__(self):
    self.head = None

  def print(self):
    temp = self.head
    while temp:
      print(temp.key, end=" ")
      temp = temp.next
    print()

  def append(self, key):
    node = Node(key)
    if not self.head: self.head = node
    else:
      temp = self.head
      while temp.next: temp = temp.next
      temp.next = node
  
  def prepend(self, key):
    node = Node(key)
    node.next = self.head
    self.head = node
  
  def delete(self, key):
    prev = self.head
    temp = prev.next
    
    if prev.key == key:
      del(prev)
      self.head = temp
      prev = temp
      temp = temp.next

    while temp:
      if temp.key == key:
        prev.next = temp.next
        del(temp)
        temp = prev
      prev = temp
      temp = temp.next

linked_list = LinkedList()

for i in range(5):
  linked_list.append(i)

for i in range(5, 10):
  linked_list.prepend(i)

linked_list.print()
linked_list.delete(7)
linked_list.print()