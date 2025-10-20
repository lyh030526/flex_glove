#include "BluetoothSerial.h"
#include <Wire.h>
#include <MPU9250_asukiaaa.h>
#include <Adafruit_AHRS.h>

BluetoothSerial SerialBT;
String device_name = "Glove_Right";

MPU9250_asukiaaa mpu;
Adafruit_Mahony ahrs;

const int flexPins[5] = {33, 32, 34, 39, 36};

void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name);
  Serial.println("Right Glove is ready to pair.");

  Wire.begin();
  mpu.setWire(&Wire);
  mpu.beginAccel();
  mpu.beginGyro();
  mpu.beginMag();
}

void loop() {
  String dataPacket = "R:";

  // 플렉스 센서 값 추가
  for (int i = 0; i < 5; i++) {
    int rawValue = analogRead(flexPins[i]);
    int mappedValue = map(rawValue, 0, 4095, 1, 1000);
    dataPacket += String(mappedValue) + ",";
  }

  // 9축 센서 값 업데이트 및 필터링
  if (mpu.accelUpdate() && mpu.gyroUpdate() && mpu.magUpdate()) {
    ahrs.update(
      mpu.gyroX() * DEG_TO_RAD, mpu.gyroY() * DEG_TO_RAD, mpu.gyroZ() * DEG_TO_RAD,
      mpu.accelX(), mpu.accelY(), mpu.accelZ(),
      mpu.magX(), mpu.magY(), mpu.magZ()
    );

    // ✨✨✨ 최종 수정된 부분 ✨✨✨
    // 개별 get 함수를 사용하여 roll, pitch, yaw 값을 가져옵니다. (단위: degree)
    float roll = ahrs.getRoll();
    float pitch = ahrs.getPitch();
    float yaw = ahrs.getYaw();

    // 계산된 값을 문자열에 추가
    dataPacket += String(pitch, 2) + ",";
    dataPacket += String(roll, 2) + ",";
    dataPacket += String(yaw, 2);

  } else {
    dataPacket += "0.00,0.00,0.00";
  }

  // 데이터 전송
  SerialBT.println(dataPacket);
  Serial.println(dataPacket);

  delay(10);
}