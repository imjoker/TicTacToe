
template<UInt32 pSize>
inline constexpr 
StaticText<pSize>::StaticText (const char * pText) noexcept : TextBase {}, vText {}
{
    std::memcpy (vText, pText, pSize);
}

template<UInt32 pSize>
inline constexpr 
StaticText<pSize>::StaticText (const char * pText, const tCoord & pCoord) noexcept : TextBase {pCoord, pSize}, vText {}
{
    std::memcpy (vText, pText, pSize);
}