
inline 
DynamicText::DynamicText () noexcept
{
	vText = (char *) calloc (DEFAULT_DYNAMIC_TXT_SIZE, sizeof(char));

	if (!vText)
	    rSize = DEFAULT_DYNAMIC_TXT_SIZE;
}

inline 
DynamicText::~DynamicText () noexcept
{
	std::free (vText);
}

void 
DynamicText::Draw () noexcept
{
	CursorUtils::SetCursorPos (rCoord);

	PrintFormatter::PrintNoReset (vText, rColor, BLACK);
}

inline bool 
DynamicText::SetText (const char * pText) noexcept
{
		UInt8 reqsize;
		UInt8 paramsize;

	paramsize = strlen(pText) + 1;
	reqsize   = GET_MULTIPLE_OF (paramsize, DEFAULT_DYNAMIC_TXT_SIZE);  // allocate in multiples of our default size

	if (rSize < reqsize) {

			char * ptr;

		ptr = (char *) std::realloc (vText, reqsize * sizeof (char));

		if (!ptr)
			return false;

		vText = ptr;
		rSize = reqsize;

		// fall-through
	}

	// if we are here, we have enough space

	std::memcpy (vText, pText, paramsize * sizeof (char));

	return true;
}

inline bool 
DynamicText::SetText (tCoord pCoord, const char * pText) noexcept
{
	SetCoord (pCoord);

	SetText (pText);
}

inline bool 
DynamicText::SetText (tCoord pCoord, const char * pText, const ColorCode & pColor) noexcept
{
	SetColor (pColor);

	SetText (pCoord, pText);
}

inline const char *
DynamicText::GetStringText () const noexcept
{
	return vText;
}
