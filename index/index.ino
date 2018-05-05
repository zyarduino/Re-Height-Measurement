float cm;
int TrigPin = 2,
    EchoPin = 3;

void setup(){
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT); //设置Pin口模式
  pinMode(EchoPin, INPUT);
}

void loop(){
  MeasureHeight();
  Serial.println(String(cm) + "cm"); 
  delay(500); 
}

void MeasureHeight(){
  digitalWrite(TrigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  cm = pulseIn(EchoPin, HIGH) / 58; //将回波时间换算成cm

  return cm;
}
