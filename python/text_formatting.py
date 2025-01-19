"""
Given an array of strings words and a width maxWidth, 
format the text such that each line has exactly maxWidth
characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is,
pack as many words as you can in each line. Pad extra spaces
' ' when necessary so that each line has exactly maxWidth
characters.

Extra spaces between words should be distributed as evenly 
as possible. If the number of spaces on a line does not divide
evenly between words, the empty slots on the left will be 
assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no 
extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space
characters only.
Each word's length is guaranteed to be greater than 0 and not 
exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", 
"justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
"""

input_words = ["12345678901234567", "0123", "456", "example", "of", "text", 
"justification."]
maxWidth = 16
output = []
line = []
length = 0

for word in input_words:
  if length + len(word) + len(line) > maxWidth:
    for i in range(maxWidth - length):
      if len(line) > 1:
        line[i % (len(line) - 1)] += " "
      else:
        line[0] += " "
    output.append("".join(line))
    line = []
    length = 0
  line.append(word)
  length += len(word)
  
last_line = " ".join(line)
spaces_to_add = maxWidth - len(last_line)
output.append(last_line + " " * spaces_to_add)
print(output)