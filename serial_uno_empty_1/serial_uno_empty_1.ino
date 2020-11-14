float A = 5.500;
float B = 1.200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  double C = A * B;
  Serial.println(C);
  delay(3000);
}
