#include "DHT.h"
#include "time.h"
#include "HTTPClient.h"
#include "WiFiMulti.h"

WiFiMulti WiFiMulti;

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

const char* ntpServer = "pool.ntp.org";
const long utcOffset_s = -18000;
const long daylightOffset_s = -144000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(10);

//  struct Configs cnfg = getConfig();

  Serial.println();
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  scanNetworks();
  connectToNetwork();

  Serial.println("Connected to the WiFi network");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());

  configTime(utcOffset_s, daylightOffset_s, ntpServer);

  dht.begin();
}


void loop() {
  // put your main code here, to run repeatedly:  
  float h=dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  printLocalTime();
  time_t now;
  time(&now);

  Serial.print(F("Current timestamp: "));
  Serial.print(now);
  Serial.print(F(" s  Humidity: "));
  Serial.print(h);
  Serial.print(F(" %  Temperature: "));
  Serial.print(t);
  Serial.print(F(" oC  "));
  Serial.print(f);
  Serial.println(F(" oF "));

  String httpRequestData = "{\"sensor_type\":\"" + appSensorTypeConfig() + "\",\"sensor_id\":\"" + appSensorIDConfig() + "\",\"metric_name\":\"humidity\",\"metric_value\":\"" + h + "\",\"timestamp_s\":\"" + now + "\",\"tags\":[{\"units\":\"%RH\"}]}";
  postRequest(serverNameConfig() + serverEndpointConfig(), httpRequestData);

  httpRequestData = "{\"sensor_type\":\"" + appSensorTypeConfig() + "\",\"sensor_id\":\"" + appSensorIDConfig() + "\",\"metric_name\":\"temperature\",\"metric_value\":\"" + f + "\",\"timestamp_s\":\"" + now + "\",\"tags\":[{\"units\":\"oF\"}]}";
  postRequest(serverNameConfig() + serverEndpointConfig(), httpRequestData);
  
  delay(appDelayConfig());
}
