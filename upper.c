#include <stdio.h>

void all_upper(char* str)
{
  // array of capital letters
    printf("%s", str); 
    char capital[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* p = str;
    int isUpper = 0;
    while(*p != '\0'){
        for(int i = 0; i < 26; i++){
            if(*p == capital[i]){
                isUpper = 1;
                break;
            }
        }
        if(isUpper == 0){
            *p = *p - 32;
        }
        isUpper = 0;
        p++;
    }
    isUpper = 0;
}

int main()
{
  char* str1 = "Gargantua is drinking tea.\n";
  all_upper(str1);
  printf(str1); // Should print "GARGANTUA IS DRINKING TEA."

  char* str2 = "Tea is drunk by Tea.\n";
  all_upper(str2);
  printf(str2); // Should print "TEA IS DRUNK BY TEA."
}