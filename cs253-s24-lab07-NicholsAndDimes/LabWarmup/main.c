/* 
 * Author: Chris Nichols
 * Date: 2024-02-24
 * Description: Analyzes text, length, output without whitespace
 */


#include<stdio.h>
#include <string.h>

//Returns the number of characters in usrStr
int GetNumOfCharacters(const char usrStr[]) {
   
   int charCount = 0;
   while (usrStr[charCount] != '\0') charCount ++;

   return charCount;
}

//outputs the string's characters except for whitespace
void OutputWithoutWhitespace(char usrStr[]){

   printf("String with no whitespace: ");

   for (size_t i = 0; i < strlen(usrStr); i++){
      if(!(*(usrStr + i) == ' ' || *(usrStr + i) == '\t')){
         printf("%c", *(usrStr + i));
      }
   }

   printf("\n");
}


int main(void) {

   const int MAX_CHAR = 50;
   int charCount = 0;
   char usrStr[MAX_CHAR];

   printf("Enter a sentence or phrase:\n");
   fgets(usrStr, MAX_CHAR, stdin);

   usrStr[strlen(usrStr) - 1] = '\0';
   // scanf("%s", &usrStr);
   printf("\nYou entered: %s\n", usrStr);

   charCount = GetNumOfCharacters(usrStr);

   printf("\nNumber of characters: %d\n", charCount);
   OutputWithoutWhitespace(usrStr);

   return 0;
}

/*Problem Description

1. Prompt the user to enter a string of their choosing, assuming a 49 character maximum. Output the string.
Note: If we create an array of size 50 to hold the string, the user will in fact only be able to enter 49 characters because the array will need to also hold the trailing null ('\0') character.


Expected Program Output (with sample user input)
Enter a sentence or phrase:
The only thing we have to fear is fear itself.

You entered: The only thing we have to fear is fear itself.


2. Complete the GetNumOfCharacters() function, which returns the number of characters in the user's string. Make sure to count the trailing newline character if applicable.
We encourage you to use a for loop in this function.


3. In main(), call the GetNumOfCharacters() function and then output the returned result.


4. Implement the OutputWithoutWhitespace() function. OutputWithoutWhitespace() outputs the string's characters except for whitespace (spaces, tabs). Note: A tab is '\t'. Call the OutputWithoutWhitespace() function in main().


Expected Program Output (with sample user input)
Enter a sentence or phrase:
The only thing we have to fear is fear itself.

You entered: The only thing we have to fear is fear itself.

Number of characters: 47
String with no whitespace: Theonlythingwehavetofearisfearitself.

Error Handling
The following describes the expected behavior in the event of unexpected user input

If the user enters a string with more than 49 characters, simply truncate it and process the truncated result
Implementation Guide
Expand the folder named LabWarmup and open the file named main.c
Enter the program code to create an application as described in the Problem Description.
Test the program using the above example to ensure it functions as expected.
Commit the changes to your local repository with a message stating that LabWarmup is completed.
Push the changes from your local repository to the github classroom repository.
Update the Coding Journal with an entry describing your experience using the steps outlined below.*/