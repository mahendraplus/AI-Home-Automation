/* *************************************************************************************\
   What is this? : HOME AUTOMATION AI HOME | Arduino Mega 2560 With ESP-01 (esp8266)
   Author  : Mahendraplus (m4u.yt)
   Version : v1.0.2
   Last-updated : 04/November/2021
   Blog    : m4u-yt.blogspot.com
  \**************************************************************************************/
/*----------------------------------------------------------------------------------------------------------------------------------------------*/
#define DEBUG false
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
void setup()
{
  /*BAZZER AND LCD ON START*/
  lcd.init(); lcd.clear(); lcd.backlight(); lcd.setCursor(0, 0); lcd.print("     M4U.YT"); lcd.setCursor(0, 1); lcd.print("");
  tone(12, 5000); delay(100);  noTone(12);  tone(12, 5500); delay(100);  noTone(12);  tone(12, 6000); delay(100);  noTone(12);
  tone(12, 6000); delay(100);  noTone(12);  tone(12, 5500); delay(100);  noTone(12);  tone(12, 5000); delay(100);  noTone(12);
  /*SERIAL CONFING*/
  Serial.begin(115200);
  Serial1.begin(115200);
  pinmode();
  /*SEND COMMNAD TO ESP-01*/
  Serial1.println("AT+RST"); delay(100);
  Serial1.println("AT+CWMODE=1"); delay(100);
  Serial1.println("AT+CWJAP=\"Your hotspot name\",\"your password\""); delay(100);
  Serial1.println("AT+CIFSR"); delay(100);
  Serial1.println("AT+CIPMUX=1"); delay(100);
  Serial1.println("AT+CIPSERVER=1,80"); delay(100);
  /*LCD PRINT , SERIAL PRINT AND BAZZER*/
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("ESP connected"); delay(500);
  lcd.clear();
  lcd.print("Ai ONLINE");


}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/
void loop()
{
lip();

         
}
//----------------------------------------------------------------------------------

void lip(){
   if (Serial1.available()) {
    if (Serial1.find("+IPD,")) {
      delay(100);
      int connectionId = Serial1.read() - 48;
      Serial1.find("pin=");
      int pinNumber = (Serial1.read() - 48) * 100;
      pinNumber += (Serial1.read() - 48) * 10;
      pinNumber += (Serial1.read() - 48);
      //-------------------------------------------------------------------------------------------//
      /*pwm pin*********    NOT FOR RELAY **********/
      beep();
      if (pinNumber == 814) {
        digitalWrite(2, HIGH);  // PIN 2 ON
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("2 ON"); 
      } if (pinNumber == 724) { 
        digitalWrite(2, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("2 OFF");
      }
      if (pinNumber == 914) {
        digitalWrite(3, HIGH);  // PIN 3
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("3 ON");
      } if (pinNumber == 824) {
        digitalWrite(3, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("3 OFF");
      }
      if (pinNumber == 1014) {
        digitalWrite(4, HIGH);  // PIN 4
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("4 ON");
      } if (pinNumber == 924) {
        digitalWrite(4, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("4 OFF");
      }
      if (pinNumber == 1114) {
        digitalWrite(5, HIGH);  // BLANK
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("5 ON");
      } if (pinNumber == 1024) {
        digitalWrite(5, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("5 OFF");
      }
      if (pinNumber == 1214) {
        digitalWrite(6, HIGH);  // BLANK
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("6 ON");
      } if (pinNumber == 1124) {
        digitalWrite(6, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("6 OFF");
      }
      if (pinNumber == 1314) {
        digitalWrite(7, HIGH);  // BLANK
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("7 ON");
      } if (pinNumber == 1224) {
        digitalWrite(7, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("7 OFF");
      }
      if (pinNumber == 1414) {
        digitalWrite(8, HIGH);  // BLANK
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("8 ON");
      } if (pinNumber == 1324) {
        digitalWrite(8, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("8 OFF");
      }
      if (pinNumber == 1514) {
        digitalWrite(9, HIGH);  // BLANK
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("9 ON");
      } if (pinNumber == 1424) {
        digitalWrite(9, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("9 OFF");
      }
      if (pinNumber == 163) {
        digitalWrite(10, HIGH);  // BLANK
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("10 ON");
      } if (pinNumber == 154) {
        digitalWrite(10, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("10 ON");
      }
      if (pinNumber == 173) {
        digitalWrite(11, HIGH);  // MY LED
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("11 ON");
      } if (pinNumber == 164) {
        digitalWrite(11, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("11 OFF");
      }
      if (pinNumber == 183) {  // BUZZER
        tone(12, 5000); 
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("12 ON"); 
        lcd.setCursor(0, 1);
        lcd.print("BUZZER 5K Freq");
      } if (pinNumber == 174) {
        noTone(12);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("12 OFF");
      }
      if (pinNumber == 193) {  // ARDUINO LED BUILD IN
        digitalWrite(13, HIGH);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("13 ON"); 
      } if (pinNumber == 184) {
        digitalWrite(13, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("13 OFF");
      }
      /***********   ONLY FOR RELAY *********/
      if (pinNumber == 283) {
        digitalWrite(22, HIGH);  // RELAY 01
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 01 ON");
      } if (pinNumber == 274) {
        digitalWrite(22, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 01 OFF");
      }
      if (pinNumber == 293) {
        digitalWrite(23, HIGH);  // RELAY 02
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 02 ON");

      } if (pinNumber == 284) {
        digitalWrite(23, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 02 OFF");
      }
      
      if (pinNumber == 303) {
        digitalWrite(24, HIGH);  // RELAY 03
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 03 ON");
      } if (pinNumber == 294) {
        digitalWrite(24, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 03 OFF");
      }
      
      if (pinNumber == 313) {
        digitalWrite(25, HIGH);  // RELAY 04
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 04 ON");
      } if (pinNumber == 304) {
        digitalWrite(25, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 04 OFF");
      }
      
      if (pinNumber == 323) {
        digitalWrite(26, HIGH);  // RELAY 05
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 05 ON");
      } if (pinNumber == 314) {
        digitalWrite(26, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 05 OFF");
      }
      
      if (pinNumber == 333) {
        digitalWrite(27, HIGH);  // RELAY 06
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 06 ON");
      } if (pinNumber == 324) {
        digitalWrite(27, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 06 OFF");
      }
      
      if (pinNumber == 343) {
        digitalWrite(28, HIGH);  // RELAY 07
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 07 ON");
      } if (pinNumber == 334) {
        digitalWrite(28, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 07 OFF");
      }
      
      if (pinNumber == 353) {
        digitalWrite(29, HIGH);  // RELAY 08
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 08 ON");
      } if (pinNumber == 344) {
        digitalWrite(29, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 08 OFF");
      }
      
      if (pinNumber == 363) {
        digitalWrite(30, HIGH);  // RELAY 09
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 09 ON");
      } if (pinNumber == 354) {
        digitalWrite(30, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 09 OFF");
      }
      if (pinNumber == 373) {
        digitalWrite(31, HIGH);  // RELAY 10
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 10 ON");
      } if (pinNumber == 364) {
        digitalWrite(31, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 10 OFF");
      }
      if (pinNumber == 383) {
        digitalWrite(32, HIGH);  // RELAY 11
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 11 ON");
      } if (pinNumber == 374) {
        digitalWrite(32, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 11 OFF");
      }
      if (pinNumber == 393) {
        digitalWrite(33, HIGH);  // RELAY 12
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 12 ON");
      } if (pinNumber == 384) {
        digitalWrite(33, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 12 OFF");
      }
      if (pinNumber == 403) {
        digitalWrite(34, HIGH);  // RELAY 13
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 13 ON");
      } if (pinNumber == 394) {
        digitalWrite(34, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 13 OFF");
      }
      if (pinNumber == 413) {
        digitalWrite(35, HIGH);  // RELAY 14
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 14 ON");
      } if (pinNumber == 404) {
        digitalWrite(35, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 14 OFF");
      }
      if (pinNumber == 423) {
        digitalWrite(36, HIGH);  // RELAY 15
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 15 ON");
      } if (pinNumber == 414) {
        digitalWrite(36, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 15 OFF");
      }
      if (pinNumber == 433) {
        digitalWrite(37, HIGH);  // RELAY 16
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 16 ON");
      } if (pinNumber == 424) {
        digitalWrite(37, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 16 OFF");
      }
      if (pinNumber == 443) {
        digitalWrite(38, HIGH);  // RELAY 17
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 17 ON");
      } if (pinNumber == 434) {
        digitalWrite(38, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 17 OFF");
      }
      if (pinNumber == 453) {
        digitalWrite(39, HIGH);  // RELAY 18
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 18 ON");
      } if (pinNumber == 444) {
        digitalWrite(39, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 18 OFF");
      }
      if (pinNumber == 463) {
        digitalWrite(40, HIGH);  // RELAY 19
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 19 ON");
      } if (pinNumber == 454) {
        digitalWrite(40, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 19 OFF");
      }
      if (pinNumber == 473) {
        digitalWrite(41, HIGH);  // RELAY 20
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 20 ON");
      } if (pinNumber == 464) {
        digitalWrite(41, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 20 OFF");
      }
      if (pinNumber == 483) {
        digitalWrite(42, HIGH);  // RELAY 21
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 21 ON");
      } if (pinNumber == 474) {
        digitalWrite(42, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 21 OFF");
      }
      if (pinNumber == 493) {
        digitalWrite(43, HIGH);  // RELAY 22
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 22 ON");
      } if (pinNumber == 484) {
        digitalWrite(43, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 22 OFF");
      }
      if (pinNumber == 503) {
        digitalWrite(44, HIGH);  // RELAY 23
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 23 ON");
      } if (pinNumber == 494) {
        digitalWrite(44, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 23 OFF");
      }
      if (pinNumber == 513) {
        digitalWrite(45, HIGH);  // RELAY 24
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 24 ON");
      } if (pinNumber == 504) {
        digitalWrite(45, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 24 OFF");
      }
      if (pinNumber == 524) {
        digitalWrite(46, HIGH);  // RELAY 25
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 25 ON");
      } if (pinNumber == 514) {
        digitalWrite(46, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 25 OFF");
      }
      if (pinNumber == 534) {
        digitalWrite(47, HIGH);  // RELAY 26
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 26 ON");
      } if (pinNumber == 524) {
        digitalWrite(47, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 26 OFF");
      }
      if (pinNumber == 543) {
        digitalWrite(48, HIGH);  // RELAY 27
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 27 ON");
      } if (pinNumber == 534) {
        digitalWrite(48, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 27 OFF");
      }
      if (pinNumber == 553) {
        digitalWrite(49, HIGH);  // RELAY 28
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 28 ON");
      } if (pinNumber == 544) {
        digitalWrite(49, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 28 OFF");
      }
      if (pinNumber == 563) {
        digitalWrite(50, HIGH);  // RELAY 29
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 29 ON");
      } if (pinNumber == 554) {
        digitalWrite(50, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 29 OFF");
      }
      if (pinNumber == 573) {
        digitalWrite(51, HIGH);  // RELAY 30
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 30 ON");
      } if (pinNumber == 564) {
        digitalWrite(51, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 30 OFF");
      }
      if (pinNumber == 583) {
        digitalWrite(52, HIGH);  // RELAY 31
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 31 ON");
      } if (pinNumber == 574) {
        digitalWrite(52, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 31 OFF");
      }
      if (pinNumber == 593) {
        digitalWrite(53, HIGH);  // RELAY 32
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 32 ON");
      } if (pinNumber == 584) {
        digitalWrite(53, LOW);
        lcd.init();
        lcd.clear();
        lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("RELAY 32 OFF");
      }
      //-------------------------------------------------------------------------------------------//

      //---->response
      String webpage = String(pinNumber);
      String cipSend = "AT+CIPSEND=";
      cipSend += connectionId;
      cipSend += ",";
      cipSend += webpage.length();
      cipSend += "\r\n";
      sendData(cipSend, 100, DEBUG);
      sendData(webpage, 100, DEBUG);
      String closeCommand = "AT+CIPCLOSE=";
      closeCommand += connectionId;
      closeCommand += "\r\n";
      sendData(closeCommand, 100, DEBUG);
    }
  }
}
//--------------------------FUNCTION---------------------------------//
/****SEND DATA***/
String sendData(String command, const int timeout, boolean debug)
{
  String response = "";
  Serial1.print(command);
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (Serial1.available())
    {
      char c = Serial1.read();
      response += c;
    }
  }
  if (debug)
  {
    Serial.print(response);
  }
  return response;
}

/*DIGITAL OUTPIN*/
void pinmode()
{
  // PWM pin ****************************
  pinMode(2, OUTPUT); digitalWrite(2, LOW);
  pinMode(3, OUTPUT); digitalWrite(3, LOW);
  pinMode(4, OUTPUT); digitalWrite(4, LOW);
  pinMode(5, OUTPUT); digitalWrite(5, LOW);
  pinMode(6, OUTPUT); digitalWrite(6, LOW);
  pinMode(7, OUTPUT); digitalWrite(7, LOW);
  pinMode(8, OUTPUT); digitalWrite(8, LOW);
  pinMode(9, OUTPUT); digitalWrite(9, LOW);
  pinMode(10, OUTPUT); digitalWrite(10, LOW);
  pinMode(11, OUTPUT); digitalWrite(11, LOW);
  pinMode(12, OUTPUT); digitalWrite(12, LOW);
  pinMode(13, OUTPUT); digitalWrite(13, LOW);
  //14 to 21 is RX TX
  //digital pin******************************
  pinMode(22, OUTPUT); digitalWrite(22, LOW);
  pinMode(23, OUTPUT); digitalWrite(23, LOW);
  pinMode(24, OUTPUT); digitalWrite(24, LOW);
  pinMode(25, OUTPUT); digitalWrite(25, LOW);
  pinMode(26, OUTPUT); digitalWrite(26, LOW);
  pinMode(27, OUTPUT); digitalWrite(27, LOW);
  pinMode(28, OUTPUT); digitalWrite(28, LOW);
  pinMode(29, OUTPUT); digitalWrite(29, LOW);
  pinMode(30, OUTPUT); digitalWrite(30, LOW);
  pinMode(31, OUTPUT); digitalWrite(31, LOW);
  pinMode(32, OUTPUT); digitalWrite(32, LOW);
  pinMode(33, OUTPUT); digitalWrite(33, LOW);
  pinMode(34, OUTPUT); digitalWrite(34, LOW);
  pinMode(35, OUTPUT); digitalWrite(35, LOW);
  pinMode(36, OUTPUT); digitalWrite(36, LOW);
  pinMode(37, OUTPUT); digitalWrite(37, LOW);
  pinMode(38, OUTPUT); digitalWrite(38, LOW);
  pinMode(39, OUTPUT); digitalWrite(39, LOW);
  pinMode(40, OUTPUT); digitalWrite(40, LOW);
  pinMode(41, OUTPUT); digitalWrite(41, LOW);
  pinMode(42, OUTPUT); digitalWrite(42, LOW);
  pinMode(43, OUTPUT); digitalWrite(43, LOW);
  pinMode(44, OUTPUT); digitalWrite(44, LOW);
  pinMode(45, OUTPUT); digitalWrite(45, LOW);
  pinMode(46, OUTPUT); digitalWrite(46, LOW);
  pinMode(47, OUTPUT); digitalWrite(47, LOW);
  pinMode(48, OUTPUT); digitalWrite(48, LOW);
  pinMode(49, OUTPUT); digitalWrite(49, LOW);
  pinMode(50, OUTPUT); digitalWrite(50, LOW);
  pinMode(51, OUTPUT); digitalWrite(51, LOW);
  pinMode(52, OUTPUT); digitalWrite(52, LOW);
  pinMode(53, OUTPUT); digitalWrite(53, LOW);
}

// beep
void beep()
{
  tone(12, 5000); delay(100);  noTone(12);
}
