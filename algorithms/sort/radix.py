def count_sort(list, mul):
  max_item = max(list)
  count_list = [0] * 10
  output_list = [0] * len(list)

  for i in list:
    index = (i//mul) % 10
    count_list[index] += 1

  for i in range(len(count_list)-1):
    count_list[i + 1] += count_list[i]

  for i in range(len(list) - 1, -1, -1):
    index = (list[i]//mul) % 10
    output_list[count_list[index] - 1] = list[i]
    count_list[index] -= 1

  for i in range(len(list)):
    list[i] = output_list[i]

def radix_sort(list):
  max_item = max(list)
  mul = 1

  while max_item:
    count_sort(list, mul)
    mul *= 10
    max_item /= 10

list = [10,21,17,34,44,11,654,1236]
radix_sort(list)
print(list)
