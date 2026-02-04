import numpy as np

def generateMatrix(key):
    key = key.upper().replace("J", "I")
    keyMatrix = []
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    used = set()

    for char in key:
        if char.isalpha() and char not in used:
            keyMatrix.append(char)
            used.add(char)

    for char in alphabet:
        if char not in used:
            keyMatrix.append(char)

    return np.array(keyMatrix).reshape(5, 5)

def findIndex(matrix, letter):
    for r, row in enumerate(matrix):
        for c, element in enumerate(row):
            if element == letter:
                return r, c
    return None

def preprocessMessage(message):
    message = message.upper().replace("J", "I").replace(" ", "")
    digraphs = []
    i = 0

    while i < len(message):
        a = message[i]
        if i + 1 < len(message):
            b = message[i + 1]
            if a == b:
                digraphs.append([a, 'X'])
                i += 1
            else:
                digraphs.append([a, b])
                i += 2
        else:
            digraphs.append([a, 'X'])
            i += 1

    return digraphs

def encryptMessage(message, key):
    keyMatrix = generateMatrix(key)
    digraphs = preprocessMessage(message)
    cipherText = ''

    for d in digraphs:
        r1, c1 = findIndex(keyMatrix, d[0])
        r2, c2 = findIndex(keyMatrix, d[1])

        if r1 == r2:
            cipherText += keyMatrix[r1][(c1 + 1) % 5]
            cipherText += keyMatrix[r2][(c2 + 1) % 5]
        elif c1 == c2:
            cipherText += keyMatrix[(r1 + 1) % 5][c1]
            cipherText += keyMatrix[(r2 + 1) % 5][c2]
        else:
            cipherText += keyMatrix[r1][c2]
            cipherText += keyMatrix[r2][c1]

    return cipherText

def decryptMessage(cipherText, key):
    keyMatrix = generateMatrix(key)
    plainText = ''

    digraphs = [cipherText[i:i+2] for i in range(0, len(cipherText), 2)]

    for d in digraphs:
        r1, c1 = findIndex(keyMatrix, d[0])
        r2, c2 = findIndex(keyMatrix, d[1])

        if r1 == r2:
            plainText += keyMatrix[r1][(c1 - 1) % 5]
            plainText += keyMatrix[r2][(c2 - 1) % 5]
        elif c1 == c2:
            plainText += keyMatrix[(r1 - 1) % 5][c1]
            plainText += keyMatrix[(r2 - 1) % 5][c2]
        else:
            plainText += keyMatrix[r1][c2]
            plainText += keyMatrix[r2][c1]

    return plainText


key = input("Enter secret key: ")
message = input("Enter message to encrypt: ")

cipher = encryptMessage(message, key)
print("Encrypted Text:", cipher)

decrypted = decryptMessage(cipher, key)
print("Decrypted Text:", decrypted)
