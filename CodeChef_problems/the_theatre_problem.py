# def fun(mymatrix,col,row,xvalue):
#   ans = 0
#   maximum = 0
#   #itration 1
#   for i in range(4):
#     if(row[i]==1):
#       for j in range(4):
#         if(col[j]==1):
#           if(mymatrix[i][j]>maximum):
#             maximum = mymatrix[i][j]
#   if(maximum==0):
#     ans-=(5-xvalue)*100
#     return ans
#   ans+=maximum*(5*xvalue)*25
#   value = []
#   for i in range(4):
#     flag = 0
#     if(row[i]==1):
#       for j in range(4):
#         if(col[j]==1):
#           if(mymatrix[i][j]==maximum):
#             col[j] = 0
#             row[i] = 0
#             value.append(fun(mymatrix,col,row,xvalue+1))
#             col[j] = 1
#             row[i] = 1
            
#   return ans + max(value)

t = int(input())
myans = 0
for _ in range(t):
  n = int(input())
  # col = [1 for i in range(4)]
  # row = [1 for i in range(4)]
  mymatrix = [[0 for i in range(4)] for i in range(4)]
  for i in range(n):
    [a,b] = input().split()
    if(a=='A'):
      mymatrix[0][(int(b)//3)%4]+=1
    elif(a=='B'):
      mymatrix[1][(int(b)//3)%4]+=1
    elif(a=='C'):
      mymatrix[2][(int(b)//3)%4]+=1
    else:
      mymatrix[3][(int(b)//3)%4]+=1
  value = []
  for a in range(4):
    for b in range(4):
      for c in range(4):
        for d in range(4):
          if(a!=b and a!=c and a!=d and b!=c and b!=d and c!=d):
            mylist = [mymatrix[0][a],mymatrix[1][b],mymatrix[2][c],mymatrix[3][d]]
            mylist.sort()
            if(mylist[0]!=0):
              value.append(mylist[0]*25 + mylist[1]*50 + mylist[2]*75 + mylist[3]*100)
            elif(mylist[1]!=0):
              value.append(mylist[3]*100 + mylist[1]*50 + mylist[2]*75 -100)
            elif(mylist[2]!=0):
              value.append(mylist[2]*75 + mylist[3]*100 -200)
            elif(mylist[3]!=0): 
              value.append(mylist[3]*100 - 300)
            else:
              value.append(-400)

  value = max(value)
  myans += value
  print(value)
print(myans)
  
  

