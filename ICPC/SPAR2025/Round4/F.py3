t, key = input().split()

txt = input()

def getRangeToIterate(isLeftToRight):
    return range(len(justAlphabetic)) if isLeftToRight else range(len(justAlphabetic) - 1, -1, -1)

d = [ord(c) - ord('a') + 2 for c in key]
d.append(1)

if t == 'E':
    # remove non alphabetic chars, and convert to lowercase
    justAlphabetic = ''.join([c.lower() for c in txt if c.isalpha()])

    encryptedText = [''] * len(justAlphabetic)
    indexToAssign = 0
    isLeftToRight = True

    # print(d)
    stop = False
    for d_i in d:
        countPos = 0
        rangeToIterate = getRangeToIterate(isLeftToRight)

        for i in rangeToIterate:
            if encryptedText[i] == '':
                countPos += 1
                if countPos % d_i == 0:
                    encryptedText[i] = justAlphabetic[indexToAssign]
                    indexToAssign += 1
                    if indexToAssign == len(justAlphabetic):
                        stop = True
                        break
        if stop: break
        isLeftToRight = not isLeftToRight
     
    print(''.join(encryptedText))
else:
    justAlphabetic = list(txt)

    decrypted = [''] * len(justAlphabetic)
    indexToAssign = 0
    isLeftToRight = True

    # print(d)
    stop = False
    for d_i in d:
        countPos = 0
        rangeToIterate = getRangeToIterate(isLeftToRight)

        for i in rangeToIterate:
            if justAlphabetic[i] != '':
                countPos += 1
                if countPos % d_i == 0:
                    decrypted[indexToAssign] = justAlphabetic[i]
                    justAlphabetic[i] = ''
                    indexToAssign += 1
                    if indexToAssign == len(justAlphabetic):
                        stop = True
                        break
        # print(decrypted)
        if stop: break
        isLeftToRight = not isLeftToRight
     
    print(''.join(decrypted))
