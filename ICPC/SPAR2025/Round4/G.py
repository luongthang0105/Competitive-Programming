from collections import defaultdict


p, t = map(int, input().split(" "))
teamNames = []
for _ in range(t):
    teamName = input()
    # contains duplicate
    if len(set(list(teamName))) != len(teamName):
        continue
    
    ok = True
    for c in teamName:
        pos = ord(c) - ord('A') + 1
        # print(c, pos)
        if pos > p:
            ok = False
            break
    if ok: teamNames.append(teamName)

# print(teamNames)
ans = 0
for i in range(1 << len(teamNames)):
    freqCount = defaultdict(int)
    elemCount = 0
    for j in range(len(teamNames)):
        # print(i, bin(1 << j), bin(i & (1 << j)))
        if ((i >> j) & 1) == 1:
            elemCount += 1
            for c in teamNames[j]:
                freqCount[c] += 1
    # print(bin(i), elemCount, freqCount)
    ok = True
    for _, freq in freqCount.items():
        if freq > 1:
            ok = False
            break
    if ok:
        ans = max(ans, elemCount)
print(ans)


