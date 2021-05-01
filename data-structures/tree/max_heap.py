def max_heapify(list, i):
  n = len(list)
  left = 2*i
  right = left + 1
  largest = i

  if left < n and list[i] < list[left]: largest = left
  if right < n and list[largest] < list[right]: largest = right

  if largest != i:
    list[largest], list[i] = list[i], list[largest]
    max_heapify(list, largest)

def build_max_heap(list):
  for i in range(len(list)//2, -1, -1):
    max_heapify(list, i)

list = [1,6,2,5,9,8,7,3,4]
build_max_heap(list)
print(list)
