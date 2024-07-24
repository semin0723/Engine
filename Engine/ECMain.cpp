#include "pch.h"
#include "ECMain.h"

ECBase* _ec = nullptr;

void Initialize()
{
	if (_ec == nullptr) {
		_ec = new ECBase;
	}
}

void Finalize()
{
	if (_ec != nullptr) {
		delete _ec;
		_ec = nullptr;
	}
}
