int IN1 = 32; 
int IN2 = 33; 
int IN3 = 25;
int IN4 = 26;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(115200);
  Serial.println("Enter number for control option:");
  Serial.println("1. UP");
  Serial.println("2. DOWN");
  Serial.println("3. STOP");
  Serial.println("4. TEST1");
  Serial.println("5. TEST2");
  Serial.println("6. TEST10");
  Serial.println();  
}

void loop()
{
  char user_input;
  
  while(Serial.available())
  {
    user_input = Serial.read();

    if (user_input =='1')
    {
      Up();
    }
    else if(user_input =='2')
    {
      Down();
    }
    else if(user_input =='3')
    {
      Stop();
    }
    else if(user_input =='4')
    {
      Stop();
      delay(10);
      Up();
      delay(300);
      Down();
      delay(200);
      Stop();
    }
    else if(user_input =='5')
    {
      Stop();
      delay(10);
      Up();
      delay(300);
      Down();
      delay(175);
      Stop();
    }
    else if(user_input =='6')
    {
      for (int i=0; i<10; i++) {
        Stop();
        delay(10);
        Up();
        delay(300);
        Stop();
        delay(2000);
        Down();
        delay(175);
        Stop();
        delay(500);
      }
    }
    else
    {
      Serial.println("Invalid option entered.");
    }
  }
}


void Up()
{
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  Serial.print("Motor 1 Up");
  Serial.println();
  
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  Serial.print("Motor 2 Up");
  Serial.println();
  Serial.println();
}

void Down()
{
  digitalWrite(IN1, 1); 
  digitalWrite(IN2, 0);
  Serial.print("Motor 1 Down");
  Serial.println();
  
  digitalWrite(IN3, 0); 
  digitalWrite(IN4, 1);
  Serial.print("Motor 2 Down");
  Serial.println();
  Serial.println();
}

void Stop()
{
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
    Serial.print("Motor 1 Stop");
    Serial.println();
    
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 0);
    Serial.print("Motor 2 Stop");
    Serial.println();
    Serial.println();

}
