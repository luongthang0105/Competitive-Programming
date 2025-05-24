password = input()

def getCapslock(password: str):
    capslockVer = [''] * len(password)
    for i, c in enumerate(password):
        if c.isalpha():
            capslockVer[i] = c.lower() if c.isupper() else c.upper()
        else:
            capslockVer[i] = c
    return ''.join(capslockVer)
capslockVer = getCapslock(password)

LSShift = {
    '`':'1',
    '1':'2',
    '2':'3',
    '3':'4',
    '4':'5',
    '5':'6',
    '6':'7',
    '~': '!',
    '!': "@",
    '@': "#",
    "#": "$",
    "$": "%",
    "%": "^",
    "^": "&",
    'q': 'w',
    'w': 'e',
    'e': 'r',
    'r': 't',
    't': 'y',
    'a':'s', 
    's':'d', 
    'd':'f', 
    'f':'g',
    'g':'h',
    'z':'x', 
    'x':'c', 
    'c':'v',
    'v':'b',
    'b':'n'
}

RSShift = {
    '7':'6',
    '8':'7',
    '9':'8',
    '0':'9',
    '-':'0',
    '=':'-',
    'y':'t',
    'u':'y',
    'i':'u',
    'o':'i',
    'p':'o',
    '[':'p',
    ']':'[',
    '\\':']',
    'h':'g',
    'j':'h',
    'k':'j',
    'l':'k',
    ';':'l',
    '\'':';',
    'n':'b',
    'm':'n',
    ',':'m',
    '.':',',
    '/':'.',
    '&':'^',
    '*':'&',
    '(':'*',
    ')':'(',
    '_':')',
    '+':'_',
    '{':'P',
    '}':'{',
    '|':'}',
    ':':'L',
    '"':':',
    '<':'M',
    '>':'<',
    '?':'>',
}

def makeShift(password: str, shifter:dict[str], isCapslock = False):
    LS = [''] * len(password)
    for i, c in enumerate(password):
        if c.lower() in shifter:
            if c.isalpha():
                if c.isupper():
                    LS[i] = shifter[c.lower()].upper()
                else:
                    LS[i] = shifter[c]
            elif c in ['{', ':', '<'] and isCapslock:
                # convertes to upper, then with capslock, this will be lower
                LS[i] = shifter[c].lower()
            elif c in ['[', ';', ','] and isCapslock:
                # converts to lower, then with capslock, this will be upper
                LS[i] = shifter[c].upper()
            else:
                LS[i] = shifter[c]
        else:
            LS[i] = c
    return ''.join(LS)

LS = makeShift(password, LSShift)
CLLS = makeShift(capslockVer, LSShift, True)
RS = makeShift(password, RSShift)
CLRS = makeShift(capslockVer, RSShift, True)

# print(LS)
# print(CLLS)
# print(RS)
# print(CLRS)
def missOne(base, other):
    if len(base) - len(other) != 1:
        return False
    if base[1:] == other:
        return True
    if base[:-1] == other:
        return True
    
    baseIndex = 0
    otherIndex = 0
    while baseIndex < len(base) and otherIndex < len(other) and base[baseIndex] == other[otherIndex]:
        baseIndex += 1
        otherIndex += 1
    baseIndex += 1
    while baseIndex < len(base) and base[baseIndex] == other[otherIndex]:
        baseIndex += 1
        otherIndex += 1
    
    return baseIndex == len(base) and otherIndex == len(other)
staticVerif = [password, capslockVer, LS, CLLS, RS, CLRS]
# print(staticVerif)
t = int(input())
for _ in range(t):
    s = input()
    if s in staticVerif:
        print("YES")
    elif missOne(password, s) or missOne(capslockVer, s):
        print("YES")
    elif missOne(s, password) or missOne(s, capslockVer):
        print("YES")
    else:
        print("NO")