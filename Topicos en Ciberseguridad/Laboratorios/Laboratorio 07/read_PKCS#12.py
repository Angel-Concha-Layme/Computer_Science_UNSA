from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.serialization.pkcs12 import load_key_and_certificates
from cryptography import x509


def get_name(certificado):
    for i in certificado.subject.get_attributes_for_oid(x509.oid.NameOID.COMMON_NAME):
        return i.value

def get_issuer(certificado):
    for i in certificado.issuer.get_attributes_for_oid(x509.oid.NameOID.COMMON_NAME):
      return i.value

def get_public_key_algorithm_format(certificado):
    format =  certificado.signature_hash_algorithm.name + ' - ' +str(certificado.public_key().key_size) + ' bits'
    return format

def get_key_usage(cert):
    usage =""
    try:
        cert.extensions.get_extension_for_class(x509.KeyUsage)
    except:
        usage = 'UNDENTIFIED'
        return usage

    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.digital_signature == True:
        usage = usage + 'Digital Signature, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.content_commitment == True:
        usage = usage + 'Content Commitment, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.key_encipherment == True:
        usage = usage + 'Key Encipherment, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.data_encipherment == True:
        usage = usage + 'Data Encipherment, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.key_agreement == True:
        usage = usage + 'Key Agreement, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.key_cert_sign == True:
        usage = usage + 'Key Cert Sign, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.crl_sign == True:
        usage = usage + 'Crl Sign, '
    return usage


def read_PKCS12(filename, password):
    with open(filename, 'rb') as f:
        data = f.read()
    private_key, certificate, additional_certificates = load_key_and_certificates(data, password, backend=default_backend())
    return private_key, certificate, additional_certificates    

def validar_contraseña(filename, password):
    try:
        private_key, certificate, additional_certificates = read_PKCS12(filename, password)
        return True
    except:
        return False
        


def process_additional_certificates(additional_certificates):
    aditional_certificates_data =[]
    for certificate in additional_certificates:
        Public_Key_Algorithm_format = get_public_key_algorithm_format(certificate)
        key_usage = get_key_usage(certificate)
        name = get_name(certificate)
        aditional_certificates_component = {
            'common name': name,
            'issuer': get_issuer(certificate),
            'valid_before': certificate.not_valid_before.strftime("%Y-%m-%d"),
            'valid_after': certificate.not_valid_after.strftime("%Y-%m-%d"),
            "Public Key Algorithm": Public_Key_Algorithm_format,
            "key usage": key_usage,
            "SHA-1": ':'.join('{:02X}'.format(x) for x in certificate.fingerprint(hashes.SHA256()))
        }
        aditional_certificates_data.append(aditional_certificates_component)

    return aditional_certificates_data


def generate_data(filename, password):
    private_key, certificate, additional_certificates = read_PKCS12(filename, password)
    private_key_data = {
        'modulus': hex(private_key.private_numbers().public_numbers.n),
        'public_exponent': private_key.private_numbers().public_numbers.e,
        'private_exponent': hex(private_key.private_numbers().d),
        'prime1': hex(private_key.private_numbers().p),
        'prime2': hex(private_key.private_numbers().q),
        'exponent1': hex(private_key.private_numbers().dmp1),
        'exponent2': hex(private_key.private_numbers().dmq1),
        'coefficient': hex(private_key.private_numbers().iqmp)
    }

    Public_Key_Algorithm_format = get_public_key_algorithm_format(certificate)
    key_usage = get_key_usage(certificate)
    name = get_name(certificate)

    certificate_data = {
        'common name': name,
        'issuer': get_issuer(certificate),
        'valid_before': certificate.not_valid_before.strftime("%Y-%m-%d"),
        'valid_after': certificate.not_valid_after.strftime("%Y-%m-%d"),
        "Public Key Algorithm": Public_Key_Algorithm_format,
        "key usage": key_usage,
        "SHA-1": ':'.join('{:02X}'.format(x) for x in certificate.fingerprint(hashes.SHA256()))
    }

    additional_certificates_data = process_additional_certificates(additional_certificates)



    return private_key_data, certificate_data, additional_certificates_data


private_key_data, certificate_data, additional_certificates = generate_data('Laboratorios\Laboratorio 07\Cert_CAxCRL-AFVig.p12', b'1234')

print("private_key_data: ", private_key_data)
print("-------------------------------------------------------------")
print("certificate_data: ", certificate_data)
print("-------------------------------------------------------------")
print("additional_certificates: ", additional_certificates)

