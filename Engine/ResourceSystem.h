#pragma once
#include "globalheader.h"
#include "SpriteSet.h"
#include "wincodec.h"
#pragma comment(lib, "windowscodecs.lib")
#include <dwrite.h>
#pragma comment(lib,"dwrite.lib")

class ResourceSystem
{
public:
	ResourceSystem() {}
	~ResourceSystem();

	static ResourceSystem* GetInstance();
	static void DeleteInstance();

	void Initialize(ID2D1HwndRenderTarget* target);

	ID2D1Bitmap** GetSprite(const std::wstring& spriteId) { return _resources[spriteId].get(); }
	SpriteSet* GetSpriteSet(const std::wstring& spriteSetId) { return _spriteSets[spriteSetId]; }

private:
	static ResourceSystem* _instance;

	ID2D1HwndRenderTarget* _target = { 0 };
	IWICImagingFactory* _wicFactory = { 0 };
	IDWriteFactory* _writeFactory = { 0 };

	void LoadImageData();
	void LoadAnimationData();

	void GetImageFromFile(const std::wstring& spritepath, ID2D1Bitmap** image);

	std::map<std::wstring, SpriteSet*> _spriteSets;
	std::map<std::wstring, std::unique_ptr<ID2D1Bitmap*>> _resources;
};

