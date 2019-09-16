+#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
char ball[] = "o";
byte b[8] =
{
  B01110,
  B10001,
  B10001,
  B01110,
  B00100,
  B00100,
  B01010,
  B11011
};
void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(0, b);
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
  lcd.setCursor(3, 0);
  lcd.print("WELCOME TO");
  lcd.setCursor(2, 1);
  lcd.print("FLAPPYBIRD ");
  lcd.write(byte(0));
  delay(3000);
  lcd.clear();
  lcd.print("Press switch");
  lcd.setCursor(1, 1);
  lcd.print("to play");
  delay(2000);
  lcd.clear();
  lcd.write(byte(0));
}
int key;
int c;
int i, flag = 0;
void loop()
{

  if (flag == 1)
  {
    lcd.clear();
    lcd.setCursor(4, 1);
    delay(200);
    lcd.print("GAME OVER");
    delay(2000);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("SCORE : ");
    lcd.print(c);
    delay(5000);
    lcd.clear();
    exit(0);
  }
  else
  {
    int y = random(0, 2);

    for (i = 15; i >= 1; i--)
    {
      key = digitalRead(7);
      Serial.println(key);
      if (key == 0)
      {
        delay(120);
        lcd.setCursor(0, key);
        lcd.write(byte(0));
        lcd.setCursor(0, 1);
        lcd.print(" ");
      }
      lcd.setCursor(0, 0);
      lcd.print(" ");
      lcd.setCursor(0, key);
      lcd.write(byte(0));
      c = (millis() - 5000) / 1000;
      lcd.setCursor(13, 0);
      lcd.print(c);
      if (y == 0 && i <= 12)
      {
        lcd.setCursor(i, y);
        lcd.print(ball);
      }
      else if (y == 1)
      {
        lcd.setCursor(i, y);
        lcd.print(ball);
      }

      delay(120);
      lcd.setCursor(i, y);
      lcd.print(" ");
      if (y == key && i == 1)
      {
        flag = 1;
      }
    }
  }
}
