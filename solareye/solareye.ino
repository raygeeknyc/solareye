#define DELTA_THRESHOLD 100
#define  REST_DURATION_MINS 5
const unsigned long REST_DURATION_MS = REST_DURATION_MINS * 60 * (long)1000;

#define  NUDGE_DURATION_SECS 1
const unsigned long NUDGE_DURATION_MS = NUDGE_DURATION_SECS * (long)1000;

const int pin_cds_left = A0;
const int pin_cds_right = A1;

const int SENSOR_SAMPLES = 5;
const int SENSOR_SAMPLE_DELAY_MS = 5;

void setup() {
  // put your setup code here, to run once:

}

void turnToSensor(const int pin) {
  int reading;
  int prev_reading = 0;
  
  // Step while the sensor reading increases
  while (reading = readSensor(pin) > (prev_reading + DELTA_THRESHOLD)) {
    prev_reading = reading;
    nudgeTowardsSensor(pin);
  }
  // If we overshot past the high light level, go back a step
  if ((prev_reading - readSensor(pin)) > DELTA_THRESHOLD) {
    nudgeTowardsSensor((pin == pin_cds_left)?pin_cds_right:pin_cds_left);
  }
}

void switchMotorTowardsSensor(const int pin) {
// TODO(raymond): Switch the DC motor to turn in the direction of the pin  
}

void nudgeTowardsSensor(const int pin) {
  switchMotorTowardsSensor(pin);
  delay(NUDGE_DURATION_MS);
}


void turnToLeft() {
  turnToSensor(pin_cds_left);
}

void turnToRight() {
  turnToSensor(pin_cds_right);
}

void findMaxLight() {
  // TODO(raymond): Switch the DC motor to turn in the direction of the pin  
}

void readSensors(const int leftPin, const int rightPin, int &leftReading, int &rightReading) {
  rightReading = readSensor(rightPin);
  leftReading = readSensor(leftPin);
}

void MoveToLight() {
  positionBySensors(pin_cds_left, pin_cds_right);
  delay(REST_DURATION_MS);
}

void positionBySensors(const int leftPin, const int rightPin) {
  int leftReading, rightReading;

  readSensors(leftPin, rightPin, leftReading, rightReading);
  int delta = leftReading - rightReading;
  if (delta > DELTA_THRESHOLD) {
    turnToRight();
  } else if (delta < DELTA_THRESHOLD * -1) {
    turnToLeft();
  } else {
    findMaxLight();
  }
}

int readSensor(int pin) {
  /***
  The multiple reads and delay are recommended to allow the shared ADC to properly
  read multiple pins in succession.
  ***/
  int samples[SENSOR_SAMPLES];
  
  for (int s=0; s<SENSOR_SAMPLES; s++) {
    samples[s] = analogRead(pin); delay(SENSOR_SAMPLE_DELAY_MS);
  }
  return smooth(samples, SENSOR_SAMPLES);
}

int smooth(int array[], int len) {
  /**
  Return the average of the array without the highest and lowest values.
  **/
  int low = 9999;
  int high = -1;
  int total = 0;
  for (int s=0; s< len; s++) {
    total += array[s];
    low = min(array[s], low);
    high = max(array[s], high);
  }
  total -= low;
  total -= high;
  return total / (len -2);
}


void loop() {
  // put your main code here, to run repeatedly:

}
