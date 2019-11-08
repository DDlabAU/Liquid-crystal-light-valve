

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(A0, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  
  // read the input on analog pin 3:
  int sensorValue = analogRead(A3);

  //Printer sensorværdien i serial monitoren
  Serial.println(sensorValue);

  //Min og max værdier som sensoren giver, skal registreres nedenfor, værdierne ændrer sig efter hvor meget lys der er
  //sensorValue = constrain(sensorValue, x_min, x_max);

  sensorValue = constrain(sensorValue, 730, 1023);

  // LCD værdien bliver mappet over sensor værdien
  int lcdvalue = map(sensorValue, 1023, 730, 0, 255);

  // Den mappede værdi bliver så sendt ud som værdi til skærmen, som ændrer sig alt efter hvodan man påvirker photocell'en
  analogWrite(A0, lcdvalue);
}
