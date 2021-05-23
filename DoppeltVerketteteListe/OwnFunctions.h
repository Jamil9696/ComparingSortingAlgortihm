#pragma once
#pragma once
#define _CRTDBG_MAP_ALLOC  

#include <string>
#include <conio.h>
#include <iostream>
#include <crtdbg.h>  


namespace StdLibrary {

	void pauseProgramm(const char*);
	void strrev(std::string& string);
	void strrev(char* c);
	void convertInt2Str(int val, char* buf, int size);
	int convertStr2Int(std::string val);
	int convertStr2Int(const char*& ptr);
	std::string substr(const char*& ptr);
	std::string readString();
}

namespace InputHandling {

	// start default to one
	int avoidWrongInputs(const char printedText[], int end, int start = 1);

}

namespace Test {

	void detectMemoryLeak();
}

