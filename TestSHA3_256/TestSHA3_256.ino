#include <Arduino.h>

// Function to retrieve flash memory size
unsigned int getFlashMemorySize() {
  #if defined(__AVR_ATmega328P__)
    return 32768;  // 32KB for ATmega328P
  #elif defined(__AVR_ATmega2560__)
    return 253952; // 256KB for ATmega2560 (Arduino Mega 2560)
  #else
    return 0;      // Unknown flash memory size
  #endif
}

// Function to retrieve SRAM size
unsigned int getSRAMSize() {
  #if defined(__AVR_ATmega328P__)
    return 2048;   // 2KB for ATmega328P
  #elif defined(__AVR_ATmega2560__)
    return 8192;   // 8KB for ATmega2560 (Arduino Mega 2560)
  #else
    return 0;      // Unknown SRAM size
  #endif
}

// Function to retrieve EEPROM size
unsigned int getEEPROMSize() {
  #if defined(__AVR_ATmega328P__)
    return 1024;   // 1KB for ATmega328P
  #elif defined(__AVR_ATmega2560__)
    return 4096;   // 4KB for ATmega2560 (Arduino Mega 2560)
  #else
    return 0;      // Unknown EEPROM size
  #endif
}

void setup() {
  Serial.begin(9600);

  // Print Arduino board information
  Serial.print("Board: ");
#ifdef BOARD_NAME
  Serial.println(BOARD_NAME);
#else
  Serial.println("Unknown board");
#endif

  // Print microcontroller information
  Serial.print("Microcontroller: ");
#ifdef __AVR_ARCH__
  Serial.println("AVR");
#elif defined(ESP8266)
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