#include <Keypad.h>
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵

char keys[ROWS][COLS] = {
{'7', '4', '1', '0'}, {'8','5','2', 'A'},
{'9', '6', '3', 'B'}, {'C', 'D', 'E', 'F'}
};
// 定義 Keypad 連到 Arduino 的接腳

byte rowPins[ROWS] = {10, 11, 12, 13};
// 連到 Keypad 的 4 個 Rows
byte colPins[COLS] = {14, 15, 16, 17};
// 連到 Keypad 的 4 個 Columns

// 建立 Keypad 物件
Keypad keypad =Keypad( makeKeymap(keys), rowPins,colPins, ROWS, COLS );
int i,j,z;
int seg7[]={2,3,4,5,7,8,9};
char c;
char TAB[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67};
char a[]={0x77,0x7C,0x39,0x5E,0x79,0x71};

void setup(){
Serial.begin(9600);
for(i=0;i<7;i++)
    {
      pinMode(seg7[i],OUTPUT); 
    }

}
void loop(){
  
  
  char key = keypad.getKey(); // 讀取 Keypad的輸入
   if (key != NO_KEY){
     if(key >= '0' && key <= '9')
          OutPort(TAB[key-'0']);
     if(key >= 'A' && key <= 'F')
          OutPort(a[key-'A']);


}
}

void OutPort(byte dat)
{
  for(j=0;j<7;j++)
    {
      if(dat%2==1)
            digitalWrite(seg7[j],HIGH);
        else
            digitalWrite(seg7[j],LOW);
        dat=dat/2;
    }
}
