#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int height, i, j, space;
   do
   {
     height = get_int("Height: ");
   }
   while (height < 1 || height > 8);

   for (i = 0; i < height; i++)
   {
      for (space = 0; space < height - i - 1; space++)
      {
         printf(" ");
      }
      for (j = 0; j <= i; j++)
      {
         printf("#");
      }
      printf("  ");
        for (j = 0; j <= i; j++)
      {