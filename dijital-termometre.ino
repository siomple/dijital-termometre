#include <DHT.h>

#define DHTPIN 2         // DHT11 sensörü Arduino'nun 2 numaralı pinine bağlı
#define DHTTYPE DHT11    // Kullanılan sensör tipi

DHT dht(DHTPIN, DHTTYPE);  // Sensör nesnesi oluşturuluyor

void setup() {
  Serial.begin(9600);    // Seri haberleşme başlatılıyor
  dht.begin();           // Sensör başlatılıyor
}

void loop() {
  float temp = dht.readTemperature();     // Sıcaklık verisi
  float hum = dht.readHumidity();         // Nem verisi

  // Sensör okuması başarısızsa
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Sensor okunamadi!");
    return;
  }

  // Verileri seri monitörde göster
  Serial.print("Sicaklik: ");
  Serial.print(temp);
  Serial.print(" °C, Nem: ");
  Serial.print(hum);
  Serial.println(" %");

  delay(2000); // 2 saniyede bir ölçüm yapılır
}
