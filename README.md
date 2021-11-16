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
  - Clicking Escape returns player from any game (even when the game is on-going) back to Menu.
  - To exit game: Select Exit option provided in Menu. Alternatively, can click Escape when in Menu.
- **User Experience:**
  - Colored content, instructions, and symbols to provide a optimal user experience for a game developed with no graphic support.
  - Upon wrong inputs such as trying to mark a space that has already been occupied (or) clicking invalid key to mark a space (or) wrong inputs to user prompts given before start of the level => Clear instruction is conveyed to the user to understand what they might have done wrong. Please see these screenshots.
  - Whenever a player wins, the line which caused the win is toggled till user interrupts.
  - In AI mode, using `Sleep()` to give user a feel that he is actually playing with another human player even when he/she is playing with AI.

### Demo game play:
https://user-images.githubusercontent.com/13928177/142049385-029661de-d1d3-427d-b8ee-980061491ed1.mp4

### Handling invalid user inputs by proper conveying proper instructions:
