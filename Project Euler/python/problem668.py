import math
import time
start_time = time.time()

n = int(input("Give the value of n : "))
k = math.ceil(math.sqrt(n))

#genrating prime numbers

prime = [True for i in range(k+1)] 
p = 2
while (p * p <= k): 
  if (prime[p] == True):
    for i in range(p * 2, k+1, p): 
      prime[i] = False
  p += 1

#storing numbers in a list
primeNum = []

for p in range(2, k): 
  if prime[p]: 
    primeNum.append(p)

count = 0

# test Code


# for i in range(1,n+1):
#   j = 0
#   temp = i
#   while(temp!=1):
#     if(primeNum[j]>=math.sqrt(i)):
#       break
#     if(temp%primeNum[j]==0):
#       temp//=primeNum[j]
#     else:
#       j+=1
#       if(j==len(primeNum)):
#         break
#     if(temp==1):
#       count+=1
#       print(i) # printing value of smooth sqrt numbers

#Adding 1 because of the number 1 is a smooth sqrt number 

# print("\n\t**Value of smooth square root number below",n,"=",count+1,"**")


#Optimised code
x = 0
for i in range(1,n+1):
  if(primeNum[x]<math.sqrt(i)):
    x+=1
  j = x
  while(j<k-1):
    if(primeNum[j]<=i):
      if(i%primeNum[j]==0):
        count-=1
        print("in")
        break
    else:
      break
    j+=1
  count+=1
  print("out")

  
print("\n\t**Value of smooth square root number below",n,"=",count,"**")

print("--- %s seconds ---" % (time.time() - start_time))