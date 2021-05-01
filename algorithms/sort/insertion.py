def insertion_sort(list):
  for i in range(1, len(list)):
    item = list[i]
    j = i

    while j > 0 and list[j-1] > item:
      list[j] = list[j-1]
      j -= 1

    list[j] = item

list = [4, 5, 9, 8, 7, 3, 2, 1, 6]
insertion_sort(list)
print(list)
