#Step 1: Create Sample Data
monthly_revenue = c(12000, 15000, 13000, 14000, 16000, 17000, 15500, 14500, 13500, 16500, 17500, 18000)
print(monthly_revenue)

monthly_expenses = c(10000, 11000, 9500, 12000, 13000, 14000, 12000, 11000, 10500, 13000, 14000, 15000)
print(monthly_expenses)

#Calculate Monthly Profit
monthly_profit = monthly_revenue - monthly_expenses
print(monthly_profit)

#Define Tax Rate (Tax Rate is 30%)
tax_rate = 0.30

#Calculate tax for each month
monthly_tax = monthly_profit * tax_rate
print(monthly_tax)

#Calculate profit after tax for each month
profit_after_tax = monthly_profit - monthly_tax
print(profit_after_tax)

#Calculate profit margin for each month
profit_margin_percentage = (profit_after_tax/monthly_revenue)*100

#Round profit margin to No Decimal point
profit_margin_rounded = round(profit_margin_percentage, 0)

#Print profit margin percentage for each month in rounded percentage
print("Monthly Profit Margin (%): ")
print(profit_margin_rounded)

#Calculate mean profit after tax for the year
mean_profit_after_tax = mean(profit_after_tax)

#Identify good months
goog_months = profit_after_tax > mean_profit_after_tax

#print good months
print("Good Months (Profit After Tax Greater Than Yearly Average) : ")
print(goog_months)

#Calculate mean profit after tax for the year
mean_profit_after_tax = mean(profit_after_tax)

#Identify bad months
bad_months = profit_after_tax < mean_profit_after_tax

#Print bad months
print("Bad Months(Profit After Tax Less Than Yearly Average) : ")
print(bad_months)

#Find the Best Month (Maximum Profit After Tax)
best_month_index = which.max(profit_after_tax)
best_month_profit = profit_after_tax[best_month_index]

#Print Best Month
print(paste("The Best Month is: ", best_month_index, "with a Profit After Tax of : ", best_month_profit))

##Find the Worst Month (Minimum Profit After Tax)
worst_month_index = which.min(profit_after_tax)
worst_month_profit = profit_after_tax[worst_month_index]

#Print Worst Month
print(paste("The Worst Month is: ", worst_month_index, "with a Profit After Tax of : ", worst_month_profit))

#Sample Data
monthly_revenue = c(12000, 15000, 13000, 14000, 16000, 17000, 15500, 14500, 13500, 16500, 17500, 18000)

monthly_expenses = c(10000, 11000, 9500, 12000, 13000, 14000, 12000, 11000, 10500, 13000, 14000, 15000)

#Create a Data Frame
financial_data = data.frame(Month = 1:12, Revenue = monthly_revenue, Expenses = monthly_expenses)