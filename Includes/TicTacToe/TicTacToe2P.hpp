#pragma once

#include "TicTacToe.hpp"

class TicTacToe2P : public TicTacToe {

    public:

static    bool       UpdateInput     (UInt8 pChar) noexcept;

static    eBoxState  GetCurrWinner   () noexcept;

          DISALLOW_ON_STACK (TicTacToe2P);
          DISALLOW_COPY (TicTacToe2P);
          NO_NEW;
};

#include "TicTacToe2P.hxx"
