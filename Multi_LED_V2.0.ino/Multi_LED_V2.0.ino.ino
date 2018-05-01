int Red_LED = 9;
int Green_LED = 11;
int Blue_LED = 10;
//Create a string holder to determine what color
String color;
String blinks;
int brightness;
int blink_cnt;
int i = 0;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(Red_LED, OUTPUT);
    pinMode(Green_LED, OUTPUT);
    pinMode(Blue_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("What color would you like(only red, green,or blue): ");
  while (Serial.available()== 0)  //hold until input is acquired
  {
    
  }
  color = Serial.readString();  //place input string in variable
  color.toUpperCase();    //force string to be upper
  
  //Ask for level of brightness and store in brightness
  Serial.println("How bright (range: 1-255):");
  while (Serial.available() == 0)
  {
    
  }
  brightness = Serial.parseInt(); //store usr given int
    //ask for any blinks
  Serial.println("Would you like the light to blink (Y/N)?");
  while (Serial.available() == 0)
  {
    
  }
  blinks = Serial.readString();
  blinks.toUpperCase(); //force input to be uppercase
  
  //pass inputs to defined function
  colorchoice(color,brightness,blinks); //call the function
}


//function created to detect based on answers
void colorchoice(String str_val,int num_val, String points)
{
    color = str_val;
    brightness = num_val;
    blinks = points;
   //if value is yes then ask for times
  if (blinks == "Y")
  {
    Serial.println("How many blinks (1-10)?");
    while (Serial.available() == 0)
    {
      
    }
    blink_cnt = Serial.parseInt();
    for(int i = 0; i < blink_cnt; i = i+1)  //loop to run i times to blink led
    {
      if (color == "GREEN")
      {
        analogWrite(Red_LED, 0);
        analogWrite(Green_LED, brightness);
        analogWrite(Blue_LED, 0);
      }
      
      else if (color == "BLUE")
      {
        analogWrite(Red_LED, 0);
        analogWrite(Green_LED, 0);
        analogWrite(Blue_LED, brightness);
      }
      else if (color == "RED")
      {
        analogWrite(Red_LED, brightness);
        analogWrite(Green_LED, 0);
        analogWrite(Blue_LED, 0);
      }
      else
      {
        Serial.println("Error! Color not available.");
        break;
      }
      delay(2000);  //delay for 2 sec before led turns off
      analogWrite(Red_LED , 0);
      analogWrite(Green_LED, 0);
      analogWrite(Blue_LED, 0);
      delay(2000);
    }
  }
  //if value is anything other than Y, run only one time
  else 
  {
    
    //if and else if to check which input was requested
    if (color == "GREEN")
    {
      analogWrite(Red_LED, 0);
      analogWrite(Green_LED, brightness);
      analogWrite(Blue_LED, 0);
    }
    else if (color == "BLUE")
    {
      analogWrite(Red_LED, 0);
      analogWrite(Green_LED, 0);
      analogWrite(Blue_LED, brightness);
    }
  
    else if (color == "RED")
    {
      analogWrite(Red_LED, brightness);
      analogWrite(Green_LED, 0);
      analogWrite(Blue_LED, 0);
    }
    else
    {
      Serial.println("Error! Color not available.");
    }
    delay(3000);    //delay is in ms, or 3 sec
    analogWrite(Red_LED, 0);
    analogWrite(Green_LED, 0);
    analogWrite(Blue_LED, 0);
  }
}

