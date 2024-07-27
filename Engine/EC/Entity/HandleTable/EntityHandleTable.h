#pragma once
#include "pch.h"

class EntityId {
public:
	EntityId() {}
	EntityId(ULL idx, ULL version) : _index(idx), _version(version) {}
	ULL _index		= (std::numeric_limits<ULL>::max)();
	ULL _version	= (std::numeric_limits<ULL>::max)();

	const bool operator==(const EntityId& other) const {
		return ((_index == other._index) && (_version == other._version));
	}
	const bool operator==(const EntityId* other) const {
		return ((_index == other->_index) && (_version == other->_version));
	}
	const bool operator!=(const EntityId& other) const {
		return ((_index != other._index) || (_version != other._version));
	}
	const bool operator!=(const EntityId* other) const {
		return ((_index != other->_index) || (_version != other->_version));
	}
};

template <class E, class EID>
class EntityHandleTable
{
	using EntityTable = std::pair<ULL, E*>;
public:
	EntityHandleTable() { ExpandTable(); }
	~EntityHandleTable() {
		for (int i = 0; i < _handleTable.size(); i++) {
			if (_handleTable[i].second == nullptr) continue;

			delete _handleTable[i].second;
			_handleTable[i].second = nullptr;
		}
	}

	EntityId MappingHandle(E* newObj) {
		ULL i = 0;
		for (; i < _handleTable.size(); i++) {
			if (_handleTable[i].second == nullptr) {
				_handleTable[i].second = newObj;
				_handleTable[i].first = (_handleTable[i].first + 1) % (std::numeric_limits<ULL>::max)();
				return EntityId(i, _handleTable[i].first);
			}
		}

		ExpandTable();
		_handleTable[i].first = 1;
		_handleTable[i].second = newObj;

		return EntityId(i, _handleTable[i].first);
	}

	void ReleaseHandle(EntityId id) {
		delete _handleTable[id._index].second;
		_handleTable[id._index].second = nullptr;
	}

	EntityId operator[](ULL idx) {
		return EntityId(idx, _handleTable[idx].first);
	}

	E* operator[](EntityId& id) {
		if (_handleTable[id._index].first == id._version) {
			return _handleTable[id._index].second;
		}
		else return nullptr;
	}

private:
	size_t _expandSize = 16;
	std::vector<EntityTable> _handleTable;

	void ExpandTable() {
		size_t oldSize = _handleTable.size();
		size_t newSize = oldSize + _expandSize;

		_handleTable.resize(newSize);
		for (size_t i = oldSize; i < newSize; i++) {
			_handleTable[i] = EntityTable(0, nullptr);
		}
	}
};

