"""MD5 Hash Generation"""
import hashlib

def generate_md5(message):
    md5_hash = hashlib.md5(message.encode())
    return md5_hash.hexdigest()

if __name__ == "__main__":
    msg = input("Enter message: ")
    hash_value = generate_md5(msg)
    
    print(f"\nMessage: {msg}")
    print(f"MD5 Hash: {hash_value}")
    print(f"Hash length: {len(hash_value) * 4} bits ({len(hash_value)} hex chars)")
    
    # Demonstrate avalanche effect
    print("\n--- Avalanche Effect Demo ---")
    msg2 = msg + "."
    hash2 = generate_md5(msg2)
    print(f"Modified message: {msg2}")
    print(f"MD5 Hash: {hash2}")
