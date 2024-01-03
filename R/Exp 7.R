#Creating DataFrame
itemCode = c(1001:1005)
itemCategory = c("Electronics", "Desktop Supplies", "Office Supplies", "USB", "CD Drive")
itemPrice = c(700, 300, 350, 400, 800)
items_df = data.frame(itemCode, itemCategory, itemPrice)
print("Data Frame with Items Information : ")
print(items_df)
print(summary(items_df$itemPrice))

#Filtering items with price greater than 350
high_priced_items = subset(items_df, itemPrice > 350)
print("Items with Price greater than 400: ")
print(high_priced_items)

#Subset the dataframe and display only the items where the category is "Office Supplies" and "Desktop Supplies".
filtered_items = subset(items_df, itemCategory %in% c("Office Supplies", "Desktop Supplies"))
print("Items with 'Office Supplies' or 'Desktop Supplies' category: ")
print(filtered_items)

#Create another dataframe called "item-details" with three different fields itemCode, ItemQtyonHand and ItemRecorderLvl and merge the two frame.
itemCode = c(1001, 1002, 1003, 1004, 1005)
ItemQtyonHand = c(20, 15, 30, 10, 25)
ItemReorderLvl = c(5, 10, 8, 3, 7)
item_details = data.frame(itemCode, ItemQtyonHand, ItemReorderLvl)
print("Data Frame 'item-details': ")
print(item_details)
merged_data = merge(items_df, item_details, by= "itemCode")
print("Merged Data Frame: ")
print(merged_data)