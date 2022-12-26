String inputString = "";
bool stringComplete = false;


void setup() {
  pinMode(8,OUTPUT);
  Serial.begin(9600);
  inputString.reserve(200);
  }

void loop() {
  if(stringComplete)
  {
    if(inputString == "LED1ON_"){
      digitalWrite(8,HIGH);
      }  
    else if(inputString == "LED1OFF_"){
      digitalWrite(8,LOW);
      }
      inputString = "";
      stringComplete = false;   
  }
}

void serialEvent(){
  while(Serial.available())
    {
      char inChar = (char)Serial.read();
      inputString += inChar;
      if(inChar == '_'){
        stringComplete = true;
        }
    }
  }
