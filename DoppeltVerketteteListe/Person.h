#pragma once
#include <string>

class Person
{
public:
	Person(std::string _name, int _alter)
		:
		name(_name),
		alter(_alter)
	{
	}

	Person operator=(const Person& other) {
		alter = other.alter;
		name = other.name;
		return other;
	}

	bool operator==(const Person& other) {
		return name == other.name && alter == other.alter;
	}

	std::string getName() const {
		return name;
	}

	int getAlter() const {
		return alter;
	}

private:
	std::string name;
	int alter;
};

