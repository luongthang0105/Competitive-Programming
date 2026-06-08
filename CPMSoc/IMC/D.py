n = int(input())

square = [[" "]*(n+1) for _ in range(n+1)]
# print(square)
row = 1
col = 1
original = n
while n > 0:
    # print(row, col, n)
    # upper
    for i in range(col, col + n):
        square[row][i] = "#"
    # lower
    for i in range(col, col + n):
        square[row + n - 1][i] = "#"
    # left
    for i in range(row, row + n):
        square[i][col] = "#"
    # right
    for i in range(row, row + n):
        square[i][col + n - 1] = "#"
    n -= 4
    row += 2
    col += 2
# print(square[1][1])
for i in range(1, original + 1):
    for j in range(1, original + 1):
        # print(i, j)
        print(square[i][j], end="")
    print("")
