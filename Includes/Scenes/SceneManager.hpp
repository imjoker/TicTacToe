       #pragma once

#include "TicTacToeAI.hpp"

static constexpr const char   sNavigation[] {"Press escape to return to Main Menu."};
static constexpr const char * sXWonStr      {"X has won the game. Press any key to return to Main Menu."};
static constexpr const char * sOWonStr      {"O has won the game. Press any key to return to Main Menu."};
static constexpr const char * sAIWonStr     {"AI has won the game. Press any key to return to Main Menu."};
static constexpr const char * sYouWonStr    {"You have won the game.  Press any key to return to Main Menu."};

class SceneManager {

	public:

		void          Init                            () noexcept;

		void          UpdateInput                     (UInt8 pKey) noexcept;

		void          Draw                            () noexcept;

	private:

		void          EnterAIMode                     () noexcept;
		bool          PlayTurn                        () noexcept;

		void          Enter2PMode                     () noexcept;

		void          UpdateMenu                      (UInt8 pKey) noexcept;

		void          DisplayCharSelectErrMsg         () noexcept;
		void          DisplayYesNoSelectErrMsg        () noexcept;
		void          DisplayFirstPlayerErrMsg        () noexcept;

	private:

	    MenuScene                           vMenu;
		DynamicText                         vInstruction;
		StaticText<sizeof (sNavigation)>    vNavigation    {sNavigation, tCoord {2, 2}};
		tCoord                              vInstrctCoord  {70, 7};

static constexpr const char * sAIModeWin[2] {sYouWonStr, sAIWonStr};
static constexpr const char * s2PModeWin[2] {sOWonStr, sXWonStr};
};

#include "SceneManager.hxx"
