#include <stdio.h>

const int TEAM_SIZE = 5;

int main(void) {

   int jerseyArray[TEAM_SIZE];
   int ratingArray[TEAM_SIZE];
   char menuChoice = ' ';
   int i, rc, rc1, jerseyInput, ratingInput = 0;

   for(i = 0; i < TEAM_SIZE; i++){
      
      rc = 0;
      while(rc == 0){
         
         printf("Enter player %d's jersey number:\n", i + 1);
         rc = scanf(" %d", &jerseyArray[i]);
         
         if (rc == 0){
            while( getchar() != '\n');
            printf("Error: Non-integer value detected, please check your data and try again\n");
         }
         else if (jerseyArray[i] < 0 || jerseyArray[i] > 99){
            rc = 0;
            while( getchar() != '\n');
            printf("Error: Non-existent jersey number selected, please check your data and try again\n");
         }
      }

      rc = 0;
      while(rc == 0){

         printf("Enter player %d's rating:\n", i + 1);
         rc = scanf(" %d", &ratingArray[i]);

         if (rc == 0){
            while( getchar() != '\n');
            printf("Error: Non-integer value detected, please check your data and try again\n");
         }
         else if (ratingArray[i] < 1 || ratingArray[i] > 9){
            rc = 0;
            while( getchar() != '\n');
            printf("Error: Non-existent rating number selected, please check your data and try again\n");
         }
      }

      printf("\n");
   }

   printf("ROSTER:\n");

   for(i = 0; i < TEAM_SIZE; i++){
      printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jerseyArray[i], ratingArray[i]);
   }

   rc = 0;
   while(rc == 0){
      printf(
         "\nMENU\n"
         "u - Update player rating\n"
         "a - Output players above a rating\n"
         "r - Replace player\n"
         "o - Output roster\n"
         "q - Quit\n\n"
         "Choose an option:\n"
      );
      scanf(" %c", &menuChoice);

      switch(menuChoice){
         case 'u':
         // update
            rc = 0;
            rc1 = 0;
            
            printf("Enter a jersey number:\n");
            rc = scanf(" %d", &jerseyInput);
            
            if (rc == 0){
               while( getchar() != '\n');
               printf("Error: Non-integer value detected, please check your data and try again\n");
               break;
            }
            else if (jerseyInput < 0 || jerseyInput > 99){
               rc = 0;
               while( getchar() != '\n');
               printf("Error: Non-existent jersey number selected, please check your data and try again\n");
               break;
            }

            for(i = 0; i < TEAM_SIZE; i++){
               rc = 0;
               rc1 = 0;
               if(jerseyArray[i] == jerseyInput){
                  printf("Enter a rating:\n");
                  rc = scanf(" %d", &ratingInput);
                  
                  if (rc == 0){
                     while( getchar() != '\n');
                     printf("Error: Non-integer value detected, please check your data and try again\n");
                     rc1 = 1;
                     break;
                  }
                  else if (ratingInput < 1 || ratingInput > 9){
                     while( getchar() != '\n');
                     printf("Error: Non-existent rating number selected, please check your data and try again\n");
                     rc1 = 1;
                     break;
                  }
                  
                  ratingArray[i] = ratingInput;
                  rc1 = 1;
                  break;
               }
            }

            if(rc1 == 0) printf("Error: Non-existent jersey number selected, please check your data and try again\n");
            break;
         
         case 'a':
            //Above rating
            rc = 0;
            printf("Enter a rating:\n", i + 1);
            rc = scanf(" %d", &ratingInput);

            if (rc == 0){
               while( getchar() != '\n');
               printf("Error: Non-integer value detected, please check your data and try again\n");
               break;
            }
            else if (ratingInput < 1 || ratingInput > 9){
               while( getchar() != '\n');
               printf("Error: Non-existent rating number selected, please check your data and try again\n");
               break;
            }
            
            printf("ABOVE %d\n", ratingInput);
            for(i = 0; i < TEAM_SIZE; i++){
               if(ratingArray[i] > ratingInput){
                  printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jerseyArray[i], ratingArray[i]);
               }
            }

            break;
         
         case 'r':
         // replace
            rc = 0;
            rc1 = 0;

            printf("Enter a jersey number:\n");
            rc = scanf(" %d", &jerseyInput);

            if (rc == 0){
               while( getchar() != '\n');
               printf("Error: Non-integer value detected, please check your data and try again\n");
               break;
            }
            else if (jerseyInput < 0 || jerseyInput > 99){
               rc = 0;
               while( getchar() != '\n');
               printf("Error: Non-existent jersey number selected, please check your data and try again\n");
               break;
            }

            for(i = 0; i < TEAM_SIZE; i++){
               if(jerseyArray[i] == jerseyInput){
                  rc = 0;
                  printf("Enter a new jersey number:\n");
                  rc = scanf(" %d", &jerseyInput);

                  if (rc == 0){
                     while( getchar() != '\n');
                     printf("Error: Non-integer value detected, please check your data and try again\n");
                     rc1 = 1;
                     break;
                  }
                  else if (jerseyInput < 0 || jerseyInput > 99){
                     while( getchar() != '\n');
                     printf("Error: Non-existent jersey number selected, please check your data and try again\n");
                     rc1 = 1;
                     break;
                  }

                  jerseyArray[i] = jerseyInput;

                  printf("Enter a rating for the new player:\n", i + 1);
                  rc = scanf(" %d", &ratingInput);

                  if (rc == 0){
                     while( getchar() != '\n');
                     printf("Error: Non-integer value detected, please check your data and try again\n");
                  }
                  else if (ratingInput < 1 || ratingInput > 9){
                     rc = 0;
                     while( getchar() != '\n');
                     printf("Error: Non-existent rating number selected, please check your data and try again\n");
                  }
                  
                  ratingArray[i] = ratingInput;
                  rc = 1;
                  rc1 = 1;
                  break;
               }
            }

            if(rc1 == 0) printf("Error: Non-existent jersey number selected, please check your data and try again\n");
            break;
         
         case 'o': 
            printf("ROSTER:\n");

            for(i = 0; i < TEAM_SIZE; i++){
               printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jerseyArray[i], ratingArray[i]);
            }

            break;
         
         case 'q':
            return 0;
         
         default:
            printf("Error: Unknown option selected\n");
         
      }

      rc = 0;
   }

   return 1;
}