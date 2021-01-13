from cs50 import get_int

rows=get_int ('Number of rows: ')

while rows <= 0 or rows > 8:
    rows = get_int ('Number of rows: ')

for i in range(rows):
    num = i + 1
    spaces = rows - num
    for f in range(spaces):
        print(" ", end = "")
    for j in range(num):
        print("#", end = "")
    print("")

