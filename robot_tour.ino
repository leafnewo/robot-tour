// motor
int motorrightpin1 = 22;
int motorrightpin2 = 23;
int motorleftpin1 = 24;
int motorleftpin2 = 25;
int Wall = 15;
// distanceSensors
const int trigPinL = 52;
const int echoPinL = 53;
const int trigPinM = 50;
const int echoPinM = 51;
const int trigPinR = 27;
const int echoPinR = 26;
long duration;
int distance = 100;
// colorSensor
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
void setup() {
  // motor
  pinMode(motorrightpin1, OUTPUT);
  pinMode(motorrightpin2, OUTPUT);
  pinMode(motorleftpin1, OUTPUT);
  pinMode(motorleftpin2, OUTPUT);
  // DistanceSensors
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
  pinMode(trigPinM, OUTPUT);
  pinMode(echoPinM, INPUT);
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);
  Serial.begin(9600);
}
void StartMotors() {
  digitalWrite(motorrightpin1, LOW);
  digitalWrite(motorrightpin2, HIGH);
  digitalWrite(motorleftpin1, LOW);
  digitalWrite(motorleftpin2, HIGH);
  
}
void StopMotor() {
  digitalWrite(motorrightpin1, LOW);
  digitalWrite(motorrightpin2, LOW);
  digitalWrite(motorleftpin1, LOW);
  digitalWrite(motorleftpin2, LOW);
  delay(1000);
}
void LeftTurn(int Sec) {
  digitalWrite(motorrightpin1, LOW);
  digitalWrite(motorrightpin2, HIGH);
  digitalWrite(motorleftpin1, HIGH);
  digitalWrite(motorleftpin2, LOW);
  delay(Sec);
}
void RightTurn(int Sec) {
  digitalWrite(motorrightpin1, HIGH);
  digitalWrite(motorrightpin2, LOW);
  digitalWrite(motorleftpin1, LOW);
  digitalWrite(motorleftpin2, HIGH);
  delay(Sec);
}
void StraightEc(int dist) {
  StartMotors();
  delay(1000);
  distance = 1000;
  while (distance > dist) {
    Serial.println(distance);
    digitalWrite(trigPinM, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinM, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinM, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinM, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
}
void BlueOne() {
  StraightEc(Wall);
  // turn
  LeftTurn(3000);
  // straight
  StartMotors();
  distance = 0;
  while (distance < 35) {
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinR, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  RightTurn(1800);
  StraightEc(Wall);
  RightTurn(2200);
  StraightEc(Wall);
  LeftTurn(1600);
  StraightEc(Wall);
  // stop
  StopMotor();
}
void BlueOne1 (){
  LeftTurn(1600);
  distance = 0;
  while (distance < 35) {
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinR, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  RightTurn(2000);
  StartMotors();
  delay(2000);
  RightTurn(2000);
  StraightEc(Wall);
  LeftTurn(3200);
  StartMotors();
  distance = 0;
  while (distance < 35) {
    digitalWrite(trigPinL, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinL, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  LeftTurn(1600);
  StraightEc(Wall);
  LeftTurn(1600);
  distance = 100;
  StartMotors();
  while (distance > 40) {
    digitalWrite(trigPinL, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinL, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; 
  }
  delay(1500);
  LeftTurn(1600);
  StopMotor();
}
void BlueTwo() {
  RightTurn(2000);
  StartMotors();
  distance = 0;
  while (distance < 100) {
    digitalWrite(trigPinL, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinL, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  StopMotor();
}
void BlueTwo1 (){
  LeftTurn(1600);
  StartMotors();
  distance = 0;
  while (distance < 100) {
    digitalWrite(trigPinL, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinL, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  distance = 100;
  LeftTurn(3200);
  StraightEc(Wall);
  LeftTurn(1600);
  StopMotor();
}
void BlueThree() {
  StartMotors();
  distance = 0;
  while (distance < 60) {
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinR, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  StopMotor();
}
void BlueThree1() {
  LeftTurn(1600);
  StartMotors();
  distance = 100;
  while (distance > 40) {
    digitalWrite(trigPinL, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinL, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  LeftTurn(3200);
  StartMotors();
  distance = 0;
  while (distance < 70) {
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinR, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  LeftTurn(1600);
  StopMotor();
}
void BlueFour() {
  RightTurn(2000);
  StraightEc(Wall);
  LeftTurn(1600);
  StraightEc(Wall);
  LeftTurn(1600);
  StartMotors();
  distance = 0;
  while (distance < 70) {
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinR, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  StopMotor();
}
void BlueFour1() {
  LeftTurn(1600);
  StartMotors();
  distance = 100;
  while (distance > 40) {
    digitalWrite(trigPinL, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinL, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  LeftTurn(3200);
  StartMotors();
  distance = 0;
  while (distance < 60) {
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinR, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  LeftTurn(1600);
  StopMotor();
}
void BlueStart() {
  RightTurn(2000);
  StartMotors();
  distance = 100;
  while (distance > 40) {
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinR, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  }
  delay(1500);
  RightTurn(2000);
  StopMotor();
}
void loop() {
  delay(1000);
  while (distance > 2) {
    digitalWrite(trigPinM, LOW);
    delayMicroseconds(21);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinM, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinM, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPinM, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
  }
  distance = 100;
  BlueOne();
}
