import serial


def main():
    with serial.Serial(port="/dev/cu.usbmodem14101", baudrate=115200) as ser:
        while True:
            line = ser.readline().decode('utf-8').strip("\n")
            print(line)

main()
