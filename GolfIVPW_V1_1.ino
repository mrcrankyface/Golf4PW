
//KONTROLLERA INPUT PINS ... Dessa stämmer troligtvis
//Input pins:
int DriverFL = A0;
int DriverFR = A1;
int DriverRL = A2;
int DriverRR = A3;
int DriverUnlock = A4;
int DriverBlock = A5;

//KONTROLLERA INPUT PINS ... Troligtvis 2-7
int FrontRightUp = 2;
int FrontRightDown = 3;
int RearLeftUp = 4;
int RearLeftDown = 5;
int RearRightUp = 6;
int RearRightDown = 7;

//KONTROLLERA OUTPUT PINS ... Troligtvis 14-21
int FLOut1 = 21;
int FLOut2 = 20;
int FROut1 = 19;
int FROut2 = 18;
int RLOut1 = 17;
int RLOut2 = 16;
int RROut1 = 15;
int RROut2 = 14;

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
  pinMode(FLOut1, OUTPUT);
  pinMode(FLOut2, OUTPUT);
  pinMode(FROut1, OUTPUT);
  pinMode(FROut2, OUTPUT);
  pinMode(RLOut1, OUTPUT);
  pinMode(RLOut2, OUTPUT);
  pinMode(RROut1, OUTPUT);
  pinMode(RROut2, OUTPUT);
}

void loop() {
  // Reading and storing button values
  int DriverFL_val = analogRead(DriverFL); // Front left door window
  int DriverFR_val = analogRead(DriverFR); // Front right door window
  int DriverRL_val = analogRead(DriverRL); // Rear left door window
  int DriverRR_val = analogRead(DriverRR); // Rear right door window
  int DriverUnlock_val = analogRead(DriverUnlock); // Lock/unlock
  int DriverBlock_val = analogRead(DriverBlock); // Blocking of rear window buttons

  int DriverFL_LastState = 1500; // Front left door window
  int DriverFR_LastState = 1500; // Front right door window
  int DriverRL_LastState = 1500; // Rear left door window
  int DriverRR_LastState = 1500; // Rear right door window
  int DriverUnlock_LastState = 1500; // Lock/unlock
  int DriverBlock_LastState = 1500; // Blocking of rear window buttons

  int FrontRightUp_val = digitalRead(FrontRightUp);
  int FrontRightDown_val = digitalRead(FrontRightDown);
  int RearLeftUp_val = digitalRead(RearLeftUp);
  int RearLeftDown_val = digitalRead(RearLeftDown);
  int RearRightUp_val = digitalRead(RearRightUp);
  int RearRightDown_val = digitalRead(RearRightDown);
  
  int FrontRightUp_LastState = 1500;
  int FrontRightDown_LastState = 1500;
  int RearLeftUp_LastState = 1500;
  int RearLeftDown_LastState = 1500;
  int RearRightUp_LastState = 1500;
  int RearRightDown_LastState = 1500;

  //Controlling wether to debug signals
  int DriverDoorReadout = 1;
  int FrontRightReadout = 0;
  int RearLeftReadout = 0;
  int RearRightReadout = 0;
  int DriverUnlockReadout = 0;
  int DriverBlockReadout = 0;
  int ReadoutDelay = 1000;

  //Controlling wether to power windows
  int PowerWindows = 0;

  if(DriverDoorReadout == 1){
    Serial.print("DriverFL: ");
    Serial.println(DriverFL_val);
    Serial.print("DriverFR: ");
    Serial.println(DriverFR_val);
    Serial.print("DriverRL: ");
    Serial.println(DriverRL_val);
    Serial.print("DriverRR: ");
    Serial.println(DriverRR_val);
    delay(ReadoutDelay);
    delay(ReadoutDelay);
  }

  if(FrontRightReadout == 1){
    Serial.print("FrontRightUp: ");
    Serial.print(FrontRightUp_val);
    Serial.print(", FrontRightDown: ");
    Serial.println(FrontRightDown_val);
    delay(ReadoutDelay);
  }

  if(RearLeftReadout == 1){
    Serial.print("RearLeftUp: ");
    Serial.print(RearLeftUp_val);
    Serial.print(", RearLeftDown: ");
    Serial.println(RearLeftDown_val);
    delay(ReadoutDelay);
  }

  if(RearRightReadout == 1){
    Serial.print("RearRightUp: ");
    Serial.print(RearRightUp_val);
    Serial.print(", RearRightDown: ");
    Serial.println(RearRightDown_val);
    delay(ReadoutDelay);
  }

  if(DriverUnlockReadout == 1){
    if(DriverUnlock_LastState == 1500){
      Serial.print("DriverUnlock: ");
      Serial.println(DriverUnlock_val);
      DriverUnlock_LastState = DriverUnlock_val;
    }
    if(DriverUnlock_val != DriverUnlock_LastState)
    Serial.print("DriverUnlock: ");
    Serial.println(DriverUnlock_val);
    DriverUnlock_LastState = DriverUnlock_val;
    delay(ReadoutDelay);
  }

  if(DriverBlockReadout == 1){
    if(DriverBlock_LastState == 1500){
      Serial.print("DriverBlock: ");
      Serial.println(DriverBlock_val);
      DriverBlock_LastState = DriverBlock_val;
    }
    if(DriverBlock_val != DriverBlock_LastState)
    Serial.print("DriverBlock: ");
    Serial.println(DriverBlock_val);
    DriverBlock_LastState = DriverBlock_val;
    delay(ReadoutDelay);
  }


  if(PowerWindows == 1){
    //Activate front left window -----------------------------
    if(DriverFL_val < 1000){ //Check if anything wants to activate FL window
      if(DriverFL_val < 300){ //Window down
        digitalWrite(FLOut1, HIGH);
        digitalWrite(FLOut2, LOW);
      }
      if(DriverFL_val > 300 && DriverFL_val < 950){ //Window up
        digitalWrite(FLOut1, LOW);
        digitalWrite(FLOut2, HIGH);
      }
    }
    //Deactivate front left window
    if(DriverFL_val > 1000){ //Turn off motor driver if button is not pushed
    digitalWrite(FLOut1, LOW);
    digitalWrite(FLOut2, LOW);
    }

    //Activate front right window -----------------------------
    if(DriverFR_val < 1000 || FrontRightUp_val == 1 || FrontRightDown_val == 1){ //Check if anythings wants to activate FR window
      if(DriverFR_val < 300 || FrontRightDown_val == 1){ //Window down
        digitalWrite(FROut1, HIGH);
        digitalWrite(FROut2, LOW);
      }
      if(DriverFR_val > 300 && DriverFR_val < 950 || FrontRightUp_val == 1){ //Window up
        digitalWrite(FROut1, LOW);
        digitalWrite(FROut2, HIGH);
      }
    }
    //Deactivate front right window
    if(DriverFR_val > 1000 && FrontRightUp_val == 0 && FrontRightDown_val == 0){ //Turn off motor driver if button is not pushed
      digitalWrite(FROut1, LOW);
      digitalWrite(FROut2, LOW);
    }

    //Activate rear left window -----------------------------
    if(DriverRL_val < 1000 || RearLeftUp_val == 1 || RearLeftDown_val == 1){ //Check if anythings wants to activate RL window
      if(DriverRL_val < 300 || RearLeftDown_val == 1){ //Window down
        digitalWrite(RLOut1, HIGH);
        digitalWrite(RLOut2, LOW);
      }
      if(DriverRL_val > 600 && DriverRL_val < 950 || RearLeftUp_val == 1){ //Window up
        digitalWrite(RLOut1, LOW);
        digitalWrite(RLOut2, HIGH);
      }
    }
    //Deactivate rear left window
    if(DriverRL_val > 1000 && RearLeftUp_val == 0 && RearLeftDown_val == 0){ //Turn off motor driver if button is not pushed
      digitalWrite(RLOut1, LOW);
      digitalWrite(RLOut2, LOW);
    }

    //Activate rear left window -----------------------------
    if(DriverRR_val < 1000 || RearRightUp_val == 1 || RearRightDown_val == 1){ //Check if anythings wants to activate RR window
      if(DriverRR_val < 300 || RearRightDown_val == 1){ //Window down
        digitalWrite(RROut1, HIGH);
        digitalWrite(RROut2, LOW);
      }
      if(DriverRR_val > 600 && DriverRR_val < 950 || RearRightUp_val == 1){ //Window up
        digitalWrite(RROut1, LOW);
        digitalWrite(RROut2, HIGH);
      }
    }
    //Deactivate rear right window
    if(DriverRR_val > 1000 && RearRightUp_val == 0 && RearRightDown_val == 0){ //Turn off motor driver if button is not pushed
      digitalWrite(RROut1, LOW);
      digitalWrite(RROut2, LOW);
    }

    /*Features to add
    - Unlock button raises/lowers all windows
    - Current sensing/limits
    - Auto raise/lower until current limit
    - Rear blocking of buttons    
    */
    
  }
}
