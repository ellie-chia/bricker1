#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BOARD_SIZE 5 
#define PLAYER_1 0
#define PLAYER_2 1


/* this function converts the string input or move input data into a game board in the terminal */

void display_board(char *board_data, int *row, int *col, int player) {

   /* x refers to x axis(rows), y refers to y axis(column) */

   int x = *row, y = *col;
   int index = x * BOARD_SIZE + y;

   /* printing x axis and the top boarder of game board */

   printf("  ");
   for (int i = 0; i < BOARD_SIZE; i++) {
      printf("%d", i);
   }
   printf("\n");
   printf(" ");
   for (int i = 0; i < 7; i++) {
      printf("*");
   }
   printf("\n");

   /* establishes that player 0 uses an X character and player 1 uses O character */

   if (player == PLAYER_2 || player == PLAYER_1) {
      if (player == PLAYER_1) {
         board_data[index] = 'X';
      } 
      else if (player == PLAYER_2) {
         board_data[index] = 'O';
      }
      

      /* if cases that show where to put * surrounding X and O game tokens depending on where they are placed on the game board */

      /* left top corner case */

      if (x == 0 && y == 0) {
         board_data[((x + 0) * BOARD_SIZE) + (y + 1)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 1)] = '*';
      }

      /* right top corner case */

      else if (x == 0 && y == 4) {
         board_data[((x + 0) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y - 1)] = '*';
      }

      /* left bottom corner case */

      else if (x == 4 && y == 0) {
         board_data[((x + 0) * BOARD_SIZE) + (y + 1)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y + 1)] = '*';
      }

      /* right bottom corner case */

      else if (x == 4 && y == 4) {
         board_data[((x + 0) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y - 1)] = '*';
      }
      /* left edge case */

      else if (y == 0) {
         board_data[((x - 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y + 1)] = '*';
         board_data[((x + 0) * BOARD_SIZE) + (y + 1)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 1)] = '*';
      }
      
      /* right edge case */

      else if (y == 4) {
         board_data[((x - 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x + 0) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y - 1)] = '*';
      }

      /* top edge case */

      else if (x == 0) {
         board_data[((x + 0) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x + 0) * BOARD_SIZE) + (y + 1)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 1)] = '*';
      }

      /* bottom edge case */

      else if (x == 4) {
         board_data[((x + 0) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x + 0) * BOARD_SIZE) + (y + 1)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y + 1)] = '*';
      }
      
      /* all other cases */

      else {
         board_data[((x - 1) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x + 0) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y - 1)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 0)] = '*';
         board_data[((x - 1) * BOARD_SIZE) + (y + 1)] = '*';
         board_data[((x + 0) * BOARD_SIZE) + (y + 1)] = '*';
         board_data[((x + 1) * BOARD_SIZE) + (y + 1)] = '*';
      }
   }

   /* print the row's y axis number and * boarder on left */
   
   for (int row = 0; row < BOARD_SIZE; row++) {
      printf("%d*", row);

      /* if there is an E identified in the string print a blank space. Otherwise print the corresponding X, O or * character */

      for (int col = 0; col < BOARD_SIZE; col++) {
         char cell = board_data[row * BOARD_SIZE + col];
         if (cell == 'E') {
            printf(" ");
         }
         else {
            printf("%c", cell);
         } 
      }

      /* print the right game board data */

      printf("*\n");

   }


   /* print bottom of the game board*/

   printf(" ");
   for (x = 0; x < BOARD_SIZE + 2; x++) {
      printf("*");
      }
   printf("\n");
   
}



/* this function checks if the move that the players have made is valid */

int check_move(char *board_data, int x, int y) {

   /* checks if there is still empty space in the game board and if the corresponding coordinates entered by the player is empty */

   while ((strchr(board_data, 'E')) != NULL) {
      int index = y + x * BOARD_SIZE;
      if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board_data[index] == 'E' && board_data[index] != '*') {
      
      /* 1 means that the space is empty */

         return 1;
      } 
      else {

      /* 0 means that the space is not empty */

         return 0;
      }
   }
}



/* main function of program */

int main(int argc, char *argv[]) {

   /* establishing the integers and characters */

   int row = 0;
   int col = 0;
   int winner = 0;
   char board_data[BOARD_SIZE * BOARD_SIZE + 1];
   int index = col + row * BOARD_SIZE;
   int current_player = -1;
   
   /* checks if string is entered for initial board data. If so, will print a specific board, if not will print an empty board */
   
   if (argc == 2) {
      strcpy(board_data, argv[1]);
   }
   else if (argc == 1) {
      strcpy(board_data, "EEEEEEEEEEEEEEEEEEEEEEEEE");
   }
   else {
      printf("Incorrect number of arguments!\n");
      return 0;
   }

   /* checks if the string entered by player is correct */
 
   if (strlen(board_data) == 25) {
      size_t valid_string;
      valid_string = strspn(board_data, "XO*E");
      if (valid_string == strlen(board_data)) {
      }
      else {
         printf("Invalid initial board data!\n");
         return 0;
      }
   }
   else {
      printf("Invalid initial board data!\n");
      return 0;
   }
   
   /* starts game and displays board */

   printf("Welcome to Bricker!\n");
   display_board(board_data, &row, &col, current_player);

   /* while there is still empty space on the board the game will continue to ask for inputs from players */

   while((strchr(board_data, 'E')) != NULL) {

      /* switches current player */

      current_player = ((current_player + 1) % 2);
      printf("Player %d turn: ", current_player + 1);
      scanf("%d %d", &row, &col);

      /* checks input in the check_move function and if valid, displays board */

      int is_valid = check_move(board_data, row, col);
      if (is_valid == 1) {
         display_board(board_data, &row, &col, current_player);
      } 
      else {
         printf("Invalid Move!\n");
         current_player--;
      }
   }

   /* if there is no more empty space on board the game will declare the winner as the last person who placed a game token down */

   if(current_player == PLAYER_1) {
      printf("Player 1 Wins!\n");
      return 0;
   }
   else {
      printf("Player 2 Wins!\n");
      return 0;
   }
}
