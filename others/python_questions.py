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

############################################################################################################
"""
2. [5 mins] What does the following function do?

#!python
def read_samples(samplefile, filter):
    samples = []
    f = open(samplefile, "r")
    for line in f.readlines():
        if line.startswith(filter):
            samples.append(line[len(filter):].strip())
    return samples

If it were called in the following context, what might you do to improve it?

#!python
for sample in read_samples("hugefile.txt", "sample:"):
    process_sample(sample) # processes a sample from the file
"""

"""
2.
One way to improve this function would be to use a context manager to automatically close the file after reading. 
This would ensure that the file is always closed, even if an exception is raised during the processing of the samples. 
Here's an updated version of the function that uses a with statement:
"""
def read_samples(samplefile, filter):
    samples = []
    with open(samplefile, "r") as f:
        for line in f:
            if line.startswith(filter):
                samples.append(line[len(filter):].strip())
    return samples
"""
This updated version of the function is functionally equivalent to the original but uses a context manager to open and close the file automatically.
"""

