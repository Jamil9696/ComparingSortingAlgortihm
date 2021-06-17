// DoppeltVerketteteListe.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include <conio.h>
#include <iostream>
#include "Person.h"
#include "LinkedList.h"
#include "OwnFunctions.h"
#include <random>
#include <time.h>
#include <chrono>

using namespace std::chrono;

void drawTree(LinkedList<Person>& liste, int i = 0);

int main() try {

    int wert = 10000;

    std::mt19937 rng(time(nullptr));
    std::uniform_int_distribution<int> randomNumber(0, wert);

    srand(time(NULL));
    int generateNumber;

    LinkedList<Person> randomList;
    
    for (int i = 0; i < wert; i++) {

        generateNumber = randomNumber(rng);
        randomList.push(new Person("random", generateNumber));

    }

    std::cout << "\n";
    std::cout << "Start!" << std::endl;
    auto start = high_resolution_clock::now();

    randomList.modifiedBubblesort();

    auto ende = high_resolution_clock::now();

    for (int i = 0; i < randomList.getSize(); i++) {
       std::cout << randomList.at(i)->getAlter() << "  ";
    }

    std::cout << "\n\n benoetigte Zeit: " << duration_cast<milliseconds>(ende - start).count() << " ms";
    
    while (!_kbhit());

    for (int i = 0; i < randomList.getSize(); i++) {
       std::cout << randomList.at(i)->getAlter() << "   ";
    }


    /*

    Person* p1 = new Person("Farouq", 20);
    Person* p2 = new Person("Jamil", 20);
    Person* p3 = new Person("Alex", 20);
    Person* p4 = new Person("Kevin", 20);
    Person* p5 = new Person("Felix", 20);
    Person* p6 = new Person("Lukas", 20);
    Person* p7 = new Person("Thomax", 20);
    Person* p8 = new Person("Ben", 20);
    Person* p9 = new Person("Sven", 20);
    Person* p10 = new Person("Steven", 20);
    Person* p11 = new Person("Nora", 20);
    Person* p12 = new Person("Katja", 20);
    Person* p13 = new Person("Toni", 20);
    Person* p14 = new Person("Klaus", 20);
    Person* p15 = new Person("Lea", 20);
   

    LinkedList<Person> personenList;
    LinkedList<Person> personenList2;
    

    personenList.push(p1);
    personenList.push(p2);
    personenList.push(p3);
    personenList.push(p4);
    personenList.push(p5);
    personenList.push(p6);
    personenList.push(p7);
    personenList.push(p8);
    personenList.push(p9);
    personenList.push(p10);
    personenList.push(p11);
    personenList.push(p12);
    personenList.push(p13);
    personenList.push(p14);
    personenList.push(p15);

    personenList.quicksort();
    drawTree(personenList);
    LinkedList<Person> newList; 
   // newList = newList.mergeToOne(personenList, personenList2);
    
    for (int i = 0; i < newList.getSize(); i++) {
        std::cout << "Name: " << newList.at(i)->getName() << ", Alter: " << newList.at(i)->getAlter() << "\n";
    }

    std::cout << "\n";
    */
    // if memory leak detected then print 
    //Test::detectMemoryLeak();
    

    int i; 
    std::cin >> i;
    std::cout << "\n\n";
    std::cout << "\n";

    return 0;

}
catch (std::string& s) {
    std::cout << s;
    while (!_kbhit());
    return 1;
}




void drawTree(LinkedList<Person> &liste, int i){

    std::cout << "============================================ TREE STRUCTURE ===========================================\n\n\n";

    std::cout << "\t\t\t\t\t\t    " << liste.at(0)->getName() << "\n\n";

    std::string name1 = liste.at(liste.getLeftChild(i))->getName();
    std::string name2 = liste.at(liste.getRightChild(i++))->getName();

    std::cout << "\t\t\t\t" << name1 << "\t\t\t\t\t" << name2 << "\n\n";

    std::string name3 = liste.at(liste.getLeftChild(i))->getName();
    std::string name4 = liste.at(liste.getRightChild(i++))->getName();

    std::string name5 = liste.at(liste.getLeftChild(i))->getName();
    std::string name6 = liste.at(liste.getRightChild(i++))->getName();

    std::cout << "\t\t\t" << name3 << "\t\t" << name4 << "\t\t\t" << name5 << "\t\t" << name6 << "\n\n";

    std::string name7 = liste.at(liste.getLeftChild(i))->getName();
    std::string name8 = liste.at(liste.getRightChild(i++))->getName();

    std::string name9 = liste.at(liste.getLeftChild(i))->getName();
    std::string name10 = liste.at(liste.getRightChild(i++))->getName();

    std::string name11 = liste.at(liste.getLeftChild(i))->getName();
    std::string name12 = liste.at(liste.getRightChild(i++))->getName();

    std::string name13 = liste.at(liste.getLeftChild(i))->getName();
    std::string name14 = liste.at(liste.getRightChild(i++))->getName();

     std::cout << "\t\t    " << name7 << "\t    " << name8 << "    "
               << name9 << "       " << name10 << "\t  " << name11 << "  "
               << name12 << "       " << name13 << "\t" << name14 << "\n\n";


}