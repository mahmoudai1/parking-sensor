int pinF = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinA = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
//int D3 = 11;
//int D4 = 12;

const int echoPin = 12;
const int trigPin = 13;

const int buzzerPin = 11;

long duration;
int distance;
int digitalDistance;

unsigned long ctTimer = 0;

unsigned long delay1 = 0;
unsigned long delay2 = 0;
unsigned long delay3 = 0;
unsigned long delay4 = 0;
unsigned long delay5 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinA, OUTPUT);     // Top left
  pinMode(pinB, OUTPUT);     // Top Right
  pinMode(pinC, OUTPUT);     // Bottom Right
  pinMode(pinD, OUTPUT);     // Bottom
  pinMode(pinE, OUTPUT);     // Bottom Left
  pinMode(pinF, OUTPUT);     // Top
  pinMode(pinG, OUTPUT);     // Center
  
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
//  pinMode(D3, OUTPUT);
//  pinMode(D4, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  ctTimer = millis();

  delay1 = millis();
  delay2 = millis();
  delay3 = millis();
  delay4 = millis();
  delay5 = millis();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
//  distance = distance / 100; to convert into meters
//  digitalDistance = distance;
  
  if(millis() - ctTimer >= 400){  // Avoid Blinks
    ctTimer = millis();
    digitalDistance = distance;
  }
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  digitalWrite(buzzerPin, LOW);

  prePrint(digitalDistance);
  
  if(distance < 7){
    if(millis() - delay1 >= 100){
      tone(buzzerPin, 500);
      delay(200)
      delay2 = millis();
      delay3 = millis();
      delay4 = millis();
    }
    if(millis() - delay1 >= 200){
      noTone(buzzerPin);
      resetDelays();
    }
  }
  else if (distance < 10){
    if(millis() - delay2 >= 200){
      tone(buzzerPin, 500);
      delay1 = millis();
      delay3 = millis();
      delay4 = millis();
    }
    if(millis() - delay2 >= 400){
      noTone(buzzerPin);
      resetDelays();
    }
  }
  else if (distance < 25){
    if(millis() - delay3 >= 300){
      tone(buzzerPin, 500);
      delay1 = millis();
      delay2 = millis();
      delay4 = millis();
    }
    if(millis() - delay3 >= 600){
      noTone(buzzerPin);
      resetDelays();
    }
  }
  else if (distance < 50){
    if(millis() - delay4 >= 400){
      tone(buzzerPin, 500);
      delay1 = millis();
      delay2 = millis();
      delay3 = millis();
    }
    if(millis() - delay4 >= 800){
      noTone(buzzerPin);
      resetDelays();
    }
  }
  else{
    noTone(buzzerPin);
    resetDelays();
  }
}

void prePrint(int number){
  int nDigits = floor(log10(abs(number))) + 1;

  if(nDigits < 3){
    char stnum[2];
    itoa(number, stnum, 10);
    
    for(int i = 0; i < nDigits; i++){
      if(i == 0){
        digitalWrite(D1, HIGH);
        digitalWrite(D2, LOW);
      }
      else if(i == 1){
        digitalWrite(D1, LOW);
        digitalWrite(D2, HIGH);
      }
      
       print(stnum[i]);
       delay(1); // 10
  }
}
  else{
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
  }
}

void print(char number){
  if(number == '0'){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
  }
  else if(number == '1'){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if(number == '2'){
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if(number == '3'){
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if(number == '4'){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
  }
  else if(number == '5'){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if(number == '6'){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if(number == '7'){
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
  }
  else if(number == '8'){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if(number == '9'){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
}

void resetDelays(){
  delay1 = millis();
  delay2 = millis();
  delay3 = millis();
  delay4 = millis();
}
