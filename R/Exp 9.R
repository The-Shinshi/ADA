#Create a data frame for employee details
employee_data = data.frame(
  id = c( 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 ) ,
  name = c( "John" , "Jane" , "Bob" , "Alice" , "Charlie" , "David" , "Emily" , "Frank" , "Grace" , "Henry" , "Ivy" , "Jack" , "Karen" , "Liam" , "Mia" , "Noah" , "Olivia" , "Peter" , "Quinn" , "Rachel" ),
  salary = c(25000 , 30000 , 35000 , 40000 , 45000 , 50000 , 55000 , 60000 , 65000 , 70000 , 75000 , 80000 , 85000 , 90000 , 95000 , 100000 , 105000 , 110000 , 115000 , 120000 ) ,
  start_date = as.Date(c("2021-01-01" , "2021-02-01" , "2021-03-01" , "2021-04-01" , "2021-05-01" , "2021-06-01" , "2021-07-01" , "2021-08-01" , "2021-09-01" , "2021-10-01" , "2021-11-01" , "2021-12-01" , "2022-01-01" , "2022-02-01" , "2022-03-01" , "2022-04-01" , "2022-05-01" , "2022-06-01" , "2022-07-01" , "2022-08-01" )) ,
  dept = c( "IT" , "HR" , "IT" , "Finance" , "IT" , "HR" , "IT" , "Finance" , "IT" , "HR" , "IT" , "Finance" , "IT" , "HR" , "IT" , "Finance" , "IT" , "HR" , "IT" , "Finance" ))

# Save the data frame to a CSV f i l e
write.csv(employee_data , file = "input.csv" , row.names = FALSE)

# Read the CSV f i l e i n t o R
employee_data = read.csv("input.csv")

# a) Find the number of rows and columns
num_rows = nrow (employee_data)
num_cols = ncol(employee_data)
cat("Number of rows : " , num_rows , "\n" )
cat("Number of columns : " , num_cols , "\n" )

# Find the maximum salary
max_salary = max(employee_data$salary)
cat("Maximum salary : " , max_salary, "\n")

#Retrieve the details of the employee with the maximum salary
employee_max_salary = employee_data[employee_data$salary == max_salary,]
cat( "Employee with maximum salary: \n" )
print(employee_max_salary)

#Retrieve all the employees working in the IT department
it_department_employees = subset(employee_data , dept == "IT")
cat("Employees working i n the IT Department : \n")
print(it_department_employees)

#Retrieve the employees in IT Department whose salary is greater than 20000
employees_IT_high_salary = subset(it_department_employees, salary > 20000 )
cat("Employees in the IT Department with salary > 20000:\n" )
print(employees_IT_high_salary)

# Write these employees to a new CSV file
write.csv(employees_IT_high_salary , "output.csv" , row.names = FALSE)





#----------------------------------------------VIVA----------------------------------------------
employees_high_10000 = subset(employee_data, salary > 10000 )
cat("Employees with salary > 10000:\n" )
print(employees_high_10000)
