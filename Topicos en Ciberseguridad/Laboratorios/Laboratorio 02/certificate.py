import socket
import ssl
import cryptography
from cryptography import x509
from cryptography.hazmat.backends import default_backend


context = ssl.create_default_context()
sock = context.wrap_socket(socket.socket(), server_hostname="www.google.com")
sock.connect(("www.google.com", 443))
cert = sock.getpeercert()
#print(cert)
print(type(cert))

data =[]

data.append(cert)
data.append(cert)
data.append(cert)

print(data)