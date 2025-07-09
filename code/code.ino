// MQ-9 Sensor LPG Detection
const int mq9Pin = A0;         // MQ-9 analog output pin
const int greenLed = 6;        // Green LED = SAFE
const int redLed = 7;          // Red LED = DANGER
const int buzzerPin = 8;       // Buzzer = DANGER

const float RL = 10.0;                 // RL in kΩ (as per your circuit, default 10kΩ)
const float RATIO_IN_CLEAN_AIR = 9.6;  // Rs/Ro ratio in clean air (for LPG on MQ-9)

float Ro = 10.0; // Calibrated sensor resistance in clean air

void setup() {
  Serial.begin(9600);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(buzzerPin, LOW);

  Serial.println("Calibrating MQ-9 in clean air...");
  Ro = calibrateSensor();
  Serial.print("Calibration complete. Ro = ");
  Serial.println(Ro);
}

void loop() {
  float Rs = getSensorResistance(analogRead(mq9Pin));
  float ratio = Rs / Ro;
  float ppm = getLPGPPM(ratio);

  Serial.print("LPG ppm: ");
  Serial.println(ppm);

  if (ppm > 400) { // Adjust threshold as needed
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);
}

float calibrateSensor() {
  float val = 0.0;
  for (int i = 0; i < 50; i++) {
    val += getSensorResistance(analogRead(mq9Pin));
    delay(200);
  }
  val /= 50.0;
  return val / RATIO_IN_CLEAN_AIR;
}

float getSensorResistance(int adcValue) {
  float voltage = adcValue * (5.0 / 1023.0);
  return (5.0 - voltage) * RL / voltage;
}

float getLPGPPM(float ratio) {
  // MQ-9 LPG curve: log(ppm) = -2.1 * log10(ratio) + 0.72
  float logPPM = -2.1 * log10(ratio) + 0.72;
  return pow(10, logPPM);
}
