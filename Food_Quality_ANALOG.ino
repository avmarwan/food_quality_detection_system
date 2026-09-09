#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

#include <Adafruit_NeoPixel.h>
#define PIN 27
#define NUMPIXELS 5
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 14
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int numberOfDevices;
DeviceAddress tempDeviceAddress;

HardwareSerial mySerial(2);

int moisture_sensor_pin = 32, Gas_sensor_pin = 35, Buzzer = 25;

int moisture_sensor_status = 0, Gas_sensor_status = 0;

String data;

unsigned long ms, msLast;
float tempC = 0;

String ph_value_string, ldr_value_string, temp_value_string, ph_sensor_data;
float ph_data = 0, ldr_data = 0, temp_data = 0;

int connection_led = 26, connection_interval = 250;
unsigned long connection_millis = 0;

void setup()
{
  mySerial.begin(9600, SERIAL_8N1, 16, 17);

  pinMode(moisture_sensor_pin, INPUT);
  pinMode(Gas_sensor_pin, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(connection_led, OUTPUT);

  SerialBT.begin("FOOD-QUALITY");

  sensors.begin();

  numberOfDevices = sensors.getDeviceCount();

  pixels.begin();
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));
  }
  pixels.show();
}

void loop()
{
  if (SerialBT.hasClient())
  {
    digitalWrite(connection_led,!digitalRead(connection_led));
  }
  else
  {
    digitalWrite(connection_led,HIGH);
  }

  moisture_sensor_status = analogRead(moisture_sensor_pin);
  Gas_sensor_status = analogRead(Gas_sensor_pin);

  sensors.requestTemperatures();
  for (int i = 0; i < numberOfDevices; i++)
  {
    if (sensors.getAddress(tempDeviceAddress, i))
    {
      tempC = sensors.getTempC(tempDeviceAddress);
    }
  }

  if (mySerial.available() > 0)
  {
    delay(100);
    String c = mySerial.readString();

    ph_value_string = c.substring(5, 10);
    ldr_value_string = c.substring(21, 24);
    temp_value_string = c.substring(29, 32);

    ph_data = ph_value_string.toFloat();
    ldr_data = ldr_value_string.toFloat();
    temp_data = temp_value_string.toFloat();

    ph_sensor_data = "*P" + String(ph_data) + "*" + "*D" + String(ldr_data) + "*" + "T" + String(temp_data) + "*";
  }


  if (SerialBT.available() > 0)
  {
    char rec = SerialBT.read();
    if (rec == 'G')
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      }
      pixels.show();
    }
    if (rec == 'B')
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      }
      pixels.show();
    }
    if (rec == 'T')
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(255, 255, 255));
      }
      pixels.show();

      digitalWrite(Buzzer, HIGH);
      delay(300);
      digitalWrite(Buzzer, LOW);
      delay(300);
      digitalWrite(Buzzer, HIGH);
      delay(300);
      digitalWrite(Buzzer, LOW);
      delay(300);

    }
  }

  data = "*M" + String(moisture_sensor_status) + "*G" + String(Gas_sensor_status) + "*T" + String(tempC) + "*P" + String(ph_data) + "*";

  ms = millis();
  if (ms - msLast > 1000)
  {
    SerialBT.println(data);
    msLast = ms;
  }
}
