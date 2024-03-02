/*
Author: Chris Nichols
Date: 2024.02.29
*/

#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"

int MakeItemBlank(ItemToPurchase *item){
    if (item == NULL){
        return -1;
    }

    strcpy(item->itemName, "none");
    strcpy(item->itemDescription, "none");
    item->itemPrice = 0;
    item->itemQuantity = 0;

    return 0;
}

void PrintItemCost(ItemToPurchase item){
    printf(
        "%s %d @ $%d = %d\n", 
        item.itemName, 
        item.itemQuantity,
        item.itemPrice,  
        item.itemQuantity * item.itemPrice
    );
}

void PrintItemDescription(ItemToPurchase item){
    printf("%s: %s\n", item.itemName, item.itemDescription);
}
