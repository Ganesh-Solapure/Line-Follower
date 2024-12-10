#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
#define ir6 A5
#define ir7 A6
#define ir8 A7

#define enA 6
#define in1 8
#define in2 7
#define in3 10
#define in4 9
#define enB 11

int base_speed = 50;

float Kp = 10, Kd = 5
, Ki = 0, p = 0, i = 0, d = 0, pid_val = 0, error = 0, prev_error = 0, sum_error = 0;

float right_speed = 0, left_speed = 0;

void forward(float left_speed, float right_speed) {
  analogWrite(enA, left_speed);
  analogWrite(enB, right_speed);
//  delay(1);
}

void setup() {
  Serial.begin(9600);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ir6, INPUT);
  pinMode(ir7, INPUT);
  pinMode(ir8, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
}

void loop() {
  int ir1_val = analogRead(ir1);
  int ir2_val = analogRead(ir2);
  int ir3_val = analogRead(ir3);
  int ir4_val = analogRead(ir4);
  int ir5_val = analogRead(ir5);
  int ir6_val = analogRead(ir6);
  int ir7_val = analogRead(ir7);
  int ir8_val = analogRead(ir8);

 
  if (ir1_val > 100) {ir1_val = 1;} else {ir1_val=0;}
  if (ir2_val > 100) {ir2_val = 1;} else {ir2_val=0;}
  if (ir3_val > 100) {ir3_val = 1;} else {ir3_val=0;}
  if (ir4_val > 100) {ir4_val = 1;} else {ir4_val=0;}
  if (ir5_val > 100) {ir5_val = 1;} else {ir5_val=0;}
  if (ir6_val > 100) {ir6_val = 1;} else {ir6_val=0;}
  if (ir7_val > 100) {ir7_val = 1;} else {ir7_val=0;}
  if (ir8_val > 100) {ir8_val = 1;} else {ir8_val=0;}

  Serial.print(ir1_val);
  Serial.print(ir2_val);
  Serial.print(ir3_val);
  Serial.print(ir4_val);
  Serial.print(ir5_val);
  Serial.print(ir6_val);
  Serial.print(ir7_val);
  Serial.print(ir8_val);




  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 1 && ir4_val == 1 && ir5_val == 1 && ir6_val == 1 && ir7_val == 1 && ir8_val == 1) error = 20;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 1 && ir7_val == 1 && ir8_val == 1)analogWrite(enA, 0);analogWrite(enB, 255); digitalWrite(in1, HIGH); digitalWrite(in2, LOW); ;
  
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 1 && ir7_val == 1 && ir8_val == 1) error = 15;
  
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = 0;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 1 && ir4_val == 1 && ir5_val == 1 && ir6_val == 1 && ir7_val == 0 && ir8_val == 0) error = 0;
  
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = 0;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = 0;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = 2;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -2;
 

  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 1 && ir4_val == 1 && ir5_val == 1 && ir6_val == 1 && ir7_val == 1 && ir8_val == 1) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = 12;


  
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 1 && ir7_val == 1 && ir8_val == 1) error = 12;
 
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 1 && ir7_val == 1 && ir8_val == 1) error = 10;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 1 && ir7_val == 1 && ir8_val == 0) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 1 && ir7_val == 0 && ir8_val == 0) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 1 && ir7_val == 0 && ir8_val == 1) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 1) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 1 && ir8_val == 0) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 1 && ir8_val == 1) error = 8;

//  ................................................................................................................................................

  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 1 && ir7_val == 1 && ir8_val == 1) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 1 && ir7_val == 1 && ir8_val == 0) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 1 && ir7_val == 0 && ir8_val == 0) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 1 && ir7_val == 0 && ir8_val == 1) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 1) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 0 && ir7_val == 1 && ir8_val == 0) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 0 && ir7_val == 1 && ir8_val == 1) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 1 && ir8_val == 1) error = 11;

  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 1) error = 12;
  
//  ................................................................................................................................................

  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 1 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -10;
  if (ir1_val == 0 && ir2_val == 1 && ir3_val == 1 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 1 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -9;
  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 1 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -9;
  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -8;
  if (ir1_val == 0 && ir2_val == 1 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;
  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 0 && ir4_val == 1 && ir5_val == 1 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;

//  ................................................................................................................................................
 
  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 1 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -9;
  if (ir1_val == 0 && ir2_val == 1 && ir3_val == 1 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 1 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -9;
  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 1 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;
  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 0 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;
  if (ir1_val == 0 && ir2_val == 1 && ir3_val == 0 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;
  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 0 && ir4_val == 1 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;

  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -11;

  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;

//  ................................................................................................................................................





  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 1 && ir7_val == 1 && ir8_val == 1) error = 10;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 1 && ir7_val == 1 && ir8_val == 0) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 1 && ir7_val == 0 && ir8_val == 0) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 1 && ir7_val == 0 && ir8_val == 1) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 1) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 1 && ir8_val == 0) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 1 && ir8_val == 1) error = 8;

//  ................................................................................................................................................

  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 1 && ir7_val == 1 && ir8_val == 1) error = 9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 1 && ir7_val == 1 && ir8_val == 0) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 1 && ir7_val == 0 && ir8_val == 0) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 1 && ir7_val == 0 && ir8_val == 1) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = 8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 1) error = 7;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 1 && ir8_val == 0) error = 7;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 1 && ir8_val == 1) error = 7;

//  ................................................................................................................................................

  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 1 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -10;
  if (ir1_val == 0 && ir2_val == 1 && ir3_val == 1 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -9;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 1 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -8;
  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 1 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -8;
  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;
  if (ir1_val == 0 && ir2_val == 1 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;
  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;

//  ................................................................................................................................................

  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 1 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -9;
  if (ir1_val == 0 && ir2_val == 1 && ir3_val == 1 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 1 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -8;
  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 1 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -8;
  if (ir1_val == 0 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;
  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -7;
  if (ir1_val == 1 && ir2_val == 1 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -11;
  if (ir1_val == 1 && ir2_val == 0 && ir3_val == 0 && ir4_val == 0 && ir5_val == 0 && ir6_val == 0 && ir7_val == 0 && ir8_val == 0) error = -12;


  p = error;
  d = error - prev_error;
  i += sum_error;

  pid_val = (Kp * p) + (Kd * d) + (Ki * i);

  sum_error += error;
  prev_error = error;

  left_speed = base_speed +pid_val;
  right_speed = base_speed -pid_val;

  if (left_speed > 255) left_speed = 150;
  if (left_speed < 0) left_speed = 0;
  if (right_speed > 255) right_speed = 150;
  if (right_speed < 0) right_speed = 0;


  //Serial.println("error");
  Serial.println(pid_val);

  forward(left_speed,right_speed);


}

 
