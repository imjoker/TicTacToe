
void 
SceneManager::Init () noexcept
{
	vMenu.Init ();

	vInstruction.SetColor (GREEN);
	vInstruction.SetCoord (vInstrctCoord);

	vNavigation.SetColor (YELLOW);
}

void 
SceneManager::UpdateInput (UInt8 pKey) noexcept
{
	UpdateMenu (pKey);
}

void
SceneManager::Draw () noexcept
{
	vMenu.DrawMenu ();
}

void 
SceneManager::EnterAIMode () noexcept
{
		char  p1;

	vInstruction.SetText ("Which character are you: X or O? ");
	vInstruction.Draw ();

	while (1) {	

	    if (scanf_s (" %c", &p1, 1) != 1) {

			DisplayCharSelectErrMsg ();
			continue;
		}

		if (p1 == 'X' || p1 == 'x') {

			TicTacToeAI::sPlayerState = eBoxState::X;
			TicTacToeAI::sAIState     = eBoxState::O;

		}
		else if (p1 == 'O' || p1 == 'o') {

			TicTacToeAI::sPlayerState = eBoxState::O;
			TicTacToeAI::sAIState     = eBoxState::X;

		} else {

			DisplayCharSelectErrMsg ();
			continue;
		}

		break;
	}

	system("cls");

	vInstruction.SetText ("Will you be playing first (Y/N)? ");
	vInstruction.Draw ();

	while (1) {	

	    if (scanf_s (" %c", &p1, 1) != 1) {

			DisplayYesNoSelectErrMsg ();
			continue;
		}

	    if (p1 == 'Y' || p1 == 'y')
			TicTacToe::SetStartPlayer (TicTacToeAI::sPlayerState);
	    else if (p1 == 'N' || p1 == 'n')
			TicTacToe::SetStartPlayer (TicTacToeAI::sAIState);
		else {

			DisplayYesNoSelectErrMsg ();
			continue;
		}

		break;
	}

	system("cls");

	vNavigation.Draw ();

	TicTacToeAI::DrawGame ();	

	while (TicTacToeAI::GetGameStatus () == eGameStatus::RUNNING) {
		
		if (!PlayTurn ())
			return;
	}

	if (TicTacToeAI::GetGameStatus () == eGameStatus::WIN) {
	    
	    vInstruction.SetText (sAIModeWin[TicTacToeAI::IsAIWon ()]);

		vInstruction.Draw ();

		TicTacToeAI::ToggleWinnigLine ();

	} else {

		vInstruction.SetText ("The game is a draw. Press any key to return to Main Menu.");
		vInstruction.Draw ();
	}

	_getch ();
}

bool 
SceneManager::PlayTurn () noexcept
{
		UInt8 keystroke;

	if (TicTacToeAI::GetCurrentTurn () == TicTacToeAI::sAIState) {

		Sleep (300);                  // sleep for 3 seconds before awaking AI

		TicTacToeAI::SetAIChoice ();
		TicTacToeAI::DrawGame (); 
		
		TicTacToeAI::ToggleTurn ();

		return true;
	}

	// else, it is player's turn

	vInstruction.SetText ("Your turn. Please choose a box: ");
	vInstruction.Draw ();

	keystroke = _getch ();

	if (keystroke == ESCAPE)
		return false;

	if (!TicTacToeAI::UpdateInput (keystroke))
		return true;

	vInstruction.SetText ("                                ");
	vInstruction.Draw ();

	TicTacToeAI::DrawGame ();         // update board with user input
    CursorUtils::SetCursorPos (0, 45);

	TicTacToeAI::ToggleTurn ();

	return true;
}

void 
SceneManager::Enter2PMode () noexcept
{
		UInt8 keystroke;
		char  p1;

	vInstruction.SetText ("Who will go first: X or O? ");
	vInstruction.Draw ();

	while (1) {	

	    if (scanf_s (" %c", &p1, 1) != 1) {

			DisplayFirstPlayerErrMsg ();
			continue;
		}

	    if (p1 == 'X' || p1 == 'x')
			TicTacToe::SetStartPlayer (eBoxState::X);
	    else if (p1 == 'O' || p1 == 'o')
			TicTacToe::SetStartPlayer (eBoxState::O);
		else {

			DisplayFirstPlayerErrMsg ();
			continue;
		}

		break;
	}

	system("cls");

	vNavigation.Draw ();

	TicTacToe2P::DrawGame ();

	while (TicTacToeAI::GetGameStatus () == eGameStatus::RUNNING) {

		if (TicTacToe2P::GetCurrentTurn () == eBoxState::X)
		    vInstruction.SetText ("It is X's turn. Please choose a box: ");
		else
		    vInstruction.SetText ("It is O's turn. Please choose a box: ");

		vInstruction.Draw ();

		keystroke = _getch ();

		if (keystroke == ESCAPE)
			return;

		if (!TicTacToe2P::UpdateInput (keystroke))
			continue;

		TicTacToe2P::DrawGame ();

		TicTacToe2P::ToggleTurn ();
	}

	if (TicTacToe2P::GetGameStatus () == eGameStatus::WIN) {

	    vInstruction.SetText (s2PModeWin[TicTacToe2P::GetCurrWinner () == eBoxState::X]);

		vInstruction.Draw ();

		TicTacToeAI::ToggleWinnigLine ();

	} else {

		vInstruction.SetText ("The game is a draw. Press any key to return to Main Menu.");
		vInstruction.Draw ();
	}

	_getch ();
}

void
SceneManager::UpdateMenu (UInt8 pKey) noexcept
{
	if (IsKeyPressed (VK_DOWN))
		return vMenu.MoveUp ();
	
	if (IsKeyPressed (VK_UP))
		return vMenu.MoveDown ();

	if (pKey == ENTER) {

		switch (vMenu.GetCurrOption ()) {

		    case eMenuOption::PLAY_WITH_AI:
				system ("cls");
				EnterAIMode ();
				TicTacToe::Init ();
				PrintFormatter::ResetPrintColor ();
				system ("cls");
				break;

			case eMenuOption::TWO_P_MODE:
				system ("cls");
				Enter2PMode ();
				TicTacToe::Init ();
				PrintFormatter::ResetPrintColor ();
				system ("cls");
				break;

			case eMenuOption::EXIT:
				PrintFormatter::ResetPrintColor ();
				exit (0);
		}
	}

	if (pKey == ESCAPE) {

		PrintFormatter::ResetPrintColor ();
		exit (0);
	}

}

inline void
SceneManager::DisplayCharSelectErrMsg () noexcept
{
	system("cls");
	vInstruction.SetText ("Invalid input. Please try again to choose between X and O as your character: ");
	vInstruction.Draw ();
}

inline void
SceneManager::DisplayYesNoSelectErrMsg () noexcept
{
	system("cls");
	vInstruction.SetText ("Invalid input. Please enter Y/y for Yes and N/n for No: ");
	vInstruction.Draw ();
}

inline void
SceneManager::DisplayFirstPlayerErrMsg () noexcept
{
	system("cls");
	vInstruction.SetText ("Invalid input. Please try again to choose between X and O as first player: ");
	vInstruction.Draw ();
}
