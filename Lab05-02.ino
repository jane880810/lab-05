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
Keypad keypad =
Keypad( makeKeymap(keys), rowPins,
colPins, ROWS, COLS );
void setup(){
Serial.begin(9600);
}
void loop(){
char key = keypad.getKey(); // 讀取 Keypad的輸入
if (key != NO_KEY){
Serial.println(key);
}
}
