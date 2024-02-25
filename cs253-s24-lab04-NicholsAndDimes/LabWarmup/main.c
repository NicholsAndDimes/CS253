/*
Author: Chris Nichols
Date: 2024.02.01
*/

#include <stdio.h>
#include <string.h>

int main(void) {

   const int MAX_WORD_LENGTH = 40;
   char serviceRequest[MAX_WORD_LENGTH + MAX_WORD_LENGTH + 2];
   char serviceRequest1[MAX_WORD_LENGTH + 1];
   char serviceRequest2[MAX_WORD_LENGTH + 1];
   int cost;

   printf("Enter desired auto service:\n");
   scanf("%40s %40s", serviceRequest1, serviceRequest2);
   strcpy(serviceRequest, serviceRequest1);
   strcat(serviceRequest, " ");
   strcat(serviceRequest, serviceRequest2);
   printf("You entered: %s %s\n", serviceRequest1, serviceRequest2);
   
   if (strcmp(serviceRequest, "Oil change") == 0){
      cost = 5;
      printf("Cost of oil change: $%d\n", cost);
   }
   else if (strcmp(serviceRequest, "Tire rotation") == 0){
      cost = 19;
      printf("Cost of tire rotation: $%d\n", cost);
   }
   else if (strcmp(serviceRequest, "Car wash") == 0){
      cost = 7;
      printf("Cost of car wash: $%d\n", cost);
   }
   else{
         printf("Error: Requested service is not recognized\n");
         return 2;
   }

   return 0;
}