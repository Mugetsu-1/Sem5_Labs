from math import gcd

class HillCipher:
    def __init__(self, key_matrix):
        self.key_matrix = [list(map(int, row)) for row in key_matrix]
        self.n = len(self.key_matrix)

        if any(len(row) != self.n for row in self.key_matrix):
            raise ValueError("Key matrix must be square")
        if gcd(self.det(self.key_matrix) % 26, 26) != 1:
            raise ValueError("Key matrix is not invertible mod 26")

    @staticmethod
    def det(matrix):
        if len(matrix) == 1:
            return matrix[0][0]
        if len(matrix) == 2:
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
        return sum(
            (-1) ** c * matrix[0][c] * HillCipher.det([row[:c] + row[c + 1:] for row in matrix[1:]])
            for c in range(len(matrix))
        )

    @staticmethod
    def mod_inverse(a, m):
        return next((x for x in range(1, m) if (a * x) % m == 1), None)

    def minor(self, matrix, row, col):
        return [r[:col] + r[col + 1:] for i, r in enumerate(matrix) if i != row]

    def matrix_mod_inv(self, matrix, modulus):
        det = self.det(matrix)
        det_inv = self.mod_inverse(det % modulus, modulus)
        if det_inv is None:
            raise ValueError("Key matrix is not invertible mod 26")

        cofactors = [
            [((-1) ** (r + c) * self.det(self.minor(matrix, r, c))) for c in range(self.n)]
            for r in range(self.n)
        ]
        adjugate = [list(row) for row in zip(*cofactors)]
        return [[(det_inv * value) % modulus for value in row] for row in adjugate]

    def prepare_text(self, text):
        return ''.join(c for c in text.upper() if c.isalpha())

    def text_to_vector(self, text):
        return [ord(c) - 65 for c in text]

    def vector_to_text(self, vector):
        return ''.join(chr(int(v) % 26 + 65) for v in vector)

    def multiply(self, matrix, vector, modulus):
        return [sum(matrix[r][c] * vector[c] for c in range(self.n)) % modulus for r in range(self.n)]

    def encrypt(self, plaintext, show_steps=False):
        plaintext = self.prepare_text(plaintext)

        while len(plaintext) % self.n != 0:
            plaintext += 'X'

        if show_steps:
            print("\nKey Matrix:")
            print(self.key_matrix)

        ciphertext = []
        for i in range(0, len(plaintext), self.n):
            block = plaintext[i:i + self.n]
            vector = self.text_to_vector(block)
            encrypted_vector = self.multiply(self.key_matrix, vector, 26)

            if show_steps:
                print("\nPlaintext block:", block)
                print("Plaintext vector:", vector)
                print("Encrypted vector:", encrypted_vector)

            ciphertext.append(self.vector_to_text(encrypted_vector))

        return ''.join(ciphertext)

    def decrypt(self, ciphertext):
        ciphertext = self.prepare_text(ciphertext)
        key_inv = self.matrix_mod_inv(self.key_matrix, 26)

        plaintext = []
        for i in range(0, len(ciphertext), self.n):
            block = ciphertext[i:i + self.n]
            vector = self.text_to_vector(block)
            decrypted_vector = self.multiply(key_inv, vector, 26)
            plaintext.append(self.vector_to_text(decrypted_vector))

        return ''.join(plaintext)


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
