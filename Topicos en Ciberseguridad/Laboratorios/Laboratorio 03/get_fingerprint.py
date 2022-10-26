from cryptography import x509
from cryptography.hazmat.backends import default_backend
import ssl
        


def get_ssl_certificate(host, port):
    cert = ssl.get_server_certificate((host, port))
    #si no tiene certificado ssl
    if cert == None:
        return None
    else:
        cert = x509.load_pem_x509_certificate(cert.encode(), default_backend())
        return cert


#usar get_ssl_certificate 
#ejemplo

print ('ok')
cert = get_ssl_certificate('www.extranet.unsa.edu.pe', 443)


print ('ok')