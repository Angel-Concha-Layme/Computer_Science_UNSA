from Crypto.PublicKey import RSA

def generar_llaves_RSA():
    llave_privada = RSA.generate(2048)
    llave_publica = llave_privada.publickey()
    return llave_privada, llave_publica


llave_privada, llave_publica = generar_llaves_RSA()

print ("Llave publica: ", llave_publica.exportKey())


