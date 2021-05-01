def binary_search(list, key):
  left = 0
  right = key

  while left < right:
    mid = left + (right - left)//2
    if key < list[mid]: right = mid - 1
    elif key > list[mid]: left = mid + 1
    else: return mid

  return -1

list = [4, 5, 6, 7, 8, 9]
print(binary_search(list, 4))
print(binary_search(list, 8))
