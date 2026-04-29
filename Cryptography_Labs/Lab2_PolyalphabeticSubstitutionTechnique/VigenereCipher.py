import string

def extend_key(key, length):
    return (key * ((length + len(key) - 1) // len(key)))[:length]

def transform(text, key, step):
    key = extend_key(key.lower(), len(text))
    result = []
    for i, letter in enumerate(text):
        if letter in string.ascii_lowercase:
            result.append(chr((ord(letter) - 97 + step * (ord(key[i]) - 97)) % 26 + 97))
        elif letter in string.ascii_uppercase:
            result.append(chr((ord(letter) - 65 + step * (ord(key[i]) - 97)) % 26 + 65))
        else:
            result.append(letter)
    return ''.join(result)

def encryptmessage(plainText, key):
    return transform(plainText, key, 1)

def decryptmessage(cipherText, key):
    return transform(cipherText, key, -1)


message = input('Enter your Message: ')
key = 'achs'
cipherText = encryptmessage(message, key)
print(f'Your encrypted Message: {cipherText}')

key2 = input('Please enter the secret key to decrypt the message: ')
plainText = decryptmessage(cipherText, key2)
print(f"Your hidden message is: {plainText}")