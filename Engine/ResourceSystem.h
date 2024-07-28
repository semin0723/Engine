#pragma once
#include "globalheader.h"
#include "SpriteSet.h"
#include "wincodec.h"
#pragma comment(lib, "windowscodecs.lib")
#include <dwrite.h>
#pragma comment(lib,"dwrite.lib")

#define BLACK 0
#define GREEN 1

class ResourceSystem
{
public:
	ResourceSystem() : _brushes(2) {}
	~ResourceSystem();

	static ResourceSystem* GetInstance();
	static void DeleteInstance();

	void Initialize(ID2D1HwndRenderTarget* target);

	ID2D1Bitmap* GetSprite(const std::wstring& spriteId) { return *_resources[spriteId]; }
	SpriteSet* GetSpriteSet(const std::wstring& spriteSetId) { return _spriteSets[spriteSetId]; }
	IDWriteTextFormat* GetTextFormat(const std::wstring& fontName, float fontSize, DWRITE_TEXT_ALIGNMENT textallign, DWRITE_PARAGRAPH_ALIGNMENT paragraphalign);

	void LoadSpriteData();

	ID2D1SolidColorBrush* GetBrush(int idx) { return _brushes[idx]; }

private:
	static ResourceSystem* _instance;

	ID2D1HwndRenderTarget* _target = { 0 };
	IWICImagingFactory* _wicFactory = { 0 };
	IDWriteFactory* _writeFactory = { 0 };

	void GetImageFromFile(const std::wstring& spritepath, ID2D1Bitmap** image);

	std::map<std::wstring, SpriteSet*> _spriteSets;
	std::map<std::wstring, std::shared_ptr<ID2D1Bitmap*>> _resources;
	std::map<std::pair<std::wstring, float>, IDWriteTextFormat*> _textformats;

	std::vector< ID2D1SolidColorBrush* > _brushes;
};

