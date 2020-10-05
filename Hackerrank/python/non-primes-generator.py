import math
def is_prime(n):
    for i in range(2, n//2 +1):
        if (n % i) == 0:    
            return False
    return True


def manipulate_generator(generator, n):
	# Enter your code here
	prime = is_prime(n + 1)
	if prime is False: return
	while prime is True:
		n = next(generator)
		prime = is_prime(n + 1)


def positive_integers_generator():
	n = 1
	while True:
		x = yield n
		if x is not None:
			n = x
		else:
			n += 1


k = int(input())
g = positive_integers_generator()
for _ in range(k):
	n = next(g)
	print(n)
	manipulate_generator(g, n)
