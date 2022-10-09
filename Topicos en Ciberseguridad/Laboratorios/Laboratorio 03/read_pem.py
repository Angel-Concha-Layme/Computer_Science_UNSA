from cryptography import x509
from cryptography.hazmat.backends import default_backend

        

def get_name(certificado):
    for i in certificado.subject.get_attributes_for_oid(x509.oid.NameOID.COMMON_NAME):
        return i.value

def get_sha(certificado): 
    return hex(certificado.serial_number).upper()


def get_public_key_algorithm_format(certificado):
    format =  certificado.signature_hash_algorithm.name + ' ' +str(certificado.public_key().key_size) + ' bits'
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


def read_pem_certificates(file):
    certs_array = []
    with open(file, 'r') as f:
        certs = f.read()
        certs = certs.split('-----END CERTIFICATE-----')
        certs.pop()
        for cert in certs:
            cert = cert + '-----END CERTIFICATE-----'
            cert = x509.load_pem_x509_certificate(cert.encode(), default_backend())

            name = get_name(cert)
            SHA = get_sha(cert)

            Public_Key_Algorithm_format = get_public_key_algorithm_format(cert)

            cert_dict = {
                "Common name": name,
                "valid_before": cert.not_valid_before.strftime("%Y-%m-%d"),
                "valid_after": cert.not_valid_after.strftime("%Y-%m-%d"),
                "Public Key Algorithm": Public_Key_Algorithm_format,
                "SHA-1": SHA
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
                "SHA-1": line[2]
            }
            certs_array.append(cert_dict)
    return certs_array


Microsoft_Edge = read_csv_certificates("D:/UNSA/REPOSITORIO/Topicos en Ciberseguridad/Laboratorios/Laboratorio 03/Microsoft_edge.csv")
Mozilla_Firefox = read_pem_certificates("D:/UNSA/REPOSITORIO/Topicos en Ciberseguridad/Laboratorios/Laboratorio 03/Mozilla_Firefox.pem")
Google_Chrome = read_pem_certificates("D:/UNSA/REPOSITORIO/Topicos en Ciberseguridad/Laboratorios/Laboratorio 03/Google_Chrome.pem")


