#include "TicTacToe.hpp"
#include <conio.h>

/********** initializing static class members ************/

eBoxState        TicTacToe::sBoardStates [3][3]  {eBoxState::UNFILLED};
UInt8            TicTacToe::sUnfilledBoxes       {9};
eBoxState        TicTacToe::sCurrTurn            {eBoxState::UNFILLED};
DynamicText      TicTacToe::sErrMsg              {};
eBoxState        TicTacToe::sWinner              {eBoxState::UNFILLED};
UInt8            TicTacToe::sWinningLine         {3};
eGameWonIn       TicTacToe::sWonIn               {eGameWonIn::UNKNOWN};

/******************* interfaces *******************/

void
TicTacToe::Init () noexcept
{
        UInt8 i;
        UInt8 j;

    for (i = 0; i < 3; ++i) {

        for (j = 0; j < 3; ++j)
            sBoardStates[i][j] = eBoxState::UNFILLED;
    }

    //sMode          = pMode;
    sWinner        = eBoxState::UNFILLED;
    sCurrTurn      = eBoxState::UNFILLED;
    sUnfilledBoxes = 9;

    sErrMsg.SetColor (GREEN);
    sErrMsg.SetCoord (sInstructionsCoord);
}

void
TicTacToe::DrawGame () noexcept 
{
        UInt8 x;
        UInt8 y;

    DrawBoard (3);

    x = sBoardStartXPos + 1;    // + 1 to leave one position empty at the start
    y = sBoardStartYPos + 1;    // + 1 to leave one position empty at the start

    for (UInt8 i = 0; i < 3; ++i) {

        for (UInt8 j = 0; j < 3; ++j) {

            DrawBoxState (x, y + ((sSpacePerBlock + 1) * j), j, i, sBoardStates[j][i]);       // + 1 to account for the margin lines
        }

        x = x + sSpacePerBlock + 1;     // + 1 to account for the margin lines
    }
}

// Draws 'pBoardFactor x pBoardFactor' board

void
TicTacToe::DrawBoard (UInt8 pBoardFactor) noexcept 
{
        UInt8 spanlen;
        UInt8 idx_row;
        UInt8 idx_col;

    spanlen = pBoardFactor * sSpacePerBlock;    // to allow 'spaceperblock' positions per box
    spanlen += (pBoardFactor - 1);              // for inter-mediate lines that help create blocks in the board.

    idx_row = sSpacePerBlock + sBoardStartXPos;
    idx_col = sSpacePerBlock + sBoardStartYPos;

    while (--pBoardFactor) {                    // we need pBoardFactor - 1 number of rows & columns to make a square board.

        GenericShapes::DrawVerticalLine (idx_row, sBoardStartYPos, spanlen, sColorOfBoard);
        GenericShapes::DrawHorizontalLine (sBoardStartXPos, idx_col, spanlen, sColorOfBoard);

        idx_row += (sSpacePerBlock + 1);
        idx_col += (sSpacePerBlock + 1);
    }
}

void
TicTacToe::DrawBoxState (UInt8 pStartXPos, UInt8 pStartYPos, UInt8 pBoardRow, UInt8 pBoardCol, eBoxState pState) noexcept 
{

    sDrawBoxState[(UInt8) pState] (pStartXPos, pStartYPos, pBoardRow, pBoardCol);
}

void 
TicTacToe::ClearBox (UInt8 pBoardRow, UInt8 pBoardCol) noexcept
{
        UInt8 xpos;
        UInt8 ypos;
        UInt8 numrows;

    xpos = (sBoardStartXPos + (pBoardRow * sSpacePerBlock) + pBoardRow) * 2;
    ypos = sBoardStartYPos + (pBoardCol * sSpacePerBlock)  + pBoardCol;

    for (numrows = sSpacePerBlock; numrows > 0; --numrows) {
            
        CursorUtils::SetCursorPos (xpos, ypos);        

        cout << "              ";

        ++ypos;
    }
}

void
TicTacToe::DrawDigit (UInt8 pStartXPos, UInt8 pStartYPos, UInt8 pBoardRow, UInt8 pBoardCol) noexcept
{
        UInt8 digit;

    digit =  ((pBoardRow * 3) + 1) + (pBoardCol);        // calculate the digit that represents the box at [pBoardRow, pBoardCol]

    pStartXPos = (pStartXPos + (sSpacePerBlock / 2) - 1) * 2;
    pStartYPos = pStartYPos + (sSpacePerBlock / 2) - 1;

    PrintFormatter::SetPrintColor (WHITE);

    CursorUtils::SetCursorPos (pStartXPos, pStartYPos);
    PrintFormatter::SetColorCodeForText (88);
    cout << " " + std::to_string (digit) + " ";

}

void
TicTacToe::DrawX (UInt8 pStartXPos, UInt8 pStartYPos, [[maybe_unused]]UInt8 pBoardRow, [[maybe_unused]]UInt8 pBoardCol) noexcept 
{

    GenericShapes::DrawX (pStartXPos, pStartYPos, sColorOfX);
}

void
TicTacToe::DrawO (UInt8 pStartXPos, UInt8 pStartYPos, [[maybe_unused]]UInt8 pBoardRow, [[maybe_unused]]UInt8 pBoardCol) noexcept 
{

    GenericShapes::DrawO (pStartXPos, pStartYPos, sColorOfO);
}

template <typename T>
void
TicTacToe::SetColorOfX (T pColor) noexcept
{
    sColorOfX = pColor;
}

template <typename T>
void
TicTacToe::SetColorOfO (T pColor) noexcept
{
    sColorOfO = pColor;
}

void
TicTacToe::SetBoxState (UInt8 pBoardRow, UInt8 pBoardCol, eBoxState pState) noexcept
{
    sBoardStates[pBoardRow][pBoardCol] = pState;

    if (pState != eBoxState::UNFILLED)
        --sUnfilledBoxes;
    else 
        ++sUnfilledBoxes;
}

eGameStatus 
TicTacToe::GetGameStatus () noexcept
{
        UInt8 pos;

    // checking for the win in rows/columns
    
    for(pos = 0; pos < 3; pos++) {

        if (sBoardStates[pos][0] == sBoardStates[pos][1] && sBoardStates[pos][0] == sBoardStates[pos][2] && sBoardStates[pos][0] != eBoxState::UNFILLED)
            return GameWonInRow (pos);

        if (sBoardStates[0][pos] == sBoardStates[1][pos] && sBoardStates[0][pos] == sBoardStates[2][pos] && sBoardStates[0][pos] != eBoxState::UNFILLED)
            return GameWonInColumn (pos);
    }

    // checking for the win for both diagonals

    if(sBoardStates[0][0] == sBoardStates[1][1] && sBoardStates[0][0] == sBoardStates[2][2] && sBoardStates[0][0] != eBoxState::UNFILLED)
        return GameWonInLeftDiag ();

    if(sBoardStates[0][2] == sBoardStates[1][1] && sBoardStates[0][2] == sBoardStates[2][0] && sBoardStates[0][2] != eBoxState::UNFILLED)
        return GameWonInRightDiag ();

    // checking if the game is a draw

    if (!sUnfilledBoxes)               // if all boxes are filled, and yet no winning criteria is hit, then the game is a draw
        return eGameStatus::DRAW;

    return eGameStatus::RUNNING;
}

inline bool
TicTacToe::IsBoxEmpty (UInt8 pBoardRow, UInt8 pBoardCol) noexcept
{
    return (sBoardStates[pBoardRow][pBoardCol] == eBoxState::UNFILLED);
}

inline void 
TicTacToe::GetRowCol (UInt8 pIdx, UInt8 & pOutRow, UInt8 & pOutCol) noexcept
{
    --pIdx;

    pOutRow = pIdx / 3;
    pOutCol = pIdx % 3;
}

inline eGameStatus
TicTacToe::GameWonInRow (UInt8 pLineNum) noexcept
{
    sWinner      = sBoardStates[pLineNum][0];
    sWinningLine = pLineNum;
    sWonIn       = eGameWonIn::ROW;

    return eGameStatus::WIN;
}

inline eGameStatus
TicTacToe::GameWonInColumn (UInt8 pLineNum) noexcept
{
    sWinner      = sBoardStates[0][pLineNum];
    sWinningLine = pLineNum;
    sWonIn       = eGameWonIn::COLUMN;

    return eGameStatus::WIN;
}

inline eGameStatus
TicTacToe::GameWonInLeftDiag () noexcept
{
    sWinner = sBoardStates[0][0];
    sWonIn  = eGameWonIn::LEFT_DIAG;

    return eGameStatus::WIN;
}

inline eGameStatus
TicTacToe::GameWonInRightDiag () noexcept
{  
    sWinner = sBoardStates[0][2];
    sWonIn  = eGameWonIn::RIGHT_DIAG;

    return eGameStatus::WIN;
}

void TicTacToe::ToggleRow () noexcept
{
    // toggle the winning row which got triple
    
    while (!_kbhit ()) {        // repeat till user interrupts

        // clear the states in the winning row

        PrintFormatter::ResetPrintColor ();

        ClearBox (0, sWinningLine);
        ClearBox (1, sWinningLine);
        ClearBox (2, sWinningLine);

        Sleep (400);

        // Draw them back

        DrawGame ();

        Sleep (400);
    }
}

void
TicTacToe::ToggleColumn () noexcept
{
    // toggle the winning column which got triple
    
    while (!_kbhit ()) {        // repeat till user interrupts

        // clear the states in the winning column

        PrintFormatter::ResetPrintColor ();

        ClearBox (sWinningLine, 0);
        ClearBox (sWinningLine, 1);
        ClearBox (sWinningLine, 2);

        Sleep (400);

        // Draw them back

        DrawGame ();

        Sleep (400);
    }
}

void
TicTacToe::ToggleLeftDiag () noexcept
{
    // toggle the winning diagnol which got triple
    
    while (!_kbhit ()) {        // repeat till user interrupts

        // clear the states in the winning diag

        PrintFormatter::ResetPrintColor ();

        ClearBox (0, 0);
        ClearBox (1, 1);
        ClearBox (2, 2);

        Sleep (400);

        // Draw them back

        DrawGame ();

        Sleep (400);
    }
}

void
TicTacToe::ToggleRightDiag () noexcept
{
    // toggle the winning diagnol which got triple
    
    while (!_kbhit ()) {        // repeat till user interrupts

        // clear the states in the winning diag

        PrintFormatter::ResetPrintColor ();

        ClearBox (0, 2);
        ClearBox (1, 1);
        ClearBox (2, 0);

        Sleep (400);

        // Draw them back

        DrawGame ();

        Sleep (400);
    }
}

inline void 
TicTacToe::ToggleTurn () noexcept
{
    if (sCurrTurn == eBoxState::O)
        sCurrTurn = eBoxState::X;
    else
        sCurrTurn = eBoxState::O;
}

inline bool
TicTacToe::SetBoxWithUserInput (UInt8 pChar, eBoxState pStateToSet) noexcept
{
        Int8  boxidx;
        UInt8 row;
        UInt8 col;

    boxidx = GetIntegerFromASCII (pChar);

    if (boxidx == -1) {

        sErrMsg.SetText ("ERROR: Please enter only a digit displayed in the empty boxes.        ");
        sErrMsg.Draw ();
        return false;
    }

    GetRowCol (boxidx, row, col);

    if (!IsBoxEmpty (row, col)) {

        sErrMsg.SetText ("ERROR: Please choose an empty box. The chosen box is already occupied.");
        sErrMsg.Draw ();
        return false;
    }

    SetBoxState (row, col, pStateToSet);
    sErrMsg.SetText ("                                                                        ");
    sErrMsg.Draw ();

    return true;
}

inline void
TicTacToe::SetStartPlayer (eBoxState pPlayer) noexcept
{
    sCurrTurn = pPlayer;
}

inline eBoxState 
TicTacToe::GetCurrentTurn () noexcept
{
    return sCurrTurn;
}

void 
TicTacToe::ToggleWinnigLine () noexcept
{
    sToggleWinningLine [(UInt8) sWonIn] ();
}
