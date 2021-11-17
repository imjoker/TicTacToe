# TicTacToe

The classic Tic-Tac-Toe game (Noughts and Crosses) is a game for two players named X and O, who take turns marking the empty spaces in a 3×3 grid. Whichever player first succeeds in marking either an entire row, or a column, or a diagonal is considered winner.

The game is built without use of any open-source graphic libraries or game engines. Implemented basic utility using C++, to support the implementation of the game.

### Features include:
- **Multiple modes:**
  - Two player mode
  - Play with AI mode
- **AI Algorithm:**
  - AI is built using Mini-Max Algorithm, which is combined with Alpha-Beta pruning to decrease the number of evaluated nodes, and thereby increasing efficiency.
- **Navigation:**
  - Clicking Escape returns the player from any non-Menu scene, back to the Menu.
  - To exit game: Can select Exit option provided in the Menu. Alternatively, can also click Escape when in the Menu.
- **User Experience:**
  - Colored content, instructions, and symbols to provide a optimal user experience for a game developed with no graphic support.
  - For invalid user inputs, clear instruction is conveyed to the user to understand what they might have done wrong. Please refer to "handling invalid user inputs" below for sample.
  - Whenever a player wins, the line which caused the win is toggled till user interrupts.
  - In AI mode, using `Sleep()` to give user a feel that he is actually playing with another human player even when he/she is playing with AI.

### Demo game play:
https://user-images.githubusercontent.com/13928177/142049385-029661de-d1d3-427d-b8ee-980061491ed1.mp4

### Handling invalid user inputs:
https://user-images.githubusercontent.com/13928177/142056328-c830a23b-0bef-4ceb-8510-cf71ae3869e0.mp4

