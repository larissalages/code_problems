a = int(input())

n = 2
myvalue = 0
i = 1
while(True):
  i+=1
  n*=2
  n = int(str(n)[:15])
  if(str(n)[:3]=='123'):
    myvalue+=1
  if(myvalue==a):
    break
print(i)

