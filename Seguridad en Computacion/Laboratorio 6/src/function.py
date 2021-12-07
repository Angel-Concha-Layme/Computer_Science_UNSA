import hmac 
import hashlib

def MD5(cad):
    hashObjectmd5 = hashlib.md5(cad.encode())
    resultmd5 = hashObjectmd5.hexdigest()
    return resultmd5

def MD4(cad):
    hashObjectmd4 = hashlib.new('md4', cad.encode())
    resultmd4 = hashObjectmd4.hexdigest()    
    return resultmd4

def SHA1(cad):
    hashObjectsha1 = hashlib.sha1(cad.encode())
    resultsha1 = hashObjectsha1.hexdigest()
    return resultsha1

def SHA256(cad):
    hashObjectsha256 = hashlib.sha256(cad.encode())
    resultsha256 = hashObjectsha256.hexdigest()    
    return resultsha256


def HMACall(key,msj):
    byte_key = bytes(key, 'UTF-8')

    msj = msj.encode()

    #MD5
    hashObjecthmacmd5 = hmac.new(byte_key,msj,hashlib.md5)
    resulthmacmd5 = hashObjecthmacmd5.hexdigest()

    #SHA256
    hashObjecthmac256 = hmac.new(byte_key,msj,hashlib.sha256)
    resulthmac256 = hashObjecthmac256.hexdigest()

    #SHA1
    hashObjecthmac1 = hmac.new(byte_key,msj,hashlib.sha1)
    resulthmac1 = hashObjecthmac1.hexdigest()
    
    vector = [resulthmacmd5, resulthmac256, resulthmac1]

    return vector