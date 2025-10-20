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
- - - - - - 
## 5.Base station
Base station은 VR 헤드셋의 위치를 추적하는 외부 센서입니다.
이 기기에서 방출하는 적외선 레이저를 헤드셋의 센서들이 감지하고, 신호의 시간 차이를 계산하여
가상 공간 내에서 사용자의 움직임을 구현합니다.

A Base Station is an external sensor used for tracking a VR headset's position.
It emits infrared lasers that are detected by the headset's sensors.
The system then calculates the signal timing differences to precisely replicate the user's movements in the virtual space.
- - - - - -
## 6.VR Headset(HTC VIVE)
HTC VIVE 헤드셋은 가상현실 세계를 체험하고 상호작용하게 해주는 장치입니다.
착용하면 디스플레이와 렌즈를 통해 가상 공간이 보이고, 내장된 헤드폰으로 사운드가 제공됩니다. 
또한 헤드셋 외부에 있는 센서들이 외부에 설치된 base station의 신호를 받아 사용자의 머리 움직임과 위치를 정확하게 추적합니다.

The HTC VIVE headset is a device for experiencing and interacting with virtual worlds. 
When you wear it, its display and lenses reveal the virtual space, while built-in headphones deliver audio.
Furthermore, sensors on the headset pick up signals from external Base Stations, enabling precise tracking of the user's head movements and location.
- - - - - -
## 7.Leap motion Controller
립모션 컨트롤러는 사용자의 손과 손가락 움직임을 추적하는 모션 인식 센서입니다.
기기의 적외선 LED와 카메라를 통해 센서 위 공간에 있는 손의 움직임과 손가락 움직임을 실시간으로 인식하여 3D 데이터로 변환하며, 
이 기기를 VR헤드셋에 부착하여 가상 공간에서 자연스러운 손동작을 구현  할 수 있습니다.

The Leap Motion Controller is a motion sensor designed to precisely track hand and finger movements.
It uses infrared LEDs and cameras to capture the real-time motion of hands in the space above it, converting these movements into 3D data.
By attaching this device to a VR headset, users can implement natural and intuitive hand gestures within a virtual environment.

- - - - - -
