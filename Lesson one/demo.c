#include <stdio.h>
int main()
{
/* These three lines show you how to use the most popular Escape
Sequences */
printf("Column A\tColumn B\tColumn C");
printf("\nMy Computer\'s Beep Sounds Like This: \a!\n");
printf("\"Letz\bs fix that typo and then show the backslash ");
printf("character \\\" she said\n");

/* Here is some more code to help you with printf(), Escape
Sequences, and Conversion Characters */
printf("Quantity\tCost\tTotal\n");
printf("%d\t\t$%.2f\t$%.2f\n", 3, 9.99, 29.97);
printf("Too many spaces \b\b\b\b can be fixed with the ");
printf("\\%c Escape character\n", 'b');
printf("\n\a\n\a\n\a\n\aSkip a few lines, and beep ");
printf("a few beeps.\n\n\n");
printf("%s %c.", "You are kicking butt learning", 'C');
printf("You just finished chapter %d.\nYou have finished ", 4);
printf("%.1f%c of the book.\n", 12.500, '%');
printf("\n\nOne third equals %.2f or ", 0.333333);
printf("%.3f or %.4f or ", 0.333333, 0.333333);
printf("%.5f or %.6f\n\n\n", 0.333333, 0.3333333);

return 0;
}