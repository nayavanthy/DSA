"""
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. 
Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
"""

class Node:
  def __init__(self):
    self.children = dict()
    self.words = []
    
class Trie:
  def __init__(self):
    self.root = Node()
    
  def insert(self, word):
    node = self.root
    
    for char in word:
      if(char not in node.children):
        node.children[char] = Node()
      
      node = node.children[char]
      node.words.append(word)
      node.words.sort()
  
  def print_trie(self, node=None, indent=""):
    if node is None:
      node = self.root
      
    for char, child_node in node.children.items():
      print(f"{indent}{char} -> {child_node.words}")
      self.print_trie(child_node, indent + "  ")
      
  def suggestedProducts(self, word):
    res =[]
    node = self.root
    for char in word:
      if char not in node.children :
        break
      
      node = node.children[char]
      res.append(node.words)
      
    for _ in range(len(word)- len(res)):
      res.append([])
    
    return res
  
products = ["mobile","mouse","moneypot","monitor","mousepad"]
trie = Trie()
for prod in products:
  trie.insert(prod)
  
trie.print_trie()

searchWord = "mousex"
output = trie.suggestedProducts(searchWord)

print("Suggestions After Each Character:")
for i, suggestions in enumerate(output):
    print(f"After typing {searchWord[i]}: {suggestions}")