SBOX = [
    [14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7],
    [0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8],
    [4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0],
    [15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13]
]

def text_to_bin(text):
    return ''.join(format(ord(c),'08b') for c in text)

def bin_to_text(binary):
    chars = [binary[i:i+8] for i in range(0,len(binary),8)]
    return ''.join(chr(int(b,2)) for b in chars)

def xor(a,b):
    return ''.join('0' if a[i]==b[i] else '1' for i in range(len(a)))

def sbox(bits6):
    row = int(bits6[0]+bits6[5],2)
    col = int(bits6[1:5],2)
    return format(SBOX[row][col],'04b')

def generate_key(key):
    key = key[1:] + key[0]
    return key[:6]

def des_round(block,key):
    L = block[:4]
    R = block[4:]

    round_key = generate_key(key)

    expanded = R + R[:2]
    x = xor(expanded,round_key)
    s = sbox(x)
    newR = xor(L,s)

    return R + newR

message = "HELLO"
key = "10101011"

binary = text_to_bin(message)

print("Original Text :",message)
print("Binary        :",binary)

block = binary[:8]
cipher_block = des_round(block,key)

cipher_binary = cipher_block + binary[8:]
print("Encrypted Binary:",cipher_binary)

decrypted_text = bin_to_text(cipher_binary)
print("Decrypted Text :",decrypted_text)
