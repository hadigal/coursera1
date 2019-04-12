#include "data.h"

void revPtr(uint8_t **str, uint8_t itr)
{
  uint8_t *ptr = *str;
  uint8_t tempItr = 0;
  uint8_t end = itr - 1;

  while(tempItr < (itr/2))
  {
    *(ptr+tempItr) = *(ptr+tempItr) ^ *(ptr+end-tempItr);
    *(ptr+end-tempItr) = *(ptr+end-tempItr) ^ *(ptr+tempItr);
    *(ptr+tempItr) = *(ptr+tempItr) ^ *(ptr+end-tempItr);
    ++tempItr;
  }
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
  // ptr is pre allocated!
  // define a temp Data
  int32_t tempData = data;
  // define itr to itrerate over ptr;
  uint8_t itr = 0;

  // check if data is -ve; if so store the data in 2's complement form; to visualize
  // set base to 2 or 16
  bool flg = false;
  if((tempData < 0) && (base == 10))
  {
    flg = true;
    tempData *= -1;
  }

  // itrerate till tempData is not 0 this way save the last digit using base to
  // ptr
  uint8_t lastDigit;
  while(tempData != 0)
  {
    // take last digit
    lastDigit = tempData%base;
    // this if part executes only when base is 16; for both base 10 and 2 only
    // else part will execute
    if(lastDigit >= 10)
    {
      *(ptr+itr) = lastDigit + 'a' - 10;
    }
    else
    {
      *(ptr+itr) = lastDigit + '0';
    }
    ++itr;
    tempData /= base; // divide tempData by base to itrerate
  }

  //  if the neg flg is set and base is 10 add '-' at the end to reversed later
  if(flg == true)
  {
    if(base == 10)
    {
      *(ptr+itr) = '-';
      ++itr;
    }

    /*this will be needed if we want to store the num in signed bit format*/

    // else if(base == 2)
    // {
    //   while(itr < 32)
    //   {
    //     if(itr == 31)
    //     {
    //       *(ptr+itr) = '1';
    //     }
    //     else
    //     {
    //       *(ptr+itr) = '0';
    //     }
    //     ++itr;
    //   }
    // }
    // else if(base == 16)
    // {
    //   while(itr < 8)
    //   {
    //     if(itr == 7)
    //     {
    //       *(ptr+itr) = '8';
    //     }
    //     else
    //     {
    //       *(ptr+itr) = '0';
    //     }
    //     ++itr;
    //   }
    // }
  }
  // terminate with NULL char
  *(ptr+itr) = '\0';
  // reverse the stored chars for ascii formated signed int number
  revPtr(&ptr,itr);
  // return count of chars in ascii format including null char
  return (itr+1);
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
  int32_t ret = 0;
  uint8_t init = 0;
  bool flg = false;
  if(base == 10 && ptr[0] == '-')
  {
    init = 1;
    flg = true;
  }

  for(size_t itr = init; (*(ptr+itr)) != '\0'; ++itr)
  {
    if(base == 10)
    {
      ret = ret*10 + *(ptr+itr) - '0';
    }
    else if(base == 2)
    {
      ret = ret*2 + *(ptr+itr) - '0';
    }
    else if(base == 16)
    {
      if((*(ptr+itr)) >= 'a')
      {
        ret = ret*16 + (*(ptr+itr) - 'a' + 10);
      }
      else
      {
        ret = ret*16 + (*(ptr+itr) - '0');
      }
    }
  }
  if(base == 10 && flg == true)
  {
    ret *= -1;
  }

  return ret;
}
