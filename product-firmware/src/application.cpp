#include <Grove_4Digit_Display.h>

TM1637 tm1637(D2,D3);

PRODUCT_VERSION(1);

void setup() {
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
  tm1637.clearDisplay();
  tm1637.display(1, 1);
  tm1637.display(2, 2);
  tm1637.display(3, 3);
}

void loop() {
  tm1637.point(POINT_ON);

  tm1637.display(0, 12);
  delay(200);
  tm1637.display(1, 1);
  delay(200);
  tm1637.display(2, 12);
  delay(200);
  tm1637.display(3, 13);

  delay(3000);
  tm1637.clearDisplay();
  delay(1000);
}
