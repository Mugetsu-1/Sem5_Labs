from math import gcd

def mod_inverse(e, phi):
    return next((d for d in range(2, phi) if (d * e) % phi == 1), None)

def rsa():
    p = int(input("Enter prime p: "))
    q = int(input("Enter prime q: "))
    
    n = p * q
    phi = (p - 1) * (q - 1)
    print(f"n = {n}, φ(n) = {phi}")

    e = int(input(f"Enter e (coprime to {phi}): "))
    while gcd(e, phi) != 1:
        e = int(input(f"Invalid! Enter e coprime to {phi}: "))

    d = mod_inverse(e, phi)

    print(f"\nPublic key: (e={e}, n={n})")
    print(f"Private key: (d={d}, n={n})")

    msg = int(input("\nEnter message (number < n): "))
    cipher = pow(msg, e, n)
    print(f"Encrypted: {cipher}")

    plain = pow(cipher, d, n)
    print(f"Decrypted: {plain}")

if __name__ == "__main__":
    rsa()
