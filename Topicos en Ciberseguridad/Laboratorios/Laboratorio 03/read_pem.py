from operator import contains
import re
from webbrowser import get
from cryptography import x509
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
import ssl
        

def get_name(cert):
    for i in cert.subject.get_attributes_for_oid(x509.oid.NameOID.COMMON_NAME):
        return i.value


def get_public_key_algorithm_format(cert):
    format =  cert.signature_hash_algorithm.name + ' ' +str(cert.public_key().key_size) + ' bits'
    return format

def format_date(date):
    date = date.split(' ')
    month = date[1]
    day = date[2]
    year = date[0]
    month = month_number(month)
    date = year + '-' + month + '-' + day
    return date


def month_number(month):
    months = {
        'Jan': '01',
        'Feb': '02',
        'Mar': '03',
        'Apr': '04',
        'May': '05',
        'Jun': '06',
        'Jul': '07',
        'Aug': '08',
        'Sep': '09',
        'Oct': '10',
        'Nov': '11',
        'Dec': '12'
    }
    return months[month]


def get_key_usage(cert):
    usage =""
    try:
        cert.extensions.get_extension_for_class(x509.KeyUsage)
    except:
        usage = 'UNDENTIFIED'
        return usage
    
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.digital_signature == True:
        usage = usage + 'digital_signature, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.content_commitment == True:
        usage = usage + 'content_commitment, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.key_encipherment == True:
        usage = usage + 'key_encipherment, ' 
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.data_encipherment == True:
        usage = usage + 'data_encipherment, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.key_agreement == True:
        usage = usage + 'key_agreement, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.key_cert_sign == True:
        usage = usage + 'key_cert_sign, '
    if cert.extensions.get_extension_for_class(x509.KeyUsage).value.crl_sign == True:
        usage = usage + 'crl_sign, '
    return usage






def read_pem_certificates(file):
    certs_array = []
    with open(file, 'r') as f:
        certs = f.read()
        certs = certs.split('-----END CERTIFICATE-----')
        certs.pop()
        contador = 0
        for cert in certs:
            cert = cert + '-----END CERTIFICATE-----'
            cert = x509.load_pem_x509_certificate(cert.encode(), default_backend())

            name = get_name(cert)
            Public_Key_Algorithm_format = get_public_key_algorithm_format(cert)


            key_usage =get_key_usage(cert)


            cert_dict = {
                "Common name": name,
                "valid_before": cert.not_valid_before.strftime("%Y-%m-%d"),
                "valid_after": cert.not_valid_after.strftime("%Y-%m-%d"),
                "Public Key Algorithm": Public_Key_Algorithm_format,
                "Key Usage": key_usage,
                "SHA-1": (':'.join(cert.fingerprint(hashes.SHA1()).hex().upper()[i:i+2] for i in range(0, len(cert.fingerprint(hashes.SHA1()).hex().upper()), 2))),
            }

            certs_array.append(cert_dict)
    return certs_array


def read_csv_certificates(file):
    certs_array = []
    with open(file, encoding='utf8') as f:
        for line in f:
            line = line.split('","')
            valid_before = format_date(line[4])
            valid_after = format_date(line[5])
            cert_dict = {
                "Common name": line[1],
                "valid_before": valid_before,
                "valid_after": valid_after,
                "Public Key Algorithm": line[6],
                "Key Usage": line[8].replace(';', ','),
                "SHA-1": (':'.join(line[2].upper()[i:i+2] for i in range(0, len(line[2].upper()), 2))),
                "Serial Number": 'NULL'
            }
            certs_array.append(cert_dict)
    return certs_array


#Microsoft_Edge = read_csv_certificates("D:/UNSA/REPOSITORIO/Topicos en Ciberseguridad/Laboratorios/Laboratorio 03/Microsoft_edge.csv")
Mozilla_Firefox = read_pem_certificates("D:/UNSA/REPOSITORIO/Topicos en Ciberseguridad/Laboratorios/Laboratorio 03/Mozilla_Firefox.pem")
#Google_Chrome = read_pem_certificates("D:/UNSA/REPOSITORIO/Topicos en Ciberseguridad/Laboratorios/Laboratorio 03/Google_Chrome.pem")





def get_ssl_certificate(host, port):
    cert = ssl.get_server_certificate((host, port))
    cert = x509.load_pem_x509_certificate(cert.encode(), default_backend())
    return cert


#usar get_ssl_certificate 
#ejemplo

cert = get_ssl_certificate('www.unsa.edu.pe', 443)
print(cert.signature_hash_algorithm)


for cert in Mozilla_Firefox:
    print(cert)
    print ('\n')