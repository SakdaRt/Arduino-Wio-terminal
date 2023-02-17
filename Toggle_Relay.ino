
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <rpcWiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleWioTerminal.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Ic8RlAUvoL-cMKKJDGqVv87pdNbkQlsJ";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "POCO";
char pass[] = "88888888";

uint32_t times1 = 0;
uint32_t times2 = 0;
uint32_t times3 = 0;
uint32_t times4 = 0;

bool button_state_1 = false;
bool button_state_2 = false;
bool button_state_3 = false;
bool button_state_4 = false;

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass , IPAddress(192,168,192,204),8080);
  pinMode(BCM4,OUTPUT);
  pinMode(BCM5,OUTPUT);
  pinMode(BCM6,OUTPUT);
  pinMode(BCM7,OUTPUT);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V1){ 
    if (!param.asInt()){ 
        digitalWrite(BCM4, !digitalRead(BCM4)); 
    } 
    Serial.println(!param.asInt());
}

BLYNK_WRITE(V2){ 
    if (!param.asInt()){ 
        digitalWrite(BCM5, !digitalRead(BCM5)); 
    } 
    Serial.println(!param.asInt());
}

BLYNK_WRITE(V3){ 
    if (!param.asInt()){ 
        digitalWrite(BCM6, !digitalRead(BCM6)); 
    } 
    Serial.println(!param.asInt());
}

BLYNK_WRITE(V4){ 
    if (!param.asInt()){ 
        digitalWrite(BCM7, !digitalRead(BCM7)); 
    } 
    Serial.println(!param.asInt());
}
