#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <Preferences.h>
#include <stdint.h>
#include "global.h"

struct WifiSettings {    
    String ssid = "";
    String password = "";
    String hostname = "";
};

struct AppSettings {
    String mqttServer = "";
    String mqttUsername = "";
    String mqttPassword = "";
    String mqttRootTopic = "fingerprintDoorbell";
    String ntpServer = "pool.ntp.org";
    String webUiPassword = "";
    bool syslogEnabled = false;
    String syslogServer = "";
    uint16_t syslogPort = 514;
    uint8_t normalLedEffect = 1;
    uint8_t normalLedColor = 2;
    uint8_t ignoreTouchLedEffect = 3;
    uint8_t ignoreTouchLedColor = 2;
    uint8_t ringDisabledLedEffect = 3;
    uint8_t ringDisabledLedColor = 3;
    String sensorPin = "00000000";
    String sensorPairingCode = "";
    bool   sensorPairingValid = false;
};

class SettingsManager {       
  private:
    WifiSettings wifiSettings;
    AppSettings appSettings;

    void saveWifiSettings();
    void saveAppSettings();

  public:
    bool loadWifiSettings();
    bool loadAppSettings();

    WifiSettings getWifiSettings();
    void saveWifiSettings(WifiSettings newSettings);
    
    AppSettings getAppSettings();
    void saveAppSettings(AppSettings newSettings);

    bool isWifiConfigured();

    bool deleteAppSettings();
    bool deleteWifiSettings();

    String generateNewPairingCode();

};

#endif