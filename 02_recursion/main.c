#include <stdio.h>
#include <time.h>
#include "fact.h"

int main()
{
   struct timespec start, end;
   double time_taken;
   int n, r;
   puts("Using standard recursion:");
   printf("Insert a number: > ");
   fscanf(stdin, "%d", &n);
   clock_gettime(CLOCK_MONOTONIC, &start);
   r = fact(n);
   clock_gettime(CLOCK_MONOTONIC, &end);
   time_taken = (end.tv_nsec - start.tv_nsec);
   printf("Factorial of %d = %d\n", n, r);
   printf("Time taken %lf ns.\n", time_taken);

   puts("Using tail recursion:");
   printf("Insert a number: > ");
   fscanf(stdin, "%d", &n);
   clock_gettime(CLOCK_MONOTONIC, &start);
   r = facttail(n,1);
   clock_gettime(CLOCK_MONOTONIC, &end);
   time_taken = (end.tv_nsec - start.tv_nsec);
   printf("Factorial of %d = %d\n", n, r);
   printf("Time taken %lf ns.\n", time_taken);

   return 0;
}
