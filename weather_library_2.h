typedef struct _weather_S{
  int temp, humidity, timme;
} weather;
weather space[100];

void print_to_SD(int hour, int temp, int humidity);
