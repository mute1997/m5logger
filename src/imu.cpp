#define M5STACK_MPU6886

#include <M5Stack.h>
#include <imu.h>
#include <utils.h>

// TODO いい感じにする (state構造体)
int record = 0;
int max_bank = 0;
imu_data_t imu_data = {};

int get_imu_data(imu_data_t *imu_data) {
  M5.IMU.getGyroData(&imu_data->gyro.gyroX, &imu_data->gyro.gyroY, &imu_data->gyro.gyroZ);
  M5.IMU.getAccelData(&imu_data->acc.accX, &imu_data->acc.accY, &imu_data->acc.accZ);
  M5.IMU.getAhrsData(&imu_data->vec.pitch, &imu_data->vec.roll, &imu_data->vec.yaw);
  M5.IMU.getTempData(&imu_data->temperature);

  return 0;
}

void show_imu_data(imu_data_t *data) {
  double offset = 4.5; // for noise
  int red_threshold = 30;
  int yellow_threshold = 20;

  int current_bank = abs(int(data->vec.pitch-offset));
  if (max_bank < current_bank) max_bank = current_bank;

  // change color depends on bank angle
  if (current_bank >= red_threshold) M5.Lcd.setTextColor(RED , BLACK);
  else if (current_bank >= yellow_threshold) M5.Lcd.setTextColor(YELLOW , BLACK);
  else M5.Lcd.setTextColor(GREEN , BLACK);

  // show current bank
  M5.Lcd.setTextSize(7);
  M5.Lcd.setCursor(30, 90);
  M5.Lcd.printf(" %02d", current_bank);

  // show max bank
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE , BLACK);
  M5.Lcd.setCursor(180, 60);
  M5.Lcd.printf("angle:");
  M5.Lcd.setCursor(280, 60);
  M5.Lcd.printf("%02d", max_bank);

  // show record status
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setCursor(180, 100);
  M5.Lcd.printf("record:");
  M5.Lcd.setCursor(280, 100);
  M5.Lcd.setTextColor(record ? GREEN : RED, BLACK);
  M5.Lcd.printf("%s", record ? "on " : "off");
}

void imu_init() {
  max_bank = 0;
  memset(&imu_data, 0, sizeof(imu_data_t));
  show_button_labels((char*)"reset", (char*)"record", NULL);
  show_title((char*)"imu");
}

void imu_finish() {
  max_bank = 0;
  memset(&imu_data, 0, sizeof(imu_data_t));
}

void button_reset() {
  max_bank = 0;
}

void button_record() {
  // TODO
  record = !record;
}

void imu() {
  get_imu_data(&imu_data);
  show_imu_data(&imu_data);
  if (M5.BtnA.wasPressed()) button_reset();
  if (M5.BtnB.wasPressed()) button_record();
  delay(1);
}
