#include <QtTest>

// add necessary includes here
#include "LinkedList.h"
#include "Person.h"

class UnitTest : public QObject
{
    Q_OBJECT

public:
    UnitTest();
    ~UnitTest();

private slots:
    void test_del_rand();
    void test_ins_rand();

    void test_del_start();
    void test_ins_start();

    void test_del_end();
    void test_ins_end();

private:
    Person p1;
    Person p2;
    Person p3;
    Person p4;

};

UnitTest::UnitTest()
    :
      p1("Farouq", 20),
      p2("Jamil", 24),
      p3("Theodor", 24),
      p4("Alex", 27)
{
}

UnitTest::~UnitTest()
{

}

void UnitTest::test_del_rand(){

    Person p5("Thomas", 27);

    LinkedList<Person> personenList;

    personenList.push(p1);
    personenList.push(p2);
    personenList.push(p3);
    personenList.push(p4);
    personenList.move();
    personenList.insert(p5);
    personenList.move();
    personenList.del();

    QVERIFY(personenList.at(2) == p3);

}

void UnitTest::test_ins_rand(){

    Person p5("Thomas", 27);

    LinkedList<Person> personenList;

    personenList.push(p1);
    personenList.push(p2);
    personenList.push(p3);
    personenList.push(p4);
    personenList.move(2);
    personenList.insert(p5);

    QVERIFY(personenList.at(3) == p5);

}

void UnitTest::test_del_start(){

    LinkedList<Person> personenList;

    personenList.push(p1);
    personenList.push(p2);
    personenList.push(p3);
    personenList.push(p4);
    personenList.del();

    QVERIFY(personenList.at(0) == p2);
}

void UnitTest::test_ins_start(){

    Person p5("Thomas", 27);

    LinkedList<Person> personenList;

    personenList.push(p1);
    personenList.push(p2);
    personenList.push(p3);
    personenList.push(p4);
    personenList.insert(p5);

    QVERIFY(personenList.at(0) == p5);
}

void UnitTest::test_del_end(){

    LinkedList<Person> personenList;

    personenList.push(p1);
    personenList.push(p2);
    personenList.push(p3);
    personenList.push(p4);
    personenList.move(3);
    personenList.del();
    QVERIFY(personenList.at(2) == p3);
}

void UnitTest::test_ins_end(){

    Person p5("Thomas", 27);

    LinkedList<Person> personenList;

    personenList.push(p1);
    personenList.push(p2);
    personenList.push(p3);
    personenList.push(p4);
    personenList.move(3);
    personenList.insert(p5);
    QVERIFY(personenList.at(4) == p5);
}

QTEST_APPLESS_MAIN(UnitTest)

#include "tst_unittest.moc"
