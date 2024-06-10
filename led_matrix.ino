#define BLYNK_TEMPLATE_ID "TMPL3VfoL-Z4D"
#define BLYNK_TEMPLATE_NAME "IOT Display"
#define BLYNK_AUTH_TOKEN "CVnE9zENYW5NRt5VMszjXGfVTwSbG1Cn"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LedControl.h>

// Pins for the LED matrix
int DIN = 16; // D0
int CS = 5;   // D1
int CLK = 4;  // D2

LedControl lc = LedControl(DIN, CLK, CS, 1);

char ssid[] = "Andy Dufresne";
char pass[] = "sana@001";

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lc.shutdown(0, false);  // The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0, 15); // Set the brightness to maximum value
  lc.clearDisplay(0);     // and clear the display
}

// Character arrays for the letters
byte a[8] = {0x7E, 0xFF, 0xC3, 0xC3, 0xFF, 0xFF, 0xC3, 0xC3}; // A
byte b[8] = {0xFE, 0xFE, 0xC6, 0xC6, 0xFE, 0xFE, 0xC6, 0xFE}; // B
byte c[8] = {0x7E, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0x7E}; // C
byte d[8] = {0xFC, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xFE, 0xFC}; // D
byte e[8] = {0xFF, 0xFF, 0xC0, 0xC0, 0xFE, 0xFE, 0xC0, 0xFF}; // E
byte f[8] = {0xFF, 0xFF, 0xC0, 0xC0, 0xFE, 0xFE, 0xC0, 0xC0}; // F
byte g[8] = {0x7E, 0xFF, 0xC0, 0xC0, 0xC7, 0xC7, 0xFF, 0x7E}; // G
byte h[8] = {0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0xFF, 0xC3, 0xC3}; // H
byte i[8] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18}; // I
byte j[8] = {0x3E, 0x3E, 0x06, 0x06, 0x06, 0x06, 0xFE, 0xFC}; // J
byte k[8] = {0xC3, 0xC6, 0xCC, 0xF8, 0xF0, 0xF8, 0xCC, 0xC6}; // K
byte l[8] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF}; // L
byte m[8] = {0xC3, 0xC3, 0xFF, 0xFF, 0xDB, 0xDB, 0xC3, 0xC3}; // M
byte n[8] = {0xC3, 0xC3, 0xE3, 0xF3, 0xFB, 0xCF, 0xC7, 0xC3}; // N
byte o[8] = {0x7E, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0x7E}; // O
byte p[8] = {0xFE, 0xFE, 0xC3, 0xC3, 0xFE, 0xFE, 0xC0, 0xC0}; // P
byte q[8] = {0x7E, 0xFF, 0xC3, 0xC3, 0xDB, 0xFF, 0x7E, 0x03}; // Q
byte r[8] = {0xFE, 0xFE, 0xC3, 0xC3, 0xFE, 0xFE, 0xCC, 0xC6}; // R
byte s[8] = {0x7E, 0xFF, 0xC0, 0xFF, 0x7E, 0x03, 0xFF, 0xFE}; // S
byte t[8] = {0xFF, 0xFF, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18}; // T
byte u[8] = {0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0x7E}; // U
byte v[8] = {0xC3, 0xC3, 0xC3, 0xC3, 0x66, 0x66, 0x3C, 0x18}; // V
byte w[8] = {0xC3, 0xC3, 0xDB, 0xDB, 0xFF, 0xFF, 0xC3, 0xC3}; // W
byte x[8] = {0xC3, 0xC3, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0xC3}; // X
byte y[8] = {0xC3, 0xC3, 0xC3, 0x7F, 0x3F, 0x03, 0xFE, 0xFC}; // Y
byte z[8] = {0xFF, 0xFF, 0x06, 0x0C, 0x18, 0x30, 0xFF, 0xFF}; // Z


// Function to display a character on the LED matrix
void printByte(byte character[]) 
{
  for (int i = 0; i < 8; i++) 
  {
    lc.setRow(0, i, character[i]);
  }
}

// Blynk function to handle virtual pin writes
BLYNK_WRITE(V0) 
{
  String inputText = param.asStr();
  if (inputText == "A") {
    printByte(a);
  } else if (inputText == "B") {
    printByte(b);
  } else if (inputText == "C") {
    printByte(c);
  } else if (inputText == "D") {
    printByte(d);
  } else if (inputText == "E") {
    printByte(e);
  } else if (inputText == "F") {
    printByte(f);
  } else if (inputText == "G") {
    printByte(g);
  } else if (inputText == "H") {
    printByte(h);
  } else if (inputText == "I") {
    printByte(i);
  } else if (inputText == "J") {
    printByte(j);
  } else if (inputText == "K") {
    printByte(k);
  } else if (inputText == "L") {
    printByte(l);
  } else if (inputText == "M") {
    printByte(m);
  } else if (inputText == "N") {
    printByte(n);
  } else if (inputText == "O") {
    printByte(o);
  } else if (inputText == "P") {
    printByte(p);
  } else if (inputText == "Q") {
    printByte(q);
  } else if (inputText == "R") {
    printByte(r);
  } else if (inputText == "S") {
    printByte(s);
  } else if (inputText == "T") {
    printByte(t);
  } else if (inputText == "U") {
    printByte(u);
  } else if (inputText == "V") {
    printByte(v);
  } else if (inputText == "W") {
    printByte(w);
  } else if (inputText == "X") {
    printByte(x);
  } else if (inputText == "Y") {
    printByte(y);
  } else if (inputText == "Z") {
    printByte(z);
  }
}
void loop() 
{
  Blynk.run();
}





#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3oym_XNLm"
#define BLYNK_TEMPLATE_NAME "Smart noise pollution monitoring"
#define BLYNK_AUTH_TOKEN "e59MX08X6W2KqHikBruULMAgR6xIVDuS"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Andy Dufresne";
char pass[] = "sana@001";

char auth[] = "e59MX08X6W2KqHikBruULMAgR6xIVDuS";
const int soundSensorPin = A0;
const int referenceValue = 10;

void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop() 
{
  int soundValue = analogRead(soundSensorPin);
  float dB = 20 * log10((float)soundValue / referenceValue);

  Serial.print("Sound Level: ");
  Serial.print(dB);
  Serial.println(" dB");
  Blynk.virtualWrite(V0, dB);  
  Blynk.run();
  delay(1000);
}

