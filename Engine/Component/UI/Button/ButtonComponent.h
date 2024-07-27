#pragma once
#include "Component.h"
#include "globalheader.h"

class ButtonComponent
{
public:
	ButtonComponent();
	~ButtonComponent();

	void SetOwner(EntityId id);
	void ChangeState(Button_State state);
	void AddState(Button_State state, State* stateAction);

	void AddOnclickFunction(std::function<void()> func) { _onclick = func; }

	Button_State _curState = Button_State::Normal;
	std::map<Button_State, State*> _states;
	std::wstring _name;
	std::function<void()> _onclick;
};

