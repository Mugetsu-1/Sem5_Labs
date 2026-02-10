S_BOX = [
    [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
    [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
    [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
    [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13],
]

def sbox_substitute(bits_6):
    row = (bits_6[0] << 1) | bits_6[5]
    col = (bits_6[1] << 3) | (bits_6[2] << 2) | (bits_6[3] << 1) | bits_6[4]
    val = S_BOX[row % 4][col]
    return [(val >> (3 - i)) & 1 for i in range(4)]

def to_bits(byte_val, n=8):
    return [(byte_val >> (n - 1 - i)) & 1 for i in range(n)]

def from_bits(bits):
    result = 0
    for b in bits:
        result = (result << 1) | b
    return result

def generate_keys(key_int, num_keys=16):
    key_bits = to_bits(key_int, 64)
    keys = []
    C = key_bits[:28]
    D = key_bits[28:56]
    shifts = [1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1]
    for s in shifts[:num_keys]:
        C = C[s:] + C[:s]
        D = D[s:] + D[:s]
        subkey = (C + D)[:48]
        keys.append(subkey)
    return keys

def feistel(half_bits, subkey):
    expanded = [half_bits[i % 8] for i in range(len(subkey))]
    mixed = [expanded[i] ^ subkey[i] for i in range(len(subkey))]
    output = []
    for i in range(0, len(mixed), 6):
        chunk = mixed[i:i+6]
        if len(chunk) == 6:
            output.extend(sbox_substitute(chunk))
    return output[:len(half_bits)]

def des_encrypt_block(block_bits, keys):
    L = block_bits[:32]
    R = block_bits[32:]
    for key in keys:
        new_R = [L[i] ^ feistel(R, key)[i] for i in range(32)]
        L = R
        R = new_R
    return R + L

def des_decrypt_block(block_bits, keys):
    return des_encrypt_block(block_bits, list(reversed(keys)))

def process_bytes(data_bytes, key_int, mode='encrypt'):
    keys = generate_keys(key_int)
    padded = data_bytes + b'\x00' * (8 - len(data_bytes) % 8) if len(data_bytes) % 8 != 0 else data_bytes
    result_bits = []
    for i in range(0, len(padded), 8):
        block = padded[i:i+8]
        block_bits = []
        for byte in block:
            block_bits.extend(to_bits(byte))
        if mode == 'encrypt':
            processed = des_encrypt_block(block_bits, keys)
        else:
            processed = des_decrypt_block(block_bits, keys)
        result_bits.extend(processed)
    result_bytes = bytearray()
    for i in range(0, len(result_bits), 8):
        result_bytes.append(from_bits(result_bits[i:i+8]))
    return bytes(result_bytes)

MESSAGE = "HelloDES!"
KEY = 0x133457799BBCDFF1

print(f"Original Message : {MESSAGE}")
print(f"Key              : {hex(KEY)}")

encrypted = process_bytes(MESSAGE.encode('utf-8'), KEY, mode='encrypt')
print(f"Encrypted (hex)  : {encrypted.hex()}")

decrypted = process_bytes(encrypted, KEY, mode='decrypt').rstrip(b'\x00').decode('utf-8')
print(f"Decrypted Message: {decrypted}")