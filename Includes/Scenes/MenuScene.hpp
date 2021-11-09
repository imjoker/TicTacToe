#pragma once

#include "Text.hpp"

#define NUM_OPTIONS 3

static  constexpr  const char   sTitle[]    { "\3-X-\3 TIC-TAC-TOE \3-O-\3" };
static  constexpr  const char   sChoose[]   { "Choose an option and click Enter" };
static  constexpr  const char   sOption1[]  { "Play with AI" };
static  constexpr  const char   sOption2[]  { "2 Player mode" };
static  constexpr  const char   sOption3[]  { "Exit"  };
static  constexpr  const char   sXShape[]   { "X" };
static  constexpr  const char   sHeart[]    { "\3" };
static  constexpr  const char   sOShape[]   { "O" };

enum class eMenuOption : UInt8 {

    PLAY_WITH_AI,
    TWO_P_MODE,
    EXIT,
    MAX,
};

class MenuScene {

    public:

                  void                Init                   () noexcept;
                      
                  void                DrawMenu               () noexcept;
        
                  void                MoveUp                 () noexcept;
                  void                MoveDown               () noexcept;

                  eMenuOption         GetCurrOption          () noexcept;

    private:

static constexpr  ColorCode           sInactiveOptColor      {CYAN};
static constexpr  ColorCode           sActiveOptColor        {RED};

        UInt8                         vCurrOption;             // current selected option in the menu

        // text

        StaticText<sizeof(sTitle)>    vTitle                 {sTitle, tCoord {77, 10}};
        StaticText<sizeof(sChoose)>   vChoose                {sChoose, tCoord {73, 13}};

        StaticText<sizeof(sOption1)>  vOption1               {sOption1, tCoord {80, 16}};
        StaticText<sizeof(sOption2)>  vOption2               {sOption2, tCoord {80, 18}};
        StaticText<sizeof(sOption3)>  vOption3               {sOption3, tCoord {80, 20}};
        TextBase  *                   vOptions[NUM_OPTIONS]  {&vOption1, &vOption2, &vOption3};

        StaticText<sizeof(sXShape)>   vXShape                {sXShape};
        StaticText<sizeof(sHeart)>    vHeart                 {sHeart};
        StaticText<sizeof(sOShape)>   vOShape                {sOShape};
        TextBase  *                   vOptShape[NUM_OPTIONS] {&vXShape, &vHeart, &vOShape};
};

#include "MenuScene.hxx" 
