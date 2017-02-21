void print_to_SD(int measured_hour, int temp, int humidity);

void print_to_serial(void);

//int print_high_temp(weather space, int array_size){

typedef struct _weather_S{
  int temp;
  int humidity;
  int measured_hour;
} weather;
