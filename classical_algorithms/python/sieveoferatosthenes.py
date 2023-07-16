import math


def sieve_of_eratosthenes(n):
    if n < 2:
        return []
    primes = [1] * (n + 1)
    primes[0] = primes[1] = 0

    for i in range(2, int(math.sqrt(n) + 1)):
        if primes[i] == 1:
            for j in range(i * i, n + 1, i):
                primes[j] = 0

    return [i for i in range(n + 1) if primes[i] == 1]


if "__name__" == "__main__":
    n = int(input())
    primes = sieve_of_eratosthenes(n)
    print(f"Prime numbers up to {n}:")
    for prime in primes:
        print(prime, end=" ")
