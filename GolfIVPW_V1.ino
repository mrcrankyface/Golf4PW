
//Input pins:
int DriverFL = A0;
int DriverFR = A1;
int DriverRL = A2;
int DriverRR = A3;
int FrontRightUp = 20;
int FrontRightDown = 22;
int RearLeftUp = 24;
int RearLeftDown = 26;
int RearRightUp = 28;
int RearRightDown = 30;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Inputs from window buttons
  pinMode(FrontRightUp, INPUT);
  pinMode(FrontRightDown, INPUT);
  pinMode(RearLeftUp, INPUT);
  pinMode(RearLeftDown, INPUT);
  pinMode(RearRightUp, INPUT);
  pinMode(RearRightDown, INPUT);
  // Outputs to motor drivers:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // Reading and storing button values
int DriverFL_val = analogRead(DriverFL); // Front left door window
int DriverFR_val = analogRead(DriverFR); // Front right door window
int DriverRL_val = analogRead(DriverRL); // Rear left door window
int DriverRR_val = analogRead(DriverRR); // Rear right door window
int FrontRightUp_val = digitalRead(FrontRightUp);
int FrontRightDown_val = digitalRead(FrontRightDown);
int RearLeftUp_val = digitalRead(RearLeftUp);
int RearLeftDown_val = digitalRead(RearLeftDown);
int RearRightUp_val = digitalRead(RearRightUp);
int RearRightDown_val = digitalRead(RearRightDown);

 //Controlling wether to debug signals
int DriverDoorReadout = 0;
int FrontRightReadout = 0;
int RearLeftReadout = 0;
int RearRightReadout = 0;

if(DriverDoorReadout == 1){
  Serial.print("DriverFL: ");
  Serial.println(DriverFL_val);
  Serial.print("DriverFR: ");
  Serial.println(DriverFR_val);
  Serial.print("DriverRL: ");
  Serial.println(DriverRL_val);
  Serial.print("DriverRR: ");
  Serial.println(DriverRR_val);
  delay(2500);
}

if(FrontRightReadout == 1){
  Serial.print("FrontRightUp: ");
  Serial.print(FrontRightUp_val);
  Serial.print(", FrontRightDown: ");
  Serial.println(FrontRightDown_val);
  delay(2500);
}

if(RearLeftReadout == 1){
  Serial.print("RearLeftUp: ");
  Serial.print(RearLeftUp_val);
  Serial.print(", RearLeftDown: ");
  Serial.println(RearLeftDown_val);
  delay(2500);
}

if(RearRightReadout == 1){
  Serial.print("RearRightUp: ");
  Serial.print(RearRightUp_val);
  Serial.print(", RearRightDown: ");
  Serial.println(RearRightDown_val);
  delay(2500);
}


/*if(A6_val < 5){
Serial.println("Unlocking car");
delay(750);
}
if(A6_val > 130 && A6_val < 180){
Serial.println("Locking car");
delay(750);
}

if(A7_val < 30 && a7block == 0){
Serial.println("Blocking rear window controls");
a7block = 1;
delay(750);
}
if(A7_val > 1000 && a7block == 1){
Serial.println("Unblocking rear window controls");
a7block = 0;
delay(750);
}
*/

if(DriverFL_val < 1000){
  delay(100);
  DriverFL_val = analogRead(DriverFL); // Driver door window
  while(DriverFL_val < 300){
    Serial.println("1L Lowering front left window");
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(150);
    DriverFL_val = analogRead(DriverFL); // Driver door window
  }
  while(DriverFL_val > 300 && DriverFL_val < 950){
    Serial.println("1R Raising front left window");
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(150);
    DriverFL_val = analogRead(DriverFL); // Driver door window
  }
}
if(DriverFL_val > 1000){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
}

/*
if(A13_val < 1000){
  delay(50);
  A13_val = analogRead(A13); // front right door window
  while(A13_val < 95){
    Serial.println("2L Lowering front right window");
    delay(500);
    A13_val = analogRead(A13); // front right door window
  }
  while(A13_val > 95 && A13_val < 600){
    Serial.println("2R Raising front right window");
    delay(500);
    A13_val = analogRead(A13); // front right door window
  }
}

if(A14_val < 1000){
  delay(50);
  A14_val = analogRead(A14); // Rear left door window
  while(A14_val < 100){
    Serial.println("3L Lowering rear left window");
    delay(500);
    A14_val = analogRead(A14); // Rear right door window
  }
  while(A14_val > 100 && A14_val < 600){
    Serial.println("3R Raising rear left window");
    delay(500);
    A14_val = analogRead(A14); // Rear right door window
  }
}
*/

if(DriverRR_val < 1000){
  delay(50);
  DriverRR_val = analogRead(DriverRR); // Rear right door window
  while(DriverRR_val < 125){
    Serial.println("4L Lowering rear right window");
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    delay(50);
    DriverRR_val = analogRead(DriverRR); // Rear right door window
  }
  while(DriverRR_val > 800 && DriverRR_val < 950){
    Serial.println("4R Raising rear right window");
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delay(50);
    DriverRR_val = analogRead(DriverRR); // Rear right door window
  }
}

if(DriverRR_val > 1000){
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
}

}
