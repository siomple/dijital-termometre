# Dijital Termometre Projesi (Arduino + DHT11)

Bu projede **DHT11 sıcaklık ve nem sensörü** kullanılarak ortamdaki sıcaklık/nem verileri okunmuş ve **Arduino UNO** üzerinden **seri monitörde gösterilmiştir**. Proje, temel gömülü sistem uygulamaları için giriş niteliğindedir.

## 🎯 Proje Amacı
- Sensör verisi okumayı öğrenmek
- Seri haberleşme kullanarak veri görselleştirmek
- Arduino IDE ile temel kod yazma pratiği kazanmak

## 🧰 Kullanılan Donanım
| Bileşen              | Açıklama                         |
|----------------------|----------------------------------|
| Arduino UNO          | Geliştirme kartı                |
| DHT11 Sensör         | Sıcaklık ve nem ölçümü          |
| Jumper Kablolar      | Bağlantılar için                |
| Breadboard           | Devre kurulumu için             |
| (Opsiyonel) LCD 16x2 | Geliştirme için kullanılabilir  |

## 💻 Yazılım ve Kütüphaneler
- Arduino IDE
- Adafruit DHT Sensor Library

## 🧠 Öğrenilen Beceriler
- Dijital sensör bağlantısı ve kullanımı  
- Seri iletişim (Serial Monitor)  
- Koşul kontrolü (`if`, `isnan`)  
- Delay ve döngü yapısı

## 🔧 Koddan Örnek
```cpp
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor okunamadi!");
    return;
  }

  Serial.print("Sicaklik: ");
  Serial.print(temp);
  Serial.print(" °C, Nem: ");
  Serial.print(hum);
  Serial.println(" %");
  delay(2000);
}
