/* 
 * Author: Chris Nichols
 * Date: 2024-02-24
 * Description: Analyzes text, length, output without whitespace
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void PrintMenu(char usrStr[]){
   
   int rc = 0;
   char menuSelection = ' ';

   while(rc == 0){
      printf(
         "\nMENU\n"
         "c - Number of non-whitespace characters\n"
         "w - Number of words\n"
         "f - Fix capitalization\n"
         "r - Replace all !'s\n"
         "s - Shorten spaces\n"
         "q - Quit\n\n"
         "Choose an option:\n"
         );

      scanf(" %c", &menuSelection);

      switch (menuSelection){
         case 'c': 
            GetNumOfNonWSCharacters(usrStr);
            break;
         case 'w':
            GetNumOfWords(usrStr);
            break;
         case 'f':
            FixCapitalization(usrStr);
            break;
         case 'r':
            ReplaceExclamation(usrStr);
            break;
         case 's':
            ShortenSpace(usrStr);
            break;
         case 'q':
            rc = 1;
            break;
         default:
            printf("Invalid\n");
      }
   }
}

void GetNumOfNonWSCharacters(char *usrStr){

   int nonWSCharCount = 0;

   for (size_t i = 0; i < strlen(usrStr); i++){
      if(!(*(usrStr + i) == ' ' || *(usrStr + i) == '\t')){
         nonWSCharCount++;
      }
   }

   printf("\nNumber of non-whitespace characters: %d\n", nonWSCharCount);
}

void GetNumOfWords(char *usrStr){

   int wordCount = 1;

   for (size_t i = 0; i < strlen(usrStr); i++){
      if((*(usrStr + i) == ' ' || *(usrStr + i) == '\t')){
         wordCount++;
      }
   }

   printf("Number of words: %d\n", wordCount);
}

void FixCapitalization(char *usrStr){

   char fixedStr[strlen(*usrStr)];

   fixedStr[0] = *(usrStr);
   toupper(fixedStr[0]);

   for (size_t i = 1; i < strlen(usrStr); i++){

      fixedStr[i] = *(usrStr + i);
      if(i > 1){
         if(fixedStr[i - 2] == '.'){
            toupper(fixedStr[i]);
         }
      }
   }

   printf("Fixed string: %s", fixedStr);
}

void ReplaceExclamation(char *usrStr){

   char fixedStr[strlen(*usrStr)];

   for (size_t i = 0; i < strlen(usrStr); i++){
      if(*(usrStr + i) == '.'){
         fixedStr[i] = "!";
      }
      else{
         fixedStr[i] = *(usrStr + i);
      }
   }

   printf("Fixed string: %s", fixedStr);
}

void ShortenSpace(char *usrStr){

   char fixedStr[strlen(*usrStr)];

   for (size_t i = 0; i < strlen(usrStr); i++){

      if(*(usrStr + i) == ' ' && *(usrStr + i + 1) == ' '){
         *(fixedStr + i) = ' ';
         i++;
      }
      else{
         fixedStr[i] = *(usrStr + i);
      }
   }

   printf("Fixed string: %s", fixedStr);
}



int main(void) {

   const int MAX_CHAR = 256;
   char usrStr[MAX_CHAR];
   
   printf("Enter a sample text:\n");
   fgets(&usrStr, MAX_CHAR, stdin);
   usrStr[strlen(usrStr) - 1] = '\0';
   printf("You entered: %s\n", usrStr);


   PrintMenu(usrStr);

   return 0;
}