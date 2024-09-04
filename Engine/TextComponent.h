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

	// set
	void SetText				(std::wstring text)						{ _text = text; }
	void SetFont				(std::wstring font)						{ _font = font; }
	void SetFontSize			(float size)							{ _font = size; }
	void SetTextAreaSize		(const Vector3& areaSize)						{ _textAreaSize = areaSize; }
	void SetTextAlignment		(DWRITE_TEXT_ALIGNMENT alignment)		{ _textAlignment = alignment; }
	void SetParagraphAlignment	(DWRITE_PARAGRAPH_ALIGNMENT alignment)	{ _paragraphAlignemt = alignment; }

	// get
	const std::wstring&					GetText()					const	{ return _text; }
	const std::wstring&					GetFont()					const	{ return _font; }
	const float							GetFontSize()				const	{ return _fontSize; }
	const Vector3&						GetTextAreaSize()			const	{ return _textAreaSize; }
	const DWRITE_TEXT_ALIGNMENT			GetTextAlignment()			const	{ return _textAlignment; }
	const DWRITE_PARAGRAPH_ALIGNMENT	GetParagraphAlignment()		const	{ return _paragraphAlignemt; }

private:
	std::wstring _text;
	std::wstring _font;
	float _fontSize = 0;
	Vector3 _textAreaSize;

	DWRITE_TEXT_ALIGNMENT		_textAlignment			= TEXT_LEFT;
	DWRITE_PARAGRAPH_ALIGNMENT	_paragraphAlignemt		= PARAGRAPH_UP;

};

