def min_heapify(list, i):
  n = len(list)
  left = 2*i
  right = left + 1
  smallest = i

  if left < n and list[i] > list[left]: smallest = left
  if right < n and list[smallest] > list[right]: smallest = right

  if smallest != i:
    list[smallest], list[i] = list[i], list[smallest]
    min_heapify(list, smallest)

def build_min_heap(list):
  for i in range(len(list)//2, -1, -1):
    min_heapify(list, i)

list = [1,6,2,5,9,8,7,3,4]
build_min_heap(list)
print(list)
