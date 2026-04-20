#include "Timer.h"
#include "MyGLCanvas.h"

void Timer::setCanvas(MyGLCanvas* newCanvas)
{
	canvas = newCanvas;
}

bool Timer::Start(int milliseconds, bool oneShot)
{
	tIndex = std::chrono::high_resolution_clock::now();

	return wxTimer::Start(milliseconds, oneShot);
}

void Timer::Notify()
{
	if (canvas)
	{
		auto tCurrent = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float> tDelta = tCurrent - tIndex;

		canvas->updateState(tDelta.count());

		//store the time index for next time through
		tIndex = tCurrent;
	}
}
