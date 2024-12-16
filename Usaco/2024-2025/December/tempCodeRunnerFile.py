

while t > 0:
    t -= 1

    n = int(input())
    count = 0
    for i in range(2, n + 1):
        p = find_p(i)

        original = original_way(i, p)
        chained = chained_way(i, p)

        if original != chained:
            print(i, "original: ", original, "chained:", chained)
            count += 1

    print(count)