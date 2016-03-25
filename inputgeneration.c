#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   // First flag is matrix dimension "n"
   int dimension  = atoi(argv[1]);

   // Type of input
   // 1 -- 0, 1; 2 -- 0, 1, 2; 3 -- Random between 0 and 32;
   int type = atoi(argv[2]);

   FILE *f = fopen("matrix.txt", "w");
   if (f == NULL)
   {
       printf("Error opening file!\n");
       exit(1);
   }
   
   srand ( time(NULL) );

   if (type == 1) {
      for (int i = 0; i < dimension*4; i++) {
         fprintf(f, "%d\n", rand() % 2);
      }
   }
   else if (type == 2) {
      for (int i = 0; i < dimension*4; i++) {
         fprintf(f, "%d\n", rand() % 3);
      }
   }
   else if (type == 3) {
      for (int i = 0; i < dimension*4; i++) {
         fprintf(f, "%d\n", rand() % 32);
      }
   }

   
   fclose(f);
}