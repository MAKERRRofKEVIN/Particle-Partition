include<LCD>
int valve0=0;
int valve1=1;
int valve2=2;
int valve3=3;
int valve4=4;
int valve5=5;
int valve6=6;
int valve7=7;
int valve8=8;
int valve9=9;
int valve10=10;
int valve11=11;
int valve12=12;
int valve13=13;
int valve14=14;
int valve15=15;
int valve16=16;
int powerswitch=17;
int connection1=18;
int connection2=19;
int connection3=20;
int connection4=21;
int lightcuring=22;
int lightcuringvalve=23;
int v1 = 24;
int v2 = 25;
int v3 = 26;
/*
following the design diagram2
valve HIGH=close LOW=open
24~26 Vacuum module
22~23 control light curing
18~21 checking whether filter connect
17 power switch
1~17 valve
*/

int lightcuring = 0;
int v1 = 0;
int v2 = 0;
int v3 = 0;
int box1 = 0;
int box2 = 0;
int box3 = 0;
int box4 = 0;
int box5 = 0;
int box6 = 0;
int tx = 0;
int rx = 0;

#define filter1=A0;
#define filter2=A1;
#define filter3=A2;
#define storage=A3;
#define box1 = A4;
#define box2 = A5;
#define box3 = A6;
#define box4 = A7;
#define box5 = A8;
#define box6 = A9;
#define boxa = A10;
#define boxb = A11;
#define boxc = A12;
#define boxd = A13;
#define boxe = A14;
#define boxf = A15;

/*
v1~v3（A1~3) are Filter
lightcuring (A4) is light curing in coalstorage
box1~6 (A5~10) are Electrostatic cabin
tx&rx(A11~12) are prepared for screen of coalstorage 
boxa~e(A13~18) are sensors in Electrostatic cabin
*/
void setup() {
pinMode(A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,OUTPUT);
pinMode(A10,A11,A12,A13,A14,A15,INPUT);
Serial.begin(9600);
lcd.print("START")
}

void loop() {
  lcd.print((analogRead(storage)/256)*100)
  analogWrite(256,box1);
  analogWrite(256,box2);
  analogWrite(256,box3);
  analogWrite(256,box4);
  analogWrite(256,box5);
  analogWrite(256,box6);
  digitalWrite(LOW,valve1);
  digitalWrite(LOW,valve2);
  digitalWrite(LOW,valve3);
  digitalWrite(LOW,valve4);
  digitalWrite(LOW,valve5);
  digitalWrite(LOW,valve6);
  digitalWrite(LOW,valve7);
  digitalWrite(LOW,valve8);
  digitalWrite(LOW,valve9);
  digitalWrite(LOW,valve10);
  digitalWrite(LOW,valve11);
  digitalWrite(LOW,valve12);
  digitalWrite(LOW,valve13);
  digitalWrite(LOW,valve14);
  digitalWrite(LOW,valve15);
  digitalWrite(LOW,valve16);
  digitalWrite(HIGH,connection1);
  digitalWrite(HIGH,connection2);
  digitalWrite(HIGH,connection3);
  digitalWrite(HIGH,connection4);
  //normal working
  
  for(analogRead(boxa)=0,analogRead(boxa)>>128,analogRead(boxa)=0) 
  {
  digitalWrite(HIGH,valve1);
  digitalWrite(HIGH,valve4);
  analogWrite(0,box1);
  analogWrite(256,box2);
  analogWrite(256,box3);
  analogWrite(256,box4);
  analogWrite(256,box5);
  analogWrite(256,box6);
  digitalWrite(HIGH,v1);
  delay(60000);
  digitalWrite(LOW,valve1);
  digitalWrite(LOW,valve4);
  analogWrite(256,box1);
  }
  //cleaning box1
  for(analogRead(boxb)=0,analogRead(boxb)>>128,analogRead(boxb)=0) 
  {
  digitalWrite(HIGH,valve2);
  digitalWrite(HIGH,valve5);
  analogWrite(0,box2);
  analogWrite(256,box1);
  analogWrite(256,box3);
  analogWrite(256,box4);
  analogWrite(256,box5);
  analogWrite(256,box6);
  digitalWrite(HIGH,v2);
  delay(60000);
  digitalWrite(LOW,valve2);
  digitalWrite(LOW,valve5);
  analogWrite(256,box2);
  
  }
  //cleaning box2
  for(analogRead(boxc)=0,analogRead(boxc)>>128,analogRead(boxc)=0) 
  {
  digitalWrite(HIGH,valve3);
  digitalWrite(HIGH,valve6);
  analogWrite(0,box3);
  analogWrite(256,box2);
  analogWrite(256,box1);
  analogWrite(256,box4);
  analogWrite(256,box5);
  analogWrite(256,box6);
  digitalWrite(HIGH,v3);
  delay(60000);
  digitalWrite(LOW,valve3);
  digitalWrite(LOW,valve6);
  analogWrite(256,box3);
  }
  //cleaning box3
  for(analogRead(boxd)=0,analogRead(boxd)>>128,analogRead(boxd)=0) 
  {
  digitalWrite(HIGH,valve7);
  digitalWrite(HIGH,valve10);
  analogWrite(0,box4);
  analogWrite(256,box2);
  analogWrite(256,box1);
  analogWrite(256,box3);
  analogWrite(256,box5);
  analogWrite(256,box6);
  digitalWrite(HIGH,v1);
  delay(60000);
  digitalWrite(LOW,valve7);
  digitalWrite(LOW,valve10);
  analogWrite(256,box4);
  }
  //cleaning box4
  for(analogRead(boxe)=0,analogRead(boxe)>>128,analogRead(boxe)=0) 
  {
  digitalWrite(HIGH,valve8);
  digitalWrite(HIGH,valve11);
  analogWrite(0,box5);
  analogWrite(256,box2);
  analogWrite(256,box1);
  analogWrite(256,box4);
  analogWrite(256,box5);
  analogWrite(256,box6);
  digitalWrite(HIGH,v2);
  delay(60000);
  digitalWrite(LOW,valve8);
  digitalWrite(LOW,valve11);
  analogWrite(256,box5);
  }
  //cleaning box5
  for(analogRead(boxf)=0,analogRead(boxf)>>128,analogRead(boxf)=0) 
  {
  digitalWrite(HIGH,valve9);
  digitalWrite(HIGH,valve12);
  analogWrite(0,box6);
  analogWrite(256,box2);
  analogWrite(256,box1);
  analogWrite(256,box4);
  analogWrite(256,box5);
  analogWrite(256,box3);
  digitalWrite(HIGH,v3);
  delay(60000);
  digitalWrite(LOW,valve9);
  digitalWrite(LOW,valve12);
  analogWrite(256,box6);
  }
  //cleaning box6
  for(analogRead(filter1)=0,analogRead(filter1)>>128,analogRead(filter1)=0) 
  {
  digitalWrite(HIGH,valve10);
  digitalWrite(HIGH,valve13);
  if(connection1=LOW)
  delay(2000);
  else if{
  digitalWrite(LOW,valve10);
  digitalWrite(LOW,valve13);
  }
  }
  //cleaning filter1
  for(analogRead(filter2)=0,analogRead(filter2)>>128,analogRead(filter2)=0) 
  {
  digitalWrite(HIGH,valve11);
  digitalWrite(HIGH,valve14);
  if(connection2=LOW)
  delay(2000);
  else if{
  digitalWrite(LOW,valve11);
  digitalWrite(LOW,valve14);
  }
  }
  //cleaning filter2
  for(analogRead(filter3)=0,analogRead(filter3)>>128,analogRead(filter3)=0) 
  {
  digitalWrite(HIGH,valve12);
  digitalWrite(HIGH,valve15);
  if(connection3=LOW)
  delay(2000);
  else if{
  digitalWrite(LOW,valve12);
  digitalWrite(LOW,valve15);
  }
  }
  //cleaning filter3
  for(analogRead(storage)=0,(analogRead(storage)/256)*100>>95,analogRead(storage)=0) 
  {
  digitalWrite(LOW,v1);
  digitalWrite(LOW,v2);
  digitalWrite(LOW,v3);
  digitalWrite(LOW,lightcuringvalve);
  digitalWrite(HIGH,lightcuring);
  if(connection4=LOW)
  delay(2000);
  else if{
  digitalWrite(HIGH,v1);
  digitalWrite(HIGH,v2);
  digitalWrite(HIGH,v3);
  }
  }
  //cleaning coal storage
}
