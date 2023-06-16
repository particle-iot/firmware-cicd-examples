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

}
