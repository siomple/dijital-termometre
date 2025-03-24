# Dijital Termometre Projesi (Arduino + DHT11)

Bu projede DHT11 sıcaklık ve nem sensörü kullanılarak ortamdaki değerler ölçülmüş ve Arduino UNO ile seri monitör üzerinden kullanıcıya aktarılmıştır. Gömülü sistemler alanında temel uygulama örneği olarak tasarlanmıştır.

## Proje Amacı

- Sensör verilerini okuyabilmek
- Seri iletişim ile ölçüm verilerini göstermek
- Arduino ortamında temel kod yazma pratiği kazanmak

## Kullanılan Donanım

- Arduino UNO
- DHT11 sıcaklık ve nem sensörü
- Breadboard ve jumper kablolar
- (İsteğe bağlı) 16x2 LCD ekran

## Yazılım ve Kütüphaneler

- Arduino IDE
- Adafruit DHT Sensor Library

## Öğrenilen Beceriler

- Dijital sensör ile veri okuma
- Seri port üzerinden veri aktarımı
- Arduino ile temel programlama yapıları (if, delay, loop)
- Sensör kontrolü ve hata yönetimi (isnan kullanımı)

## Koddan Örnek

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

Geliştirme Fikirleri
LCD ekran üzerinden anlık verileri göstermek

ESP32 ile Wi-Fi bağlantısı kurarak verileri web arayüzüne aktarmak

SD kart modülüyle ölçüm kayıtlarını loglamak

Hazırlayan
Ahmet Emin Yakar
LinkedIn: linkedin.com/in/ahmet-emin-yakar-bbb6732a6
