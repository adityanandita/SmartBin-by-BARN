//PRD
//ADIT, BANI, NIKOLAS, REZDA
//SOURCE ARDUINO

#define echoPin 8 //pin echo sensor ultrasonik
#define trigPin 9 //pin trigger sensor ultrasonik
#define led1 2 //pin utk led kuning
#define led2 3 //pin utk led merah
long duration, distance; //definisi output sensor dan jarak
void setup() {
  Serial.begin (9600); //inisialiasasi komunikasi serial

  //deklarasi pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(10, OUTPUT); //pin 10 untuk komunikasi ke esp32
}

void loop() {
  //membuat sensor mengeluarkan output
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //menerima input dari trigger

  //perhitungan untuk dijadikan jarak
  distance = duration / 58.2;
  Serial.println(distance);
  if (distance >= 30) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  } else if (distance <= 20 && distance > 7) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(10, LOW); //memberi sinyal LOW ke esp32 ketika setengah penuh
    // Serial.println(2);
  } else if (distance <= 7 && distance > 1) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(10, HIGH); //member sinyal HIGH ke esp32 ketika mau penuh
    //Serial.println(3);
  }
  //waktu tunda 50mS
  delay(50);
}
