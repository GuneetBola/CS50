from cs50 import get_float

change = get_float("How much change is owed: ")
##making sure the input it positive
while change<0:
    change = get_float("How much change is owed: ")
clear
## changing all change to cents instead of dollars
cents = change * 100
## setting all the coins to zero at first
quarters = 0
dimes = 0
nickels = 0
pennies = 0

##checking each time if there are enough cents for each type of coin
while cents >= 25:
    quarters = quarters + 1
    cents = cents - 25
while cents >= 10:
    dimes = dimes + 1
    cents = cents - 10
while cents >= 5:
    nickels = nickels + 1
    cents= cents - 5
while cents >= 1:
    pennies = pennies + 1
    cents = cents - 1

##adding all the coins together
coins = quarters + dimes + nickels + pennies
##printing the number of coins owed
print(coins)
