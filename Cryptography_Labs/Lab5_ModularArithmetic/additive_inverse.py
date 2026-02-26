# Additive Inverse: a + (-a) ≡ 0 (mod m)

def additive_inverse(a, m):
    return (-a) % m

m = int(input("Enter modulus m: "))
a = int(input("Enter number a: "))

inv = additive_inverse(a, m)
print(f"\nAdditive Inverse of {a} mod {m} = {inv}")
print(f"Verification: ({a} + {inv}) mod {m} = {(a + inv) % m}")
