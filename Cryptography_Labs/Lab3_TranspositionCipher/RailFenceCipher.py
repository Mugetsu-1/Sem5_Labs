def encryptRailFence(text, key):
    text = text.replace(" ", "").upper()
    rail = [['\n' for _ in range(len(text))] for _ in range(key)]

    dir_down = False
    row, col = 0, 0

    for char in text:
        if row == 0 or row == key - 1:
            dir_down = not dir_down

        rail[row][col] = char
        col += 1

        row += 1 if dir_down else -1

    result = ""
    for i in range(key):
        for j in range(len(text)):
            if rail[i][j] != '\n':
                result += rail[i][j]

    return result


def decryptRailFence(cipher, key):
    rail = [['\n' for _ in range(len(cipher))] for _ in range(key)]

    dir_down = None
    row, col = 0, 0

    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == key - 1:
            dir_down = False

        rail[row][col] = '*'
        col += 1
        row += 1 if dir_down else -1

    index = 0
    for i in range(key):
        for j in range(len(cipher)):
            if rail[i][j] == '*' and index < len(cipher):
                rail[i][j] = cipher[index]
                index += 1

    result = ""
    row, col = 0, 0
    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == key - 1:
            dir_down = False

        result += rail[row][col]
        col += 1
        row += 1 if dir_down else -1

    return result



message = "ACHS college"
key = 3

encrypted = encryptRailFence(message, key)
decrypted = decryptRailFence(encrypted, key)

print("Plaintext :", message)
print("Key       :", key)
print("Encrypted :", encrypted)
print("Decrypted :", decrypted)
