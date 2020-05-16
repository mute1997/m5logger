#include <M5Stack.h>
#include <setting.h>
#include <utils.h>

void setting_init() {
  show_title((char*)"settings");
}

void setting_finish() {
}

void setting() {
  M5.Lcd.setCursor(60, 90);
  M5.Lcd.printf("(TODO)");

  // TODO
  // 輝度設定
  // スリープ
  // etc...
}
