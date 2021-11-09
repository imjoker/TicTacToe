
void
MenuScene::Init () noexcept
{
        tCoord heartcoord;

    vTitle.SetColor (RED);

    vChoose.SetColor (BLUE);

    vOption1.SetColor (sActiveOptColor);
    vOption2.SetColor (sInactiveOptColor);
    vOption3.SetColor (sInactiveOptColor);

    heartcoord = vOption1.GetCoord ();
    heartcoord.uXCoord -= 3;
    vXShape.SetCoord (heartcoord);

    heartcoord.uYCoord = vOption2.GetCoord ().uYCoord;
    vHeart.SetCoord (heartcoord);

    heartcoord.uYCoord = vOption3.GetCoord ().uYCoord;
    vOShape.SetCoord (heartcoord);

    vCurrOption = 0;
    vOptShape[vCurrOption]->SetColor (sActiveOptColor);
}

void
MenuScene::DrawMenu () noexcept
{

        UInt8 idx;

    vTitle.Draw ();

    vChoose.Draw ();

    for (idx = 0; idx < 3; ++idx) {

        vOptShape[idx]->Draw ();
        vOptions[idx]->Draw ();
    }
}

void
MenuScene::MoveUp () noexcept
{
	vOptions[vCurrOption]->SetColor (sInactiveOptColor);
    vOptShape[vCurrOption]->SetColor (BLACK);

	if (vCurrOption == 0)
		vCurrOption = NUM_OPTIONS - 1;
	else
		--vCurrOption;

	vOptions[vCurrOption]->SetColor (sActiveOptColor);
    vOptShape[vCurrOption]->SetColor (sActiveOptColor);
}

void
MenuScene::MoveDown () noexcept
{
	vOptions[vCurrOption]->SetColor (sInactiveOptColor);
	vOptShape[vCurrOption]->SetColor (BLACK);

	++vCurrOption;
	vCurrOption %= NUM_OPTIONS; 

	vOptions[vCurrOption]->SetColor (sActiveOptColor);
    vOptShape[vCurrOption]->SetColor (sActiveOptColor);
}

inline eMenuOption 
MenuScene::GetCurrOption () noexcept
{
    return (eMenuOption) vCurrOption;
}
