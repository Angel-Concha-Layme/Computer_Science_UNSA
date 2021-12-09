import unicodedata
from codecs_to_hex import to_hex

while True:
    text = input()
    print('UTF-8 : {!r}'.format(to_hex(text.encode('utf-32'), 4)))
