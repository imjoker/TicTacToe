#pragma once

#include "PrintFormatter.hpp"

#if (WIN_KERNEL)

 static const HANDLE gStdHandle = GetStdHandle (STD_OUTPUT_HANDLE);
 static       COORD  gCoord;

#endif

 struct tCoord {

     UInt8 uXCoord;
     UInt8 uYCoord;
 };

class CursorUtils {

    public:

static    void      SetCursorPos       (UInt8 pXPos, UInt8 pYPos) noexcept;
static    void      SetCursorPos       (const tCoord & pCoord) noexcept;

        // dis-allowing stack instances or head instances and copy operators

        DISALLOW_ON_STACK (CursorUtils);
        DISALLOW_COPY (CursorUtils);
        NO_NEW;
};

#include "CursorUtils.hxx"

