
def find_day(stockData, n):
	r = l = n
	len_list = len(stockData)
	while(l > 0 or r < len_list-1):
		if l > 0:
			l -= 1
			if stockData[l] < stockData[n]:
				return l+1
		if r < len_list-1:
			r += 1
			if stockData[r] < stockData[n]:
				return r+1
	return -1

def predictAnswer(stockData, queries):
	days = []
	for query in queries:
		days.append(find_day(stockData, query-1))
	return days

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    stockData_count = int(input().strip())

    stockData = []

    for _ in range(stockData_count):
        stockData_item = int(input().strip())
        stockData.append(stockData_item)

    queries_count = int(input().strip())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input().strip())
        queries.append(queries_item)

    result = predictAnswer(stockData, queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
