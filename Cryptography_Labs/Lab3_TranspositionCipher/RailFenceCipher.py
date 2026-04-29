def _pattern(length, key):
    if key == 1:
        return [0] * length
    row, step, rows = 0, 1, []
    for _ in range(length):
        rows.append(row)
        if row == 0:
            step = 1
        elif row == key - 1:
            step = -1
        row += step
    return rows

def encryptRailFence(text, key):
    text = text.replace(" ", "").upper()
    rows = _pattern(len(text), key)
    return ''.join(ch for r in range(key) for i, ch in enumerate(text) if rows[i] == r)

def decryptRailFence(cipher, key):
    rows = _pattern(len(cipher), key)
    counts = [rows.count(i) for i in range(key)]
    rails, start = [], 0
    for count in counts:
        rails.append(iter(cipher[start:start + count]))
        start += count
    return ''.join(next(rails[row]) for row in rows)



message = "ACHS college"
key = 3

encrypted = encryptRailFence(message, key)
decrypted = decryptRailFence(encrypted, key)

print("Plaintext :", message)
print("Key       :", key)
print("Encrypted :", encrypted)
print("Decrypted :", decrypted)
