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
	for (auto& i : _brushes) {
		i->Release();
	}
	_brushes.clear();

	if(_wicFactory != nullptr) _wicFactory->Release();
	if (_writeFactory != nullptr) _writeFactory->Release();

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

	_target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Green), &_brushes[1]);
	_target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &_brushes[0]);
}

IDWriteTextFormat* ResourceSystem::GetTextFormat(const std::wstring& fontName, float fontSize, DWRITE_TEXT_ALIGNMENT textallign, DWRITE_PARAGRAPH_ALIGNMENT paragraphalign)
{
	if (_textformats.find({ fontName, fontSize }) == _textformats.end()) {
		IDWriteTextFormat* textformat = nullptr;

		_writeFactory->CreateTextFormat(
			fontName.c_str(),
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			fontSize,
			L"",
			&textformat
		);

		_textformats[{fontName, fontSize}] = textformat;
	}

	_textformats[{fontName, fontSize}]->SetTextAlignment(textallign);
	_textformats[{fontName, fontSize}]->SetParagraphAlignment(paragraphalign);

	return _textformats[{fontName, fontSize}];
}

void ResourceSystem::LoadSpriteData()
{
	std::wstring filename = L"data\\SpriteData\\SpriteData.CSV";
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

			std::wstring spriteId, spritePath;

			wss = std::wstringstream(line);

			std::getline(wss, spriteId, L',');
			std::getline(wss, spritePath, L',');

			spSet->AddSpriteId(spriteId);

			ID2D1Bitmap* newBitmap;

			GetImageFromFile(spritePath, &newBitmap);

			std::shared_ptr<ID2D1Bitmap*> newBitmapPtr = std::make_shared<ID2D1Bitmap*>(newBitmap);

			_resources[spriteId] = newBitmapPtr;
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
