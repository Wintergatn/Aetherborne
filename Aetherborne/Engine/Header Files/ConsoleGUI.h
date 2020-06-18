#pragma once

namespace Aetherborne {

#ifdef _DEBUG

	class ConsoleGUI
	{

	public:

		void RedirectIOToConsole();
		//WORD GetConsoleTextAttribute(HANDLE hCon);

	};

#endif

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
