#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class MouseEvents
{
public:
	struct MouseEventArgs;

	static void TriggerMouseMove(MouseEventArgs args);
	static void TriggerMouseRefresh(MouseEventArgs args);
	static void TriggerMouseDown(MouseEventArgs args);
	static void TriggerMouseUp(MouseEventArgs args);
	static void TriggerMouseScroll();
	static void TriggerStateChange(MouseEventArgs args);
	static void TriggerClickableMouseOverEvent();
	static void TriggerClickableMouseOutEvent();
	static void TriggerDragEvent();

	struct MouseEventArgs
	{
		Vec2 mouseCoords;
		bool isDragging;
		bool canClick;
		bool isLeftClicked;
		bool handled;

		MouseEventArgs(Vec2 mouseCoords, bool isDragging, bool canClick, bool isLeftClicked) : mouseCoords(mouseCoords), isDragging(isDragging), canClick(canClick), isLeftClicked(isLeftClicked), handled(false)
		{
		}
	};

	static const std::string MouseMoveEvent;
	static const std::string MouseRefreshEvent;
	static const std::string MouseDownEvent;
	static const std::string MouseUpEvent;
	static const std::string MouseScrollEvent;
	static const std::string MouseStateUpdateEvent;
	static const std::string ClickableMouseOverEvent;
	static const std::string ClickableMouseOutEvent;
	static const std::string MouseDragEvent;
};
