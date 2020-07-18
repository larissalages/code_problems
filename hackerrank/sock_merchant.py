#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    pairs = 0
    socks = {}
    for elem in ar:
        if elem not in socks:
            socks[elem] = 1
        else:
            if socks[elem] == 1:
                pairs += 1
                socks[elem] = 0
            else:
                socks[elem] += 1
    return pairs

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
