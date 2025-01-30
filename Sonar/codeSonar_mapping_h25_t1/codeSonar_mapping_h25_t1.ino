const int TrigPin = 9;
const int EchoPin = 10;
float distance; 

bool detecter = false; 

#include <RunningMedian.h>

RunningMedian signalCapteur = RunningMedian(50);

void setup()
{
  Serial.begin(57600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  digitalWrite(TrigPin, LOW); 
}

void loop()
{
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  
  distance = pulseIn(EchoPin, HIGH) / 58.8;  //echo converti en cm

  signalCapteur.add( int(distance) );
  long m = signalCapteur.getMedian();
  long a = signalCapteur.getAverage();  
                                         
  // Serial.print(distance);
  // Serial.print(" ");
  // Serial.print(m);
  // Serial.print(" ");
  // Serial.println(a); 

  if (m > 500) {
    detecter = true;
  } else {
    detecter = false;
  }

  //Serial.print(detecter);
  Serial.print("isDetect ");
  Serial.println(detecter);

  delay(10);
}
