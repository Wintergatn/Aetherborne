#pragma once

namespace Aetherborne {

	class ConsoleGUI
	{

	public:

		void RedirectIOToConsole();
		//WORD GetConsoleTextAttribute(HANDLE hCon);

	};
}


/*namespace Aetherborne {

	#ifndef __CONSOLEGUI_H__
	#define __CONSOLEGUI_H__

	#ifdef _DEBUG

		void RedirectIOToConsole();
		//WORD GetConsoleTextAttribute(HANDLE hCon);

	#endif

	#endif
}*/
