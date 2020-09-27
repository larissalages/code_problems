class Radix:
	def sort(self, data):
		if data is None:
			raise TypeError('Data cannot be None')
		if not data:
			return data
		return self._sort(data)

	def _sort(self, data):
		max_number = max(data)
		digits = len(str(abs(max_number)))

		for d in range(digits):
			buckets = [[] for _ in range(10)]
			for num in data:
				q = num//10**d
				r = q % 10
				buckets[r].append(num)
			data = []
			for bucket in buckets:
				data.extend(bucket)
		return data


# Ex:
array = [50, 2, 13, 23, 11, 100]
print(Radix().sort(array))

