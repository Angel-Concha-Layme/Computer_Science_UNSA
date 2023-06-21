import re
import os
import string

DATA_DIR = 'Gutenberg_Text'

def get_file_paths(data_dir):
    """
    Devuelve una lista de rutas de archivo para todos los archivos de texto en el directorio y sus subdirectorios.
    Los archivos de texto tienen la extensión .txt.
    """
    file_paths = [os.path.join(root, file) for root, _, files in os.walk(data_dir) for file in files if file.endswith('.txt')]

    with open('file_paths.txt', 'w', encoding='utf-8') as file_paths_txt:
        file_paths_txt.write('\n'.join(file_paths))

    return file_paths


def remove_metadata(text):
    """
    Elimina el encabezado, el pie de página y la puntuación de un texto.
    Devuelve el texto en minúsculas y sin espacios en blanco al principio y al final.
    """
    # encuentra la línea que divide la cabecera y el cuerpo
    header_divider = re.search(r'\*\*\* START OF THIS PROJECT GUTENBERG EBOOK \*\*\*', text)
    if header_divider:
        # el cuerpo comienza en la siguiente línea
        header_divider = header_divider.end() + 1
        text = text[header_divider:]

    # encuentra la línea que divide el cuerpo y el pie de página
    footer_divider = re.search(r'\*\*\* END OF THIS PROJECT GUTENBERG EBOOK \*\*\*', text)
    if footer_divider:
        # el cuerpo termina en la línea anterior
        footer_divider = footer_divider.start()
        text = text[:footer_divider]

    # eliminar puntuación y convertir a minúsculas
    text = text.translate(str.maketrans('', '', string.punctuation + '«»¡¿”“—'))
    text = text.lower()

    return text.strip()


def preprocess(data_dir):
    """
    Procesa todos los archivos de texto en el directorio y sus subdirectorios.
    Los archivos de texto tienen la extensión .txt.
    Elimina el encabezado, el pie de página y la puntuación de cada archivo.
    """
    file_paths = get_file_paths(data_dir)
    num_files = len(file_paths)
    for i, file_path in enumerate(file_paths, start=1):
        with open(file_path, 'r', encoding='utf-8') as file:
            text = file.read()
            text = remove_metadata(text)
        with open(file_path, 'w', encoding='utf-8') as file:
            file.write(text)
        print(f"[{i}/{num_files}] files processed: {file_path}")


preprocess(DATA_DIR)
