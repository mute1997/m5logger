#define M5STACK_MPU6886

#include <M5Stack.h>
#include <utils.h>

// features
#include <imu.h>
#include <setting.h>

int feature_ptr = 0;
feature_t features[] = {
  {imu_init, imu_finish, imu},
  {setting_init, setting_finish, setting},
  // TODO
  // 盗難防止
  // 電圧計
  // 二酸化炭素計
};

void change_next_feature() {
  // call destructor
  features[feature_ptr].fn_finish();
  M5.Lcd.clear(BLACK);

  // increase pointer
  int array_len = sizeof(features)/sizeof(feature_t);
  if (feature_ptr == array_len-1) feature_ptr = 0;
  else feature_ptr++;

  // call constructor
  features[feature_ptr].fn_init();
}

void setup(){
  M5.begin();

  dacWrite(25, 0); // reduction speaker noise

  M5.Power.begin();

  M5.IMU.Init();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE , BLACK);

  features[feature_ptr].fn_init();
}

void loop() {
  M5.update();
  show_button_labels(NULL, NULL, (char*)"next");
  features[feature_ptr].fn_main();
  if (M5.BtnC.wasPressed()) change_next_feature();
}
