import serial
import pyautogui
import time
from tqdm import tqdm

# Replace 'COM3' with your Arduino serial port, e.g., '/dev/ttyUSB0' on Linux or '/dev/ttyACM0'
arduino_port = '/dev/cu.usbmodem14201'
baud_rate = 9600

ser = serial.Serial(arduino_port, baud_rate, timeout=1)

def progress_bar(duration):
    for _ in tqdm(range(duration), desc="Progress", unit="s"):
        time.sleep(1)

# Example usage: Show a 60-second progress bar
progress_bar(60)

ser.reset_input_buffer()

print("Listening for commands...")

while True:
    line = ser.readline().decode('utf-8').strip()
    if line == "LEFT":
        print("Go to previous page")
        pyautogui.press('left')  # Usually left arrow goes previous page in PDFs
    elif line == "RIGHT":
        print("Go to next page")
        pyautogui.press('right')  # Usually right arrow goes next page in PDFs