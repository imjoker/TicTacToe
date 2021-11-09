#include "PrintFormatter.hpp"

template <typename T>
void
PrintFormatter::PrintAndReset (const string & s, const T & pTextColor) noexcept
{

    SetPrintColor (pTextColor);
    cout << s;    
    ResetPrintColor ();
}

template <typename T>
void
PrintFormatter::PrintAndReset (const string & s, const T & pTextColor, const T & pBackGroundColor) noexcept 
{

    SetPrintColor (pTextColor, pBackGroundColor);
    cout << s;
    ResetPrintColor ();
}

template <typename T>
void
PrintFormatter::PrintNoReset (const string & s, const T & pTextColor) noexcept
{
    // print with color, but don't reset color afterwards (faster)

    SetPrintColor (pTextColor);
    cout << s;
}

template <typename T>
void
PrintFormatter::PrintNoReset (const string & s, const T & pTextColor, const T & pBackGroundColor) noexcept
{
    // print with color, but don't reset color afterwards (faster)

    SetPrintColor (pTextColor, pBackGroundColor);
    cout << s;
}

template <typename T>
void 
PrintFormatter::SetPrintColor (const T & pTextColor) noexcept
{

#if (WIN_KERNEL)        
    
    SetConsoleTextAttribute (gHandle, pTextColor);

#else  // LIN_KERNEL
    
    gString.replace (2, 2, pTextColor);
    gString.replace (4, 1, "m");
    gString.erase (5);

    cout << gString;
#endif
}

template <typename T>
void 
PrintFormatter::SetPrintColor (const T & pTextColor, const T & pBackGroundColor) noexcept
{

#if (WIN_KERNEL)        

    SetConsoleTextAttribute (gHandle, pBackGroundColor << 4 | pTextColor);

#else // LIN_KERNEL

    gString.replace (2, 2, pBackGroundColor);
    gString.replace (4, 1, ";");
    gString.replace (5, 2, pTextColor);
    gString.replace (7, 1, "m");
    gString.erase (8);

    cout << gString;
#endif
}

void 
PrintFormatter::SetColorCodeForText (UInt8 pColorCode) noexcept
{
    cout << "\u001b[48;5;" + std::to_string (pColorCode) + "m";
}

void
PrintFormatter::ResetPrintColor () noexcept
{

#if (WIN_KERNEL)
    SetConsoleTextAttribute (gHandle, 7);  // reset color
#elif defined(__linux__)
    cout << "\033[0m";                     // reset color
#endif
}

