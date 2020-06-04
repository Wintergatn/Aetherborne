#include "Console.h"

#include "AddTimestamp.h"
#include "ConsoleGUI.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

Console::Console() {
	std::cout << "AETHERBORNE" << std::endl;
	std::cout << "Version 1.0 -- Now in Vulkan!" << std::endl << std::endl << std::endl;
	cActive = true;
}

Console::~Console() { }

// SCRIPT COMMANDS
void Console::exitConsole() {
	cActive = false;
	std::cout << "Exiting console." << std::endl;
}

void Console::clearConsole() {
	std::cout << "Clearing console." << std::endl;
}

void Console::echoConsole() {
	std::cout << "Echo." << std::endl;
}

void Console::messageConsole() {
	std::cout << "Sending message." << std::endl;
}

// DEFINES ALL AVAILABLE COMMANDS
void Console::buildScriptMap() {

	//reinterpret_cast<void*>(&afunction)
	//scrMap.emplace(std::make_pair("exit", reinterpret_cast<void*>(&Console::exitConsole)));
	//scrMap.emplace('exit', &Console::exitConsole);			//0 - exit the console
	//scrMap.emplace(std::make_pair("clr", &Console::clearConsole));			//1 - clear the console
	//scrMap.emplace(std::make_pair("echo", &Console::echoConsole));			//2 - print input back to terminal
	//scrMap.emplace(std::make_pair("message", &Console::messageConsole));	//3 - post a message to the message bus

	//scrMap["exit"] = exitConsole;
}


// CONSOLE MISC
bool Console::isActive() {
	return cActive;
}

std::string Console::getInput() {
	std::string cInput;
	std::getline(std::cin, cInput);
	return cInput;
}

void Console::parseCommand(std::string cmd) {
	std::stringstream cmdStream(cmd);
	std::string cmdParse;
	cmdStream >> cmdParse;

	// look for command in the script map and execute it
	//auto const find = scrMap.find(cmdParse);
	//if (find != scrMap.end()) find->second();
	//else std::cout << "Could not recognize command." << std::endl;
}