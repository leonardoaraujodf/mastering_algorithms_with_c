#include <stdio.h>
#include <stdlib.h>

#include "directls.h"

void print_usage()
{
   printf("List directories content.\n");
   printf("Usage:\n");
   printf("./a.out <dirname1> .. <dirnameN>\n");
   printf("\n");
}

int main(int argc, char * argv[])
{
   if(argc < 2)
   {
      print_usage();
      exit(1);
   }

   int i = argc - 1;
   int j;
   int count;
   Directory * entries;
   while(i > 0)
   {
      count = directls(argv[i], &entries);
      if(count < 0)
      {
         printf("An internal error occurred. Exiting!\n");
         exit(-1);
      }
      printf("Directory %s:\n", argv[i]);
      for(j = 0; j < count; j++)
      {
         printf("%s\n", entries[j].name);
      }

      free(entries);
      i--;
   }

   return 0;
}
