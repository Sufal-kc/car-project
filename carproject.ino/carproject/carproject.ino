char Incoming_value = 0;
long duration;
int distance;
void setup() {
  // put your setup code   here, to run once:
Serial.begin(9600);
//for led
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
//for irsensor
pinMode(6,OUTPUT);//TIGRPIN
pinMode(7,INPUT);//echo pinoutput
//for motor driver side pins using jumper wire
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}

void   loop() {
   digitalWrite(6, LOW);
  
  digitalWrite(6, HIGH);
 
  digitalWrite(6, LOW);

  duration = pulseIn(7, HIGH);
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  //delay(1000);
  
  if (((Serial.available()>0)||(distance>10)) > 0)
    {
      Incoming_value = Serial.read();
      //Serial.println(Incoming_value);
      if (Incoming_value == 'F')
        {digitalWrite(3,HIGH);//for led green
        //igitalWrite(7,HIGH);//for motors 5volt
        digitalWrite(8,   HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10,   HIGH);
        digitalWrite(11, LOW);
        }
      else if(Incoming_value == 'B')
        {digitalWrite(2,HIGH);//for led red
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);}
      else if(Incoming_value == 'R')
       { digitalWrite(3,LOW);
         digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);}
      else if(Incoming_value == 'L')
        {digitalWrite(2,LOW);}
    }
}