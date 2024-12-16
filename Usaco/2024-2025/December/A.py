
def find_p(n):
    p = 1
    while pow(10, p) < n:
        p += 1
    return p

def round(n, p):
    s = list(str(n))
    if int(s[-p]) >= 5:
        s = list(str(n + pow(10, p)))
    for i in range(len(s) - p, len(s)):
        s[i] = '0'
    return int(''.join(s))
    

def original_way(n, p):
    return round(n, p)

def chained_way(n, p):
    for i in range(1, p + 1):
        n = round(n, i)
        # print(n)
    return n

# print(chained_way(15, 2))
t = int(input())

while t > 0:
    t -= 1

    n = int(input())
    s = str(n)
    p = find_p(n)
    if p == 1:
        print(0)
        continue 
    elif p == 2:
        if n > 49: print(5)
        elif n < 45: print(0)
        else: print(n - 45 + 1)
        continue

    count = 0
    addon = '5'
    for i in range(1, p-1):
        count += int(addon)
        addon += '5'
    
    minPossible = int('4' * (p - 1) + '5')
    maxPossible = int('4' + '9' * (p - 1))
    if minPossible <= n <= maxPossible: count += n - minPossible + 1 
    elif n > maxPossible: count += maxPossible - minPossible + 1
    # count = 0
    # for i in range(2, n + 1):
    #     p = find_p(i)

    #     original = original_way(i, p)
    #     chained = chained_way(i, p)

    #     if original != chained:
    #         print(i)
    #         count += 1

    print(count)