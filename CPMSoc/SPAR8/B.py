import math
from decimal import *
n = int(input())

costs = 0
for _ in range(n):
    costs += Decimal(input())

total = Decimal(input())

str_cost = list(str(costs))
final_cost = costs
if 1 <= int(str_cost[-1]) <= 4:
    str_cost[-1] = '0'
    final_cost = Decimal(''.join(str_cost))
elif 5 <= int(str_cost[-1]) <= 9: 
    str_cost[-1] = '0'
    final_cost = Decimal(''.join(str_cost)) + Decimal('0.1')

print(f"Total price: ${costs}")
print(f"Rounded price: ${final_cost}")
print(f"Change: ${total - final_cost}")