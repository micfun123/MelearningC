#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char *str;

   /* Initial memory allocation */
   str = (char *) malloc(12);
   strcpy(str, "TeaEatsCake");
   printf("String = %s,  Address = %u\n", str, str);

   /* Reallocating memory */
   str = (char *) realloc(str, 14);
   strcat(str, ":D");
   printf("String = %s,  Address = %u\n", str, str);

   free(str);
   
   return(0);
}