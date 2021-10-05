n,d = map(int,input().strip().split())
exp = list(map(int, input().strip().split()))
count = {}
i = 0
while i<d:
    x = exp[i]
    if x not in count:
        count[x] = 0
    count[x] += 1
    i+=1

def median():
    global count
    cnt,midval = 0,0
    for i in range(201):
        if i in count:
            cnt += count[i]
            if cnt >= d//2:
                midval = i
                break
    secondval = midval
    
    if cnt == d//2:
        x = midval + 1
        while x not in count or count[x] == 0:
            x+=1
        secondval = x
    if d%2==1:
        return secondval
    return (midval + secondval)/2
        
ans = 0
i-=1
while i<n-1:
    md = median()
    if exp[i+1] >= 2*md:
        ans += 1
    count[exp[i+1-d]]-=1
    x = exp[i+1]
    if x not in count:
        count[x] = 0
    count[x]+=1
    i+=1
    
print (ans)
