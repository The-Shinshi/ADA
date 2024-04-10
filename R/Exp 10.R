data(mtcars)

my_dataframe = mtcars[,c("mpg", "cyl", "disp" , "hp" , "drat" , "wt" , "qsec" , "vs", "am" , "gear" , "carb")]

print(my_dataframe)

num_observations = nrow(mtcars)
num_variables = ncol(mtcars)

cat("To tal number of observations: " , num_observations , "\n" )
cat("Total number of variables : ", num_variables, "\n")

car_max_hp = mtcars[which.max(mtcars$hp) ,]

car_min_hp = mtcars[which.min(mtcars$hp),]

print("Car with the largest horsepower : ")
print(car_max_hp)
print("Car with the least horsepower : ")
print(car_min_hp)

par(mfrow = c(4 , 3) , mar = c(3 , 3 , 1 , 1))
for( i in 1 : ncol (mtcars)) {
  hist(mtcars[ ,i], main = names(mtcars) [ i ] , xlab = "", col = "skyblue") 
  lines(density(mtcars[ , i]) , col = "red" )}

library(e1071)
skew = sapply(mtcars , skewness)
cat( "Skewness of variables : \ n" )
print(skew)

hp_3_cyl = mtcars$hp[mtcars$cyl == 3]
hp_4_cyl = mtcars$hp[mtcars$cyl == 4]

#calculate the avg diff
avg_diff = mean(hp_3_cyl - hp_4_cyl)
#calculate the std deviation 
std_dev_diff = sd(hp_3_cyl - hp_4_cyl)

#print result
print(paste("Average differance in hp :" , round(avg_diff,2)))
print(paste("standard deviation of the differance : ", round(std_dev_diff,2)))

cor_matrix = cor(mtcars)

#find the pair with highest correlation

max_corr = max(cor_matrix[upper.tri(cor_matrix,diag = FALSE)])

indices = which(cor_matrix == max_corr , arr.ind = TRUE)

#get the variable name for theb pair
variable1 = rownames(cor_matrix)[indices[1,1]]
variable2 = colnames(cor_matrix)[indices[1,2]]

#print result
print(paste("pair with the highest pearson correaltion :",variable1, "and", variable2))
print(paste("highest pearson correaltion :", round(max_corr,2)))