#include <LiquidCrystal_I2C.h>

// LM35 sensör A0 pininde
const int lm35Pin = A0;

// LCD adres ve boyut (I2C)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Min/Maks sıcaklık takibi
float minTemp = 100.0;
float maxTemp = -100.0;

// Uyarı eşiği
const float tempThreshold = 30.0;

void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Termometre Basladi");
  delay(2000);
  lcd.clear();
}

void loop() {
  int analogValue = analogRead(lm35Pin);
  float voltage = analogValue * (5.0 / 1023.0);
  float temperatureC = voltage * 100;

  // Min / Maks güncelle
  if (temperatureC < minTemp) minTemp = temperatureC;
  if (temperatureC > maxTemp) maxTemp = temperatureC;

  // LCD yazdir
  lcd.setCursor(0, 0);
  lcd.print("Anlik: ");
  lcd.print(temperatureC, 1); // 1 basamakli
  lcd.print((char)223); // ° simgesi
  lcd.print("C ");

  if (temperatureC > tempThreshold) {
    lcd.setCursor(0, 1);
    lcd.print("YUKSEK SICAKLIK!");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Min:");
    lcd.print(minTemp, 0);
    lcd.print(" Max:");
    lcd.print(maxTemp, 0);
  }

  delay(2000);
}
