#include <M5Stack.h>
#include <utils.h>

void show_button_labels(char* right, char* center, char* left) {
  // MEMO: 320 * 240

  int base_right = 60;
  int base_center = 160;
  int base_left = 260;
  int text_size = 2;

  M5.Lcd.setTextSize(text_size);

  if (right != NULL) {
    M5.Lcd.setCursor(base_right-(strlen(right)/2*(text_size*6)), 220);
    M5.Lcd.printf("%s", right);
  }

  if (center != NULL) {
    M5.Lcd.setCursor(base_center-(strlen(center)/2*(text_size*6)), 220);
    M5.Lcd.printf("%s", center);
  }

  if (left != NULL) {
    M5.Lcd.setCursor(base_left-(strlen(left)/2*(text_size*6)), 220);
    M5.Lcd.printf("%s", left);
  }
}

void show_title(char* title) {
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.setTextSize(3);
  M5.Lcd.printf("%s", title);
}

