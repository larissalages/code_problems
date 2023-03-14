def set_cols_rows_to_zero(m):
	len_rows = len(m)
	len_cols = len(m[0])
	list_pos = []

	# finding zeros in the matrix
	for i in range(len_rows):
		for j in range(len_cols):
			if m[i][j] == 0:
				list_pos.append([i,j])

	# replacing rows and cols by zeros
	for pos in list_pos:
		for j in range(len_cols): # add zeros on row
			m[pos[0]][j] = 0
		for i in range(len_rows):
			m[i][pos[1]] = 0
	return m

test = [[1,2,3], [4,0,6], [1,3,8]]
test2 =[
		    [1, 5, 45, 0, 81],
		    [6, 7, 2, 82, 8],
		    [20, 22, 49, 5, 5],
		    [0, 23, 50, 4, 92],
  	]
r = set_cols_rows_to_zero(test2)
print(r)
