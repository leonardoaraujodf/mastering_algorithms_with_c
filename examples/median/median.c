#include <stdio.h>

#include "median.h"
#include "sort.h"
#define DEBUG
//#define USE_CT_SORT
#define USE_RADIX_SORT

int median(int * data, int size, int * med)
{
   int i, max, digits = 1;
   if((data == NULL) || (med == NULL) || (size <= 0))
      return -1;

   /* Find the maximum value in data. */
   for (i = 0, max = data[0]; i < size; i++)
   {
      if(data[i] > max)
         max = data[i];
   }
#ifdef USE_CT_SORT
   if(ctsort(data, size, max + 1))
      return -1;
#endif

#ifdef USE_RADIX_SORT
   /* Find how many digits */
   while(max /= 10)
      digits++;
   if(rxsort(data, size, digits, 10))
      return -1;
#endif

#ifdef DEBUG
   printf("[%s:%d] DATA SORTED: ", __func__, __LINE__ );
   for(i = 0; i < size; i++)
      printf("%d ", data[i]);
   printf("\n");
#endif

   *med = data[(size + 1) / 2];
   return 0;
}
