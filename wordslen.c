#include <stdio.h>


//added comments as this is such a mess

int len(char* str)
{
    char ignore[] = {' ', '\t', ',', '.', '!', '?', '\n'};  //bad letter
    int count = 0;
    int ignored = 0;
    while (*str != '\0') {
        for (int i = 0; i < 8; i++) {  //loop throught bad letter
            if (*str == ignore[i]) {
                str++; //we move on to the next letter
                if (count != 0) { //if the last letter was bad there was no word
                    printf("%d ", count);
                    count = 0;
                }
                ignored = 1;
                break; //stop checking bad letters as one has been found
            }
        }
        if (ignored == 1) {  //reset the bad letter
            ignored = 0;
            str++;
        }
        else { //it was good letter so we add to count
            count++;
            str++;
        }

    }
    printf("%d\n", count); // yay happy end of the string
    
}

int main()
{
    char str1[] = "gargantua        is drinking tea.           ";
    len(str1);
    char str2[] = "Tea is drunk by tea."; 
    len(str2);
    char str3[] = "";
    len(str3);
    return 0;
}