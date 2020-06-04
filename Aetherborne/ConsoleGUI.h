/*#pragma once

class GUICon
{

public:

	void RedirectIOToConsole();
	WORD GetConsoleTextAttribute(HANDLE hCon);

};*/

#ifndef __CONSOLEGUI_H__
#define __CONSOLEGUI_H__

#ifdef _DEBUG

	void RedirectIOToConsole();
	//WORD GetConsoleTextAttribute(HANDLE hCon);

#endif

#endif
