// include the library code:
#include <LiquidCrystal.h>
#include "Wire.h"
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define DS1307_ADDRESS 0x68
#include "DHT.h"
#include <SPI.h>
#include <SD.h>
#include <WiFi.h>


char ssid[] = "yourNetwork";      // your network SSID (name)
char pass[] = "secretPassword";   // your network password
int keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

WiFiServer server(80);

/*
  SD card read

 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 */

File myFile;
int sdData[100],dataCount = 0,sdPara[10];

#define DHTPIN 5     // what pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302)

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

byte zero = 0x00; //workaround for issue #527

#define ONE_WIRE_BUS 6
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/************************Hardware Related Macros************************************/
#define         MG_PIN                       (1)     //define which analog input channel you are going to use
#define         BOOL_PIN                     (2)
#define         DC_GAIN                      (8.5)   //define the DC gain of amplifier


/***********************Software Related Macros************************************/
#define         READ_SAMPLE_INTERVAL         (50)    //define how many samples you are going to take in normal operation
#define         READ_SAMPLE_TIMES            (5)     //define the time interval(in milisecond) between each samples in 
                                                     //normal operation

/**********************Application Related Macros**********************************/
//These two values differ from sensor to sensor. user should derermine this value.
#define         ZERO_POINT_VOLTAGE           (0.220) //define the output of the sensor in volts when the concentration of CO2 is 400PPM
#define         REACTION_VOLTGAE             (0.020) //define the voltage drop of the sensor when move the sensor from air into 1000ppm CO2

/*****************************Globals***********************************************/
float           CO2Curve[3]  =  {2.602,ZERO_POINT_VOLTAGE,(REACTION_VOLTGAE/(2.602-3))};   
                                                     //two points are taken from the curve. 
                                                     //with these two points, a line is formed which is
                                                     //"approximately equivalent" to the original curve.
                                                     //data format:{ x, y, slope}; point1: (lg400, 0.324), point2: (lg4000, 0.280) 
                                                     //slope = ( reaction voltage ) / (log400 –log1000) 
                                                   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define StartConvert 0
#define ReadTemperature 1

const byte numReadings = 20;     //the number of sample times
byte ECsensorPin = A2;  //EC Meter analog output,pin on analog 2
byte DS18B20_Pin = 3; //DS18B20 signal, pin on digital 3
unsigned int AnalogSampleInterval=25,printInterval=700,tempSampleInterval=850;  //analog sample interval;serial print interval;temperature sample interval
unsigned int reading[numReadings];      // the readings from the analog input
byte index2 = 0;                  // the index of the current reading
unsigned long AnalogValueTotal = 0;                  // the running total
unsigned int AnalogAverage = 0,averageVoltage=0;                // the average
unsigned long AnalogSampleTime,printTime,tempSampleTime;
float temperature2,ECcurrent; 
 
//Temperature chip i/o
OneWire ds(DS18B20_Pin);  // on digital pin 2


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

byte resetButtonA = 36;
byte resetButtonB = 37;
byte statusLed    = 38;

byte sensorInterrupt = 0;  // 0 = pin 2; 1 = pin 3
byte sensorPin       = 2;

// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// litre/minute of flow.
float calibrationFactor = 4.5;

volatile byte pulseCount;  

float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitresA;
unsigned long totalMilliLitresB;

unsigned long oldTime;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define LCD_RS 52
#define LCD_EN 53
#define LCD_D4 50
#define LCD_D5 51
#define LCD_D6 48
#define LCD_D7 49




#define upPin 22
#define downPin 23
#define leftPin 24
#define rightPin 25
#define backPin 26
#define okPin 27
#define levelSW 37

#define cutOff 337
long nutCycle = 5000;
#define wait 50
#define reads 5000
#define mainMax 7
#define setMax 7
#define pumpMax 6
#define timeMax 6
#define resMax 2
#define cycleMax 2
#define chillerMax 3
#define carbonMenuMax 2
#define humidityMax 3
#define pumpMax 6
#define subPumpMax 3
#define calMax 6
#define freqMax 2
#define timeResMax 3
#define resChangeMax 3
#define manualTimeMax 5
#define readMax 6
#define phMax 6
#define botMax 2
#define nutMax 6

#define dosage 5
#define pumpRate 1         //Peristaltic pumps rate in ml/s
#define waterMax 255
#define nutMax 255
#define onMax 255
#define offMax 255
#define startMax 255
#define stopMax 255
#define chilHysMax 255
#define carbonMax 1000
#define carbonHysMax 1000
#define offRHMax 100
#define onRHMax 100
#define RHHysMax 100
#define ltrMax 255
#define upPhMax 255
#define downPhMax 255
#define setPhValMax 14


#define chillerPin 39
#define misterPin 40
#define co2Pin 41
#define lightPin 42
#define waterOutPin 43
#define waterInPin 44
#define alarmPin 45

long startRead = 0, onStart = 0, offStart =0,onLightStart = 0, offLightStart = 0;

int maximum, index, phUpIndex=4, phDownIndex =5,totalWeeks,weekCount = 0;
boolean main0 = false;
boolean sub1 = false;
boolean sub2 = false;
boolean temp = false;
boolean pumpPH = false;
boolean nutState = true;
boolean botState = false;

boolean humidState = false;
boolean tempState = false;
boolean lightState = false;
boolean startState = false;
//boolean temp = false;
//boolean pumpPH = false;

int tempVal = 0;
float humid = 0;
float co2Val = 0;
float phValue =0;

#define SensorPin 0          //pH meter Analog output to Arduino Analog Input 0
unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10],tempPh;

int second =      50; //0-59
int minute =      13; //0-59
int hour =        10; //0-23
int weekDay =     7; //1-7 
int monthDay =    25; //1-31
int month =       1; //1-12
int year = 15;      //00-99

int manMonth =       1; //1-12
int manMinute =      13; //0-59
int manHour =        10; //0-23
int manDate =       7; //1-7
int liters  =       0; //0-99


int waterSize =0;
int nutSize = 0;
int onTime =0;
int offTime =0;
int startTemp = 0;
int stopTemp = 0;
int chilHys = 0;
int desCarbon = 0;
int carbonHys = 0;
int onRH =0;
int offRH = 0;
int RHHys = 0;
int freq = 0;
int resHour =0;
int resMinute = 0;
int resDay = 0;
int upPh = 0;
int downPh = 0;
float setPhVal = 0;
int pumpNum = 1;
int nutVolume = 0;
int startDate = 1;
int startHour = 1;
int startMinute = 1;
int startDay = 1;


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

int pointer[5];
int pump[]={0,0,0,0,0,0}, pumpPin[] = {30,31,32,33,34,35};
int data[10][4];
int currentNut[]={1000,1000,1000,1000,1000,1000};
int botSize[]={1000,1000,1000,1000,1000,1000};
int manualNut[]={0,0,0,0,0,0};


void setup() {
  Wire.begin();
  Serial.begin(9600);
  for(int i = 22; i<29; i++)
  {
    pinMode(i, INPUT);
  }
  
  pinMode(levelSW, INPUT);
  
  for(int i = 39; i<46; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i,LOW);
  }
  
  pinMode(alarmPin,OUTPUT);
  digitalWrite(alarmPin,LOW);
  
  for(int i = 0; i<6; i++)
  {
    pinMode(pumpPin[i], OUTPUT);
    digitalWrite(pumpPin[i],LOW);
  }
  
  pinMode(BOOL_PIN, INPUT);                        //set pin to input
  digitalWrite(BOOL_PIN, HIGH);                    //turn on pullup resistors
  
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  dht.begin();
  
  for (byte thisReading = 0; thisReading < numReadings; thisReading++)
    reading[thisReading] = 0;
  TempProcess(StartConvert);   //let the DS18B20 start the convert
  AnalogSampleTime=millis();
  printTime=millis();
  tempSampleTime=millis();
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pinMode(statusLed, OUTPUT);
  digitalWrite(statusLed, HIGH);  // We have an active-low LED attached
  
  // Set up the pair of counter reset buttons and activate internal pull-up resistors
  pinMode(resetButtonA, INPUT);
  digitalWrite(resetButtonA, HIGH);
  pinMode(resetButtonB, INPUT);
  digitalWrite(resetButtonB, HIGH);
  
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);

  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitresA = 0;
  totalMilliLitresB = 0;
  oldTime           = 0;

  // The Hall-effect sensor is connected to pin 2 which uses interrupt 0.
  // Configured to trigger on a FALLING state change (transition from HIGH
  // state to LOW state)
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //assign();
  
  pinMode(10, OUTPUT);
  
  readSD();
  
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if ( fv != "1.1.0" )
    Serial.println("Please upgrade the firmware");

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();
  // you're connected now, so print out the status:
  printWifiStatus();
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  int pumpOnTime = dosage/pumpRate*1000;
  
  if(sub1 == true)
  {
    selection();
  }
  
  lcd.clear();
  
  for(int i=0;i<6;i++)
  {
    if(pump[i] == 1)
    {
      phUpIndex = i;
      break;
    }
  }
  
  for(int i=0;i<6;i++)
  {
    if(pump[i] == 2)
    {
      phDownIndex = i;
      break;
    }
  }
  
  while(!sub1)
  {
    response();
    ec();
    printDate();
    manualResChange();
    nutFunction();
    level();
    
      if(lightState == true && (millis() - onLightStart) < onTime*1000)
      {
        digitalWrite(lightPin,HIGH);
      }
      else if(nutState == true)
      {
        lightState = false;
        offLightStart = millis();
      }
      if(lightState == false && (millis() - offLightStart) < offTime*1000)
      {
        digitalWrite(lightPin,LOW);
      }
      else if(lightState == false)
      {
        lightState = true;
        onLightStart = millis();
      }
    
    
    if(startDate == monthDay && startState == false)
    {
      startDay = weekDay;
      startState = true;
    }
    
    if(millis()-startRead > reads)
    {
      startRead = millis();
      
      lcd.clear();
      lcd.setCursor(0, 0);
      
      printec();
      
      temperature();
      humidity();
      ph();
      CO2();
      function();
      update();
    }
    
    if(phValue<setPhVal)
    {
      if(nutState == true && (millis() - onStart) < pumpOnTime)
      {
        digitalWrite(pumpPin[phUpIndex],HIGH);
      }
      else if(nutState == true)
      {
        nutState = false;
        offStart = millis();
        currentNut[phUpIndex] -= dosage;
      }
      if(nutState == false && (millis() - offStart) < nutCycle)
      {
        digitalWrite(pumpPin[phUpIndex],LOW);
      }
      else if(nutState == false)
      {
        nutState = true;
        onStart = millis();
      }
    }
    
    if(phValue>setPhVal)
    {
      //digitalWrite(pumpPin[phDownIndex],HIGH);
      if(nutState == true && (millis() - onStart) < pumpOnTime)
      {
        digitalWrite(pumpPin[phDownIndex],HIGH);
      }
      else if(nutState == true)
      {
        nutState = false;
        offStart = millis();
        currentNut[phDownIndex] -= dosage;
      }
      if(nutState == false && (millis() - offStart) < nutCycle)
      {
        digitalWrite(pumpPin[phDownIndex],LOW);
      }
      else if(nutState == false)
      {
        nutState = true;
        onStart = millis();
      }
    }
   
  }
  
}



