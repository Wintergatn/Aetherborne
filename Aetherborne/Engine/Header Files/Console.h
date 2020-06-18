#pragma once
#include "AddTimestamp.h"

#include <thread>

namespace Aetherborne {

#ifdef _DEBUG

	class Console
	{

	public:
		Console();

		void run();
		void stop();

		void getInput(std::string &command);
		bool isRunning();

		//void buildScriptMap();
		//void parseCommand(std::string cmd);
		//void resetCommand();

		//void clearConsole();
		//void echoConsole();
		//void messageConsole();
		//void exitConsole();

	private:
		void RedirectIOToConsole();
		void loop();

		static const WORD MAX_CONSOLE_LINES = 500;
		std::thread m_thread;
		bool m_running = false;
		std::string m_command;
		//std::string tokens[256];

	};

#endif
}