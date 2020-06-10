#pragma once

#include <string>
#include <unordered_map>


namespace Aetherborne {

	class Console
	{

	public:
		Console();
		~Console();

		bool isActive();
		std::string getInput();
		void buildScriptMap();
		void parseCommand(std::string cmd);
		void resetCommand();

		void clearConsole();
		void echoConsole();
		void messageConsole();
		void exitConsole();

	private:
		bool cActive;
		std::string command;
		std::string tokens[256];

	};
}