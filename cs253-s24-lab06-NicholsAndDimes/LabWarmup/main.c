/*
Author: Chris Nichols
Date: 2024.02.14
*/

#include <stdio.h>

const int TEAM_SIZE = 5;

int main(void) {

   double weightArray[TEAM_SIZE];
   double weightTotal = 0.0;
   double weightMax = 0.0;
   int i, rc = 0;

   for(i = 0; i < TEAM_SIZE; i++){
      rc = 0;
      while(rc == 0){
         printf("Enter weight %d:\n", i + 1);
         rc = scanf(" %lf", &weightArray[i]);
         while (getchar() != '\n');
         if (weightArray[i] <= 0.0) rc = 0;
      }
   }

   printf("You entered: ");
   for(i = 0; i < TEAM_SIZE; i++){
      if(weightArray[i] > weightMax) weightMax = weightArray[i];
      weightTotal += weightArray[i];
      printf("%0.2lf ", weightArray[i]);
   }

   printf("\n\nTotal weight: %0.2lf\nAverage weight: %0.2lf\nMax weight: %0.2lf\n",
      weightTotal,
      weightTotal / TEAM_SIZE,
      weightMax
   );
   
   return 0;
}