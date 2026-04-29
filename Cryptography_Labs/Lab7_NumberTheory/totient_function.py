from math import gcd

def totient(n):
    return sum(gcd(i, n) == 1 for i in range(1, n + 1))

def totient_formula(n):
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
