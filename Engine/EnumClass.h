#pragma once

enum class CollisionGroup {
	Default,
	TriggerBox,
	Player,
	Monster,

	End = 32,
};

enum class Button_State {
	Normal,
	Hover,
	Pressed,
	Released,
	Clicked,

};