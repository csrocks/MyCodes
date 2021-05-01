def max_heapify(list, i, n):
  left = 2*i
  right = left + 1
  largest = i

  if left < n and list[i] < list[left]: largest = left
  if right < n and list[largest] < list[right]: largest = right

  if largest != i:
    list[largest], list[i] = list[i], list[largest]
    max_heapify(list, largest, n)

def build_max_heap(list):
  for i in range(len(list)//2, -1, -1):
    max_heapify(list, i, len(list))

def heap_sort(list):
  build_max_heap(list)
  for i in range(len(list)-1, 0, -1):
    list[i], list[0] = list[0], list[i]
    max_heapify(list, 0, i)

list = [4, 5, 9, 8, 7, 3, 2, 1, 6]
heap_sort(list)
print(list)
