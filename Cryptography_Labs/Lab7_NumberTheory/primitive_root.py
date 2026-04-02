"""Primitive Root"""

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def totient(n):
    count = 0
    for i in range(1, n + 1):
        if gcd(i, n) == 1:
            count += 1
    return count

def is_primitive_root(g, n):
    phi = totient(n)
    powers = set()
    for i in range(1, phi + 1):
        powers.add(pow(g, i, n))
    return len(powers) == phi

def find_primitive_roots(n):
    roots = []
    for g in range(2, n):
        if is_primitive_root(g, n):
            roots.append(g)
    return roots

if __name__ == "__main__":
    n = int(input("Enter n: "))
    roots = find_primitive_roots(n)
    
    if roots:
        print(f"Primitive roots of {n}: {roots}")
        g = roots[0]
        print(f"\nPowers of {g} mod {n}:")
        for i in range(1, n):
            print(f"{g}^{i} mod {n} = {pow(g, i, n)}")
    else:
        print(f"No primitive roots exist for {n}")
