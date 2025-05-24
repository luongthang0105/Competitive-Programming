from collections import defaultdict


p, t = map(int, input().split(" "))
teamNames = []
for _ in range(t):
    teamName = input()
    # contains duplicate
    
    ok = True
    seenChar = set()
    for c in teamName:
        pos = ord(c) - ord('A') + 1
        # print(c, pos)
        if pos > p or c in seenChar:
            ok = False
            break
        seenChar.add(c)
    if ok: teamNames.append(teamName)

# print(teamNames)
ans = 0
for i in range(1 << len(teamNames)):
    freqCount = defaultdict(int)
    elemCount = 0
    ok = True
    for j in range(len(teamNames)):
        # print(i, bin(1 << j), bin(i & (1 << j)))
        if ((i >> j) & 1) == 1:
            elemCount += 1            
            for c in teamNames[j]:
                freqCount[c] += 1
                if freqCount[c] > 1:
                    ok = False
                    break
            if not ok: break
    if ok:
        ans = max(ans, elemCount)
print(ans)


