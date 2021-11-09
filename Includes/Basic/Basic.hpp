#pragma once

#include <iostream>
#include <stdio.h>

#if (_WIN32 || _WIN64)
    #define WIN_KERNEL 1
#else
    #define LIN_KERNEL 1
#endif

#if (WIN_KERNEL)

    #define WIN32_LEAN_AND_MEAN
    #define VC_EXTRALEAN
    #include <Windows.h>                       

#endif // Windows

#if (WIN_KERNEL)
    using UInt8   =  unsigned _int8;
    using UInt16  =  unsigned _int16;
    using UInt32  =  unsigned _int32;
    using UInt64  =  unsigned _int64;
    using Int8    =  signed _int8;
    using Int16   =  signed _int16;
    using Int32   =  signed _int32;
    using Int64   =  signed _int64;
#else                                          // linux kernel (MAC OS, iOS, Android, Linux)
    #include    <cstdint>

    using UInt8   =  __uint8_t;
    using UInt16  =  __uint16_t;
    using UInt32  =  __uint32_t;
    using UInt64  =  __uint64_t;
    using Int8    =  __int8_t;
    using Int16   =  __int16_t;
    using Int32   =  __int32_t;
    using Int64   =  __int64_t;
#endif

// ascii values of certain keywords
#define ENTER   13
#define ESCAPE  27
#define ZERO    48
#define ONE     49
#define TWO     50
#define THREE   51
#define FOUR    52
#define FIVE    53
#define SIX     54
#define SEVEN   55
#define EIGHT   56
#define NINE    57

using namespace std;

#define DISALLOW_COPY(ClassName)                    ClassName                (const ClassName &) = delete;         \
                                                    ClassName &  operator =  (const ClassName &) = delete;


#define DISALLOW_ON_STACK(ClassName)                ClassName                () = delete;                           \
                                                    ~ClassName               () = delete;

#define NO_NEW                                                                                                     \
                                                    void * operator new      (std::size_t)            = delete;    \
                                                    void * operator new[]    (std::size_t)            = delete;    \
                                                    void * operator new      (std::size_t, void *)    = delete;    \
                                                    void * operator new[]    (std::size_t, void *)    = delete;    \
                                                    void   operator delete   (void *)                 = delete;    \
                                                    void   operator delete[] (void *)                 = delete;    \
                                                    void   operator delete   (void *, void *)         = delete;    \
                                                    void   operator delete[] (void *, void *)         = delete;


#define GET_MULTIPLE_OF(pValue, pFactor) (((pValue + pFactor - 1U) / pFactor) * pFactor);


Int8
GetIntegerFromASCII (UInt8 pAscii)
{
    switch (pAscii) {

        case ZERO:
            return 0;

        case ONE:
            return 1;

        case TWO:
            return 2;

        case THREE:
            return 3;

        case FOUR:
            return 4;

        case FIVE:
            return 5;

        case SIX:
            return 6;

        case SEVEN:
            return 7;

        case EIGHT:
            return 8;

        case NINE:
            return 9;

        default:
            return -1;
    }
}

bool
IsKeyPressed (UInt8 pKey)
{
	return (GetKeyState (pKey) & 0x8000);
}