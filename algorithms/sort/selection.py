def selection_sort(list):
  for i in range(len(list)):
    min_key = i

    for j in range(i+1, len(list)):
      if list[j] < list[min_key]:
        min_key = j

    list[i], list[min_key] = list[min_key], list[i]

list = [4, 5, 9, 8, 7, 3, 2, 1, 6]
selection_sort(list)
print(list)
