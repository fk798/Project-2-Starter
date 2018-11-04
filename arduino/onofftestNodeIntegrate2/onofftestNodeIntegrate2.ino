//const int LED = D13;//just the pin its attached to
//const int BUTTON = D7;//pin where pushbutton is connected
//  int val = 0;          //variable to store value of input pin state 
//  int state = 0;        //0 is led off , 1 is on
//  int oldVal = 0;       //stores previous value of val, needed for debouncing
////  int counter = 0; // to determine the size of data array
//  int readSize = 500;
//  int beatArray[500]; // max size of array, change this for longer heartbeat reads ..atleast 1min
//  int arrayCount = 0; // counter for a for loop
//  int brate = 9600;
//  

int testARY[3] = {123, 456, 789};
String strArray = "[";
for (int i = 0; i < testARY.length; i++ ) {
  strArray += testARY[i];
  strArray += ", ";
}
strArray += "]";
//-----------for Wifi-------------------------

#include <ESP8266WiFi.h>
 
const char* ssid     = "GrnRodan";
const char* password = "";
 
//const char* host = "wifitest.adafruit.com";
const char* host = "192.168.1.126";

//------------------------------------------------------------------------------------------------------
//
void setup() {
//  // put your setup code here, to run once
//  pinMode(LED, OUTPUT); //declares that led is output
//  pinMode(BUTTON, INPUT);  //and button is input
//  
//  Serial.begin(brate);//from sensor code

  //-----------for Wifi----------------------------------------------------
  pinMode(0, OUTPUT);
  Serial.begin(115200);
  delay(100);
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  //----------------------------------------------------------------------------
}

int value = 0;//for wifi
//
void loop() {
//  // put your main code here, to run repeatedly:
//  
//  val = digitalRead (BUTTON); 
//  if ((val == HIGH)&&(oldVal == LOW)) {
//    state = 1-state;
//    delay (100);
//  }
//
//  oldVal = val;//oldVal persists the switch 
//  
//  if ((state ==1) &&(arrayCount < readSize)){
//    digitalWrite(LED, HIGH); //turn it on
//    int sensorValue = analogRead(A0); //for sensor value storage
//    Serial.println(sensorValue);      //for displaying in console
//    delay (100);                      //for rate 10 times a second
//    //counter = counter +1; 
//    beatArray[arrayCount] = sensorValue;
//    arrayCount++;//counts how much of data is collected
//  }else if((state ==1)&&(arrayCount == readSize)){
////  delay(2000);
//    state = 0;
//    oldVal = LOW;
//    arrayCount = 0;
//    Serial.println(beatArray[(readSize-1)]);// just testing if array is filled
//    Serial.println("Above number is the last number in the array");
//  }else{
//  digitalWrite(LED, LOW); //turn it off
//  }

  //------------------for wifi----------------------
 digitalWrite(0, HIGH);
  delay(500);
  digitalWrite(0, LOW);
  delay(500);

    delay(5000);
  ++value;
 
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
//  const int httpPort = 80;
  const int httpPort = 3000;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
//  String url = "/testwifi/index.html";
  String url = "/";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
//  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//               "Host: " + host + "\r\n" + 
//               "Connection: close\r\n\r\n");
//  delay(500);
//
//  client.print(String("POST ") + url + " HTTP/1.1\r\n" +
//               "Host: " + host + "\r\n" + 
//               "Connection: close\r\n\r\n" + "?testkey=testval" + "\r\n") ;
//
//   delay(500);
//     

client.print(String("POST ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n" +  strArray + "\r\n") ;

   delay(500);
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
  //-------------------------------------------
}
