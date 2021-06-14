
int indicator = 7;
int sensorPin = A4; 
int setled = 12;
int switchoutput = 4;
int pattern = 3;
int sensorValue = 0;
unsigned long currtime = 0;
unsigned long timegot = 0;
int counter = 0;

int timestamp[] = {600, 800, 200, 300};
int mytime[10];
int timecount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(indicator, OUTPUT);
  pinMode(setled, OUTPUT);
  
}

void loop() {
  
  if(digitalRead(switchoutput) == 1)
  {
    for(int i = 0 ;i<10; i++)
      mytime[i] = 0;
    digitalWrite(setled, HIGH);
    delay(300);
    digitalWrite(setled, LOW);
    
     int count = 0;
    int timenow = 0;
    
      while(count < pattern)
  {
    sensorValue = analogRead(sensorPin);
    if(sensorValue > 150)
    {
         delay(20);
     Serial.println(millis() - timenow);
    
      mytime[count] = millis() - timenow;
      timenow = millis();
      count++;
      
    }
    
  }  
   digitalWrite(setled, HIGH);
    delay(300);
    digitalWrite(setled, LOW);
    Serial.println(mytime[1]);
    Serial.println(mytime[2]);
 }
 
  sensorValue = analogRead(sensorPin);
  if(sensorValue > 150)
  {
    delay(20);
    Serial.println(millis() - currtime);
//    if( mytime[0] != 0)
//    {
      if( currtime == 0 || (millis() - currtime > (mytime[timecount+1] - 100) && millis() - currtime < (mytime[timecount+1] + 100)) )
    {
      counter++;
      if(counter > 1)
       timecount += 1;
         
      currtime = millis();
      if(counter == pattern)
      { 
          digitalWrite(indicator, HIGH);
          delay(300);
          digitalWrite(indicator, LOW);
          counter = 0;
          currtime = 0;
          timecount = 0;
      }
    }
//    }
//    else if( currtime == 0 || (millis() - currtime > timestamp[timecount] && millis() - currtime < timestamp[timecount+1]) )
//    {
//      counter++;
//      if(counter > 1)
//       timecount += 2;
//         
//      currtime = millis();
//      if(counter == 3)
//      { 
//          digitalWrite(indicator, HIGH);
//          delay(300);
//          digitalWrite(indicator, LOW);
//          counter = 0;
//          currtime = 0;
//          timecount = 0;
//      }
//    }
    else 
    {
      currtime = millis();
      counter = 1;
      timecount = 0;
    }
  }
  
}
