'''
Problem Link - https://www.codechef.com/JULY20B/problems/CHFNSWPS
'''

from sys import *
from math import *
from collections import *

mod = 1000000007

def get_array(): return list(map(int, stdin.readline().split()))
 
def get_ints(): return map(int, stdin.readline().split())

def get_int(): return int(stdin.readline())
 
def get_input(): return stdin.readline().strip()

def main():
    tc = get_int()
    while(tc):
    	N = get_int();arr = get_array();arr1 = get_array()
    	mini = min(min(arr),min(arr1))
    	counter = Counter(arr+arr1)
    	set,dic,dic1 = 0,{},{}
    	for i in counter:
    		if counter[i]&1:set = 1;break
    		else:
    			dic[i] = counter[i]/2
    	if set:stdout.write("-1\n");
    	else:
    		dic1,list1,list2 = dic,[],[]
    		for i in range(N):
    			if dic[arr[i]]:
    				dic[arr[i]] -= 1
    			else:
    				list1.append(arr[i])
    		for i in range(N):
    			if dic1[arr1[i]]:
    				dic1[arr1[i]] -= 1
    			else:
    				list2.append(arr1[i])
    		list1.sort();list2.sort(reverse=True)
    		length = len(list1)
    		if length==0:stdout.write('0\n')
    		else:
    			ans = 0
    			for i in range(length):
    				ans += min(2*mini,min(list1[i],list2[i]))
    			stdout.write(str(ans) + '\n')
    	tc-=1

if __name__ == "__main__":
    main()
