/*
Author: Chris Nichols
Date: 2024.02.29
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"


void BufferPurge(void) {
   char c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
}

void PrintMenu(ShoppingCart cart){

    int rc = 0;
    char menuSelection;

    while(rc == 0){
        printf(
            "\nPROGRAM MENU\n"
            "a - Add item to cart\n"
            "r - Remove item from cart\n"
            "i - Output item descriptions\n"
            "o - Output shopping cart\n"
            "q - Quit\n\n"
            "Choose an option:\n"
        );

        scanf(" %c", &menuSelection);

        switch (menuSelection){
            
            case 'a':
                ItemToPurchase item;
                MakeItemBlank(&item);
                printf("ADD ITEM TO CART\n");
                printf("Enter the item name:\n");
                BufferPurge();
                scanf("%79[^\n]]s", item.itemName);
                BufferPurge();
                printf("Enter the item description:\n");
                scanf("%79[^\n]]s", item.itemDescription);
                BufferPurge();
                printf("Enter the item price:\n");
                while (scanf("%d", &item.itemPrice) < 1){
                    printf("Please enter an integer value\n");
                    BufferPurge();
                }
                printf("Enter the item quantity:\n");
                while (scanf("%d", &item.itemPrice) < 1){
                    printf("Please enter an integer value\n");
                    BufferPurge();
                }
                // PrintItemDescription(item);
                printf("name: %s\n", cart.customerName);
                cart = AddItem(item, cart);
                break;
            
            case 'r':
                char itemName[MAX_ITEM_SIZE];
                printf("Enter name of item to remove:\n");
                scanf("%79[^\n]]s", itemName);
                BufferPurge();
                cart = RemoveItem(itemName, cart);
                break;

            case 'i':
                printf("Item Descriptions\n");
                PrintDescriptions(cart);
                break;

            case 'o':
                PrintInvoice(cart);
                break;

            case 'q':
                rc = 1;
                break;

            default:
                printf("Error: Unknown option selected\n");
      }
   }
}

// createItem(){
//     int rc = 0;
//     ItemToPurchase item;

//     rc = MakeItemBlank(&item);
//     if (rc < 0) {
//         printf("Error: Unable to initilize item");
//         exit(1);
//     }

//     printf("Item 1\nEnter the item name:\n");
//     scanf("%79[^\n]]s", item.itemName);
//     BufferPurge();
//     printf("Input the item price:\n");
//     while (scanf("%d", &item.itemPrice) < 1){
//         printf("Please enter an integer value\n");
//         BufferPurge();
//     }
//     BufferPurge();
//     printf("Enter the item quantity:\n");
//     while (scanf("%d", &item.itemQuantity) < 1){
//         printf("Please enter an integer value\n");
//         BufferPurge();
//     }
//     BufferPurge();
// }

int main(void){
    /*
    Enter Customer's Name:
    John Doe
    Enter Today's Date:
    February 1, 2016

    Customer Name: John Doe
    Today's Date: February 1, 2016
    */
    

    ShoppingCart cart;

    printf("Enter Customer's Name:\n");
    scanf("%79[^\n]]s", cart.customerName);
    BufferPurge();
    printf("Enter Today's Date:\n");
    scanf("%49[^\n]]s", cart.currentDate);
    BufferPurge();

    printf("Customer Name: %s\nToday's Date: %s\n", cart.customerName, cart.currentDate);

    PrintMenu(cart);

    return 0;
}
