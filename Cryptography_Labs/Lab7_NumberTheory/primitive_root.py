from math import gcd

def totient(n):
    return sum(gcd(i, n) == 1 for i in range(1, n + 1))

def is_primitive_root(g, n):
    phi = totient(n)
    return len({pow(g, i, n) for i in range(1, phi + 1)}) == phi

def find_primitive_roots(n):
    return [g for g in range(2, n) if is_primitive_root(g, n)]

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
