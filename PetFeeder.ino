#include <util/delay.h>
#include <LiquidCrystal.h>
#include <IRremote.h>
#include <Servo.h> 

//Coduri IR-Remote
#define R1 0xFFA25D
#define R2 0xFF629D
#define R3 0xFFE21D
#define R4 0xFF22DD
#define R5 0xFF02FD
#define R6 0xFFC23D
#define R7 0xFFE01F
#define R8 0xFFA857
#define R9 0xFF906F
#define R0 0xFF9867
#define R_star 0xFF6897
#define R_hash 0xFFB04F
#define R_OK 0xFF38C7
#define R_UP 0xFF18E7
#define R_DOWN 0xFF4AB5
#define R_LEFT 0xFF10EF
#define R_RIGHT 0xFF5AA5

int receiver = 3;
IRrecv irrecv(receiver); 
decode_results results;

LiquidCrystal lcd(A0, A1, A2, 8, 7, 6);
const int backlight = 13;
volatile boolean backlight_on;
int counter = 0;

volatile int secunda = 0;
volatile int secundaCounter = 0;
volatile int minut = 0;
volatile int ora = 0;
volatile int period_min = 0;

Servo myservo; 
int val;
bool cwRotation, ccwRotation;

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  irrecv.enableIRIn();
  myservo.attach(5);

  pinMode(backlight, OUTPUT);
  digitalWrite(backlight, HIGH);
  backlight_on = true;
  irrecv.enableIRIn();

  lcd.begin(16, 2);
   lcd.clear();
}

void loop() {
  myservo.write(0);
  switch (counter){
        case 0:{
          meniuPrincipal();
        }
        
        case 1:{
          if(period_min == 0 && counter == 1){
            lcd.setCursor(0,0);
            lcd.print("Period: ");
            lcd.setCursor(8,0);
            lcd.print("min");
            setPeriodMin();
            secunda = 0;
            secundaCounter = 0;
                
         }
          else if (period_min != 0 && counter == 1) {
           myservo.write(0);
           lcd.setCursor(0, 1);
           if (ora<10) lcd.print("0");
           lcd.print(ora);
           lcd.setCursor(2,1);
           lcd.print(":");
           if (minut<10) lcd.print("0");
           lcd.print(minut);
           lcd.setCursor(5,1);
           lcd.print(":");
           if (secunda<10) lcd.print("0");
           lcd.print(secunda);
           lcd.print(" ");
           
           lcd.setCursor(0, 0);
           lcd.print("Every:");
           lcd.setCursor(7,0);
           lcd.print(period_min);
           lcd.setCursor(9,0);
           lcd.print("min");
        
          if (secundaCounter > period_min * 60){ //60min * 60 sec = 3600 sec
              myservo.write(175);
              secundaCounter = 0;
          }

          if (irrecv.decode(&results)) {
            Serial.println(results.value, HEX);
            irrecv.resume(); // Receive the next value
        
            if (results.value == R_LEFT || results.value == R_star){
              lcd.clear();
              period_min = 0;
              irrecv.resume();
              counter  = 0; 
              
            }
          }
          
          secunda++;
          secundaCounter++;
          if (secunda == 60)
           {
             secunda = 0;
             minut++;
             if (minut>=60)
             {
               minut = 0;
               ora ++;
               if (ora >= 24)
               {
                 ora = 0;
               }
             }
           }
            delay(1000);
          }
        }
        
        case 2:{
         controlRemote();
        }

        case 3:{
          
          break;
        }
        default:  break;
  }
      delay(10);
}


void meniuPrincipal(){
      lcd.setCursor(0,0);
      lcd.print("Welcome!");
      lcd.setCursor(0,1);
      lcd.print("Press 1 or 2");
    if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

    switch(results.value){
      case R1:{
        lcd.clear();
        counter = 1;
        break;
      }
      case R2:{
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Remote control!");
        lcd.setCursor(0,1);
        lcd.print("Press 'OK'");
        counter = 2;
        break;
      }
      default: break;
    }
  }
}

void controlRemote(){
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

    if (results.value == R_OK)
    {
      myservo.write(175);
      delay(250); 
      myservo.write(0);
    }

    else if (results.value == R_star || results.value == R_LEFT) {
      counter = 0;
      lcd.clear();
    }
    else irrecv.resume();
}

}

void setPeriodMin(){
 // while(1){
    if (irrecv.decode(&results)) {
      Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

        switch(results.value){
         case R1:{
          period_min = 1;
          lcd.clear();  
          break;
         }
         case R2:{
          period_min = 2;
          lcd.clear();  
          break;
         }
         case R3:{
          period_min = 3;
          lcd.clear();  
          break;
         }
         case R4:{
          period_min = 4;
          lcd.clear();
          break;
         }

         case R5:{
          period_min = 5;
          lcd.clear();
          break;
         }

         case R6:{
          period_min = 6;
          lcd.clear();
          break;
         }

         case R7:{
          period_min = 7;
          lcd.clear();
          break;
         }

          case R8:{
          period_min = 8;
          lcd.clear();
          break;
         }

        case R9:{
          period_min = 9;
          lcd.clear();
          break;
         }

         
         default:{
         
         } 
  }
 }
}
