from math import gcd


class HillCipher:
    MOD = 26

    def __init__(self, key_matrix):
        self.key = [list(map(int, row)) for row in key_matrix]
        self.n = len(self.key)
        if not self.key or any(len(row) != self.n for row in self.key):
            raise ValueError("Key matrix must be square")
        if gcd(self._det(self.key) % self.MOD, self.MOD) != 1:
            raise ValueError("Key matrix is not invertible mod 26")

    def _det(self, matrix):
        if len(matrix) == 1:
            return matrix[0][0]
        if len(matrix) == 2:
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
        total = 0
        for c, value in enumerate(matrix[0]):
            minor = [row[:c] + row[c + 1 :] for row in matrix[1:]]
            total += ((-1) ** c) * value * self._det(minor)
        return total

    def _inverse_key(self):
        det_inv = pow(self._det(self.key) % self.MOD, -1, self.MOD)
        cofactors = [
            [
                ((-1) ** (r + c))
                * self._det([row[:c] + row[c + 1 :] for i, row in enumerate(self.key) if i != r])
                for c in range(self.n)
            ]
            for r in range(self.n)
        ]
        adjugate = zip(*cofactors)
        return [[(det_inv * value) % self.MOD for value in row] for row in adjugate]

    @staticmethod
    def _clean(text):
        return "".join(ch for ch in text.upper() if ch.isalpha())

    @staticmethod
    def _to_vector(block):
        return [ord(ch) - 65 for ch in block]

    @staticmethod
    def _to_text(vector):
        return "".join(chr(value % 26 + 65) for value in vector)

    def _multiply(self, matrix, vector):
        return [sum(matrix[r][c] * vector[c] for c in range(self.n)) % self.MOD for r in range(self.n)]

    def _transform(self, text, matrix, pad=False):
        text = self._clean(text)
        if pad:
            text += "X" * (-len(text) % self.n)
        elif len(text) % self.n:
            raise ValueError("Ciphertext length must be a multiple of key size")

        return "".join(
            self._to_text(self._multiply(matrix, self._to_vector(text[i : i + self.n])))
            for i in range(0, len(text), self.n)
        )

    def encrypt(self, plaintext):
        return self._transform(plaintext, self.key, pad=True)

    def decrypt(self, ciphertext):
        return self._transform(ciphertext, self._inverse_key())


if __name__ == "__main__":
    examples = [
        ([[3, 3], [2, 5]], "EllOOo"),
        ([[6, 24, 1], [13, 16, 10], [20, 17, 15]], "ACHS"),
    ]

    for key, plaintext in examples:
        cipher = HillCipher(key)
        encrypted = cipher.encrypt(plaintext)
        print("Key Matrix:", key)
        print("Plaintext :", plaintext)
        print("Ciphertext:", encrypted)
        print("Decrypted :", cipher.decrypt(encrypted))
        print()
