#!/bin/python3

import math
import os
import random
import re
import sys

def consumer():
    while True:
        x = yield
        print(x)

def producer(n):
    for _ in range(n):
        x = int(input())
        yield x


# Complete the 'rooter', 'squarer', and 'accumulator' function below.

def rooter():
    while True:
        x = yield
        yield math.sqrt(x)

def squarer():
    while True:
        x = yield
        yield x**2

def accumulator():
    sum = 0
    while True:
        x = yield
        sum += x
        yield sum


def pipeline(prod, workers, cons):
    for num in prod:
        for i, w in enumerate(workers):
            num = w.send(num)
            next(w)
        cons.send(num)
    for worker in workers:
        worker.close()
    cons.close()


if __name__ == '__main__':
    order = input().strip()
    
    n = int(input())

    prod = producer(n)

    cons = consumer()
    next(cons)
    
    root = rooter()
    next(root)

    accumulate = accumulator()
    next(accumulate)

    square = squarer()
    next(square)

    pipeline(prod, eval(order), cons)
