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


print("encrypted message in hex: ", encrypted_message.hex())




#decrypt message with private key

private_key = serialization.load_pem_private_key(
    open('Laboratorios\Laboratorio 06\Angel_private.pem', 'rb').read(),
    password=None,
    backend=default_backend()
)

def decrypt_message(encrypted_message, private_key):
    original_message = private_key.decrypt(
        encrypted_message,
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )
    return original_message

encrypted_message = "PXIasDGjoh/4vyKjQM5GDZvc0J02ePoBbEmJ3YiPWtz9/srVr0q+CmFyQUdbk68fxZIUDLI70oQMMKFe4lhX6Ckk9b66QZicC6HMM0fPJG4UIBHPioyscrlwUzl6WDftRCwUDBOgqCzwahrr9/AYcE6dmapog15NS4OHDBlGEL4S7Jy4IiJ4ukKkos70mVBKyewY8fm+6C5j7Jk0sVFFlT3OD2gIBKoYJzxOFaRM643Upfi6bblxix9y/c5eavaBhNz9OsUUt/MV6H/hiBp0qTbgqcd/Fsvgkz5RXBKhdjNxX09b8Zxg96sbG719k3aPGsntX0/9D1dEv4TT6lQ4fg=="


decrypted_message = decrypt_message(encrypted_message, private_key)