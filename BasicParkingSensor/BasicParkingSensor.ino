

const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;



void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  //Trigger the sensor
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  long time = pulseIn(echoPin, HIGH);
  int distance = time * 0.034 / 2;

  // start buzzer with respect to distance
  if (distance > 0 && distance <= 30) {
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);

    int waitingTime = map(distance, 2, 30, 50, 500);
    delay(waitingTime);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}
