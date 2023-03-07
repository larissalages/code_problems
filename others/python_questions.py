"""
1. [5 mins] Convert the following for loops to list comprehensions:

a.
 #!python
  odds = []
  for i in range(10):
      if i % 2:
          odds.append(i)

b. 
#!python
  odds_mask = []
  for i in range(10):
      if i // 2 != i / 2:
          odds_mask.append(1)
      else:
          odds_mask.append(0)

c.
#!python
  x = [[1,2,3], [4,5,6], [7,8,9]]
  y = []
  for i in x:
      for j in i:
          y.append(j)
"""

# a.
odds = []
for i in range(10):
  if i % 2:
      odds.append(i)

print(odds)

odds2 = [i for i in range(10) if i % 2]
print(odds2)

# b.
odds_mask = []
for i in range(10):
  if i // 2 != i / 2:
      odds_mask.append(1)
  else:
      odds_mask.append(0)
print(odds_mask)

odds_mask2 = [1 if i // 2 != i / 2 else 0 for i in range(10)] 
print(odds_mask2)

# c. 
x = [[1,2,3], [4,5,6], [7,8,9]]
y = []
for i in x:
  for j in i:
      y.append(j)
print(y)

y = [j for i in x for j in i]
print(y)     
