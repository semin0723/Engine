#pragma once
#include "Component.h"
#include "globalheader.h"
#include <dwrite.h>

//   |Text      |
#define TEXT_LEFT			DWRITE_TEXT_ALIGNMENT_LEADING

//   |   Text   |
#define TEXT_CENTER			DWRITE_TEXT_ALIGNMENT_CENTER

//   |      Text|
#define TEXT_RIGHT			DWRITE_TEXT_ALIGNMENT_TRAILING

//   |T  e  x  t|
#define TEXT_FILL			DWRITE_TEXT_ALIGNMENT_JUSTIFIED

#define PARAGRAPH_UP		DWRITE_PARAGRAPH_ALIGNMENT_NEAR
#define PARAGRAPH_CENTER	DWRITE_PARAGRAPH_ALIGNMENT_CENTER
#define PARAGRAPH_DOWN		DWRITE_PARAGRAPH_ALIGNMENT_FAR

class TextComponent : public Component<TextComponent>
{
public:
	TextComponent();
	~TextComponent() {}

	void Initialize() {}
	void Begin() {}
	void FixedUpdate() {}
	void Update(float dt);
	void End() {}
	void Destroy() {}

	void Render(ID2D1HwndRenderTarget* target);

	std::wstring _text;
	std::wstring _font;
	float _fontSize = 0;

	DWRITE_TEXT_ALIGNMENT		_textAlignment			= TEXT_LEFT;
	DWRITE_PARAGRAPH_ALIGNMENT	_paragraphAlignemt		= PARAGRAPH_UP;
private:

};

