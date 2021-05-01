def bubble_sort(list):
  for i in range(len(list)-1):
    for j in range(len(list)-i-1):
      if list[j] > list[j+1]:
        list[j], list[j+1] = list[j+1], list[j]

list = [4, 5, 9, 8, 7, 3, 2, 1, 6]
bubble_sort(list)
print(list)
