#include <stdio.h>
#include <limits.h>
#include <float.h>

int my_int;
float my_float;
double my_double;

int main() {
  my_int = INT_MAX;
  my_float = FLT_MAX;
  my_double = DBL_MAX;
  printf("Max int: %d, size: %d\n", my_int, (int) sizeof(int));
  printf("Max float: %f, size: %d\n", my_float, (int) sizeof(float));
  printf("Max double: %f, size: %d\n", my_double, (int) sizeof(double));
  return 0;
}
