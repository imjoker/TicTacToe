#include "Shapes.hpp"

// GenericShapes

template <typename T>
void 
GenericShapes::DrawHorizontalLine (UINT8 pStartXPos, UInt8 pStartYPos, UInt8 pSpanLen, T Color, UInt8 pLineThickness) noexcept
{
        UInt8 xpos;
        UInt8 thickness;

    pSpanLen   = 2 * pSpanLen;                            // to bring equality in interpretation of span length between horizontal (X-axis) and vertical (Y-axis) span lengths
    pStartXPos = 2 * pStartXPos;                          // (i.e. cursor length = 2 * length that is taken to print one character)

    PrintFormatter::SetPrintColor<T> (Color, Color);

    for (thickness = 0; thickness < pLineThickness; ++thickness) {

        CursorUtils::SetCursorPos (pStartXPos, pStartYPos + thickness);

        for (xpos = 0; xpos < pSpanLen; ++xpos)
            cout << " ";                                 

    }

    PrintFormatter::ResetPrintColor ();
}

template <typename T>
void 
GenericShapes::DrawVerticalLine (UINT8 pStartXPos, UInt8 pStartYPos, UInt8 pSpanLen, T Color, UInt8 pLineThickness) noexcept
{
        UInt8 ypos;
        UInt8 thickness;

    pStartXPos = pStartXPos * 2;                                       // to bring equality in interpretation of span length between horizontal (X-axis) and vertical (Y-axis) span lengths           

    PrintFormatter::SetPrintColor<T> (Color, Color);

    for (ypos = 0; ypos < pSpanLen; ++ypos) {

        CursorUtils::SetCursorPos (pStartXPos, pStartYPos + ypos);

        for (thickness = 0; thickness < pLineThickness; ++thickness)   
            cout << "  ";                                              // print two spaces to equate the interpretation of thicknes between horizontal and vertical lines

    }

    PrintFormatter::ResetPrintColor ();
}

template <typename T>
void
GenericShapes::DrawX (UInt8 pStartXPos, UInt8 pStartYPos, T pColor) noexcept 
{
    
        UInt8 i;

    PrintFormatter::SetPrintColor (pColor);

    pStartXPos = 2 * pStartXPos;

    for (i = 0; i < sNumRowsInShapeX; ++i) {

        CursorUtils::SetCursorPos (pStartXPos, pStartYPos + i);
        cout << sXShape[i];
    }
}

template <typename T>
void
GenericShapes::DrawO (UInt8 pStartXPos, UInt8 pStartYPos, T pColor)  noexcept
{

        UInt8 i;

    PrintFormatter::SetPrintColor (pColor);

    pStartXPos = 2 * pStartXPos;

    for (i = 0; i < sNumRowsInShapeO; ++i) {

        CursorUtils::SetCursorPos (pStartXPos, pStartYPos + i);
        cout << sOShape[i];
    }
}
