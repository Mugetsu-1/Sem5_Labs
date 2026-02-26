# Multiplicative Inverse using Extended Euclidean Algorithm
# Finds x such that a*x ≡ 1 (mod m)

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    gcd, x1, y1 = extended_gcd(b, a % b)
    return gcd, y1, x1 - (a // b) * y1

def multiplicative_inverse(a, m):
    gcd, x, _ = extended_gcd(a % m, m)
    if gcd != 1:
        return None  # Inverse doesn't exist
    return x % m

m = int(input("Enter modulus m: "))
a = int(input("Enter number a: "))

inv = multiplicative_inverse(a, m)
if inv is None:
    print(f"\nNo multiplicative inverse exists (gcd({a},{m}) ≠ 1)")
else:
    print(f"\nMultiplicative Inverse of {a} mod {m} = {inv}")
    print(f"Verification: ({a} * {inv}) mod {m} = {(a * inv) % m}")
