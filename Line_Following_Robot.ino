#define ENA 4
#define ENB 8
int mot1=9; 
int mot2=6; 
int mot3=3; 
int mot4=5;
int left=13; 
int right=12;
int Left=0; 
int Right=0;
void LEFT (void); 
void RIGHT (void); 
void STOP (void);
void setup()
{
Serial.begin(9600); 
pinMode(mot1,OUTPUT); 
pinMode(mot2,OUTPUT); 
pinMode(mot3,OUTPUT); 
pinMode(mot4,OUTPUT);
pinMode(left,INPUT); 
pinMode(right,INPUT);

pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
}
void loop()
{
digitalWrite(ENA,HIGH);
digitalWrite(ENB,HIGH);
Left=digitalRead(left);
Serial.println("left:");
Serial.println(Left); 
Right=digitalRead(right); 
Serial.println("Right:");
Serial.println(Right); 
Serial.println("................");
while((Left==1) && (Right==0))
{ 
  LEFT();
Left=digitalRead(left); 
Right=digitalRead(right);
}
while((Right==1) && (Left==0))
{ 
  RIGHT();
Left=digitalRead(left); 
Right=digitalRead(right);
}
while((Right==1) && (Left==1))
{
STOP();
Left=digitalRead(left); 
Right=digitalRead(right);
}
while((Right==0) && (Left==0))
{
forward();
Left=digitalRead(left);  
Right=digitalRead(right);
}
//delay(100);
}
void forward ()
{
Serial.println("Move Forward:");
analogWrite(mot1,45); 
analogWrite(mot2,0); 
analogWrite(mot3,45); 
analogWrite(mot4,0);
}
void LEFT ()
{
Serial.println("Turn Left:");
analogWrite(mot1,0); 
analogWrite(mot2,0); 
analogWrite(mot3,80); 
analogWrite(mot4,0);
}
void RIGHT ()
{
Serial.println("Turn Right:");
analogWrite(mot1,80); 
analogWrite(mot2,0);
analogWrite(mot3,0); 
analogWrite(mot4,0);
}
void STOP ()
{
  Serial.println("Stop....");
analogWrite(mot1,0); 
analogWrite(mot2,0); 
analogWrite(mot3,0); 
analogWrite(mot4,0);
}