#include "course.h"

//For this function you will need to call a handful of functions and test your
//function outputs. You only need to call each of the following functions once.
//These include test_data1(), test_data2(), test_memmove1(), test_memmove2(),
//test_memmove3(), test_memcopy(), test_memset(), and test_reverse().
int8_t course1()
{
  int8_t ret;
  ret = test_data1();
  ret = test_data2();
  ret = test_memmove1();
  ret = test_memmove2();
  ret = test_memmove3();
  ret = test_memcopy();
  ret = test_memset();
  ret = test_reverse();

  return ret;
}

// This function will test to atoi and itoa conversions for you.
int8_t test_data1()
{
  printf("\n****** test_data1 **********\n");
  uint8_t ptr[33];
  int val = -1;
  int retVal = my_itoa(val, ptr, 2);
  printf("itoa1:%s\tret_len:%d\n",ptr,retVal);

  uint8_t temp[33] = {'f','f','f','f','f','f','f','f','\0'};
  int atoi_val = my_atoi(temp, 8, 16);
  printf("atoi1:%d\n",atoi_val);
  printf("\n****************************\n");
  return 0;
}

//This function will test to atoi and itoa conversions for you.
int8_t test_data2()
{
  printf("\n****** test_data2 **********\n");
  uint8_t ptr[33];
  int val = -1;
  int retVal = my_itoa(val, ptr, 16);
  printf("itoa2:%s\tret_len2:%d\n",ptr,retVal);

  uint8_t temp[33] = {'f','f','f','f','f','f','f','f','\0'};
  int atoi_val = my_atoi(temp, 8, 16);
  printf("atoi2:%d\n",atoi_val);
  printf("\n****************************\n");
  return 0;
}

//This function will test non-overlapped memmove.
int8_t test_memmove1()
{
  printf("\n****** test_memmove1 **********\n");
  uint8_t src[6] = "hello\n";
  uint8_t *dst = (uint8_t *)calloc(6,sizeof(*dst));
  printf("before my_memmove1:%s\n",src);
  dst = my_memmove(src,dst, 6);
  printf("dest_non_overlap:%s\n",dst);
  printf("\n****************************\n");
  return 0;
}

// This function will test overlapped memmove where there is overlap of the end
// of destination and start of the source regions.
int8_t test_memmove2()
{
  printf("\n****** test_memmove2 **********\n");
  //uint8_t src[12] = "hello\n";
  uint8_t *src = (uint8_t *)calloc(12,sizeof(*src));
  int8_t itr;
  uint8_t *tmpSrc = NULL;
  for(itr = 0; itr < 6; ++itr)
  {
    if(itr < 3)
    {
      *(src+itr) = 'h';
    }
    else
    {
      *(src+itr) = 'r';
    }
  }
  *(src+itr) = '\0';
  printf("before my_memmove2:%s\n",src);
  tmpSrc = src+5;

  tmpSrc = my_memmove(src,tmpSrc, 6);

  printf("dest_overlap1:%s\n",src);
  printf("\n**********************************\n");
  return 0;
}

// This function will test overlapped memmove where there is overlap of
// the start of destination and end of the source regions.
int8_t test_memmove3()
{
  printf("\n****** test_memmove3 **********\n");
  //uint8_t src[12] = "hello";
  uint8_t *src = (uint8_t *)calloc(12,sizeof(*src));
  int8_t itr;
  uint8_t *tmpSrc = NULL;
  for(itr = 0; itr < 6; ++itr)
  {
    if(itr < 3)
    {
      *(src+itr) = 'h';
    }
    else
    {
      *(src+itr) = 'r';
    }
  }
  *(src+itr) = '\0';
  printf("before my_memmove3:%s\n",src);
  tmpSrc = src+4;

  tmpSrc = my_memmove(src,tmpSrc, 6);

  printf("dest_overlap2:%s\n",src);
  printf("\n*********************************\n");
  return 0;
}

// This function will test memcopy.
int8_t test_memcopy()
{
  printf("\n****** test_memcopy **********\n");
  uint8_t src[6] = "hello";
  uint8_t dst[6];

  uint8_t *dstPtr = my_memcopy(src, dst, 6);

  printf("memcpy_dst:%s\n",dstPtr);
  printf("\n********************************\n");
  return 0;
}

// This function will test memset and memzero.
int8_t test_memset()
{
  printf("\n****** test_memset **********\n");
  uint8_t src[11];
  uint8_t *tmpSrc = my_memset(src,10,49);
  src[10] = '\0';

  printf("memset:%s\n",tmpSrc);
  printf("\n*******************************\n");
  return 0;
}

// This function will test reverse.
int8_t test_reverse()
{
  printf("\n****** test_reverse **********\n");
  uint8_t *src = (uint8_t *)calloc(6,sizeof(*src));
  for(int8_t itr = 0; itr < 6; ++itr)
  {
    if(itr < 3)
    {
      *(src+itr) = 'h';
    }
    else
    {
      *(src+itr) = 'r';
    }
  }
  //uint8_t *tmp = my_reverse(src, 6);
  printf("before rev:%s\n",src);
  src = my_reverse(src, 6);

  printf("rev:%s\n",src);
  printf("\n*********************************\n");
  return 0;
}
