"""
1. [2 min]  Below are 2 2D matrices.

A = [[1 4]  B = [[1 2]
     [2 5]       [1 2]]
     [3 6]]

a. What does AB equal?
b. What does BA equal?
c. What does B(B^T)  equal?
"""
A = [[1,4],[2,5], [3,6]]
B = [[1,2],[1,2]]

##############################################################################################################
# Q. a. Solution 1

def multp_matrices(matrix1, matrix2):
    n_rows1 = len(matrix1)
    n_cols1 = len(matrix1[0])
    n_rows2 = len(matrix2)
    n_cols2 = len(matrix2[0])
    
    if n_cols1 != n_rows2:
        print("The multiplication cannot be done. The matrix dimensions are different")
        return []
    
    mult = [[0 for _ in range(n_cols2)] for _ in range(n_rows1)]

    for i in range(n_rows1):
        for j in range(n_cols2):
            for k in range(n_cols1):
                mult[i][j] += matrix1[i][k]*matrix2[k][j]
    
    return mult
                
    
multp_matrices(A, B)
  
##############################################################################################################  
# Q.a Solution 2
# Using numpy

import numpy as np

C = np.matmul(A,B)
print(C)

######################################################################
# Q. b
multp_matrices(B, A)

#Using numpy (it will give a error)
try:
    C = np.matmul(B,A)
    print(C)
except Exception as e:
    print(e)

######################################################################
# Q. c.

def transpose_matrix(matrix):
    n_rows = len(matrix)
    n_cols = len(matrix[0])
    
    new_matrix = [[0 for _ in range(n_cols)] for _ in range(n_rows)]
    
    for i in range(n_rows):
        for j in range(n_cols):
            new_matrix[j][i] = matrix[i][j]
    return new_matrix

T = transpose_matrix(B)
D = multp_matrices(B, T)
print(D)

# Or using numpy
b = np.matrix(B)
b = b.transpose()
D = np.matmul(B,b)
print(D)
