#include <stdio.h>
#include "data.h"

int main(void)
{
  uint8_t ptr[33];

  //ptr = (uint8_t *)calloc(33,sizeof(*ptr));

  int val = my_itoa(-1, ptr, 10);

  char temp[33] = {'f','f','f','f','f','f','f','d','\0'};

  //char temp[33] = {'8','0','0','0','0','0','0','0','\0'};

  int atoi_val = my_atoi(temp, 10, 16);

  printf("ptr:%s\n",ptr);

  printf("atoi_val:%d\n",atoi_val);

  //free(ptr);
  return 0;
}
