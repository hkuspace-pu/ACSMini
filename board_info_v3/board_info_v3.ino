#include <Arduino.h>

// Function to retrieve flash memory size
unsigned int getFlashMemorySize() {
  #if defined(ESP8266)
    return ESP.getFlashChipSize();
  #elif defined(ESP32)
    return ESP.getFlashChipSize();
  #else
    return 0;      // Unknown flash memory size
  #endif
}

// Function to retrieve SRAM size
unsigned int getSRAMSize() {
  #if defined(ESP8266)
    return ESP.getFreeHeap();
  #elif defined(ESP32)
    return ESP.getHeapSize();
  #else
    return 0;      // Unknown SRAM size
  #endif
}

// Function to retrieve EEPROM size
unsigned int getEEPROMSize() {
  #if defined(ESP8266)
    return 4096;   // 4KB EEPROM for ESP8266
  #elif defined(ESP32)
    return 4096;   // 4KB EEPROM for ESP32
  #else
    return 0;      // Unknown EEPROM size
  #endif
}

void setup() {
  Serial.begin(9600);

  // Print Arduino board information
  Serial.print("Board: ");
#if defined(ARDUINO_WEMOS_D1MINI)
  Serial.println("WeMos D1 Mini");
#else
  Serial.println("Unknown board");
#endif

  // Print microcontroller information
  Serial.print("Microcontroller: ");
#ifdef ESP8266
  Serial.println("ESP8266");
#elif defined(ESP32)
  Serial.println("ESP32");
#else
  Serial.println("Unknown microcontroller");
#endif

  // Print clock frequency
  Serial.print("Clock frequency: ");
  Serial.print(F_CPU);
  Serial.println(" Hz");

  // Print flash memory size
  Serial.print("Flash memory size: ");
  Serial.print(getFlashMemorySize());
  Serial.println(" bytes");

  // Print SRAM size
  Serial.print("SRAM size: ");
  Serial.print(getSRAMSize());
  Serial.println(" bytes");

  // Print EEPROM size
  Serial.print("EEPROM size: ");
  Serial.print(getEEPROMSize());
  Serial.println(" bytes");
}

void loop() {
  // Your code here
}