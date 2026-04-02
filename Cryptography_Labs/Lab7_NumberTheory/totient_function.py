"""Euler's Totient Function"""

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

def totient_formula(n):
    """More efficient using Euler's product formula"""
    result = n
    p = 2
    temp = n
    while p * p <= temp:
        if temp % p == 0:
            while temp % p == 0:
                temp //= p
            result -= result // p
        p += 1
    if temp > 1:
        result -= result // temp
    return result

if __name__ == "__main__":
    num = int(input("Enter a number: "))
    print(f"φ({num}) = {totient(num)}")
    print(f"Coprimes of {num}: {[i for i in range(1, num+1) if gcd(i, num) == 1]}")
