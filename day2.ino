int Buzzer_Pin = 9;
int LDR1_Pin = A0;
int LDR2_Pin = A1;
int People_Inside = 0;
int space = 0;
int enter = 0;
int quit = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(Buzzer_Pin,OUTPUT);
pinMode(LDR1_Pin,INPUT);
pinMode(LDR2_Pin,INPUT);
Serial.begin(9600);
}


void loop() {
  
  // put your main code here, to run repeatedly:
 int LDR1_sensor = analogRead(LDR1_Pin);
 int LDR2_sensor = analogRead(LDR2_Pin);

// Print Number of Persons at room
Serial.println( People_Inside);


  //  Enter The room
if (space > 0) {
    if ( LDR1_sensor <= 300 && LDR2_sensor > 300 && enter == 0) {
     enter++;
    }
}

if (LDR2_sensor <= 300 && LDR1_sensor > 300 && enter > 0) { 
    People_Inside++;
    quit = 0;
    enter = 0;
    space=0;
  }
  
 // Space from one man to other
if (LDR2_sensor > 300 && LDR1_sensor > 300) {
  space++;
}

  // Exit The room
if (space > 0) {
    if ( LDR2_sensor <= 300 && LDR1_sensor > 300  && enter == 0) {
      quit++; 
      }
}
if (LDR1_sensor <= 300 && LDR2_sensor > 300 && quit > 0) { 
    People_Inside--;
    enter =0;
    quit = 0;
    space=0;
  }


  // There isn't People in the Room
if (People_Inside < 0) {
  People_Inside = 0;
}
 // The Max Number of People at room is 5
if (People_Inside > 5) {
  People_Inside = 5;
}


// If People at room equal 5 The buzzer will open
if (People_Inside == 5 || People_Inside > 5) {
analogWrite(Buzzer_Pin,HIGH);
} else {
 analogWrite(Buzzer_Pin,LOW);

}


}
