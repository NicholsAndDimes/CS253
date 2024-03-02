/*
Author: Chris Nichols
Date: 2024.02.29
*/

#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#define MAX_ITEM_SIZE 80

// Define itemToPurchase struct
struct itemToPurchase{
    char itemName[MAX_ITEM_SIZE];
    char itemDescription[MAX_ITEM_SIZE];
    int itemPrice;
    int itemQuantity;
};

// Define ItemToPurchase type
typedef struct itemToPurchase ItemToPurchase;

// MakeItemBlank init the fields in the struct
int MakeItemBlank(ItemToPurchase *item);

// Display item cost
void PrintItemCost(ItemToPurchase item);

// Display item description
void PrintItemDescription(ItemToPurchase item);

#endif