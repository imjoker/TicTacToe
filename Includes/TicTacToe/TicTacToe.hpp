#pragma once

#include "MenuScene.hpp"

enum class eBoxState : UInt8 {

    UNFILLED,    // indicates that box is not filled yet
    X,           // indicates that box is filled with X
    O,           // indicates that box is filled with O
};

enum class eGameStatus : UInt8 {

    RUNNING,     // game is still running
    DRAW,        // game is over, and we have no winner
    WIN,         // game is over, and we have a winners
};

enum class eGameWonIn : UInt8 {

    ROW,         // game won in row
    COLUMN,      // game won in column
    LEFT_DIAG,   // game won in left diag
    RIGHT_DIAG,  // game won in right diag
    UNKNOWN,     
};

class TicTacToe {

	public:

static        void            Init                      () noexcept;

static        void            DrawGame                  () noexcept;

              template <typename T>
static        void            SetColorOfX               (T pColor) noexcept;
              template <typename T>
static        void            SetColorOfO               (T pColor) noexcept;

static        void            SetStartPlayer            (eBoxState pPlayer) noexcept;

static        eGameStatus     GetGameStatus             () noexcept;

static        bool            IsBoxEmpty                (UInt8 pBoardRow, UInt8 pBoardCol) noexcept;

static        void            ToggleTurn                () noexcept;
static        eBoxState       GetCurrentTurn            () noexcept;

static        void            ToggleWinnigLine          () noexcept;

    protected:

static        void            GetRowCol                 (UInt8 pIdx, UInt8  & pOutRow, UInt8 & pOutCol) noexcept;

static        bool            SetBoxWithUserInput       (UInt8 pChar, eBoxState pStateToSet) noexcept;
static        void            SetBoxState               (UInt8 pBoardRow, UInt8 pBoardCol, eBoxState pState) noexcept;

    private:

static        void            DrawBoard                 (UInt8 pBoardFactor) noexcept;

static        void            DrawBoxState              (UInt8 pStartXPos, UInt8 pStartYPos, UInt8 pBoardRow, UInt8 pBoardCol, eBoxState pState) noexcept;
static        void            ClearBox                  (UInt8 pBoardRow, UInt8 pBoardCol) noexcept;

static        void            DrawDigit                 (UInt8 pStartXPos, UInt8 pStartYPos, UInt8 pBoardRow, UInt8 pBoardCol) noexcept;
static        void            DrawX                     (UInt8 pStartXPos, UInt8 pStartYPos, UInt8 pBoardRow, UInt8 pBoardCol) noexcept;
static        void            DrawO                     (UInt8 pStartXPos, UInt8 pStartYPos, UInt8 pBoardRow, UInt8 pBoardCol) noexcept;

static        eGameStatus     GameWonInRow              (UInt8 pLineNum) noexcept;
static        eGameStatus     GameWonInColumn           (UInt8 pLineNum) noexcept;
static        eGameStatus     GameWonInLeftDiag         () noexcept;
static        eGameStatus     GameWonInRightDiag        () noexcept;

static        void            ToggleRow                 () noexcept;
static        void            ToggleColumn              () noexcept;
static        void            ToggleLeftDiag            () noexcept;
static        void            ToggleRightDiag           () noexcept;

    protected:

        using DrawBoxStateFunc = void (*) (UInt8 pStartXPos, UInt8 StartYPos, UInt8 pBoardRow, UInt8 pBoardCol);
        using ToggleWinFunc    = void (*) ();

    // function mappings

static constexpr DrawBoxStateFunc sDrawBoxState[3]      { DrawDigit, DrawX, DrawO };
static constexpr ToggleWinFunc    sToggleWinningLine[4] { ToggleRow, ToggleColumn, ToggleLeftDiag, ToggleRightDiag };

    // constants 

static constexpr UInt8            sBoardStartXPos       { 35 };
static constexpr UInt8            sBoardStartYPos       { 10 };
static constexpr UInt8            sSpacePerBlock        { 7 };

static constexpr tCoord           sInstructionsCoord    {70, 5};

    // properties 

static constexpr ColorCode        sColorOfBoard         {GRAY};
static constexpr ColorCode        sColorOfX             {DARK_RED};
static constexpr ColorCode        sColorOfO             {DARK_BLUE};

    // properties

static           eBoxState        sBoardStates [3][3];
static           UInt8            sUnfilledBoxes;
static           eBoxState        sCurrTurn;

static           eBoxState        sWinner;
static           UInt8            sWinningLine;
static           eGameWonIn       sWonIn;

static           DynamicText      sErrMsg; 

          DISALLOW_ON_STACK (TicTacToe);
          DISALLOW_COPY (TicTacToe);
          NO_NEW;
};

#include "TicTacToe.hxx"  // TicTacToe