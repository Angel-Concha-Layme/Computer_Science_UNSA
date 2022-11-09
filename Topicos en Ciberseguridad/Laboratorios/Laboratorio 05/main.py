

from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.backends import default_backend


#read RSA key from file in pem format:
"""
-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAgf3h/+uHpUg+4doqYDEm
Y67EGwr4w5NuRtcq9jPo/nbReQgpBuH/c5EhbwChR6/TZrpHKhUST2tvaEGVk6ib
R7BjS3+gFknvJ84f/3ga67ChVG4fcE4TZ/bJ6ucDwOVy0XV7P7FctERRyXAHdGoI
qyShnT3XZjbLHrAzNzRCm0xjW2VfuJUQEFFzpTndQa0rJOTMwMqHK73B06jHlrNJ
YyLH1n4zd4lylU/O5Zc090IvQ6MkJNmF6MOCDmArOL/dMMBp76sLpopUrpV71+Q4
WafIRbgNYVEl+EC0g39ujDOmrRqtfH0wDTck/ojFrgZjhDRWjdJl4qBk+5Eq7kuI
AQIDAQAB
-----END PUBLIC KEY-----
"""

def read_pem_public_key(file):
    with open(file, 'rb') as key_file:
        public_key = serialization.load_pem_public_key(
            key_file.read(),
            backend=default_backend() 
        )
    return public_key



public_key = read_pem_public_key('Laboratorios\Laboratorio 05\Angel.pem')

print (public_key)

#properties of public key
def get_public_key_properties(public_key):
    public_numbers = public_key.public_numbers()
    modulus = hex(public_numbers.n)
    
    exponent = hex(public_numbers.e)
    return modulus, exponent

modulus, exponent = get_public_key_properties(public_key)
print (modulus)
print (exponent)


print("------------------------------")


def read_pem_private_key(file):
    with open(file, 'rb') as key_file:
        private_key = serialization.load_pem_private_key(
            key_file.read(),
            password=None,
            backend=default_backend()
        )
    return private_key

private_key = read_pem_private_key('Laboratorios\Laboratorio 05\Angel_private.pem')

print (private_key)

#properties of private key: modulus, publicExponen, privateExponent, prime1, prime2, exponent1, exponent2, coefficient
def get_private_key_properties(private_key):
    private_numbers = private_key.private_numbers()
    modulus = hex(private_numbers.public_numbers.n)
    public_exponent = hex(private_numbers.public_numbers.e)
    private_exponent = hex(private_numbers.d)
    prime1 = hex(private_numbers.p)
    prime2 = hex(private_numbers.q)
    exponent1 = hex(private_numbers.dmp1)
    exponent2 = hex(private_numbers.dmq1)
    coefficient = hex(private_numbers.iqmp)
    return modulus, public_exponent, private_exponent, prime1, prime2, exponent1, exponent2, coefficient


modulus, public_exponent, private_exponent, prime1, prime2, exponent1, exponent2, coefficient = get_private_key_properties(private_key)

print ("modulus: ", modulus)
print ("public_exponent: ", public_exponent)
print ("private_exponent: ", private_exponent)
print ("prime1: ", prime1)
print ("prime2: ", prime2)
print ("exponent1: ", exponent1)
print ("exponent2: ", exponent2)
print ("coefficient: ", coefficient)




#funcion para verificar si el archivo PEM es una llave publica con el formato correcto
def is_pem_public_key(file):
    try:
        public_key = read_pem_public_key(file)
        return True
    except:
        return False

#funcion para verificar si el archivo PEM es una llave privada con el formato correcto
def is_pem_private_key(file):
    try:
        private_key = read_pem_private_key(file)
        return True
    except:
        return False




if is_pem_private_key('Laboratorios\Laboratorio 05\Angel.pem') == True:
    print("El archivo es una llave privada")
else:
    print("El archivo no es una llave privada")

if is_pem_public_key('Laboratorios\Laboratorio 05\Angel.pem') == True:
    print("El archivo es una llave publica")
else:
    print("El archivo no es una llave publica")


