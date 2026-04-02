"""ElGamal Cryptographic System"""
import random

def elgamal():
    # Public parameters
    p = int(input("Enter prime p: "))
    g = int(input("Enter generator g: "))
    
    # Private key
    x = int(input("Enter private key x: "))
    
    # Public key
    y = pow(g, x, p)
    print(f"\nPublic key: (p={p}, g={g}, y={y})")
    print(f"Private key: x={x}")
    
    # Encryption
    msg = int(input("\nEnter message (number < p): "))
    k = random.randint(2, p - 2)  # Random k
    
    c1 = pow(g, k, p)
    c2 = (msg * pow(y, k, p)) % p
    
    print(f"Random k = {k}")
    print(f"Ciphertext: (c1={c1}, c2={c2})")
    
    # Decryption
    s = pow(c1, x, p)
    plain = (c2 * pow(s, -1, p)) % p
    
    print(f"Decrypted: {plain}")

if __name__ == "__main__":
    elgamal()
