import random
import math
import Sha
public_key = 11
private_key=13
n= public_key * private_key
phi_n = (public_key-1) * (private_key-1)

def mod_inverse(e, phi):
    for d in range(3, phi):
       if (d * e) % phi == 1:
	       return d
    

e=7
d = mod_inverse(e, phi_n)


file_path = "App.hex"
with open(file_path, "rb") as file:
    massage = file.read()


with open("var2.txt", "rb") as file:
    j = file.read().decode('utf-8')

print (j)

ciphertext = [pow(c, e, n) for c in massage]

encrypted_bytes = b"".join(int.to_bytes(c, (c.bit_length() + 7) // 8, 'big') for c in ciphertext)

j=str(j)
enc="App"+"-"+j+".hex"
print (enc)


encrypted_file_path = enc
with open(encrypted_file_path, "wb") as encrypted_file:
    encrypted_file.write(encrypted_bytes)


with open('App.hex', 'r') as file:
    file_content = file.read().strip()

sh="Sha2"+"-"+j+".hex"
# Compute SHA-1 hash of the entire file content
hash_value = Sha.sha1(file_content.encode('utf-8'))
hash_str = str(hash_value)
with open(sh, 'w') as file:
    file.write(hash_str)

print("SHA-1 hash of the file content:", hash_value)


j=int(j)
j+=1
j=str(j)
with open("var2.txt", "w") as file:
     file.write(j)

