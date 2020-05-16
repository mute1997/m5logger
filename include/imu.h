typedef struct acc {
  float accX;
  float accY;
  float accZ;
} acc_t;

typedef struct gyro {
  float gyroX;
  float gyroY;
  float gyroZ;
} gyro_t;

typedef struct vec {
  float pitch;
  float roll;
  float yaw;
} vec_t;

typedef struct imu_data {
  acc_t acc;
  gyro_t gyro;
  vec_t vec;
  float temperature;
} imu_data_t;

typedef struct state {
  int angle;
  int speed;
} state_t;

void imu();
void imu_init();
void imu_finish();
