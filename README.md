# Flex Glove

## 1.Flex Glove 

Flex Glove는 손가락과 손의 움직임을 인식하는 스마트 장갑입니다.
Flex Sensor가 손가락의 구부림 정도를 측정하고, MPU9250이 손의 기울기와 회전 방향을 감지합니다.
측정된 센세 데이터는 LOLIN D32 보드를 통해 처리되며, 블루투스 기능으로 pc로 실시간 전송됩니다.
이를 통해 사용자의 손동작을 인식할 수 있습니다.

Flex Glove is a smart glove that recognizes the movements of the fingers and hand.
The Flex Sensor measures how much each finger bends, and the MPU9250 detects the hand’s tilt and rotation.
The collected sensor data is processed by the LOLIN D32 board and sent to a PC in real time via Bluetooth.
Through this process, the glove can accurately recognize the user’s hand movements.
- - - - - - 
## 2.flex_sensor

Flex Sensor는 구부림에 따라 수치가 달라지는 센서로, 휘어진 정도를 숫자로 읽을 수 있습니다. 
손가락의 움직임을 감지해 구부러진 정도를 알아내며, 아두이노는 이 변화를 숫자로 받아 움직임을 인식합니다.

The Flex Sensor is a sensor whose value changes depending on how much it bends.
It measures the degree of bending as a number and detects finger movements.
Arduino reads these changes as numerical values to recognize the motion.
- - - - - -
## 3.mpu9250

MPU9250은 가속도계,자이로센서,지자기센서(나침반)가 하나로 합쳐진 9축센서 입니다.
아두이노와 연결하면 센세데이터를 통해 기울기,회전,방향등을 이용해 움직임을 실시간으로 추적할 수 있습니다.

The MPU9250 is a 9-axis sensor that combines an accelerometer, gyroscope, and magnetometer (compass) in a single module.
When connected to an Arduino, it can track motion in real time by using sensor data to measure tilt, rotation, and direction.
- - - - - - 
## 4.LOLIND32
LOLIN D32 보드는 ESP32 칩을 사용한 아두이노 호환 보드입니다. 
WI-FI와 블루투스 기능이 내장되어 있어 무선 통신이 가능하며, 이를 통해 센서 데이터를 PC로 실시간 전송할 수 있습니다.

The LOLIN D32 board is an Arduino-compatible board that uses the ESP32 chip.
It has built-in Wi-Fi and Bluetooth features, enabling wireless communication and allowing real-time transmission of sensor data to a PC.
