My bricker code is comprised of three different functions, a display board function, check move function and main function.

In the display board function the bricker game board is created and modified depending on the player’s input string and the coordinates entered during game. Firstly, the x axis and the top boarder. After player X is assigned to 0 and player O to 1. This is important as in the main current player was defined to -1 to ensure that when the initial board was built it did not place a token. The string is fed through a series of test cases which analyse where to place * boarders around X and O, and to print space when ‘E’ is present. The function then builds the rest of the game board.

In the check_move function the code ensures that the space nominated by a player is blank and that the move is valid.

When the game is started, if the player has input a string, the game will use this board data, otherwise a blank string is created. Players’ turns are switched, stopping only to congratulate the last player as the winner if there are no empty spaces left.
