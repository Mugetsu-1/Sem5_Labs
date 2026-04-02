"""Diffie-Hellman Key Exchange"""

def diffie_hellman():
    # Public parameters
    p = int(input("Enter prime p: "))
    g = int(input("Enter primitive root g: "))
    
    # Private keys
    a = int(input("Enter Alice's private key: "))
    b = int(input("Enter Bob's private key: "))
    
    # Public keys
    A = pow(g, a, p)  # Alice's public key
    B = pow(g, b, p)  # Bob's public key
    
    print(f"\nAlice's public key A = {g}^{a} mod {p} = {A}")
    print(f"Bob's public key B = {g}^{b} mod {p} = {B}")
    
    # Shared secret
    s_alice = pow(B, a, p)  # Alice computes
    s_bob = pow(A, b, p)    # Bob computes
    
    print(f"\nShared secret (Alice): {B}^{a} mod {p} = {s_alice}")
    print(f"Shared secret (Bob): {A}^{b} mod {p} = {s_bob}")
    
    # Simple encryption using shared key
    msg = int(input("\nEnter message (number): "))
    encrypted = (msg * s_alice) % p
    decrypted = (encrypted * pow(s_alice, -1, p)) % p
    
    print(f"Encrypted: {encrypted}")
    print(f"Decrypted: {decrypted}")

if __name__ == "__main__":
    diffie_hellman()
