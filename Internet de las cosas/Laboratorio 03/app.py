import time
from grovepi import *

# Definición de constantes para los puertos
LIGHT_SENSOR_PORT = 0  # Sensor de luz conectado al puerto D0
LED_PORT = 5           # LED conectado al puerto D5
RELAY_PORT = 13        # Relé conectado al puerto D13

# Umbral de luz para activar el sistema de seguridad
THRESHOLD = 512

# Inicialización de los sensores y actuadores
light_sensor = GroveLightSensor(LIGHT_SENSOR_PORT)
led = GroveLed(LED_PORT)
relay = GroveRelay(RELAY_PORT)

def read_light_intensity(sensor):
    """
    Lee la intensidad de luz del sensor.
    """
    return sensor.light

def activate_security_system(led, relay):
    """
    Activa el sistema de seguridad encendiendo el LED y el relé.
    """
    led.on()
    relay.on()
    print('Security system activated: Light below threshold.')

def deactivate_security_system(led, relay):
    """
    Desactiva el sistema de seguridad apagando el LED y el relé.
    """
    led.off()
    relay.off()
    print('Security system deactivated: Light above threshold.')

def run_security_check():
    """
    Ejecuta el chequeo de seguridad basado en la intensidad de la luz.
    """
    try:
        while True:
            light_intensity = read_light_intensity(light_sensor)
            print(f'Light intensity: {light_intensity}')
            
            if light_intensity < THRESHOLD:
                activate_security_system(led, relay)
            else:
                deactivate_security_system(led, relay)
            
            time.sleep(1)

    except KeyboardInterrupt:
        print('Program terminated by user.')
        deactivate_security_system(led, relay)
    except IOError:
        print('Error: Cannot read sensor or actuator state.')

# Ejecutar el chequeo de seguridad
if __name__ == '__main__':
    run_security_check()


