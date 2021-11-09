#pragma once

#include "Shapes.hpp"
#include <cstring>
#include <stdlib.h>

class TextBase {

	public:

					       TextBase          ();
constexpr                  TextBase          (const tCoord & pCoord, UInt32 pSize) noexcept;

			void           SetColor          (const ColorCode & pColor) noexcept;
			void           SetCoord          (const tCoord & pCoord) noexcept;

			void	       UpdateString      (const char * pText) noexcept;

	virtual void           Draw              () noexcept;

virtual const char *       GetStringText     () const noexcept;
			tCoord         GetCoord          () const noexcept;

	protected:


		tCoord     rCoord;           // co-ordinates of text
		ColorCode  rColor;           // color of the text
		UInt32     rSize;            // size of content
};

#include "TextBase.hxx"

template <UInt32 pSize = 0>
class StaticText : public TextBase {

	public:

constexpr              StaticText          (const char * pText) noexcept;
constexpr              StaticText          (const char * pText, const tCoord & pCoord) noexcept;

	private:

		char   vText[pSize];
};

#include "StaticText.hxx"

#define DEFAULT_DYNAMIC_TXT_SIZE 16

class DynamicText : public TextBase {

	public:

		               DynamicText   () noexcept;

				       ~DynamicText  () noexcept;

			void       Draw          () noexcept override;

            bool       SetText       (const char * pText) noexcept;
            bool       SetText       (tCoord pCoord, const char * pText) noexcept;
			bool       SetText       (tCoord pCoord, const char * pText, const ColorCode & pColor) noexcept;

	  const char *     GetStringText () const noexcept override;

	private:

			char *     vText;
};

#include "DynamicText.hxx"




