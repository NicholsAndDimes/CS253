/*
Author: Chris Nichols
Date: 2024.02.29
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ItemToPurchase.h"

void BufferPurge(void) {
   char c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
}


int main(void) {
 
   int rc = 0;
   ItemToPurchase item1, item2;

   rc = MakeItemBlank(&item1);
   if (rc < 0) {
      printf("Error: Unable to initilize item");
      exit(1);
   }

   rc = MakeItemBlank(&item2);
   if (rc < 0) {
      printf("Error: Unable to initilize item");
      exit(1);
   }

   printf("Item 1\nEnter the item name:\n");
   scanf("%79[^\n]]s", item1.itemName);
   BufferPurge();
   printf("Input the item price:\n");
   while (scanf("%d", &item1.itemPrice) < 1){
      printf("Please enter an integer value\n");
      BufferPurge();
   }
   BufferPurge();
   printf("Enter the item quantity:\n");
   while (scanf("%d", &item1.itemQuantity) < 1){
      printf("Please enter an integer value\n");
      BufferPurge();
   }
   BufferPurge();

   printf("\nItem 2\nEnter the item name:\n");
   scanf("%79[^\n]]s", item2.itemName);
   BufferPurge();
   printf("Input the item price:\n");
   while (scanf("%d", &item2.itemPrice) < 1){
      printf("Please enter an integer value\n");
      BufferPurge();
   }
   BufferPurge();
   printf("Enter the item quantity:\n");
   while (scanf("%d", &item2.itemQuantity) < 1){
      printf("Please enter an integer value\n");
      BufferPurge();
   }
   BufferPurge();
   
   printf("\n\nTotal Cost:\n");
   PrintItemCost(&item1);
   PrintItemCost(&item2);
   printf(
      "Total: $%d\n", 
      (item1.itemPrice * item1.itemQuantity) + (item2.itemPrice * item2.itemQuantity)
   );

   return 0;
}