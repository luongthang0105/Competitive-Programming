from collections import deque
from fractions import Fraction

s = input()
n = len(s)
leftGreaterElem = [-1] * n
rightGreaterElem = [n] * n

stack = []
for i in range(n):
    if len(stack) == 0:
        stack.append((s[i], i))
    else:
        while stack and stack[-1][0] <= s[i]:
            stack.pop()

        if stack:
            leftGreaterElem[i] = stack[-1][1]
        stack.append((s[i], i))
stack = []
for i in range(n - 1, -1, -1):
    if len(stack) == 0:
        stack.append((s[i], i))
    else:
        while stack and stack[-1][0] < s[i]:
            stack.pop()
        if stack:
            rightGreaterElem[i] = stack[-1][1]
        stack.append((s[i], i))

# print(leftGreaterElem)
# print(rightGreaterElem)

summ = 0
for i in range(n):
    numAvaiLeft = i - leftGreaterElem[i]
    numAvaiRight = rightGreaterElem[i] - i
    summ += numAvaiLeft * numAvaiRight * int(s[i])

numerator = summ 
denom = (n + 1) * n // 2

if numerator % denom == 0:
    print(numerator // denom)
else:
    wholePart = numerator // denom
    if wholePart > 0:
        fraction = Fraction(numerator % denom, denom)
        print(f"{wholePart} {fraction.numerator}/{fraction.denominator}")
    else:
        fraction = Fraction(numerator, denom)
        print(f"{fraction.numerator}/{fraction.denominator}")
        
