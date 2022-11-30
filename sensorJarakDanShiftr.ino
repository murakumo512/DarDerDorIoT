#include <NewPing.h> //Library untuk HC-SR04
#include <WiFi.h>
#define TRIGGER_PIN  5  // setelah berpusing2 melihat tutor di yt ada yang bisa make "D5" dan ternyata di tempat aing ga bisa, ngentot "D"nya diilangin baru bisa
#define ECHO_PIN     4  //
#define MAX_DISTANCE 250 //Maksimum Pembacaan Jarak (cm)
//Mac address esp32 : 0C:B8:15:F5:3E:84

 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); //Setup Pin HC-SR04 dan Jarak Pembacaan dengan Fungsi Library
const char* ssid = "ambon manise"; //jeneng wifi
 
void setup() {
  Serial.begin(9600); //Memulai Komunikasi Serial Monitor

  WiFi.begin(ssid);
  Serial.println("\nConnecting");
  
  while(WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      delay(100);
  }
  
  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}
 
void loop() {   
  int jarak = sonar.ping_cm(); //Melakukan Pembacaan Jarak dalam bentuk cm
  //Mencetak Hasil Pembacaan pada Serial Monitor          
  Serial.println("Monitoring Jarak");
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");
  delay(4000); //Delay 1 Detik
}
