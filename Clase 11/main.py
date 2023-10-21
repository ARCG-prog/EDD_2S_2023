import base64
import io
from PIL import Image


#pip install Pillow

imagenB64 = ''

def codificarTexto():
    texto = input("Ingresa un texto: ")

    texto_codificado = base64.b64encode(texto.encode('utf-8')).decode('utf-8')

    print("Texto Codificado:", texto_codificado)
    
    texto_decodificado = base64.b64decode(texto_codificado.encode('utf-8')).decode('utf-8')
    print("Texto Decodificado: ", texto_decodificado)

def codificarImagen():
    global imagenB64
    ruta = input("Ingresa el nombre de imagen: ")
    try:
        with open(ruta, "rb") as imagen:
            imagen_bytes = imagen.read()

            imagenB64 = base64.b64encode(imagen_bytes).decode('utf-8')
            #print(imagenB64)

    except Exception as e:
        print('Error: ', e)

def decodificarImagen():
    
    try:
        imagenBytes = base64.b64decode(imagenB64.encode('utf-8'))
        imagen = Image.open(io.BytesIO(imagenBytes))

        imagen.show()        

    except Exception as e:
        print('Error Decode: ', e)

#codificarImagen()
decodificarImagen()