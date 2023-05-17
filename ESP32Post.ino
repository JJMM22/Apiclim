#include <WiFi.h>
#include <HTTPClient.h> // nos permite hacer peticiones http
#include <ArduinoJson.h>
#include <DHT.h>
#include "FirebaseESP32.h"

#define FIREBASE_HOST "https://proyectclima-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "8W3OQmXGmTbNSKfR9HycMkodjUOpjBzLuadjQOUT"
FirebaseData ProyectClima;
String ruta = "Sensores";

const char* ssid = "MORAN_6BAA";
const char* pass = "M0R4N2322";

#include "DHT.h"
#define DHTPIN 23
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);

float h;
float t;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  delay(2000);
  Serial.print("Se esta conectado a la red WiFi denominada");
  Serial.println(ssid);
  while (WiFi.status() !=WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  Serial.println(F("DHTxx test!"));
  dht.begin();
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Falla de la Lectura del Sensor"));
    return;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  h = dht.readHumidity();
  t = dht.readTemperature();
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(", Temperatura: ");
  Serial.print(t);
  Serial.print("");

  Firebase.setInt(ProyectClima, ruta + "/SensorT", t);
  Firebase.setInt(ProyectClima, ruta + "/SensorH", h);

// documento serializado
String json;
serializeJson(doc, json);

WiFiClient client;  // or WiFiClientSecure for HTTPS
HTTPClient http;
// Send request
http.begin("https://apiclimaservicio2.onrender.com");
//cabeceras JSON
http.addHeader("Content-Type", "application/json");
int res = http.POST(json);

Serial.println(json);
// respuesta
Serial.println(http.getString());
Serial.println(res);
// desconecta
http.end();
delay(60000);
}
}
