alphabets = 26

class Node:
  def __init__(self):
    self.next = [None]*alphabets
    self.is_word = False

class Trie:
  def __init__(self):
    self.root = Node()

  def insert(self, word):
    if not word: return
    temp = self.root

    for i in range(0, len(word)):
      index = ord(word[i].lower()) - ord('a')
      if not temp.next[index]: temp.next[index] = Node()
      temp = temp.next[index]

    temp.is_word = True

  def search(self, word):
    if not word: return
    temp = self.root

    for i in range(0, len(word)):
      index = ord(word[i].lower()) - ord('a')
      if not temp.next[index]: return False
      temp = temp.next[index]

    return True if temp.is_word else False

  def remove(self, word):
    if not word: return
    self._remove(self.root, word, 0)


  def _remove(self, root, word, i):
    if not root: return
    if i == len(word):
      if any(root.next):
        root.is_word = False
        return
      return True

    index = ord(word[i].lower()) - ord('a')
    delete = self._remove(root.next[index], word, i+1)

    if delete:
      del root.next[index]
      root.next[index] = None
      return None if root.is_word else True

t = Trie()
t.insert('abc')
t.insert('abcdef')
t.insert('xyz')
print('ab', t.search('ab'))
print('abcd', t.search('abcd'))
print('abc', t.search('abc'))
print('Remove abc', t.remove('abc'))
print('abc', t.search('abc'))
print('abcdef', t.search('abcdef'))
print('Remove abcdef', t.remove('abcdef'))
print('abcdef', t.search('abcdef'))
