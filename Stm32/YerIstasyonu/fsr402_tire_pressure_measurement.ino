int fsr_pin_left_fore = A0;
int fsr_pin_right_fore = A1;
int fsr_pin_left_back = A2;
int fsr_pin_right_back = A3;

int fsr_value_left_fore, fsr_value_right_fore, fsr_value_left_back, fsr_value_right_back;
float voltage_left_fore, voltage_right_fore, voltage_left_back, voltage_right_back;
float resistance;
float pressure_left_fore, pressure_right_fore, pressure_left_back, pressure_right_back;

void setup() {
  Serial.begin(9600);
  pinMode(fsr_pin_left_fore, INPUT);
  pinMode(fsr_pin_right_fore, INPUT);
  pinMode(fsr_pin_left_back, INPUT);
  pinMode(fsr_pin_right_back, INPUT);
}

void loop() {
  left_fore();
  right_fore();
  left_back();
  right_back();
  delay(500); // Döngü sonunda bekleme
}

void left_fore() {
  fsr_value_left_fore = analogRead(fsr_pin_left_fore);
  voltage_left_fore = fsr_value_left_fore * (5.0 / 1023.0);
  if (fsr_value_left_fore == 0) {
    Serial.println("Left Fore Pressure: Not detected.");
  } else {
    resistance = (5.0 - voltage_left_fore) * 10000.0 / voltage_left_fore;
    pressure_left_fore = pow(10, ((log10(resistance) - 6.0) / -0.5));
    Serial.print("Left Fore Analog Value: ");
    Serial.println(fsr_value_left_fore);
    Serial.print("Left Fore Strength (N): ");
    Serial.println(pressure_left_fore, 2);
  }
}

void right_fore() {
  fsr_value_right_fore = analogRead(fsr_pin_right_fore);
  voltage_right_fore = fsr_value_right_fore * (5.0 / 1023.0);
  if (fsr_value_right_fore == 0) {
    Serial.println("Right Fore Pressure: Not detected.");
  } else {
    resistance = (5.0 - voltage_right_fore) * 10000.0 / voltage_right_fore;
    pressure_right_fore = pow(10, ((log10(resistance) - 6.0) / -0.5));
    Serial.print("Right Fore Analog Value: ");
    Serial.println(fsr_value_right_fore);
    Serial.print("Right Fore Strength (N): ");
    Serial.println(pressure_right_fore, 2);
  }
}

void left_back() {
  fsr_value_left_back = analogRead(fsr_pin_left_back);
  voltage_left_back = fsr_value_left_back * (5.0 / 1023.0);
  if (fsr_value_left_back == 0) {
    Serial.println("Left Back Pressure: Not detected.");
  } else {
    resistance = (5.0 - voltage_left_back) * 10000.0 / voltage_left_back;
    pressure_left_back = pow(10, ((log10(resistance) - 6.0) / -0.5));
    Serial.print("Left Back Analog Value: ");
    Serial.println(fsr_value_left_back);
    Serial.print("Left Back Strength (N): ");
    Serial.println(pressure_left_back, 2);
  }
}

void right_back() {
  fsr_value_right_back = analogRead(fsr_pin_right_back);
  voltage_right_back = fsr_value_right_back * (5.0 / 1023.0);
  if (fsr_value_right_back == 0) {
    Serial.println("Right Back Pressure: Not detected.");
  } else {
    resistance = (5.0 - voltage_right_back) * 10000.0 / voltage_right_back;
    pressure_right_back = pow(10, ((log10(resistance) - 6.0) / -0.5));
    Serial.print("Right Back Analog Value: ");
    Serial.println(fsr_value_right_back);
    Serial.print("Right Back Strength (N): ");
    Serial.println(pressure_right_back, 2);
  }
}

https://www.tinkercad.com/things/aMXskxG5bnG-basinc-sensoru-her-bir-tekerlek-icin/editel?returnTo=%2Fthings%2FaMXskxG5bnG-basinc-sensoru
