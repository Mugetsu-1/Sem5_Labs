def caesar_encrypt(message, key):
    encrypted = ""
    for char in message:
        if char.isupper():
            encrypted += chr((ord(char) - 65 + key) % 26 + 65)
        elif char.islower():
            encrypted += chr((ord(char) - 97 + key) % 26 + 97)
        else:
            encrypted += char
    return encrypted

def caesar_decrypt(encrypted_message, key):
    decrypted = ""
    for char in encrypted_message:
        if char.isupper():
            decrypted += chr((ord(char) - 65 - key) % 26 + 65)
        elif char.islower():
            decrypted += chr((ord(char) - 97 - key) % 26 + 97)
        else:
            decrypted += char
    return decrypted


message = "Saugat Bikram Thapa"
key = 4

encrypted = caesar_encrypt(message, key)
print(f"Original Message: {message}")
print(f"Encrypted Message: {encrypted}")

decrypted = caesar_decrypt(encrypted, key)
print(f"Decrypted Message: {decrypted}")