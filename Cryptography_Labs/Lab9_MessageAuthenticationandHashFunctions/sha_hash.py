import hashlib

def generate_sha(message, algorithm='sha256'):
    return {
        'sha1': hashlib.sha1,
        'sha256': hashlib.sha256,
        'sha512': hashlib.sha512,
    }.get(algorithm, hashlib.sha256)(message.encode()).hexdigest()

if __name__ == "__main__":
    msg = input("Enter message: ")
    print(f"\nMessage: {msg}")
    for name, algo in (('SHA-1', 'sha1'), ('SHA-256', 'sha256'), ('SHA-512', 'sha512')):
        print(f"{name}: {generate_sha(msg, algo)}")
    print("\n--- Hash Lengths ---")
    for name, bits in (('SHA-1', 160), ('SHA-256', 256), ('SHA-512', 512)):
        print(f"{name}: {bits} bits ({bits // 4} hex chars)")
