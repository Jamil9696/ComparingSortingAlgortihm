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
    Person* p5 = new Person("Felix", 20);
    Person* p6 = new Person("Lukas", 20);
    Person* p7 = new Person("Thomax", 20);
    Person* p8 = new Person("Ben", 20);
    Person* p9 = new Person("Sven", 20);



    //Auto* auto1 = new Auto("VW", "DA1234", 4);
    //Auto* auto2 = new Auto("BMW", "KL5678", 3);
    //Auto* auto3 = new Auto("Mercedes", "KA9103", 2);

   
    LinkedList<Person> personenList;

    // Person p5 = personenList.get();


    personenList.add(p1);
    personenList.add(p2);
    personenList.add(p3);
    personenList.add(p4);
    personenList.add(p5);
    personenList.add(p6);
    personenList.add(p7);
    personenList.add(p8);

    personenList.sortedFunction();

    for (int i = 0; i < personenList.size(); i++) {
        std::cout << "Name: " << personenList.at(i)->getName() << ", Alter: " << personenList.at(i)->getAlter() << "\n";
    }

    personenList.insert(p8, true);

    personenList.insert(2, p2);
    personenList.insert(personenList.size(), p1);
    personenList.delAt(2);

    personenList.popAt(personenList.size());
    personenList.del();
    personenList.pop();
    personenList.del();
    personenList.pop();
    personenList.del();
    personenList.del();
    personenList.del();
    personenList.pop();
    personenList.pop();
    personenList.pop();
    personenList.pop();

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    delete p7;
    delete p8;
    delete p9;

    Test::detectMemoryLeak();
    
    return 0;
}
catch (std::string& s) {
    std::cout << s;
    while (!_kbhit());
    return 1;
}

