"""RSA Algorithm"""

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def mod_inverse(e, phi):
    for d in range(2, phi):
        if (d * e) % phi == 1:
            return d
    return None

def rsa():
    p = int(input("Enter prime p: "))
    q = int(input("Enter prime q: "))
    
    n = p * q
    phi = (p - 1) * (q - 1)
    
    print(f"n = {n}, φ(n) = {phi}")
    
    # Find e
    e = int(input(f"Enter e (coprime to {phi}): "))
    while gcd(e, phi) != 1:
        e = int(input(f"Invalid! Enter e coprime to {phi}: "))
    
    # Find d
    d = mod_inverse(e, phi)
    
    print(f"\nPublic key: (e={e}, n={n})")
    print(f"Private key: (d={d}, n={n})")
    
    # Encryption
    msg = int(input("\nEnter message (number < n): "))
    cipher = pow(msg, e, n)
    print(f"Encrypted: {cipher}")
    
    # Decryption
    plain = pow(cipher, d, n)
    print(f"Decrypted: {plain}")

if __name__ == "__main__":
    rsa()
