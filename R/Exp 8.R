data(airquality)
hist(airquality$Ozone,  main = "Histogram of Ozone Levels", xlab = "Ozone (ppb)", col = "lightblue", border = "black")

# Histogram for Ozone Levels
hist(airquality$Ozone , col = "lightgreen", main = "" , xlab = "", ylab = "Frequency")

#Change Axis limits of a Histogram
hist(airquality$Ozone , col = "lightcoral", main = "Histogram of Ozone Levels", xlab = "Ozone Levels" , xlim = c(0,150), ylim = c(0,40))

#Add Density curve to the histogram
cleaned_data = na.omit(airquality$Ozone)
hist(cleaned_data, col = "lightblue" , main = "Histogram of Ozone",xlab = "Ozone Levels", ylab = "Frequency")
lines(density(cleaned_data), col = "red")




# -------------------------------------------------------VIVA -------------------------------------------------------------------------------------
data(airquality)
hist(airquality$Ozone,  main = "Histogram of Ozone", col = "red", border = "black")
