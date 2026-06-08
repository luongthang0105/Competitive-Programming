from collections import defaultdict
pen = {
    "GDX": 5,
    "SNK":15,
    "PRV":25,
    "TWO":20,
    "LNO":15,
    "LRB":10
}

n = int(input())
scores = defaultdict(int)

while True:
    line = input()
    if (line == "END"): break

    name, code = line.split()
    scores[name] += pen[code]

print(f"Week {n}")
print("Students for detention:")
cnt = 0
for name, score in scores.items():
    if 30 < score <= 50:
        print(name, end= ' ') 
        cnt += 1
if (cnt == 0):
    print("None")


print()
print("Parental meeting for:")
cnt = 0
for name, score in scores.items():
    if score > 50:
        print(name, end= ' ') 
        cnt += 1
if (cnt == 0):
    print("None")

