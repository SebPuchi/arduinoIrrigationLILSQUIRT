#include <LiquidCrystal.h> 
int Contrast=75;
 LiquidCrystal lcd(11, 13, 10, 9, 8, 7); 


int screenWidth = 16;
int screenHeight = 2;


byte water[] = {
  B00100,
  B00100,
  B01110,
  B01110,
  B11111,
  B11101,
  B11011,
  B01110
};



int stringStart, stringStop = 0;
int scrollCursor = screenWidth;








int IN1 = 2;
int IN2 = 3;
int IN3 = 4;

int moistureSensorANALOG = A1;
int moistureSensor2ANALOG = A2;
int moistureSensor3ANALOG = A3;



float sensor1Value = 0;
float sensor2Value = 0;
float sensor3Value = 0;

void setup() {



  analogWrite(12,Contrast);
  lcd.begin(screenWidth,screenHeight);
  lcd.createChar(0,water);


Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  
  pinMode(moistureSensorANALOG, INPUT);
  pinMode(moistureSensor2ANALOG, INPUT);
  pinMode(moistureSensor3ANALOG, INPUT);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);

}

void loop() {

  lcd.setCursor(1, 1);
  lcd.write(byte(0));
  lcd.setCursor(3, 1);
  lcd.print("lil squirt");
  lcd.setCursor(14, 1);
  lcd.write(byte(0));

  
 


  String line1 = "Plant 1 Moisture - "+ String(analogRead(moistureSensorANALOG))+" Plant 2 Moisture - "+ String(analogRead(moistureSensor2ANALOG))+" Plant 3 Moisture - "+ String(analogRead(moistureSensor3ANALOG)) ;
  lcd.setCursor(scrollCursor, 0);
  lcd.print(line1.substring(stringStart,stringStop));
    delay(500);
    lcd.clear();
    
  if(stringStart == 0 && scrollCursor > 0){
    scrollCursor--;
    stringStop++;
  } else if (stringStart == stringStop){
    stringStart = stringStop = 0;
    scrollCursor = screenWidth;
  } else if (stringStop == line1.length() && scrollCursor == 0) {
    stringStart++;
  } else {
    stringStart++;
    stringStop++;
  }

  

 



//Plant 1
  Serial.print("Plant 1 - Moisture Level: ");
  sensor1Value = analogRead(moistureSensorANALOG);
  Serial.println(sensor1Value);
  Serial.println();


  digitalWrite(IN1, HIGH);
  if (sensor1Value > 300) {
     lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write("WATERING Plant 1");
    digitalWrite(IN1, LOW);
    delay(1000);
    digitalWrite(IN1, HIGH);
    delay(5000);
    lcd.clear();
  
  } 


//Plant 2

Serial.print("Plant 2 - Moisture Level: ");
  sensor2Value = analogRead(moistureSensor2ANALOG);
  Serial.println(sensor2Value);
  Serial.println();


  digitalWrite(IN2, HIGH);
  if (sensor2Value > 300) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write("WATERING Plant 2");
    digitalWrite(IN2, LOW);
    delay(1000);
    digitalWrite(IN2, HIGH);
    delay(5000);
    lcd.clear();
  
  } 

 

//Plant 3

Serial.print("Plant 3 - Moisture Level: ");
  sensor3Value = analogRead(moistureSensor3ANALOG);
  Serial.println(sensor3Value);
  Serial.println();


  digitalWrite(IN3, HIGH);
  if (sensor3Value > 300) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write("WATERING Plant 3");
    digitalWrite(IN3, LOW);
    delay(1000);
    digitalWrite(IN3, HIGH);
    delay(5000);
    lcd.clear();
  
  } 



  

  
 










}