#include <stdio.h>
#include <string.h>

int sampleAppDelayConfig() {
  int delay_ms = 60000;
  return delay_ms;
}

String sampleAppSensorTypeConfig() {
  String sensorType = "batCave";
  return sensorType;
}

String sampleAppSensorIDConfig() {
  String sensorID = "fruitBat"; 
  return sensorID;
}

const char* sampleWifiSSIDConfig() {
  const char* ssid = "your_wifi_ssid";
  return ssid;
}

const char* sampleWifiPWConfig() {
  const char* pw = "your_wifi_password";
  return pw;
}

String sampleServerNameConfig() {
  String serverName = "your_server_location_with_port";
  return serverName;
}

String sampleServerEndpointConfig() {
  String endpoint = "your_api_endpoint";
  return endpoint;
}

String sampleServerUsernameConfig() {
  String username = "your_server_auth_username";
  return username;
}

String sampleServerPasswordConfig() {
  String password = "your_server_auth_password";
  return password;
}
