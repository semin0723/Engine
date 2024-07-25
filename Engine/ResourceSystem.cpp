#include "pch.h"
#include "ResourceSystem.h"
#include <fstream>
#include <sstream>

ResourceSystem* ResourceSystem::_instance = nullptr;

ResourceSystem::~ResourceSystem()
{
	for (auto& i : _spriteSets) {
		delete i.second;
	}
	_spriteSets.clear();
	_resources.clear();
	_wicFactory->Release();
	_writeFactory->Release();
}

ResourceSystem* ResourceSystem::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new ResourceSystem;
	}
	return _instance;
}

void ResourceSystem::DeleteInstance()
{
	delete _instance;
	_instance = nullptr;
}

void ResourceSystem::Initialize(ID2D1HwndRenderTarget* target)
{
	_target = target;

	HRESULT res = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&_wicFactory)
	);

	HRESULT hr = DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(_writeFactory),
		reinterpret_cast<IUnknown**>(&_writeFactory));
}

void ResourceSystem::LoadImageData()
{
	std::wstring filename = L"";
	std::wifstream file(filename);

	std::wstringstream wss;
	std::wstring line;
	
	while (true) {
		std::getline(file, line);
		if (line == L"") break;

		std::wstring spriteId, spritePath;
		wss = std::wstringstream(line);

		std::getline(wss, spriteId, L',');
		std::getline(wss, spritePath, L',');

		ID2D1Bitmap* newBitmap;

		GetImageFromFile(spritePath, &newBitmap);

		std::unique_ptr<ID2D1Bitmap*> newBitmapPtr = std::unique_ptr<ID2D1Bitmap*>(&newBitmap);

		_resources[spriteId] = std::move(newBitmapPtr);
	}
}

void ResourceSystem::LoadAnimationData()
{
	std::wstring filename = L"";
	std::wifstream file(filename);

	std::wstringstream wss;
	std::wstring line;

	std::wstring spriteSetId;

	while (true) {
		std::getline(file, line);
		if (line == L"") break;

		spriteSetId = line;

		std::getline(file, line);

		SpriteSet* spSet = new SpriteSet;
		while (true) {
			std::getline(file, line);
			if (line == L"}") break;

			std::wstring spriteId;
			spriteId = line;
			spSet->AddSpriteId(spriteId);
		}
		_spriteSets.insert({ spriteSetId, spSet });
	}
}

void ResourceSystem::GetImageFromFile(const std::wstring& spritepath, ID2D1Bitmap** image)
{
	IWICBitmapDecoder* decoder = nullptr;
	IWICFormatConverter* converter = nullptr;
	IWICBitmapFrameDecode* frame = nullptr;

	HRESULT res = _wicFactory->CreateDecoderFromFilename(
		spritepath.c_str(),
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnDemand,
		&decoder
	);
	decoder->GetFrame(0, &frame);

	_wicFactory->CreateFormatConverter(&converter);
	converter->Initialize(
		frame,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL,
		0.f,
		WICBitmapPaletteTypeCustom
	);

	_target->CreateBitmapFromWicBitmap(converter, nullptr, image);

	if (converter)
		converter->Release();

	if (decoder)
		decoder->Release();

	if (frame)
		frame->Release();
}
