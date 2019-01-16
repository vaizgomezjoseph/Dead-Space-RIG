int redpin = 8;
int greenpin = 10;
int bluepin = 9;

int piezoPin = 11;

int light_1 = 12;
int light_2 = 13;
int light_3 = 2;
int light_4 = 3;
int light_5 = 4;
int light_6 = 5;
int light_7 = 6;
int light_8 = 7;

int stat_1, stat_2, stat_3, stat_4, stat_5, stat_6, stat_7, stat_8 = 0;

int r, g, b = 0;

int cyan[3] = {0, 1, 1};
int green[3] = {0, 1, 0};
int yellow[3] = {1, 1, 0};
int red[3] = {1, 0, 0};

int value;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);

  pinMode(light_1, OUTPUT);
  pinMode(light_2, OUTPUT);
  pinMode(light_3, OUTPUT);
  pinMode(light_4, OUTPUT);
  pinMode(light_5, OUTPUT);
  pinMode(light_6, OUTPUT);
  pinMode(light_7, OUTPUT);
  pinMode(light_8, OUTPUT);

  Serial.begin(9600); // comment out later
}

// the loop routine runs over and over again forever:
void loop() {
  value = analogRead(A0);
  Serial.println(value); // comment out later
  switch((value-value%114)/114){
    case 0:
       r = cyan[0];
       g = cyan[1];
       b = cyan[2];

       stat_1 = 1;
       stat_2 = 1;
       stat_3 = 1;
       stat_4 = 1;
       stat_5 = 1;
       stat_6 = 1;
       stat_7 = 1;
       stat_8 = 1;

       break;
    case 1:
       r = cyan[0];
       g = cyan[1];
       b = cyan[2];

       stat_1 = 1;
       stat_2 = 1;
       stat_3 = 1;
       stat_4 = 1;
       stat_5 = 1;
       stat_6 = 1;
       stat_7 = 1;
       stat_8 = 0;

       break;
    case 2:
       r = green[0];
       g = green[1];
       b = green[2];

       stat_1 = 1;
       stat_2 = 1;
       stat_3 = 1;
       stat_4 = 1;
       stat_5 = 1;
       stat_6 = 1;
       stat_7 = 0;
       stat_8 = 0;

       break;
    case 3:
       r = green[0];
       g = green[1];
       b = green[2];

       stat_1 = 1;
       stat_2 = 1;
       stat_3 = 1;
       stat_4 = 1;
       stat_5 = 1;
       stat_6 = 0;
       stat_7 = 0;
       stat_8 = 0;

       break;
    case 4:
       r = yellow[0];
       g = yellow[1];
       b = yellow[2];

       stat_1 = 1;
       stat_2 = 1;
       stat_3 = 1;
       stat_4 = 1;
       stat_5 = 0;
       stat_6 = 0;
       stat_7 = 0;
       stat_8 = 0;

       break;
    case 5:
       r = yellow[0];
       g = yellow[1];
       b = yellow[2];

       stat_1 = 1;
       stat_2 = 1;
       stat_3 = 1;
       stat_4 = 0;
       stat_5 = 0;
       stat_6 = 0;
       stat_7 = 0;
       stat_8 = 0;

       break;
    case 6:
       r = red[0];
       g = red[1];
       b = red[2];

       stat_1 = 1;
       stat_2 = 1;
       stat_3 = 0;
       stat_4 = 0;
       stat_5 = 0;
       stat_6 = 0;
       stat_7 = 0;
       stat_8 = 0;

       break;
    case 7:
       r = red[0];
       g = red[1];
       b = red[2];

       stat_1 = 1;
       stat_2 = 0;
       stat_3 = 0;
       stat_4 = 0;
       stat_5 = 0;
       stat_6 = 0;
       stat_7 = 0;
       stat_8 = 0;

       break;
    case 8:
       r = 0;
       g = 0;
       b = 0;

       stat_1 = 0;
       stat_2 = 0;
       stat_3 = 0;
       stat_4 = 0;
       stat_5 = 0;
       stat_6 = 0;
       stat_7 = 0;
       stat_8 = 0;

       break;
    default:
       r = 0;
       g = 0;
       b = 0;
       break;
  }
  digitalWrite(light_1, stat_1);
  digitalWrite(light_2, stat_2);
  digitalWrite(light_3, stat_3);
  digitalWrite(light_4, stat_4);
  digitalWrite(light_5, stat_5);
  digitalWrite(light_6, stat_6);
  digitalWrite(light_7, stat_7);
  digitalWrite(light_8, stat_8);

  digitalWrite(redpin, r);
  digitalWrite(greenpin, g);
  digitalWrite(bluepin, b);

  //Blink lights in order to indicate that health is "critically low".
  if(stat_1 == 1 && stat_2 ==1 && stat_3 ==0 && stat_4 ==0 && stat_5 ==0 && stat_6 ==0 && stat_7 ==0 && stat_8 ==0){
    delay(1900);
    digitalWrite(redpin, 0);
    digitalWrite(greenpin, 0);
    digitalWrite(bluepin, 0);
    digitalWrite(light_1, LOW);
    digitalWrite(light_2, LOW);
    delay(750);
  }
  else if(stat_1 == 1 && stat_2 ==0 && stat_3 ==0 && stat_4 ==0 && stat_5 ==0 && stat_6 ==0 && stat_7 ==0 && stat_8 ==0){
    delay(500);
    digitalWrite(redpin, 0);
    digitalWrite(greenpin, 0);
    digitalWrite(bluepin, 0);
    digitalWrite(light_1, LOW);
    delay(500);
  }//emmit flatline tone to indicate wearer's demise
  else if(stat_1 == 0 && stat_2 ==0 && stat_3 ==0 && stat_4 ==0 && stat_5 ==0 && stat_6 ==0 && stat_7 ==0 && stat_8 ==0){
    tone(piezoPin, 1005, 50);
  }

  delay(10);
}

