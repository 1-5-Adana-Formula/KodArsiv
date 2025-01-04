#include <MPU6050.h>
#include <Wire.h>

MPU6050 sensor;
int ivmeX, ivmeY, ivmeZ, GyroX, GyroY, GyroZ;
void setup() {

  Serial.begin(9600);
  Wire.begin();
  sensor.initialize();
}

void loop() {

  sensor.getAcceleration(&ivmeX, &ivmeY, &ivmeZ);
  sensor.getRotation(&GyroX, &GyroY, &GyroZ);

  ivmeX = map(ivmeX, -17000, 17000, 0, 180);//ivmex ten adlığımız 17000 ile -17000 arasındaki verileri 0 ile 180 arasına atadık
  Serial.print("ivme X = ");
  Serial.println(ivmeX);
  ivmeY = map(ivmeY, -17000, 17000, 0, 180);
  Serial.print("ivme Y = ");
  Serial.println(ivmeY);
  ivmeZ = map(ivmeZ, -17000, 17000, 0, 180);
  Serial.print("ivme Z = ");
  Serial.println(ivmeZ);

  Serial.print("Gyro X = ");
  Serial.println(GyroX);

  Serial.print("Gyro Y = ");
  Serial.println(GyroY);

  Serial.print("Gyro Z = ");
  Serial.println(GyroZ);

  delay(1000);
}

https://wokwi.com/projects/418152375859445761
