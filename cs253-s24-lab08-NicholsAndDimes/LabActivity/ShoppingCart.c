/*
Author: Chris Nichols
Date: 2024.02.29
*/

#include<stdio.h>
#include<string.h>

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

/*
char customerName [ ]
char currentDate [ ]
ItemToPurchase cartItems [ ] - has a maximum of 10 slots (can hold up to 10 items of any quantity)
int cartSize - the number of filled slots in array cartItems [ ] (number of items in cart of any quantity)
*/

/* AddItem: Add an item to the next available location in the cartItems array. 
 *   If there are no available positions remaining in the cartItems array, make no
 *   changes to the ShoppingCart. Display a message in the terminal stating that
 *   the item was not added because the ShoppingCart is full.
 *   Return the ShoppingCart object when finished.
 * 
 * item - ItemToPurchase object to be added to the ShoppingCart
 * cart - ShoppingCart object to update
 * 
 * returns - Updated ShoppingCart object
 */
ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart){
    if(GetNumItemsInCart(cart) < 10){
        cart.cartItems[cart.cartSize - 1] = item;
        cart.cartSize++;
        printf("name %s\n", cart.customerName);
        PrintItemDescription(item);
        return cart;
    }
    else {
        printf("Error: the item was not added because the ShoppingCart is full.");

        return cart;
    }

}

/* RemoveItem: Remove the first occurrance of an item (starting with position 0) from the 
 *   ShoppingCart that matches the specified name. To remove the item, shift all of the 
 *   items after it in the cartItems array down by one position. Finally, decrement cartSize.
 * 
 *   If there are no matching items in the ShoppingCart or if the ShoppingCart is empty, display a message in the terminal
 *   stating that no matching items were found and make no changes to the ShoppingCart.  
 * 
 *   Return the ShoppingCart object when finished.
 * 
 * name - NULL teminitate string containing item name
 * cart - ShoppingCart object to update
 * 
 * returns - Updated ShoppingCart object
 */
ShoppingCart RemoveItem(char name[], ShoppingCart cart){

    int rc = 0;

    for(int i = 0; i < cart.cartSize; i++){
        
        if(strcmp((cart.cartItems[i]).itemName, name) == 0){
            
            while(i < cart.cartSize){
                cart.cartItems[i] = cart.cartItems[i + 1];
            }
            rc = 1;
            cart.cartSize--;
        }
    }

    if(rc == 1){
        printf("ERROR: no matching items were found and make no changes to the ShoppingCart.");
    }

    return cart;
}

int GetNumItemsInCart(ShoppingCart cart){
    return cart.cartSize;
}

int GetCostOfCart(ShoppingCart cart){

    int totalCost = 0;

    for(int i = 0; i < cart.cartSize; i++){
        totalCost += cart.cartItems[i].itemPrice * cart.cartItems[i].itemQuantity;
    }

    return totalCost;
}

void PrintInvoice(ShoppingCart cart){
    /*
    John Doe's Shopping Cart - February 1, 2016
    Number of Items: 8

    Nike Romaleos 2 @ $189 = $378
    Chocolate Chips 5 @ $3 = $15
    Powerbeats Headphones 1 @ $128 = $128

    Total: $521
    */
    int totalCost = 0;
    int itemCost = 0;

    printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of items: %d\n\n", GetNumItemsInCart(cart));
    
    for(int i = 0; i < GetNumItemsInCart(cart); i++){
        itemCost = cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice;
        PrintItemCost(cart.cartItems[i]);
        totalCost+=itemCost;
        PrintItemDescription(cart.cartItems[i]);
    }
}

void PrintDescriptions(ShoppingCart cart){
    
    for(int i = 0; i < cart.cartSize; i++){
        PrintItemDescription(cart.cartItems[i]);
    }
}