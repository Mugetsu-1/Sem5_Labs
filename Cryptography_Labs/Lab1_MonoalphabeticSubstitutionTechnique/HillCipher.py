import numpy as np

class HillCipher:
    def __init__(self, key_matrix):
        self.key_matrix = np.array(key_matrix)
        self.n = len(key_matrix)

        det = int(round(np.linalg.det(self.key_matrix)))
        if HillCipher.gcd(det % 26, 26) != 1:
            raise ValueError("Key matrix is not invertible mod 26")

    @staticmethod
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a

    @staticmethod
    def mod_inverse(a, m):
        for x in range(1, m):
            if (a * x) % m == 1:
                return x
        return None

    def matrix_mod_inv(self, matrix, modulus):
        det = int(round(np.linalg.det(matrix)))
        det_inv = HillCipher.mod_inverse(det % modulus, modulus)
        matrix_inv = np.linalg.inv(matrix)
        adjugate = np.round(det * matrix_inv).astype(int)
        return (det_inv * adjugate) % modulus

    def prepare_text(self, text):
        return ''.join(filter(str.isalpha, text)).upper()

    def text_to_vector(self, text):
        return [ord(c) - 65 for c in text]

    def vector_to_text(self, vector):
        return ''.join(chr(int(v) % 26 + 65) for v in vector)

    def encrypt(self, plaintext, show_steps=False):
        plaintext = self.prepare_text(plaintext)

        while len(plaintext) % self.n != 0:
            plaintext += 'X'

        ciphertext = ''

        if show_steps:
            print("\nKey Matrix:")
            print(self.key_matrix)

        for i in range(0, len(plaintext), self.n):
            block = plaintext[i:i + self.n]
            vector = self.text_to_vector(block)

            encrypted_vector = np.dot(self.key_matrix, vector) % 26

            if show_steps:
                print("\nPlaintext block:", block)
                print("Plaintext vector:", vector)
                print("Encrypted vector:", encrypted_vector.tolist())

            ciphertext += self.vector_to_text(encrypted_vector)

        return ciphertext

    def decrypt(self, ciphertext):
        ciphertext = self.prepare_text(ciphertext)
        key_inv = self.matrix_mod_inv(self.key_matrix, 26)

        plaintext = ''

        for i in range(0, len(ciphertext), self.n):
            block = ciphertext[i:i + self.n]
            vector = self.text_to_vector(block)
            decrypted_vector = np.dot(key_inv, vector) % 26
            plaintext += self.vector_to_text(decrypted_vector)

        return plaintext


if __name__ == "__main__":

    print("2 x 2 Hill Cipher")

    key_2x2 = [[3, 3],
               [2, 5]]

    cipher_2x2 = HillCipher(key_2x2)

    plaintext1 = "EllOOo"
    encrypted1 = cipher_2x2.encrypt(plaintext1, show_steps=True)
    decrypted1 = cipher_2x2.decrypt(encrypted1)

    print("\nCiphertext:", encrypted1)
    print("Decrypted :", decrypted1)

    print("\n3 x 3 Hill Cipher")

    key_3x3 = [[6, 24, 1],
               [13, 16, 10],
               [20, 17, 15]]

    cipher_3x3 = HillCipher(key_3x3)

    plaintext2 = "ACHS"
    encrypted2 = cipher_3x3.encrypt(plaintext2, show_steps=True)
    decrypted2 = cipher_3x3.decrypt(encrypted2)

    print("\nCiphertext:", encrypted2)
    print("Decrypted :", decrypted2)
