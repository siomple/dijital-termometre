# Dijital Termometre Projesi (Arduino + LM35 + LCD)

Bu projede LM35 sıcaklık sensörü ile ortam sıcaklığı ölçülerek, 2x16 LCD ekran üzerinde anlık, minimum ve maksimum sıcaklıklar gösterilmiştir. Belirlenen eşik değerinin üzerinde sıcaklık ölçüldüğünde ekranda "YÜKSEK SICAKLIK!" uyarısı verilir.

## Kullanılan Donanım

- Arduino MEGA 2560 R3
- LM35 Sıcaklık Sensörü
- LCD 2x16 Ekran (I2C modülü ile)
- Breadboard ve jumper kablolar

## Özellikler

- Anlık sıcaklık değeri (°C) LCD üzerinde gösterilir  
- Minimum ve maksimum sıcaklıklar anlık takip edilir  
- 30°C üzeri sıcaklıkta görsel uyarı verilir  
- Basit bağlantılar ve az parça ile kolay kurulum

## Bağlantılar

**LM35 Bağlantısı**
- VCC → 5V
- GND → GND
- OUT → A0

**LCD I2C Bağlantısı (MEGA için)**
- SDA → 20
- SCL → 21

## Arduino IDE Kullanımı

1. `LiquidCrystal_I2C` kütüphanesini Library Manager'dan kur
2. Kodları Arduino IDE'ye yükle
3. Seri monitöre ihtiyaç olmadan LCD üzerinden değerleri gözlemle

## Proje Geliştirme Fikirleri

- Fan kontrolü (30°C üstü fanı aç)
- SD kart modülü ile veri kaydı
- Bluetooth üzerinden veri aktarımı

## Hazırlayan

Ahmet Emin Yakar  
[LinkedIn Profilim](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)
