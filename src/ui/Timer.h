#ifndef TIMER_H_
#define TIMER_H_

#include <wx/timer.h>
#include <chrono>

class MyGLCanvas;

class Timer : public wxTimer
{
	std::chrono::high_resolution_clock::time_point tIndex;

	MyGLCanvas * canvas = nullptr;

public:

	void setCanvas(MyGLCanvas* newCanvas);

	bool Start(int milliseconds, bool oneShot = wxTIMER_CONTINUOUS) override;
	void Notify() override;
};

#endif