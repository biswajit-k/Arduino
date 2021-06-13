
int led = 7;
int sensorPin = A4; 
int sensorValue = 0;
unsigned long currtime = 0;
unsigned long timegot = 0;
int counter = 0;

int timestamp[] = {600, 800, 200, 300};
int timecount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  
  
}

void loop() {

  sensorValue = analogRead(sensorPin);
//  Serial.println(sensorValue);

  if(sensorValue > 150)
  {
    delay(20);
    Serial.println(millis() - currtime);
    if( currtime == 0 || (millis() - currtime > timestamp[timecount] && millis() - currtime < timestamp[timecount+1]) )
    {
      counter++;
      if(counter > 1)
       timecount += 2;
         
      currtime = millis();
      if(counter == 3)
      { 
          digitalWrite(led, HIGH);
          delay(300);
          digitalWrite(led, LOW);
          counter = 0;
          currtime = 0;
          timecount = 0;
      }
    }
    else 
    {
      currtime = millis();
      counter = 1;
      timecount = 0;
    }
  }
  
//  delay(100);
//  digitalWrite(curr, 1);
//  delay(1000);
//  digitalWrite(curr, 0);
//  delay(1000);
}
