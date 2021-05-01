def merge(list, left, mid, right):
  l = left
  r = mid + 1
  merged_list = []

  while l <= mid and r <= right:
    if list[l] < list[r]:
      merged_list.append(list[l])
      l += 1
    else:
      merged_list.append(list[r])
      r += 1

  while l <= mid:
    merged_list.append(list[l])
    l += 1

  while r <= right:
    merged_list.append(list[r])
    r += 1

  for i in range(right - left + 1):
    list[left + i] = merged_list[i]

def merge_sort(list, left, right):
  if left < right:
    mid = left + (right - left)//2
    merge_sort(list, left, mid)
    merge_sort(list, mid + 1, right)
    merge(list, left, mid, right)

list = [4, 5, 9, 8, 7, 3, 2, 1, 6]
merge_sort(list, 0, len(list)-1)
print(list)
