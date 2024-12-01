#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <MPU6050_tockn.h>

#define SIM800_TX_PIN 7
#define SIM800_RX_PIN 8
#define TEMPERATURE_PIN 3  // Pin for DS18B20 sensor

SoftwareSerial sim800(SIM800_TX_PIN, SIM800_RX_PIN);
OneWire oneWire(TEMPERATURE_PIN);
DallasTemperature sensors(&oneWire); // Declare DallasTemperature object

#define PHONE_NUMBER "+919480534389" // Change this to your phone number
#define TEMPERATURE_THRESHOLD 32  // Change this to your desired temperature threshold

MPU6050 mpu6050(Wire);

bool quakeDetected = false;

void setup() {
  Serial.begin(9600);
  sim800.begin(9600);
  Wire.begin();
  Serial.println("Initializing DS18B20 sensor...");
  sensors.begin();

  Serial.println("Initializing MPU6050 sensor...");
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
    // MPU6050 reading
  mpu6050.update();
  if (mpu6050.getAccX() > 1 || mpu6050.getAccY() > 1 || mpu6050.getAccZ() > 1 ) {
    if (!quakeDetected) {
      sendSMS(PHONE_NUMBER, "Warning: Quake detected!, Evacuate in an orderly fashion.");
      Serial.println("Warning: Quake detected!");
      quakeDetected = true;
    }
  } else {
    quakeDetected = false;
  }
  // Temperature reading
  sensors.requestTemperatures(); // Request temperature readings from DS18B20
  float temperatureC = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  if (temperatureC > TEMPERATURE_THRESHOLD) {
    sendSMS(PHONE_NUMBER, "Warning temp above 30!, Heatwave inbound.");
    Serial.println("Warning: Temperature above threshold!");
    delay(1000); // Wait for 3 seconds before sending another SMS to avoid spamming
  }


 // Wait for 2 seconds before checking temperature and MPU6050 again
}

void sendSMS(String number, String message) {
  sim800.println("AT+CMGF=1"); // Set SMS mode to text
  delay(100);
  sim800.println("AT+CMGS=\"" + number + "\""); // Send SMS command with phone number
  delay(100);
  sim800.print(message); // Send the message
  delay(100);
  sim800.println((char)26); // End SMS with CTRL+Z
  delay(100);
}
