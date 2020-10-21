#Question link
# https://www.hackerrank.com/challenges/fibonacci-modified/problem

#solution

dp=[0]

def fun(t1,t2,tn):
    l1=len(dp)
    for i in range(l1,tn+1):
        dp.append( ( dp[i-2] +(dp[i-1]**2) ) )

arr=input().split();
dp.append(int(arr[0]));
dp.append(int(arr[1]));
tn=int(arr[2])
fun(dp[1],dp[2],tn)
print(dp[len(dp)-1])
