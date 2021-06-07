#include <WiFi.h>

const char* ssid = "eSpark Consulting Group";
const char* password = "eSparkCons";


//int mic = A0;
//int mic_res = 15;
//
//
//const int sampleTime = 50; 
//int micOut;
//
//int preValue = 0; 
//
//void setup() {
//  Serial.begin(115200);
//
//  pinMode(mic_res, OUTPUT);
//  digitalWrite(mic_res, HIGH);
//}
//
//void loop() {
//   int micOutput = findPTPAmp();
//
//}   
//
//
//
//int findPTPAmp(){
//
//   unsigned long startTime= millis(); 
//   unsigned int PTPAmp = 0; 
//
//
//   unsigned int maxAmp = 0;
//   unsigned int minAmp = 4095;
//
//
//   while(millis() - startTime < sampleTime) 
//   {
//      micOut = analogRead(mic);
//      if( micOut < 4095)
//      {
//        if (micOut > maxAmp)
//        {
//          maxAmp = micOut;
//        }
//        else if (micOut < minAmp)
//        {
//          minAmp = micOut;
//        }
//      }
//   }
//
//  PTPAmp = maxAmp - minAmp;
//  double micOut_Volts = (PTPAmp * 3.3) / 4096;
//
//  
//  Serial.println(PTPAmp); 
//  return PTPAmp;   
//}


int mic = 35;
int mic_res = 16;


const int sampleTime = 50; 
int micOut;

int preValue = 0; 

void setup() {
  Serial.begin(115200);

  /*WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());*/

  pinMode(mic_res, OUTPUT);
  digitalWrite(mic_res, HIGH);
}

void loop() {
   int micOutput = findPTPAmp();

}   



int findPTPAmp(){

   unsigned long startTime= millis(); 
   unsigned int PTPAmp = 0; 


   unsigned int maxAmp = 0;
   unsigned int minAmp = 1024;


   while(millis() - startTime < sampleTime) 
   {
      micOut = analogRead(mic);
      if( micOut < 4095)
      {
        if (micOut > maxAmp)
        {
          maxAmp = micOut;
        }
        else if (micOut < minAmp)
        {
          minAmp = micOut;
        }
      }
   }

  PTPAmp = maxAmp - minAmp;
  double micOut_Volts = (PTPAmp * 3.3) / 4096;

  
  Serial.println(PTPAmp); 
  return PTPAmp;   
}
