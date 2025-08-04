#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 7
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.print("DHT Init...");
  delay(1000);
  lcd.clear();
}
void loop() {
  delay(2000); 
  float tC = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(tC) || isnan(h)) {
    Serial.println("DHT read failed!");
    lcd.setCursor(0, 0);
    lcd.print("DHT Error");
    return;
  }
  Serial.print("Temp: ");
  Serial.print(tC, 1);
  Serial.print(" °C   Hum: ");
  Serial.print(h, 1);
  Serial.println(" %");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tC, 1);
  lcd.print(" C   ");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h, 1);
  lcd.print(" %   ");
}
