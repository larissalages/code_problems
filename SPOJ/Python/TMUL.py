// https://www.spoj.com/problems/TMUL/

n = int(input())
arr = [ ]

for i in range(0,n):
	a,b= input().split()
	arr.append(int(a)*int(b))
	
for num in arr:
	print(num)
