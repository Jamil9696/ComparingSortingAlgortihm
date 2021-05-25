// DoppeltVerketteteListe.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include <conio.h>
#include <iostream>
#include "Person.h"
#include "Auto.h"
#include "LinkedList.h"
#include "OwnFunctions.h"

int main() try {

    Person* p1 = new Person("Farouq", 20);
    Person* p2 = new Person("Jamil", 20);
    Person* p3 = new Person("Alex", 20);
    Person* p4 = new Person("Kevin", 20);


    //Auto* auto1 = new Auto("VW", "DA1234", 4);
    //Auto* auto2 = new Auto("BMW", "KL5678", 3);
    //Auto* auto3 = new Auto("Mercedes", "KA9103", 2);

    LinkedList<Person> personenList;

    // Person p5 = personenList.get();

    personenList.add(p1);
    personenList.add(p2);
    personenList.add(p3);
    personenList.add(p4);

    for (int i = 0; i < personenList.size(); i++) {
        std::cout << "Name: " << personenList.at(i)->getName() << " . Alter: " << personenList.at(i)->getAlter() << "\n";
    }

    personenList.insert(2, p2);
    personenList.insert(personenList.size(), p1);
    personenList.delAt(2);

    personenList.popAt(personenList.size());
    personenList.pop();
    personenList.pop();
    personenList.pop();
    personenList.pop();

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    Test::detectMemoryLeak();
    
    return 0;
}
catch (std::string& s) {
    std::cout << s;
    while (!_kbhit());
    return 1;
}
