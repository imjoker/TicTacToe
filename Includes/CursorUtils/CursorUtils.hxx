

inline void
CursorUtils::SetCursorPos (UInt8 pXPos, UInt8 pYPos) noexcept 
{
   
#if (WIN_KERNEL)
    gCoord.X = pXPos;
    gCoord.Y = pYPos;
    
    SetConsoleCursorPosition (gStdHandle, gCoord);
#else
    printf("\033[%d;%dH", pYPos+1, pXPos+1);
#endif
}

inline void
CursorUtils::SetCursorPos (const tCoord & pCoord) noexcept
{
    SetCursorPos (pCoord.uXCoord, pCoord.uYCoord);
}


/*
- Position the Cursor:
  \033[<L>;<C>H
     Or
  \033[<L>;<C>f
  puts the cursor at line L and column C.
- Move the cursor up N lines:
  \033[<N>A
- Move the cursor down N lines:
  \033[<N>B
- Move the cursor forward N columns:
  \033[<N>C
- Move the cursor backward N columns:
  \033[<N>D
 
- Clear the screen, move to (0,0):
  \033[2J
- Erase to end of line:
  \033[K
 
- Save cursor position:
  \033[s
- Restore cursor position:
  \033[u
*/
