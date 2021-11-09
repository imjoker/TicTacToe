#pragma once

#include "CursorUtils.hpp"

class GenericShapes {

	public:

              template <typename T>
static        void                        DrawHorizontalLine        (UINT8 pStartXPos, UInt8 pStartYPos, UInt8 pSpanLen, T Color, UInt8 pLineThickness = 1) noexcept;
              template <typename T>
static        void                        DrawVerticalLine          (UINT8 pStartXPos, UInt8 pStartYPos, UInt8 pSpanLen, T Color, UInt8 pLineThickness = 1) noexcept;

              template <typename T>
static        void                        DrawX                     (UInt8 pStartXPos, UInt8 pStartYPos, T pColor) noexcept;
              template <typename T>
static        void                        DrawO                     (UInt8 pStartXPos, UInt8 pStartYPos, T pColor) noexcept;

    private:

static constexpr       UInt8    sSizeOfO                   { 5 };
static constexpr       UInt8    sNumRowsInShapeX           { 5 };
static constexpr       UInt8    sNumRowsInShapeO           { 5 };

static constexpr const char *   sXShape[sNumRowsInShapeX]  { "±±±    ±±±", 
                                                             " ±±±  ±±±", 
                                                             "  ±±±±±±", 
                                                             " ±±±  ±±±",
                                                             "±±±    ±±±" };

static constexpr const char *   sOShape[sNumRowsInShapeO]  { "±±±±±±±±±±", 
                                                             "±±      ±±", 
                                                             "±±      ±±", 
                                                             "±±      ±±",
                                                             "±±±±±±±±±±" };
};

#include "Shapes.hxx"   // Shapes