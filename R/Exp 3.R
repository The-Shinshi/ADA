A = matrix(c(1,2,3,4,5,6,7,8,9), nrow = 3, ncol = 3)
B = matrix(c(9,8,7,6,5,4,3,2,1), nrow = 3, ncol = 3)

print("Matrix A: ")
print(A)

print("Matrix B: ")
print(B)

#Transpose of the matrix
transpose_A = t(A)
transpose_B = t(B)

print("Transpose of Matrix A: ")
print(transpose_A)

print("Transpose of Matrix B: ")
print(transpose_B)

#Addition of two Matrix
C = A+B
print("Addition of Matrix A and B: ")
print(C)

#Subtraction of two matrix
print("Subtraction of Matrix A and B: ")
print(C)

#Multiplication of two matrix
C = A%*%B
print("Matrix Multiplication of A and B: ")
print(C)