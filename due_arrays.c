#include <stdio.h>
#include <string.h>


char* coins[] = {"BTC","ETH","LIT"};
int prices[] = {10000, 100, 10};

int get_price(char* coin)
{
    int count = 0;
    while (coins[count] != NULL) {
        if (strcmp(coin, coins[count]) == 0) {
            return prices[count];
        }
        count++;
    }
    return -1;
}


int main()
{
    printf("The price of BTC is %d\n", get_price("BTC"));
    printf("The price of ETH is %d\n", get_price("ETH"));
    printf("The price of LIT is %d\n", get_price("LIT"));
    printf("The price of DOGE is %d\n", get_price("DOGE"));
    return 0;
}