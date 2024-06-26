#include <Servo.h>

#define echo 11
#define trig 12
Servo motor;

void setup() {
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  motor.attach(9);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);  // 2 mikro saniyeden daha uzun bir süre yüksek seviyede tutulmalıdır.
  digitalWrite(trig, LOW);  

  float zaman = pulseIn(echo, HIGH);
  float cm = zaman / 58.2; // Darbenin süresini kullanarak mesafeyi hesaplar.
  Serial.println(cm);

  if (cm < 10) {
    motor.write(0);
    delay(2000);
    motor.write(90);
  }

  // Sensörden alınan değerlerin doğruluğunu kontrol etmek için ek mesajlar
  Serial.print("Trig sinyali gönderildi, ");
  Serial.print("Echo pinindeki darbenin süresi: ");
  Serial.print(zaman);
  Serial.print(", Hesaplanan mesafe: ");
  Serial.println(cm);
}