def bucket_sort(list):
  bucket = [[] for _ in range(len(list))]

  for i in list:
    bucket[int(i * len(list))].append(i)

  for i in bucket:
    i.sort()

  index = 0
  for i in bucket:
    for j in i:
      list[index] = j
      index += 1

list = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.34346]
bucket_sort(list)
print(list)
