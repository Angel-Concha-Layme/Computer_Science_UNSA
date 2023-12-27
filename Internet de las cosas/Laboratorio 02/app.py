import time
import random
from counterfit_shims_grove.grove_light_sensor_v1_2 import GroveLightSensor
from counterfit_connection import CounterFitConnection

# Initialize the CounterFit Connection
def init_connection():
    CounterFitConnection.init('127.0.0.1', 5000)

# Function to read light sensor value
def read_light_sensor(sensor):
    return random.uniform(min_light, max_light) # simulate light reading

# Function to check if light is below threshold
def is_light_below_threshold(light, threshold):
    return light < threshold

# Main function to run the program
def main():
    init_connection()

    light_sensor_2 = GroveLightSensor(1)
    min_light = 0
    max_light = 1
    threshold = 0.5

    print('min_light: ', min_light)
    print('max_light: ', max_light)
    print('threshold: ', threshold)

    while True:
        light = read_light_sensor(light_sensor_2)
        if is_light_below_threshold(light, threshold):
            print('Light below threshold:', light)
        time.sleep(1)

if __name__ == "__main__":
    main()
