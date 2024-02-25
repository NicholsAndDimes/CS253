/*
Author: Chris Nichols
Date: 2024.02.01
*/

#include <stdio.h>
#include <string.h>

int main(void) {

   const int MAX_WORD_LENGTH = 80;
   char serviceRequest1[MAX_WORD_LENGTH + 1];
   char serviceRequest2[MAX_WORD_LENGTH + 1];
   int cost1;
   int cost2;
   int total;

   printf("Davy's auto shop services\nOil change -- $35\nTire rotation -- $19\n");
   printf("Car wash -- $7\nCar wax -- $12\n\nSelect first service:\n");
   scanf(" %80[^\n]", serviceRequest1);
   printf("Select second service:\n");
   scanf(" %80[^\n]", serviceRequest2);
   printf("\nDavy's auto shop invoice\n\nService 1: ");

   if (strcmp(serviceRequest1, "Oil change") == 0){
      cost1 = 5;
      printf("%s, $%d\n", serviceRequest1, cost1);
   }
   else if (strcmp(serviceRequest1, "Tire rotation") == 0){
      cost1 = 19;
      printf("%s, $%d\n", serviceRequest1, cost1);
   }
   else if (strcmp(serviceRequest1, "Car wash") == 0){
      cost1 = 7;
      printf("%s, $%d\n", serviceRequest1, cost1);
   }
   else if (strcmp(serviceRequest1, "Car wax") == 0){
      cost1 = 12;
      printf("%s, $%d\n", serviceRequest1, cost1);
   }
   else if (strcmp(serviceRequest1, "-") == 0){
      cost1 = 0;
      printf("No service\n");
   }
   else{
         printf("\nError: Requested service is not recognized\n");
         return 2;
   }

   printf("Service 2: ");
   if (strcmp(serviceRequest2, "Oil change") == 0){
      cost2 = 5;
      printf("%s, $%d\n", serviceRequest2, cost2);
   }
   else if (strcmp(serviceRequest2, "Tire rotation") == 0){
      cost2 = 19;
      printf("%s, $%d\n", serviceRequest2, cost2);
   }
   else if (strcmp(serviceRequest2, "Car wash") == 0){
      cost2 = 7;
      printf("%s, $%d\n", serviceRequest2, cost2);
   }
   else if (strcmp(serviceRequest2, "Car wax") == 0){
      cost2 = 12;
      printf("%s, $%d\n", serviceRequest2, cost2);
   }
   else if (strcmp(serviceRequest2, "-") == 0){
      cost2 = 0;
      printf("No service\n");
   }
   else{
         printf("\nError: Requested service is not recognized\n");
         return 2;
   }

   total = cost1 + cost2;

   printf("\nTotal: $%d\n", total);
   
   return 0;
}