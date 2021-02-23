# Cenozoa IoT Farm Platform

The Cenozoa IoT Farm is a custom built platform. The vision of this platform is to achieve a network of sensors and automated systems to form a highly connected, fully integrated hobby farm. The platform is designed so that many types of IoT sensors can integrate with the system, sending measurement (i.e. temperature, humidity, light) or status (i.e. watering, heating, open/close) metrics to a server. Through a UI, the sensor metrics can be viewed and additional meta data (i.e. alert limits, location) can be added to enrich each sensor or manual overrides can be set (i.e. stop watering, turn off heat or close door).

Currently one IoT sensor type has been developed: a temperature and humidity monitoring sensor (https://github.com/danielleahrens/batCave). This sensor's primary purpose is to monitor the environmental conditions of various storage locations. Such as a cold, humid root cellar for storing cabbage and root vegetables, a cool, dry root cellar for storing winter squash or a cold, dry root cellar for storing alliums.

The current status and 24 hour highs and lows for each sensor can be viewed in the UI (https://github.com/danielleahrens/attenborough), as well as an expanded, detailed view of the previous week's metrics. The user can add and change a sensor's alert limits and update its location through the UI (no updating firmware when you add a new sensor or move it to a new spot in the house!).

In addition to acting as the primary hub for the sensors and the UI, the Cenozoa web server (https://github.com/danielleahrens/cenozoa) also monitors each sensor's current status and compares it to its alert limits. It fires an alert if a sensor is outside of the allowable range, so that the user can respond accordingly. 

# batCave
This is the firmware running on the temperature/humidity sensors (an ESP32 DevKit V1 with a DHT22 temperature/humidity sensor). It sends temperature and humidity metrics to the Cenozoa webserver (https://github.com/danielleahrens/cenozoa).

![cenozoa_diagram](https://user-images.githubusercontent.com/31782840/108779365-bf1c8a80-7534-11eb-91d8-64da8f6bad4e.png)

This sensor is a part of the Cenozoa IoT Farm Platform (https://cenozoa.danielleahrens.com) the component parts include:
- Web Server: https://github.com/danielleahrens/cenozoa
- User Interface: https://github.com/danielleahrens/attenborough
- Temp/Humidity Sensor: https://github.com/danielleahrens/batCave

This code was developed using the Arduino IDE, see this article for IDE set up: https://medium.com/initial-state/how-to-build-your-own-esp32-temperature-monitor-6967b797b913

