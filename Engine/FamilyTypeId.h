#pragma once
#include "pch.h"

template <class T>
class FamilyTypeId
{
public:
	template <class F>
	static const TypeId Get() {
		static const TypeId = _typeCount++;
		return typeId;
	}
	static const TypeId Get() { return _typeCount; }

private:
	static TypeId _typeCount;
};

