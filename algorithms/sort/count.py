def count_sort(list):
  max_item = max(list)
  count_list = [0] *  (max_item + 1)

  for i in list:
    count_list[i] += 1

  index = 0
  for i in range(max_item + 1):
    count = count_list[i]
    while count:
      list[index] = i
      index += 1
      count -= 1

def count_sort_2(list):
  max_item = max(list)
  count_list = [0] * (max_item + 1)
  output_list = [0] * (len(list))

  for i in list:
    count_list[i] += 1

  for i in range(max_item):
    count_list[i + 1] += count_list[i]

  for i in range(len(list) - 1, -1, -1):
    output_list[count_list[list[i]] - 1] = list[i]
    count_list[list[i]] -= 1

  for i in range(len(list)):
    list[i] = output_list[i]

list = [4, 5, 9, 8, 7, 3, 2, 1, 6]
count_sort(list)
print(list)

list_2 = [4, 5, 9, 8, 7, 3, 2, 1, 6]
count_sort_2(list_2)
print(list_2)
