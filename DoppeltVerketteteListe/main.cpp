// DoppeltVerketteteListe.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include <conio.h>
#include <iostream>
#include "Person.h"
#include "Auto.h"
#include "LinkedList.h"
#include "OwnFunctions.h"

int main() try {
    Person p1("Farouq", 20);
    Person p2("Jamil", 24);
    Person p3("Theodor", 24);
    Person p4("Alex", 27);


    //Auto* auto1 = new Auto("VW", "DA1234", 4);
    //Auto* auto2 = new Auto("BMW", "KL5678", 3);
    //Auto* auto3 = new Auto("Mercedes", "KA9103", 2);

    LinkedList<Person> personenList;

    // Person p5 = personenList.get();

    personenList.push(p1);
    personenList.push(p2);
    personenList.push(p3);
    personenList.move(1);
    personenList.insert(p4);
    std::cout << personenList.size() << "\n";
    std::cout << personenList.at(2).getName() << "\n"; //Muesste Alex rauskommen

    personenList.pop();
    personenList.pop();
    personenList.pop();
    personenList.pop();

    Test::detectMemoryLeak();


    while (!_kbhit());
    return 0;
}
catch (std::string& s) {
    std::cout << s;
    while (!_kbhit());
    return 1;
}
