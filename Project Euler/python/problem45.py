# n = int(input("Give the value of n "))

n = 1000000

prime = [True for i in range(n+1)] 
p = 2
while (p * p <= n): 
  if (prime[p] == True):
    for i in range(p * 2, n+1, p): 
      prime[i] = False
  p += 1

primeNum = []
for p in range(2, n): 
  if prime[p]: 
    primeNum.append(p)


def NumOfPrimeFact(n):
  count=0
  j = 0
  while(n!=1):
    if(n%primeNum[j]==0):
      count+=1
      while(n%primeNum[j]==0):
        n/=primeNum[j]
    j+=1
  return count

k  = int(input("give the value of prime factors: "))

i = 1
flag = 0
while(flag<k):
  if(NumOfPrimeFact(i)==k):
    flag+=1
  else:
    flag = 0
  i+=1

print("\n\n\t\t*****first number is =",i-k,"*****\n\n")