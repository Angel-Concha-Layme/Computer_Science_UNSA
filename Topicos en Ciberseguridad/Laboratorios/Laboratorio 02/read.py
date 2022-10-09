import os
import sys
import re
import subprocess
import datetime
import time
import json
import base64
import hashlib
import binascii
import OpenSSL
import cryptography
from cryptography import x509
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.serialization import load_pem_private_key
from cryptography.hazmat.primitives.serialization import load_pem_public_key
from cryptography.hazmat.primitives.serialization import Encoding
from cryptography.hazmat.primitives.serialization import PublicFormat
from cryptography.hazmat.primitives.serialization import NoEncryption
from cryptography.hazmat.primitives.serialization import load_der_public_key
from cryptography.hazmat.primitives.serialization import load_der_private_key
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives.asymmetric import dsa
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.asymmetric import utils
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives.asymmetric import dsa
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.asymmetric import utils
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.asymmetric import rsa

def read_cert(cert):
    #open the certificate
    with open(cert, 'rb') as f:
        cert = x509.load_pem_x509_certificate(f.read(), default_backend())
    #get the properties of the certificate
    version = cert.version
    serial_number = cert.serial_number
    signature_algorithm = cert.signature_hash_algorithm.name
    issuer = cert.issuer
    validity = cert.not_valid_before
    validity = cert.not_valid_after
    subject = cert.subject
    public_key = cert.public_key()
    extensions = cert.extensions

    return version, serial_number, signature_algorithm, issuer, validity, subject, public_key, extensions 




#use read function

version, serial_number, signature_algorithm, issuer, validity, subject, public_key, extensions = read_cert("cert.pem")

def test(cert):
    with open(cert, 'rb') as f:
        cert = x509.load_pem_x509_certificate(f.read(), default_backend())
        print(cert)


#test("Topicos en Ciberseguridad\Laboratorios\Laboratorio 02\cert.pem")

#cert = x509.load_pem_x509_certificate("Topicos en Ciberseguridad\Laboratorios\Laboratorio 02\cert.pem", default_backend( ))



def read_certs(certs):
    #array to store the certificates
    certs_array = []
    #open the file
    with open(certs, 'r') as f:
        #read the file
        certs = f.read()
        #split the certificates
        certs = certs.split('-----END CERTIFICATE-----')
        #remove the last element
        certs.pop()
        #for each certificate
        for cert in certs:
            #add the end of the certificate
            cert = cert + '-----END CERTIFICATE-----'
            #get the properties of the certificate
            version, serial_number, signature_algorithm, issuer, validity, subject, public_key, extensions = read_cert("Topicos en Ciberseguridad\Laboratorios\Laboratorio 02\cert.pem")
            #add the certificate to the array
            certs_array.append({'version': version, 'serial_number': serial_number, 'signature_algorithm': signature_algorithm, 'issuer': issuer, 'validity': validity, 'subject': subject, 'public_key': public_key, 'extensions': extensions})
    return certs_array
    
#use read function
#certs_array = read_certs("Topicos en Ciberseguridad\Laboratorios\Laboratorio 02\certs.pem")
#cert_2 =read_cert("Topicos en Ciberseguridad\Laboratorios\Laboratorio 02\cert2.pem")

#print(cert_2)

#for cert in certs_array:
#    print(cert)
#    print("")


#PEM_READER FUNCTION TO READ THE CERTIFICATES USING THE OPENSSL LIBRARY




from cryptography import x509
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes


def read_cert(cert):
    with open(cert, 'rb') as f:
        cert = x509.load_pem_x509_certificate(f.read(), default_backend())
    return cert

#cert = read_cert("Topicos en Ciberseguridad\Laboratorios\Laboratorio 02\cert.pem")


#read the certificates from mozila trust store and return an array with the certificates 
def read_certs(file):
    certs_array = []
    with open(file, 'r') as f:
        certs = f.read()
        certs = certs.split('-----END CERTIFICATE-----')
        certs.pop()
        for cert in certs:
            cert = cert + '-----END CERTIFICATE-----'
            cert = x509.load_pem_x509_certificate(cert.encode(), default_backend())
            certs_array.append(cert)
    return certs_array


#certs_mozila = read_certs("Topicos en Ciberseguridad\Laboratorios\Laboratorio 02\certs.pem")
#cert_1 = read_cert("Topicos en Ciberseguridad\Laboratorios\Laboratorio 02\cert.pem")



#print(cert_1.fingerprint(hashes.SHA256()))

#print issuer   
#print(cert_1.issuer)


#get SSL/TLS Certificate from a website
import socket
import ssl

def get_cert(host, port):
    context = ssl.create_default_context()
    with socket.create_connection((host, port)) as sock:
        with context.wrap_socket(sock, server_hostname=host) as ssock:
            cert = ssock.getpeercert()
            cert = x509.load_pem_x509_certificate(cert, default_backend())
            return cert

#cert_2 = get_cert("www.google.com", 443)
#print(cert_2.issuer)

