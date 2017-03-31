const int pin_cds_1 = A0;
const int pin_cds_2 = A1;

const int SENSOR_SAMPLES = 5;
const int SENSOR_SAMPLE_DELAY_MS = 5;

void setup() {
  // put your setup code here, to run once:

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
