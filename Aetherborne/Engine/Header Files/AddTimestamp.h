#pragma once
#include <iostream>
#include <Windows.h>

namespace Aetherborne {

	class AddTimestamp : public std::streambuf
	{

	public:
		AddTimestamp(std::basic_ios<char>& out);
		~AddTimestamp();

	protected:
		int_type overflow(int_type m = traits_type::eof());

	private:
		AddTimestamp(const AddTimestamp&);
		AddTimestamp& operator = (const AddTimestamp&); //not copyable

		WORD GetConsoleTextAttribute(HANDLE hCon);

		std::string getTime();

		//members
		std::basic_ios<char>& out_;
		std::streambuf* sink_;
		bool newline_;

	};
}
