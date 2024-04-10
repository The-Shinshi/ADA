# Provided data
Years_Exp <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
Salary <- c(40000, 45000, 50000, 55000, 60000, 65000, 70000, 75000, 80000, 85000)

# Create a data frame
salary_data <- data.frame(Years_Exp, Salary)

# Fit the linear regression model
model <- lm(Salary ~ Years_Exp, data = salary_data)

# Plot the scatter plot
plot(salary_data$Years_Exp, salary_data$Salary,
     xlab = "Years of Experience", ylab = "Salary",
     main = " Years of Experience vs. Salary")

# Add the best fit line
abline(model, col = "blue", lwd = 2)

# Calculate predicted salaries
predicted_salaries <- predict(model, newdata = salary_data)

# Add predicted salaries to the data frame
salary_data$Predicted_Salary <- predicted_salaries

# Plot Actual vs. Predicted Salaries
plot(salary_data$Salary, salary_data$Predicted_Salary,
     xlab = "Actual Salary", ylab = "Predicted Salary",
     main = "Actual vs. Predicted Salaries")

# Add a 45-degree reference line
abline(a = 0, b = 1, col = "red", lwd = 2)

# Save the data as a CSV file
write.csv(salary_data, file = "salary_data_with_predictions.csv", row.names = FALSE)

# Create a vector of random numbers
data <- rnorm(500)
# Create a boxplot
boxplot(data, main = "Boxplot", ylab = "Values")

# Install and load the lattice package
install.packages("lattice")
library(lattice)
# Create a box-whisker plot
bwplot(rnorm(500), main = "Box-Whisker Plot", ylab = "Values")

# Install and load the ggplot2 package
install.packages("ggplot2")
library(ggplot2)
# Create a scatter plot
ggplot(mtcars, aes(x = mpg, y = disp)) + geom_point()
