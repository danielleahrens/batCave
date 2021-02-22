void postRequest(String requestPath, String httpRequestData, String authUsername, String authPassword) {
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;

    Serial.print("server name: ");
    Serial.println(requestPath);
    http.begin(requestPath);

    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", "Basic " + base64::encode(authUsername + ":" + authPassword));
   
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    int httpResponseCode = http.POST(httpRequestData);
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}
