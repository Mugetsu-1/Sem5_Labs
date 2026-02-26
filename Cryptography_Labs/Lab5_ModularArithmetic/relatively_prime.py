# Relatively Prime: two numbers are relatively prime if gcd(a, b) = 1

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

a = int(input("Enter first number a: "))
b = int(input("Enter second number b: "))

g = gcd(a, b)
print(f"\ngcd({a}, {b}) = {g}")
if g == 1:
    print(f"{a} and {b} are RELATIVELY PRIME (co-prime)")
else:
    print(f"{a} and {b} are NOT relatively prime")
