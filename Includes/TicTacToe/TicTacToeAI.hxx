
eBoxState TicTacToeAI::sAIState     {eBoxState::UNFILLED};
eBoxState TicTacToeAI::sPlayerState {eBoxState::UNFILLED};

bool 
TicTacToeAI::UpdateInput (UInt8 pChar) noexcept
{
    return SetBoxWithUserInput (pChar, sPlayerState);
}

void
TicTacToeAI::SetAIChoice () noexcept
{
        tBenefitIndex var;
        UInt8         x;
        UInt8         y;


    if (!sUnfilledBoxes)
        return;           // early return

    for (x = 0; x < 3; ++x) {

        for (y = 0; y < 3; ++y) {

            if (IsBoxEmpty (x, y)) {

                SetBoxState (x, y, sAIState);

                if (GetGameStatus() == eGameStatus::WIN)
                    return;

                SetBoxState (x, y, eBoxState::UNFILLED);
            }
        }
    }

    var = AlphaBeta (-100, 100, true);

    SetBoxState (var.uRowIdx, var.uColIdx, sAIState);  // AI is X
}

inline bool
TicTacToeAI::IsAIWon () noexcept
{
    return (sWinner == sAIState);
}

tBenefitIndex
TicTacToeAI::AlphaBeta (Int8 alpha, Int8 beta, bool player) noexcept
{
 
        eGameStatus    status;
        tBenefitIndex  var;
        UInt8          x;
        UInt8          y;
        Int8           x_idx {-1};
        Int8           y_idx {-1};

     status = GetGameStatus ();
    
    if (status != eGameStatus::RUNNING) {

        var.uRowIdx = -1;
        var.uColIdx = -1;

        switch (status) {

            case eGameStatus::DRAW:
                var.uBenefit = 0;
                break;

            case eGameStatus::WIN:
                var.uBenefit = (sWinner == sAIState) ? 10 : -10;
                break;
        }

        return var;
    }

    if (player == true) {

            Int8 maxi;

        maxi = -100;    // Max. possible score of sAIState

        // Check all possible moves
        for (x = 0; x < 3; ++x) {

            for (y = 0; y < 3; ++y) {

                if (IsBoxEmpty (x, y)) {

                    SetBoxState (x, y, sAIState);

                    var = AlphaBeta (alpha, beta, !player);

                    if (maxi < var.uBenefit) {

                        maxi = var.uBenefit;
                        x_idx  = x;
                        y_idx  = y;

                        alpha = MAX (alpha, maxi);

                        if (beta <= alpha) {

                            SetBoxState (x, y, eBoxState::UNFILLED);
                            break;
                        }
                    }

                    // Unfill this box
                    SetBoxState (x, y, eBoxState::UNFILLED);
                }
            }
        }

        var.uRowIdx  = x_idx;
        var.uColIdx  = y_idx;
        var.uBenefit = maxi;

        return var;

    } else {

            Int8 mini;

        mini = 100;   // Min. possible score of sPlayerState

        for (x = 0; x < 3; ++x) {

            for (y = 0; y < 3; ++y) {

                if (IsBoxEmpty (x, y)) {

                    SetBoxState (x, y, sPlayerState);

                    var = AlphaBeta (alpha, beta, !player);

                    if(mini > var.uBenefit) {

                        mini   = var.uBenefit;
                        x_idx = x;
                        y_idx = y;

                        beta = MIN (beta , mini);

                        if (beta <= alpha) {

                            SetBoxState (x, y, eBoxState::UNFILLED);
                            break;
                        }
                    }

                    SetBoxState (x, y, eBoxState::UNFILLED);
                }
            }

        }

        var.uRowIdx  = x_idx;
        var.uColIdx  = y_idx;
        var.uBenefit = mini;

        return var;
    }
}
