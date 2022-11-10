from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives import hashes





clave_publica = serialization.load_pem_public_key( 
    open('Laboratorios\Laboratorio 06\public_profesor.pem', 'rb').read(),
    backend=default_backend()
)


# function to send message with public key 

def send_message(message, public_key):
    encrypted_message = public_key.encrypt(
        message,
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()), 
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    return encrypted_message
     
#send message
message = b'Mensaje de prueba'
encrypted_message = send_message(message, clave_publica)

print ("encrypted message: ", encrypted_message)
print ("\n")
print("encrypted message in hex: ", encrypted_message.hex())

print('\n')
print(encrypted_message)


#save encrypted message in file
with open('Laboratorios\Laboratorio 06\encrypted_message.txt', 'wb') as file:
    file.write(encrypted_message.hex())





