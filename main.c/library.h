typedef struct _weather_S{ 
  int temp; 
  int humidity; 
  int measured_hour; 
} weather;

void print_to_SD(int measured_hour, int temp, int humidity); 
 
void print_to_serial(void); 
 
void print_high_low_temp(weather* space, int array_size);
 
