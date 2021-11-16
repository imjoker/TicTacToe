# TicTacToe

The classic Tic-Tac-Toe game (Noughts and Crosses) is a game for two players named X and O, who take turns marking the empty spaces in a 3×3 grid. Whichever player first succeeds in marking either an entire row, or a column, or a diagonal is considered winner.

The game is built without use of any open-source graphic libraries or game engines. Developed basic utility using C++, to support the implementation of the game.

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
  - In AI mode, using `Sleep()` to give user a feel that he is actually playing with another human player even when he/she is playing with AI.

