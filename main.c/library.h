void print_to_serial(int measured_hour, int temp, int humidity);

void print_to_SD(int measured_hour, int temp, int humidity);
int print_high_temp(int space);

typedef struct _weather_S{
  int temp;
  int humidity;
  int measured_hour;
} weather;
