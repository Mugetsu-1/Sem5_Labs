def shift(text, key):
    result = []
    for char in text:
        if char.isupper():
            base = 65
        elif char.islower():
            base = 97
        else:
            result.append(char)
            continue
        result.append(chr((ord(char) - base + key) % 26 + base))
    return ''.join(result)

def caesar_encrypt(message, key):
    return shift(message, key)

def caesar_decrypt(encrypted_message, key):
    return shift(encrypted_message, -key)


message = "Saugat Bikram Thapa"
key = 4

encrypted = caesar_encrypt(message, key)
print(f"Original Message: {message}")
print(f"Encrypted Message: {encrypted}")

decrypted = caesar_decrypt(encrypted, key)
print(f"Decrypted Message: {decrypted}")