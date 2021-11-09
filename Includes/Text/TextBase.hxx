
TextBase::TextBase ()
{
	rCoord.uXCoord = 0;
	rCoord.uYCoord = 0;

	rColor = BLACK;

	rSize = 0;
}

constexpr
TextBase::TextBase (const tCoord & pCoord, UInt32 pSize) noexcept : rCoord {pCoord}, rColor {}, rSize {pSize}
{

}

inline void 
TextBase::SetColor (const ColorCode & pColor) noexcept
{
	rColor = pColor;
}

inline void
TextBase::SetCoord (const tCoord & pCoord) noexcept
{
	rCoord = pCoord;
}

inline void
TextBase::Draw () noexcept
{
	CursorUtils::SetCursorPos (rCoord);

	PrintFormatter::PrintNoReset (GetStringText (), rColor, BLACK);
}

inline const char * 
TextBase::GetStringText() const noexcept
{
	return (const char *) ((void *)(((UInt8 *) this) + sizeof (TextBase)));
}

inline tCoord
TextBase::GetCoord () const noexcept
{
	return rCoord;
}

void 
TextBase::UpdateString (const char * pText) noexcept
{
	if (strlen (pText) != rSize)
		return;                   // wrong usage, cannot update.

    std::memcpy ((void *) GetStringText (), pText, rSize);
}
