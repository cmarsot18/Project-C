#ifndef TEST_ASSOCIATION_H
#define TEST_ASSOCIATION_H


#include <string>
#include <vector>

#include "../Test/TestUnit.h"
#include "Association.hpp"

using namespace std;

#define CLASS_NAME_STRING "Association"


class TestAssociation : public CppUnit::TestFixture {
private:
    string nom;
    string lieu;
    vector<Membre> vm;
    vector<Consultant*>vc;

public:
    TestAssociation();
    virtual ~TestAssociation();

    void setUp();
    void tearDown();

    CppUnit::TestSuite * make_suite();

    TEST_DECL(Association);
    TEST_DECL(ajouterMembre);
    TEST_DECL(supprimerMembre);
    TEST_DECL(fail);

};

#endif /* TEST_ASSOCIATION_H */