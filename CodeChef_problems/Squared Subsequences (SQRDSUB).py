
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = [0]*n
    l = []
    r = []
    for i in range(n):
        if(a[i]%2!=0):
            b[i] = 1
        else:
            if(a[i]%4==0):
                b[i] = 4
            else:
                b[i] = 2
    count = 0
    for i in range(n):
        if(b[i] == 1):
            count+=1
        if(b[i]==4):
            count = 0
        elif(b[i]==2):
            l.append(count+1)
            count = 0
    count = 0
    for i in range(-1,-n-1,-1):
        if(b[i] == 1):
            count+=1
        elif(b[i]==4):
            count = 0
        elif(b[i]==2):
            r.append(count+1)
            count = 0
    c = 0
    for i in range(len(r)):
        c+=l[i]*r[-i-1]
    print((n*(n+1)//2)-c)
