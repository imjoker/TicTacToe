#pragma once

#include "TicTacToe2P.hpp"

#ifndef MAX
#define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b)            (((a) < (b)) ? (a) : (b))
#endif

struct tBenefitIndex {

    Int8  uBenefit; 
    Int8  uRowIdx;
    Int8  uColIdx;
};

class TicTacToeAI : public TicTacToe {

    public:

static  bool                UpdateInput       (UInt8 pChar) noexcept;

static  void                SetAIChoice       () noexcept;

static  bool                IsAIWon           () noexcept;

    // members

static  eBoxState           sAIState;
static  eBoxState           sPlayerState;

    private:

static  tBenefitIndex       AlphaBeta         (Int8 alpha, Int8 beta, bool player) noexcept;

          DISALLOW_ON_STACK (TicTacToeAI);
          DISALLOW_COPY (TicTacToeAI);
          NO_NEW;
};

#include "TicTacToeAI.hxx"
