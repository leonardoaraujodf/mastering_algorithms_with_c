#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "median.h"

#define ARRAY_SIZE (10)
#define MAX_VALUE (250)

int main()
{
   int i, average = 0, data_median;
   int data[ARRAY_SIZE];
   /* Use current time as seed for random generator */
   srand(time(0));
   printf("[%s:%d] DATA: ", __func__, __LINE__);
   for(i = 0; i < ARRAY_SIZE; i++)
   {
      data[i] = rand() % MAX_VALUE;
      average += data[i];
      printf("%d ", data[i]);
   }
   printf("\n");
   average = average / ARRAY_SIZE;
   if(median(data, ARRAY_SIZE, &data_median))
   {
      printf("[%s:%d] Fail to calculate median!\n", __func__, __LINE__);
      return EXIT_FAILURE;
   }
   printf("[%s:%d] Average: %d\n", __func__, __LINE__, average);
   printf("[%s:%d] Median: %d\n", __func__, __LINE__, data_median);

   return 0;
}
