/* --- SophEE Robot Software Template --- 
 * -------------------------------------- 
 * Wifi connection and initialization is
 * already done for you. 
 * 
 * Initialize the motor outputs and write 
 * code for each robot instruction.
 * 
 * Don't forget to check the WiFi
 * parameters are correct in this file
 * as well as script.js
 * 
 * Good Luck!
*/
// Import required libraries
#include "ESP8266WiFi.h"
#include <aREST.h>
#include <Wire.h>

// Create aREST instance
aREST rest = aREST();

// WiFi parameters
const char* ssid = "CupOfTea";
const char* password = "melodicunit308";

// The port to listen for incoming TCP connections 
#define LISTEN_PORT           80

// Create an instance of the server
WiFiServer server(LISTEN_PORT);

// Function
int stop(String message);
int forward(String message);
int right(String message);
int left(String message);
int backward(String message);

void setup(void)
{  
  // Start Serial
  Serial.begin(115200);  

  // Functions          
  rest.function("stop", stop);
  rest.function("forward", forward);
  rest.function("left", left);
  rest.function("right", right);
  rest.function("backward", backward);
      
  // Give name and ID to device
  rest.set_id("1");
  rest.set_name("robot");
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
  
  // Print the IP address
  Serial.println(WiFi.localIP());
  
}

void loop() {
  
  // Handle REST calls
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);
 
}

int stop(String command) {

  Serial.println("Stop");
  // Enter code to stop robot here
  
}

int forward(String command) {
   Serial.println("Forward");
  // Enter code to move robot forward here
}

int left(String command) {
   Serial.println("Left");
   // Enter code to turn robot left here
  
}

int right(String command) {
   Serial.println("Right");
   // Enter code to turn robot right here
  
}

int backward(String command) {
   Serial.println("Back");
   // Enter code to make robot reverse here

}
