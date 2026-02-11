**EX3 2026 \- Functions and Arrays**

General instructions  
The T.A responsible for this exercise is Eyal Dayan.

* You must fork the repository ex3 from the [course’s git](https://github.com/CSI-BIU/ex3).  
* Change ex3.c according to instructions.  
* After completing all the requirements, submit it to the [submit system](https://submit.cs.biu.ac.il/cgi-bin/welcome.cgi) under **ex3** til **10.12.25 at 23:59:59**.  
* Your submission should be a zip file containing:  
  * .git folder (after fork and clone, as you did in ex0).  
  * ex3.c  
  * README.md (optional)  
* Late submissions will be fined accordingly:  
  * One day \- 10 points. (the maximum grade is 90\)  
  * Two days \- 20 points.  
  * Three days \- 30 points.  
  * **You can’t submit this or any other exercise more than 3 days late.**  
* Please post any questions about the exercise **publicly** in the course forum.  
* Requests for an extension (for justified reasons only) should be sent to the email: [CSI.BIU2024@gmail.com](mailto:CSI.BIU2024@gmail.com) **with:**  
* Full Name.  
* Your Submit system username.  
* ID.

The input and output design instructions must be read carefully, exactly according to the attached examples.  
There are executable programs (Linux) in the forum, each with different dimensions.  
You can run them on your computer and it may help you understand better.  
The automation grading system checks that your output is the same as the expected output and therefore your output must be **exactly the same** as the examples.  
As so, there is a Coding Style file in the forum \- read it and work accordingly.  
Testing your code on the server is highly recommended to ensure there are no warnings or errors.  
An exercise that will have warning(s) or error(s) will get a fine that can reach 100 points.  
You are reminded that thinking together is a blessing, working together is cheating.  
An exercise that the system will catch as a “copy” will result in **0** \- for everyone involved, and additional actions will take place.

In the development of your code, you can use any work environment.  
The main thing is that you know how to take the code files from this environment, check them on the university servers, and submit them using the submission system.  
Please note that you submit only the files containing your code, and not unnecessary files created by the work environment.  
Also, **DO NOT** submit files/folders with names containing Hebrew characters.  
Please note that it is not possible to copy a file with a path containing Hebrew characters to the university's servers.

This exercise compile command (Linux) is:  
gcc \-std=c99 \-Wall \-Wextra \-Werror \-DNDEBUG \-DROWS=6 \-DCOLS=7 ex3.c \-o ex3.out \-lm

Please note the following orders about the compile command in the first section of the file.

---

**Exercise 3 \- Connect 4**

In this exercise we will implement a version of the game **Connect Four**.  
In the classic version of the game two players play against each other.  
Each player has tokens of one shape and on each turn the player drops a token into a board that consists of columns and rows.  
The goal of the game is to connect n tokens of the same color in a continuous vertical, horizontal or diagonal line before the opponent manages to do so.

In our version we will implement two types of players:

**Human player** \- the program will ask the user to choose a column into which they want to insert a token.  
**Computer player** \- the computer will choose a column according to a priority order that will be defined later.

**Game values via compilation flags**  
The board dimensions will be received as constant values through the compilation command using the \-D flag.  
So, if you want to test different dimensions you need to compile it with different flags.  
for example, this compilation command:  
**gcc \-std=c99 \-Wall \-Wextra \-Werror \-DNDEBUG \-DROWS=8 \-DCOLS=10 ex3.c \-o ex3.out \-lm**  
Will set the number of rows to 8, the number of columns to 10.  
The code must work even if we change the board dimensions by changing these constants.  
”Magic numbers” should not appear in the code.  
You can assume the following assumption:  
The minimum board dimension will be 1 \[including 1\].  
***Please note:*** you cannot change the name of those define values, and you cannot remove the \#ifndef and the \#endif before and after each defined value.

**Program flow**  
After the compilation, we are running the program normally **./ex3.out**  
And then, **we start:**

We are printing the dimension and the sequence needed for the current game:  
**Connect Four (6 rows x 7 cols)**  
You are given this printf command in the git code.

Then, the user should be asked to choose the type of the first player and then the type of the second player. Any combination of players is possible (4 ordered options in total).  
**Choose type for player 1: h \- human, c \- computer: h**  
**Choose type for player 2: h \- human, c \- computer: c**  
Please note, you cannot assume anything about the input, beside it will be ASCII characters.  
Lucky for you, this function is also given to you in the git file.

After we get the players, we will:  
1\. Print an empty game board.  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
 **1 2 3 4 5 6 7**  
**Note that the function to print the board is also given to you in the git file**

2\. Ask the first player to play and print the updated board.  
If the player is a human it should print the following message:  
**Player {PLAYER NUMBER} (X) turn.**  
**Enter column (1-{NUMBER OF COLUMNS}):**   
And let the player choose a column to drop the token at.  
If the player is a computer it should print the following messages:  
**Player {PLAYER NUMBER} (X) turn.**  
**Computer chose column {CHOSEN COLUMN}**  
with the chosen column of the computer.  
and then print the updated board. for example:  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|X|.|.|.|**  
 **1 2 3 4 5 6 7**

3\. Ask the second player to play and print the updated board.  
4\. Continue in this manner until the end of the game.  
**For example:**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
 **1 2 3 4 5 6 7**  
**Player 1 (X) turn.**  
**Enter column (1-7): 4**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|X|.|.|.|**  
 **1 2 3 4 5 6 7**  
**Player 2 (O) turn.**  
**Computer chose column 4**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|O|.|.|.|**  
**|.|.|.|X|.|.|.|**  
 **1 2 3 4 5 6 7**  
**Player 1 (X) turn.**  
**Enter column (1-7): 3**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|O|.|.|.|**  
**|.|.|X|X|.|.|.|**  
 **1 2 3 4 5 6 7**  
**Player 2 (O) turn.**  
**Computer chose column 5**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|.|.|.|.|**  
**|.|.|.|O|.|.|.|**  
**|.|.|X|X|O|.|.|**  
 **1 2 3 4 5 6 7**  
**Player 1 (X) turn.**  
**Enter column (1-7):**

In this Example, we chose the first player to be a human \- “h”, and the second player to be a computer \- “c”.  
Then, we printed the empty board.  
At the start \- we waited for input \[a number for the column\], and printed the board after his choice.  
Then, because it was the computer turn, we printed the board after the computer choice immediately \[there is no input waiting time\].  
And so on.

The logic above is also relevant for 2 human players \[just do the human logic in each turn\], and 2 computer players \[just print their choices until one wins\].

At the end of the game, print an appropriate victory message after printing the winning board:  
**|.|.|O|O|X|X|.|**  
**|.|.|X|X|X|O|.|**  
**|.|O|O|O|O|X|.|**  
**|.|X|X|X|O|O|X|**  
**|.|X|O|O|X|X|O|**  
**|O|O|O|X|X|X|O|**  
 **1 2 3 4 5 6 7**  
**Player 2 (O) wins\!**

If no free columns remain and no player has created a sequence of 4 tokens \- the game ends in a tie.  
print the following message:  
**Board full and no winner. It's a tie\!**  
Victory detection should be performed on every move in four directions: vertical, horizontal and diagonals.

**Behavior of the Human player**  
This player may choose any column. If the chosen column is illegal, a message will be displayed and the player will be asked to choose again.  
As follows:  
**Enter column (1-7): 8**  
**Invalid column. Choose between 1 and 7\.**  
**Player 1 (X) turn.**  
**Enter column (1-7): 4**  
**Column 4 is full. Choose another column.**  
**Enter column (1-7): a**  
**Invalid input. Enter a number.**  
**Enter column (1-7):**    
   
	  
**d**  
**Invalid input. Enter a number.**  
**Enter column (1-7): \-1**  
**Invalid column. Choose between 1 and 7\.**  
**Enter column (1-7):** 

Please notice that the behavior of invalid input is:

1. If it’s a number that is not in range of the valid columns \- we will output: “Invalid column. Choose between 1 and b.” When b is the number of columns we have.  
2. If it’s a number in the valid range, but the column is already full, we will print “Column x is full. Choose another column.” When x is the number the user tried to enter.  
3. If it’s not a number, and not white space character, we will output: “Invalid input. Enter a number.”  
4. If it’s a white-space character, we will ignore it.

**Behavior of the computer player**  
This player will choose a column according to a defined priority order. If several columns share the same priority level they should be chosen according to the ordering rule described below.

Priority order  
1\. **Winning move** \- if it is possible to win on the next move \- choose the column that produces the win.  
2\. **Blocking the opponent** \- if the opponent can win on their next move choose the column that prevents this.  
3\. **Creating a sequence of three** \- if it is possible to create a sequence of three tokens do so.  
4\. **Blocking the opponent’s sequence of three**.  
5\. Choosing according to the **arbitrary ordering rule**.

*Programming tip:* each type of player (human or computer) should return only the chosen column number. The game engine is responsible for checking legality, performing the move and updating the board.

Ordering rule for columns  
When several options have the same priority level, choose a column according to the following rules:  
1\. Prefer the column whose distance from the center column is minimal.  
2\. If the distance is equal, choose the left column among the two.

**For example:**  
If there are 7 columns the ordering is:  
4 \-\> 3 \-\> 5 \-\> 2 \-\> 6 \-\> 1 \-\> 7

If there are 6 columns the ordering is:  
3 \-\> 4 \-\> 2 \-\> 5 \-\> 1 \-\> 6

**Full running Example. 4 X 4 board \- two computers**  
**Connect Four (4 rows x 4 cols)**  
**Choose type for player 1: h \- human, c \- computer: c**  
**Choose type for player 2: h \- human, c \- computer: c**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Computer chose column 2**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|X|.|.|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 2**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|O|.|.|**  
**|.|X|.|.|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Computer chose column 2**  
**|.|.|.|.|**  
**|.|X|.|.|**  
**|.|O|.|.|**  
**|.|X|.|.|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 2**  
**|.|O|.|.|**  
**|.|X|.|.|**  
**|.|O|.|.|**  
**|.|X|.|.|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Computer chose column 3**  
**|.|O|.|.|**  
**|.|X|.|.|**  
**|.|O|.|.|**  
**|.|X|X|.|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 1**  
**|.|O|.|.|**  
**|.|X|.|.|**  
**|.|O|.|.|**  
**|O|X|X|.|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Computer chose column 4**  
**|.|O|.|.|**  
**|.|X|.|.|**  
**|.|O|.|.|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 3**  
**|.|O|.|.|**  
**|.|X|.|.|**  
**|.|O|O|.|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Computer chose column 3**  
**|.|O|.|.|**  
**|.|X|X|.|**  
**|.|O|O|.|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 1**  
**|.|O|.|.|**  
**|.|X|X|.|**  
**|O|O|O|.|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Computer chose column 4**  
**|.|O|.|.|**  
**|.|X|X|.|**  
**|O|O|O|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 1**  
**|.|O|.|.|**  
**|O|X|X|.|**  
**|O|O|O|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Computer chose column 1**  
**|X|O|.|.|**  
**|O|X|X|.|**  
**|O|O|O|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 4**  
**|X|O|.|.|**  
**|O|X|X|O|**  
**|O|O|O|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Computer chose column 3**  
**|X|O|X|.|**  
**|O|X|X|O|**  
**|O|O|O|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 4**  
**|X|O|X|O|**  
**|O|X|X|O|**  
**|O|O|O|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Board full and no winner. It's a tie\!**

**Full running Example. 10 X 4 board \- human and computer**

**Connect Four (10 rows x 4 cols)**  
**Choose type for player 1: h \- human, c \- computer: h**  
**Choose type for player 2: h \- human, c \- computer: c**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Enter column (1-4): 2**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|X|.|.|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 2**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|O|.|.|**  
**|.|X|.|.|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Enter column (1-4): 3**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|O|.|.|**  
**|.|X|X|.|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 1**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|O|.|.|**  
**|O|X|X|.|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Enter column (1-4): 3**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|O|X|.|**  
**|O|X|X|.|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 3**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|O|.|**  
**|.|O|X|.|**  
**|O|X|X|.|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Enter column (1-4): 4**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|O|.|**  
**|.|O|X|.|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 2**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|O|O|.|**  
**|.|O|X|.|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Enter column (1-4): 4**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|O|O|.|**  
**|.|O|X|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 2**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|O|.|.|**  
**|.|O|O|.|**  
**|.|O|X|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Enter column (1-4): 2**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|X|.|.|**  
**|.|O|.|.|**  
**|.|O|O|.|**  
**|.|O|X|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 4**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|X|.|.|**  
**|.|O|.|.|**  
**|.|O|O|O|**  
**|.|O|X|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 1 (X) turn.**  
**Enter column (1-4): 1**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|X|.|.|**  
**|.|O|.|.|**  
**|.|O|O|O|**  
**|X|O|X|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) turn.**  
**Computer chose column 1**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|.|.|.|**  
**|.|X|.|.|**  
**|.|O|.|.|**  
**|O|O|O|O|**  
**|X|O|X|X|**  
**|O|X|X|X|**  
 **1 2 3 4**  
**Player 2 (O) wins\!**

**Full running Example. 5 X 5 board \- human and human**

**Connect Four (5 rows x 5 cols)**  
**Choose type for player 1: h \- human, c \- computer: h**  
**Choose type for player 2: h \- human, c \- computer: h**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
 **1 2 3 4 5**  
**Player 1 (X) turn.**  
**Enter column (1-5): 0**  
**Invalid column. Choose between 1 and 5\.**  
**Enter column (1-5): a**  
**Invalid input. Enter a number.**  
**Enter column (1-5):**   
	   
**7**  
**Invalid column. Choose between 1 and 5\.**  
**Enter column (1-5): 3**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|X|.|.|**  
 **1 2 3 4 5**  
**Player 2 (O) turn.**  
**Enter column (1-5): 1**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|O|.|X|.|.|**  
 **1 2 3 4 5**  
**Player 1 (X) turn.**  
**Enter column (1-5): 3**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|X|.|.|**  
**|O|.|X|.|.|**  
 **1 2 3 4 5**  
**Player 2 (O) turn.**  
**Enter column (1-5): 2**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|X|.|.|**  
**|O|O|X|.|.|**  
 **1 2 3 4 5**  
**Player 1 (X) turn.**  
**Enter column (1-5): 3**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|X|.|.|**  
**|.|.|X|.|.|**  
**|O|O|X|.|.|**  
 **1 2 3 4 5**  
**Player 2 (O) turn.**  
**Enter column (1-5): 4**  
**|.|.|.|.|.|**  
**|.|.|.|.|.|**  
**|.|.|X|.|.|**  
**|.|.|X|.|.|**  
**|O|O|X|O|.|**  
 **1 2 3 4 5**  
**Player 1 (X) turn.**  
**Enter column (1-5): 3**  
**|.|.|.|.|.|**  
**|.|.|X|.|.|**  
**|.|.|X|.|.|**  
**|.|.|X|.|.|**  
**|O|O|X|O|.|**  
 **1 2 3 4 5**  
**Player 1 (X) wins\!**

Good Luck\!