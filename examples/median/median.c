#include <stdio.h>

#include "median.h"
#include "sort.h"
#define DEBUG

int median(int * data, int size, int * med)
{
   int i, max;
   if((data == NULL) || (med == NULL) || (size <= 0))
      return -1;

   /* Find the maximum value in data. */
   for (i = 0, max = data[0]; i < size; i++)
   {
      if(data[i] > max)
         max = data[i];
   }

   /* Sort data */
   if(ctsort(data, size, max + 1))
      return -1;

#ifdef DEBUG
   printf("[%s:%d] DATA SORTED: ", __func__, __LINE__ );
   for(i = 0; i < size; i++)
      printf("%d ", data[i]);
   printf("\n");
#endif

   *med = data[(size + 1) / 2];
   return 0;
}
