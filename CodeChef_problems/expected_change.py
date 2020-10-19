def fun(s):
  ans = 0
  o = 0
  c = 0
  for i in s:
    if(i=="("):
      o+=1
    elif(i==")"):
      c+=1
    if(c>o):
      c-=1
      o+=1
      ans+=1
  return ans

t = int(input())

for _ in range(t):
  n = int(input())
  s = input()
  ans = 0
  N = 10**9+7
  value = ((n+1)*n)//2
  value = pow(value,N-2,N)
  print(value)
  for i in range(n):
    ans+=fun(s[i:])
  print((ans*value)%N)