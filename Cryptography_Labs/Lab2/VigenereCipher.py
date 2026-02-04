import numpy as np
import string


lowerCase = list(string.ascii_lowercase)
upperCase = list(string.ascii_uppercase)

def extend_key(key, length):
    """Extend key to match the required length."""
    repeats = int(np.ceil(length / len(key)))
    return (key * repeats)[:length]

def encryptmessage(plainText, key):
    cipherText = ''
    key = extend_key(key, len(plainText))
    count = 0
    
    for letter in plainText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index + shifter) % 26
            cipherText += lowerCase[shiftedIndex]
            count += 1

        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index + shifter) % 26
            cipherText += upperCase[shiftedIndex]
            count += 1

        else:
            cipherText += letter
            count += 1
    return cipherText

def decryptmessage(cipherText, key):
    plainText = ''
    key = extend_key(key, len(cipherText))
    count = 0
    
    for letter in cipherText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index - shifter) % 26
            plainText += lowerCase[shiftedIndex]
            count += 1

        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count])
            shiftedIndex = (index - shifter) % 26
            plainText += upperCase[shiftedIndex]
            count += 1

        else:
            plainText += letter
            count += 1
    return plainText


message = input('Enter your Message: ')
key = 'achs'
cipherText = encryptmessage(message, key)
print(f'Your encrypted Message: {cipherText}')

key2 = input('Please enter the secret key to decrypt the message: ')
plainText = decryptmessage(cipherText, key2)
print(f"Your hidden message is: {plainText}")