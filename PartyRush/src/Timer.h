#pragma once

#include "ofMain.h"
#include "Parameters.h"

class Timer {
	private:
		float lastTime;
		float currentTime;
		int countdown;
	public:
		void initTimer();
		int updateTime();
		string getTimeFormat();
		bool timeIsUp();
		bool crazyTime();
};