#include "pch.h"
#include "ButtonComponent.h"
#include "ButtonStates.h"

ButtonComponent::ButtonComponent()
{
	ButtonNormal* btnNormal = new ButtonNormal("ButtonNormal");
	AddState(Button_State::Normal, btnNormal);

	ButtonPressed* btnPressed = new ButtonPressed("ButtonPress");
	AddState(Button_State::Pressed, btnPressed);

	ButtonClicked* btnClicked = new ButtonClicked("ButtonClicked");
	AddState(Button_State::Clicked, btnClicked);

	ButtonReleased* btnReleased = new ButtonReleased("ButtonReleased");
	AddState(Button_State::Released, btnReleased);

	ButtonHover* btnHover = new ButtonHover("ButtonHover");
	AddState(Button_State::Hover, btnHover);
}

ButtonComponent::~ButtonComponent()
{
	for (auto& i : _states) {
		delete i.second;
	}
	_states.clear();
}

void ButtonComponent::SetOwner(EntityId id)
{
	for (auto& i : _states) {
		i.second->SetOwner(id);
	}
}

void ButtonComponent::ChangeState(Button_State state)
{
	_states[_curState]->StateExit();
	_curState = state;
	_states[_curState]->StateEnter();
}

void ButtonComponent::AddState(Button_State state, State* stateAction)
{
	_states[state] = stateAction;
}