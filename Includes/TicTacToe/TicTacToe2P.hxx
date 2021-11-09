
bool 
TicTacToe2P::UpdateInput (UInt8 pChar) noexcept
{
    return SetBoxWithUserInput (pChar, sCurrTurn);
}

inline eBoxState
TicTacToe2P::GetCurrWinner () noexcept
{
    return sWinner;
}