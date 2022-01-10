//PRD
//ADIT, BANI, NIKOLAS, REZDA
//SOURCE ESP32

#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp32_SSL.h>
BlynkTimer timer;
#include <WiFi.h>
#include <WiFiClientSecure.h>
char ssid[] = "SPEEDY. 5";
char pass[] = "rumah2bagus";
char auth[] = "wjkod5S4Rq98zCNlQOOrx5b-TFGDoOi1";

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(2, INPUT); //pin 2 utk menerima input dari arduino
  Blynk.begin(auth, ssid, pass); //koneksi ke cloud blynk
  timer.setInterval(5000L, uwu); //delay 5 detik untuk menjalankan blynk
}
void uwu(){
  int val = digitalRead(2); //membaca pin 2
  Serial.println(val);
  if (val == 0) {
    Blynk.virtualWrite(V0, "di atas 7 cm"); //jika sinyal yg diterima LOW, maka masih di atas setengah, lalu mengirim data ke cloud Blynk dan dapat di lihat statusnya di aplikasi Blynk
  } else {
    Blynk.virtualWrite(V0, "di bawah 7 cm"); //jika sinyal yg diterima HIGH, maka sudah mau penuh, lalu mengirim data ke cloud Blynk dan dapat di lihat statusnya di aplikasi Blynk
    Blynk.email("irsoekarno888@gmail.com", "TONG SAMPAH", "UDAH MAU PENUH"); //mengirim e-mail ke pengguna
    Blynk.notify("TONG SAMPAHNYA MAU PENUH"); //mengirim notifikasi ke aplikasi blynk
  }
}
void loop()
{
  Blynk.run();
  timer.run();
}
