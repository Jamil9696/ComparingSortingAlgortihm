#pragma once
#include <string>

class Auto
{
public:

	Auto(std::string _marke, std::string _nummernschild, int _reifenAnzahl)
		:
		marke(_marke),
		nummernschild(_nummernschild),
		reifenAnzahl(_reifenAnzahl)
	{
	}

	Auto operator=(const Auto& other) {
		reifenAnzahl = other.reifenAnzahl;
		marke = other.marke;
		nummernschild = other.nummernschild;

		return other;
	}

	bool operator==(const Auto& other) {
		return nummernschild == other.nummernschild;
	}

	std::string getMarke() const {
		return marke;
	}

	int getReifenAnzahl() const {
		return reifenAnzahl;
	}

private:
	std::string marke;
	std::string nummernschild;
	int reifenAnzahl;
};

