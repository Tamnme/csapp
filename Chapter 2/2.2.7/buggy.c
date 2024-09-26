#include<stdio.h>
#include <string.h>
//--- Practice Problem 2.25

float sum_elements (float a[], int length) {
  // if (length == 0) {
  //   printf("invalid length");
  //   return -1;
  // }
  int i;
  float result = 0;

  for (i = 0; i <= length-1; i++)
  result += a[i];
  return result;
}

int main(){
  float a[] ={1, 2, 3};
  printf("%f", sum_elements(a, 0));
  return 0;
}