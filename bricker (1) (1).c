#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BOARD_SIZE 5 
#define PLAYER_1 0
#define PLAYER_2 1


/* this function converts the string input or move input data into a game board in the terminal */

void display_board(char *board_data, int *row, int *col, int player) {





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
