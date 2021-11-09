#pragma once

#include "Basic.hpp"

#include <string>

#if (WIN_KERNEL)
 static constexpr UInt8 BLACK       { 0 };
 static constexpr UInt8 DARK_BLUE   { 1 };
 static constexpr UInt8 DARK_GREEN  { 2 };
 static constexpr UInt8 LIGHT_BLUE  { 3 };
 static constexpr UInt8 DARK_RED    { 4 };
 static constexpr UInt8 MAGENTA     { 5 };
 static constexpr UInt8 ORANGE      { 6 };
 static constexpr UInt8 LIGHT_GRAY  { 7 };
 static constexpr UInt8 GRAY        { 8 };
 static constexpr UInt8 BLUE        { 9 };
 static constexpr UInt8 GREEN       { 10 };
 static constexpr UInt8 CYAN        { 11 };
 static constexpr UInt8 RED         { 12 };
 static constexpr UInt8 PINK        { 13 };
 static constexpr UInt8 YELLOW      { 14 };
 static constexpr UInt8 WHITE       { 15 };

 static const HANDLE gHandle = GetStdHandle (STD_OUTPUT_HANDLE);

 using ColorCode = UInt8;

#else
 static constexpr const char * BLACK       { "30" };
 static constexpr const char * DARK_BLUE   { "34"};
 static constexpr const char * DARK_GREEN  { "32" };
 static constexpr const char * LIGHT_BLUE  { "36" };
 static constexpr const char * DARK_RED    { "31" };
 static constexpr const char * MAGENTA     { "35" };
 static constexpr const char * ORANGE      { "33" };
 static constexpr const char * LIGHT_GRAY  { "37" };
 static constexpr const char * GRAY        { "90" };
 static constexpr const char * BLUE        { "94" };
 static constexpr const char * GREEN       { "92" };
 static constexpr const char * CYAN        { "96" };
 static constexpr const char * RED         { "91" };
 static constexpr const char * PINK        { "95" };
 static constexpr const char * YELLOW      { "93" };
 static constexpr const char * WHITE       { "97" };
 
 static                 string gString = "\033[";

 using ColorCode = const char *;

#endif


class PrintFormatter {

    public:

          // print interfaces in desired colors

          template <typename T>
static    void                     PrintAndReset               (const string & s, const T & pTextColor) noexcept;
          template <typename T>
static    void                     PrintAndReset               (const string & s, const T & pTextColor, const T & pBackGroundColor) noexcept;
          template <typename T>
static    void                     PrintNoReset                (const string & s, const T & pTextColor) noexcept;
          template <typename T>
static    void                     PrintNoReset                (const string & s, const T & pTextColor, const T & pBackGroundColor) noexcept;

          // set/reset printing color

          template <typename T>
static    void                     SetPrintColor               (const T & pTextColor) noexcept;
          template <typename T>
static    void                     SetPrintColor               (const T & pTextColor, const T & pBackGroundColor) noexcept;

static    void                     SetColorCodeForText         (UInt8 pColorCode) noexcept;

static    void                     ResetPrintColor             () noexcept;

    
          // dis-allowing stack instances or head instances and copy operators

          DISALLOW_ON_STACK (PrintFormatter);
          DISALLOW_COPY (PrintFormatter);
          NO_NEW;
};

#include "PrintFormatter.hxx"

 