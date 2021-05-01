def cal_lps(key):
  lps = [0] * len(key)
  prev = 0
  i = 1

  while i < len(key):
    if key[prev] == key[i]:
      prev += 1
      lps[i] = prev
      i += 1
    else:
      if prev: prev = lps[prev - 1]
      else:
        lps[i] = 0
        i += 1

  return lps

def kmp(text, key):
  indices = []
  lps = cal_lps(key)
  i = 0
  j = 0

  while i < len(text):
    if text[i] == key[j]:
      i += 1
      j += 1

    if j == len(key):
      indices.append(i - j)
      j = lps[j-1]
    elif i < len(text) and  text[i] != key[j]:
      if j: j = lps[j-1]
      else: i += 1

  return indices

text = "ababaaaaaba"
key = "aba"
indices = kmp(text, key)
print(indices)
