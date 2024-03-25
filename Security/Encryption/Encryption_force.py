#############################################
# Author		: Abdelrahman Aboalam
# date		    : 20/2/2024
# version		: 1.0.0
# description   : Code in OEM  
# peri		    : for devolper only
#############################################
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


with open("var.txt", "rb") as file:
    i = file.read().decode('utf-8')

print (i)

ciphertext = [pow(c, e, n) for c in massage]

encrypted_bytes = b"".join(int.to_bytes(c, (c.bit_length() + 7) // 8, 'big') for c in ciphertext)

i=str(i)
enc="FPG"+"-"+i+".hex"
print (enc)


encrypted_file_path = enc
with open(encrypted_file_path, "wb") as encrypted_file:
    encrypted_file.write(encrypted_bytes)


with open('App.hex', 'r') as file:
    file_content = file.read().strip()

sh="Sha"+"-"+i+".hex"
# Compute SHA-1 hash of the entire file content
hash_value = Sha.sha1(file_content.encode('utf-8'))
hash_str = str(hash_value)
with open(sh, 'w') as file:
    file.write(hash_str)

print("SHA-1 hash of the file content:", hash_value)


i=int(i)
i+=1
i=str(i)
with open("var.txt", "w") as file:
     file.write(i)

