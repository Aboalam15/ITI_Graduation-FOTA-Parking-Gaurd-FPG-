#############################################
# Author		: Abdelrahman Aboalam
# date	     	: 20/2/2024
# version		: 1.0.0
# description   : Code in Raspberry pi 
# peri		    : for devolper only
#############################################

import pyrebase
import os
import math
import serial
import time
import sys
import Sha


ser = serial.Serial(
   port='/dev/serial0',  # Serial port connected to your UART device
   baudrate=115200,        # Baudrate of the UART communication
   timeout=.04            # Timeout for reading from serial port
)

#############################################
# here I config parameters for firebase
#############################################
config = {
  "apiKey": "AIzaSyB4upuWHQAn7PkVjE80lVGyJAigtJrqx5w",
  "authDomain": "fpg-fota-park-guard.firebaseapp.com",
  "databaseURL": "https://fpg-fota-park-guard-default-rtdb.firebaseio.com",
  "projectId": "fpg-fota-park-guard",
  "storageBucket": "fpg-fota-park-guard.appspot.com",
  "messagingSenderId": "216601476340",
  "appId": "1:216601476340:web:9947039f4fa77c1a58f2a1",
  "measurementId": "G-70F7M5G6X8"
}

#############################################
# here I config parameters of RSA 
#############################################
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

#############################################
# here i define functions of sending recordes
#############################################
def send_hex_record(record):
    for byte in record:
        ser.write(byte.encode('utf-8'))  # Sending the ASCII representation of each byte
    ser.write(b'\n')  # Send newline character after each record
    print("Sent:", record.strip())

# Function to send the next record from the file
def send_next_record(file):
    for line in file:
        if not line.strip() or line[0] != ':':
            continue
        send_hex_record(line.strip())
        return

###################################################
# here I extract variable to search to next version
###################################################
with open("var.txt", "rb") as file:
    i = file.readline().decode('utf-8').strip()

######################################################
    
with open("var2.txt", "rb") as file:
    j = file.readline().decode('utf-8').strip()

######################################
# here I config my files with firebase
######################################

firebase =pyrebase.initialize_app(config)
localdirectory = '/home/Aboalam/Desktop/Grad'  # Local directory where the file will be downloaded
i=str(i)
enc="FPG"+"-"+i+".hex"
print (enc)
cloudpath = enc  # Path to the HEX file in Firebase Storage

localdirectory2 = '/home/Aboalam/Desktop/Grad'
j=str(j)
enc2="App-"+j+".hex"
cloudpath2=enc2
###################################################
# here I Rename the Encrypted file with new version
###################################################

App="App-"+ i + ".hex"
localfilename = App # Name of the file after downloading
App2="Appo-"+ j + ".hex"
localfilename2 = App2 # Name of the file after downloading

###################################################
# here I Searching for updates on the server
###################################################

firebase.storage().child(cloudpath).download(localdirectory + '/' + localfilename)
firebase.storage().child(cloudpath2).download(localdirectory2 + '/' + localfilename2)


###################################################
# here wait response from STM
###################################################
while True:
    data = ser.readline().decode(errors='ignore').strip()
    if data == "R" :
        ser.write(b'R')
        print("rec")
        break




#
#
#
###################################################
# here I Check if Force update 
###################################################
#
#
#
if os.path.exists(localdirectory + '/' + localfilename):

    ser.write(b'0')
    print("send 0")
    localfilename="Sha"+"-"+i+".hex"
    cloudpath="Sha"+"-"+i+".hex"
    firebase.storage().child(cloudpath).download(localdirectory + '/' + localfilename)

###################################################
# here I Start to decrypt file
###################################################
  
    file_path = App
    with open(file_path, "rb") as file:
       massage = file.read()
       
    file_content_decrypted = [pow(c, d, n) for c in massage]

    decrypted_file_path = "FPG-"+i+".hex"
    with open(decrypted_file_path, "wb") as decrypted_file:
       decrypted_file.write(bytes(file_content_decrypted))

    with open(decrypted_file_path, "r") as file:
                file_content = file.read().strip()

###################################################
# here I Start to make new digest after decrypt
###################################################
                
    if os.path.exists(decrypted_file_path):
        hash_value = Sha.sha1(file_content.encode('utf-8'))
        hash_str = str(hash_value)
    
        with open (localfilename,"r") as file :
            content =  file.read().strip()

###################################################
# here I Check if it same data
###################################################
            
        if content == hash_str :
            while True:
                data = ser.readline().decode(errors='ignore').strip()
                if data == "R" :
                 print("rec")
                 break
            with open(decrypted_file_path, 'r') as file:
                send_next_record(file)
###################################################
# here I Start to send hex file record by record
###################################################
                while True:
                        # Read data from serial port
                        data = ser.readline().decode(errors='ignore').strip()

                        # Check if received data is "OK"
                        if data == "OK":
                            print("Received 'OK' from STM")
                            send_next_record(file)
                        if data == "NOK":
                            print("Received 'NOK' from STM")
                            ser.close()
                            i=int(i)
                            i+=1
                            i=str(i)
                            with open("var.txt", "w") as file:
                                file.write(i)
                            sys.exit(0) 

        else :
            ser.close()
            i=int(i)
            i+=1
            i=str(i)
            sys.exit(0)
    
    else:
      print("error")

#
#
#
########################################
# here for optional update
########################################
#
#
#
elif os.path.exists(localdirectory2 + '/' + localfilename2):
    localfilename="Sha2"+"-"+j+".hex"
    cloudpath="Sha2"+"-"+j+".hex"
    firebase.storage().child(cloudpath).download(localdirectory + '/' + localfilename)
    ser.write(b'3')

###################################################
# here I check for response from STM
###################################################
    while True :
        data = ser.readline().decode(errors='ignore').strip()
        if data == "NO" :
          sys.exit(0)
        if data == "R" :
            ser.write(b'R')
            time.sleep(0.2)
            ser.write(b'0')
            print("sent 0")
            while True :
                data = ser.readline().decode(errors='ignore').strip()
                if data == "R" :
                    print("recieve")
                    break
            time.sleep(.5)
###################################################
# here I Start to decrypt file
###################################################
            file_path = App2
            with open(file_path, "rb") as file:
                massage = file.read()
            
            file_content_decrypted = [pow(c, d, n) for c in massage]

            decrypted_file_path = "Appo-"+j+".hex"
            with open(decrypted_file_path, "wb") as decrypted_file:
                decrypted_file.write(bytes(file_content_decrypted))


            with open(decrypted_file_path, "r") as file:
                file_content = file.read().strip()


            if os.path.exists(decrypted_file_path):
             hash_value = Sha.sha1(file_content.encode('utf-8'))
             hash_str = str(hash_value)
            
             with open (localfilename,"r") as file :
                content =  file.read().strip()
###################################################
# here I Check if it same data
###################################################
                if content == hash_str :


                    with open(decrypted_file_path, 'r') as file:
                        send_next_record(file)
###################################################
# here I Start to send hex file record by record
###################################################
                        while True:
                                # Read data from serial port
                                data = ser.readline().decode(errors='ignore').strip()

                                # Check if received data is "OK"
                                if data == "OK":
                                    print("Received 'OK' from STM")
                                    send_next_record(file)
                                if data == "NOK":
                                    print("Received 'NOK' from STM")
                                    ser.close()
                                    j=int(j)
                                    j+=1
                                    j=str(j)
                                    with open("var2.txt", "w") as file:
                                        file.write(j)
                                    sys.exit(0) 
                else :
                    ser.close()
                    j=int(j)
                    j+=1
                    j=str(j)
                    sys.exit(0) 

#
#
#
########################################
# here for No update
########################################
#
#
#
else:
    ser.write(b'1')
    print("No Updates")
    sys.exit(0) 
