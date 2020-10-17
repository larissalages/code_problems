import math

def pantaNumber(ver):
  return (ver*(3*ver-1))/2

n =  2500

panta = []

for i in range(1,n+1):
  panta.append(pantaNumber(i))

for i in range(1,n):
  print("value of i =",i)
  for j in range(n-i):
    print("value of (i,j)",(i,j))
    if panta[j+i]+panta[j] in panta:
      if panta[j+i]-panta[j] in panta:
        print("the smallest value D =",panta[j+i]-panta[i])
        quit()

        
