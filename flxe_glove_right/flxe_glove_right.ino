#include "BluetoothSerial.h"
#include <Wire.h>
#include <MPU9250_asukiaaa.h>
#include <math.h> 
#include <MadgwickAHRS.h>

BluetoothSerial SerialBT;
String device_name = "Glove_Right"; // 또는 "Glove_Right"
MPU9250_asukiaaa mpu;
const int flexPins[5] = {33, 32, 25, 39, 36};

Madgwick filter;
unsigned long lastUpdate = 0;
const unsigned long updateInterval = 30; // 30ms = 33.33Hz

// 드리프트 보정을 위한 변수
float beta = 0.3; // 기본값 0.1보다 높게 설정 (가속도계 신뢰도 증가)

void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name);
  Serial.println("Glove is ready to pair.");

  Wire.begin();
  mpu.setWire(&Wire);
  
  mpu.beginAccel();
  mpu.beginGyro();
  // mpu.beginMag(); // 자기계 제거 - 실내에서 부정확하고 드리프트 유발

  // Madgwick 필터 초기화
  filter.begin(33.33);
  
  // 베타 값 설정 (드리프트 보정 강화)
  // 높을수록 가속도계를 더 신뢰 (드리프트 감소, 약간의 떨림 증가)
  // 범위: 0.01 ~ 1.0, 권장: 0.2 ~ 0.5
  // filter.setBeta(beta); // Madgwick 라이브러리에 따라 이 함수가 없을 수 있음
  
  Serial.println("Sensor initialized!");
  Serial.print("Update rate: ");
  Serial.print(1000.0 / updateInterval);
  Serial.println(" Hz");
  delay(1000); // 센서 안정화 대기
}

void loop() {
  unsigned long currentTime = millis();
  
  // 정확한 시간 간격으로만 업데이트
  if (currentTime - lastUpdate < updateInterval) {
    return;
  }
  
  lastUpdate = currentTime;

  String dataPacket = "";

  // 플렉스 센서 읽기
  for (int i = 0; i < 5; i++) {
    int rawValue = analogRead(flexPins[i]);
    dataPacket += String(rawValue);
    
    if (i < 4) {
      dataPacket += ",";
    }
  }

  // MPU 센서 읽기
  mpu.accelUpdate();
  mpu.gyroUpdate();
  // mpu.magUpdate(); // 자기계 제거

  float ax = mpu.accelX();
  float ay = mpu.accelY();
  float az = mpu.accelZ();
  
  float gx = mpu.gyroX();
  float gy = mpu.gyroY();
  float gz = mpu.gyroZ();

  // Madgwick 필터 업데이트 (6축 IMU 모드 - 자기계 제거)
  filter.updateIMU(gx, gy, gz, ax, ay, az);

  // Quaternion 값 직접 가져오기 (라이브러리 수정 후)
  float q0 = filter.getQ0(); // w
  float q1 = filter.getQ1(); // x
  float q2 = filter.getQ2(); // y
  float q3 = filter.getQ3(); // z

  dataPacket += ",";
  dataPacket += String(ax, 2);
  dataPacket += ",";
  dataPacket += String(ay, 2);
  dataPacket += ",";
  dataPacket += String(az, 2);
  
  dataPacket += ",";
  dataPacket += String(q0, 4);
  dataPacket += ",";
  dataPacket += String(q1, 4);
  dataPacket += ",";
  dataPacket += String(q2, 4);
  dataPacket += ",";
  dataPacket += String(q3, 4);

  SerialBT.println(dataPacket);
  Serial.println(dataPacket);
}