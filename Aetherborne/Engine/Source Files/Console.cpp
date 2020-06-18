#include "../Header Files/Console.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace Aetherborne;

Console::Console() {
	//AllocConsole();
	RedirectIOToConsole();
	std::cout << "AETHERBORNE" << std::endl;
	std::cout << "Version 0.1 -- Now in Vulkan!" << std::endl;

	// Check extensions for Vulkan.
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
	std::cout << extensionCount << " extensions supported." << std::endl << std::endl << std::endl;
}

void Console::RedirectIOToConsole() {

	int hConHandle;
	long lStdHandle;
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	FILE* fp;

	// set screen buffer to be big enough to scroll through text
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	coninfo.dwSize.Y = MAX_CONSOLE_LINES;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coninfo.dwSize);

	// redirect unbuffered STDOUT outputs to the console
	lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);

	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);

	// redirect unbuffered STDIN inputs to the console
	lStdHandle = (long)GetStdHandle(STD_INPUT_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);

	fp = _fdopen(hConHandle, "r");
	*stdin = *fp;
	setvbuf(stdin, NULL, _IONBF, 0);

	// redirect unbuffered STDERR to the console
	lStdHandle = (long)GetStdHandle(STD_ERROR_HANDLE);
	hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);

	fp = _fdopen(hConHandle, "w");
	*stderr = *fp;
	setvbuf(stderr, NULL, _IONBF, 0);

	// make cout, wcout, cin, wcin, wcerr, cerr, wclog, and clog point to console as well
	std::ios::sync_with_stdio();

}

void Console::run() {
	m_running = true;
	m_thread = std::thread([this]() {
		loop();
		});
}

void Console::stop() {
	m_running = false;
	std::cout << "Closing console..." << std::endl;
	FreeConsole();
	m_thread.join();
}

bool Console::isRunning() {
	return m_running;
}

void Console::getInput(std::string &command) {
	std::getline(std::cin, command);
	//std::stringstream cmdStream(command);
	//std::string cmdParse;
	//cmdStream >> cmdParse;

	//scripting logic
	std::cout << "Could not recognize command." << std::endl;
}

void Console::loop() {
	while (m_running) {
		getInput(m_command);
	}
}

// SCRIPT COMMANDS
/*void Console::exitConsole() {
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
}*/

// DEFINES ALL AVAILABLE COMMANDS
/*void Console::buildScriptMap() {

	//reinterpret_cast<void*>(&afunction)
	//scrMap.emplace(std::make_pair("exit", reinterpret_cast<void*>(&Console::exitConsole)));
	//scrMap.emplace('exit', &Console::exitConsole);			//0 - exit the console
	//scrMap.emplace(std::make_pair("clr", &Console::clearConsole));			//1 - clear the console
	//scrMap.emplace(std::make_pair("echo", &Console::echoConsole));			//2 - print input back to terminal
	//scrMap.emplace(std::make_pair("message", &Console::messageConsole));	//3 - post a message to the message bus

	//scrMap["exit"] = exitConsole;
}*/

/*
// Needed for coloring text
WORD GetConsoleTextAttribute(HANDLE hCon) {
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}*/

/*void Console::parseCommand(std::string cmd) {
	std::stringstream cmdStream(cmd);
	std::string cmdParse;
	cmdStream >> cmdParse;

	// look for command in the script map and execute it
	//auto const find = scrMap.find(cmdParse);
	//if (find != scrMap.end()) find->second();
	//else std::cout << "Could not recognize command." << std::endl;
}*/