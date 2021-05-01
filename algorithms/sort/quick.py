from random import randint

def random_index(left, right):
  return randint(left, right)

def partition(list, left, right):
  pivot = random_index(left, right)
  list[left], list[pivot] = list[pivot], list[left]
  index = left + 1

  for i in range(left + 1, right + 1):
    if list[i] < list[left]:
      list[i], list[index] = list[index], list[i]
      index += 1

  pivot = index - 1
  list[left], list[pivot] = list[pivot], list[left]
  return pivot

def quick_sort(list, left, right):
  if left < right:
    pivot = partition(list, left, right)
    quick_sort(list, left, pivot - 1)
    quick_sort(list, pivot + 1, right)

list = [4, 5, 9, 8, 7, 3, 2, 1, 6]
quick_sort(list, 0, len(list)-1)
print(list)
