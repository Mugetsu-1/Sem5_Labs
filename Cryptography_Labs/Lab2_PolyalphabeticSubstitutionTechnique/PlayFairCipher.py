def generateMatrix(key):
    key = key.upper().replace("J", "I")
    keyMatrix = []
    used = set()

    for char in key + "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if char.isalpha() and char not in used:
            keyMatrix.append(char)
            used.add(char)

    return [keyMatrix[i:i + 5] for i in range(0, 25, 5)]

def findIndex(matrix, letter):
    return next((r, c) for r, row in enumerate(matrix) for c, element in enumerate(row) if element == letter)

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

def transform(digraphs, matrix, step):
    result = []
    for a, b in digraphs:
        r1, c1 = findIndex(matrix, a)
        r2, c2 = findIndex(matrix, b)

        if r1 == r2:
            result.append(matrix[r1][(c1 + step) % 5] + matrix[r2][(c2 + step) % 5])
        elif c1 == c2:
            result.append(matrix[(r1 + step) % 5][c1] + matrix[(r2 + step) % 5][c2])
        else:
            result.append(matrix[r1][c2] + matrix[r2][c1])

    return ''.join(result)

def encryptMessage(message, key):
    return transform(preprocessMessage(message), generateMatrix(key), 1)

def decryptMessage(cipherText, key):
    return transform([cipherText[i:i+2] for i in range(0, len(cipherText), 2)], generateMatrix(key), -1)


key = input("Enter secret key: ")
message = input("Enter message to encrypt: ")

cipher = encryptMessage(message, key)
print("Encrypted Text:", cipher)

decrypted = decryptMessage(cipher, key)
print("Decrypted Text:", decrypted)
