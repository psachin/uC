'''
echo.py

For Python v3
'''
import serial
fd = serial.Serial('/dev/ttyUSB0', 38400, stopbits=1, timeout = 1.0)


while 1:
  c = input('Enter a character : ')
  fd.write(c.encode('utf-8'))
  print('Received ', fd.read())
