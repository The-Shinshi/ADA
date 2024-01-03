#A

#Numeric data type

#Assign an integer value to y
y = 5
#print the type of variable
print(typeof(y))
#Assign a decimal value to x
x = 5.6
#print the type of variable
print(typeof(x))
#Assign an integer value to y
y = 5
#Is y an integer?
print(is.integer(y))


#Integer data type

#Create an integer value
x = as.integer(5)
#Print the type of x
print(typeof(x))
#Declare an integer by appending an L suffix
y = 5L
#print the type of y
print(typeof(y))


#Logical Data type

x = 4
y = 3
# Comparing two values
z = x > y
print(z)
# Print the type of z
print(typeof(z))


#Complex Data type

#Assign a complex value to x
x = 4 + 3i
# Print the type of x
print(typeof(x))


#Character Data type

#Assign a character value to char
char = "ATME college of Engineering"
# Print the type of char
print(typeof(char))


#B

#i) Arithmetic Operators

#1. Addition Operator
a = 1
b = 4
print(a+b)

#2. Subtraction Operator
a = 6
b = 8.4
print(a-b)

#3. Multiplication Operator
a = 6
b = 8.4
print(a*b)

#4. Division Operator
a = 20
b = 5
print(a/b)

#5. Power Operator
a = 4
b = 3
print(a^b)

#6. Modulo Operator
a = 10
b = 3
print(a%%b)

#ii) Logical Operators

#1. Element-wise Logical AND operator
a = 1.35
b = 5+3i
print(a&b)

#2. Element-wise Logical OR operator
a = 1.35
b = 5+3i
print(a|b)

#3. Not Operator
a = TRUE
print(!a)

#4. Logical AND operator
a = 20
b = 5
print(a&&b)

#5. Logical OR operator
a = 4
b = 0
print(a||b)


#C

#Sequence generation and creation of vectors

# Sequence generation
seq1 = 1:10
seq2 = seq(from = 5, to = 50, by = 5)

#Vector creation
num_vector = c(10,20,30)
char_vector = c("apple", "banana", "cherry")
log_vector = c(TRUE, FALSE, FALSE, TRUE)
mixed_vector = c(1, "Hello", TRUE)

#Print the results
print(seq1)
print(seq2)
print(num_vector)
print(char_vector)
print(log_vector)
print(mixed_vector)


#D

#Sequence generation and creation of vectors
a = matrix(1:6,2,3)
print(a)


#E

# Define vectors
vector1 = c(1,2,3)
vector2 = c(4,5,6)
vector3 = c(7,8,9)

# Create matrix by row binding
matrix_by_row = rbind(vector1, vector2, vector3)

# Create matrix by column binding
matrix_by_column = cbind(vector1, vector2, vector3)

#Print Results
print("Matrix by row Binding:")
print(matrix_by_row)
print("Matrix by column Binding:")
print(matrix_by_column)


#F

#1. Extracting Elements from Vectors

#Define a vector
vector = c("a","b","c","d","e")
print(vector)

#Extract elements
# Extract the first element
element1 = vector[1]
# Extract the second to fourth elements
element2 = vector[2:4]
# Extract all elements except the first
# Extract all elements except the first
element3 = vector[-1]

print(element1)
print(element2)
print(element3)

#2. Extracting Elements from Matrices
# Define a matrix
matrix = matrix(1:9, nrow = 3)
print(matrix)

# Extract elements
#Extract elements from the first row, second column

element4 = matrix[1,2]
print(element4)

#Extract the first row
row1 = matrix[1, ]
print(row1)

#Extract the second column
column2 = matrix[ ,2]
print(column2)

# Extract a sub-matrix
sub_matrix = matrix[1:2, 2:3]
print(sub_matrix)


#3. Extracting Elements from Array
#Define an array
array1 = array(1:12, dim = c(3,2,2))
print(array1)

# Extract the elements from the first row, second column, first depth layer
element5 = array1[1,2,1]
print(element5)

#Extract a sub-array
sub_array = array1[1:2, ,2]
print(array1)