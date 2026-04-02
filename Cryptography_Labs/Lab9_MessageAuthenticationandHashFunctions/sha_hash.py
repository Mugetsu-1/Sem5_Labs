"""SHA Hash Generation"""
import hashlib

def generate_sha(message, algorithm='sha256'):
    if algorithm == 'sha1':
        hash_obj = hashlib.sha1(message.encode())
    elif algorithm == 'sha256':
        hash_obj = hashlib.sha256(message.encode())
    elif algorithm == 'sha512':
        hash_obj = hashlib.sha512(message.encode())
    return hash_obj.hexdigest()

if __name__ == "__main__":
    msg = input("Enter message: ")
    
    print(f"\nMessage: {msg}")
    print(f"\nSHA-1:   {generate_sha(msg, 'sha1')}")
    print(f"SHA-256: {generate_sha(msg, 'sha256')}")
    print(f"SHA-512: {generate_sha(msg, 'sha512')}")
    
    print("\n--- Hash Lengths ---")
    print("SHA-1:   160 bits (40 hex chars)")
    print("SHA-256: 256 bits (64 hex chars)")
    print("SHA-512: 512 bits (128 hex chars)")
