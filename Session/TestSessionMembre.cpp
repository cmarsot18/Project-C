//
// Created by marsot on 20/04/2020.
//

#include "TestSessionMembre.h"
/*
#include <algorithm>
#include <iterator>
#include <numeric>
*/
using namespace std;

TestSessionMembre::TestSessionMembre(){

};

// ----------------------------------------------

TestSessionMembre::~TestSessionMembre(){

};


/**
 * setUp: function called before each test
 */
void TestSessionMembre::setUp() {
    Personne Membre;
}

/**
 * setUp: function called after each test
 */
void TestSessionMembre::tearDown() {
}

/**
 * test that all values are present by computing
 * sum i=1,size of v[i] which is supposed to be
 * equal to size*(size+1)/2
 */
void TestSessionMembre::TestSessionMembre() {
    // vector has been filled by method 'setUp'
    Session_Membre * C1 = new Session_Membre( Membre );

    CPPUNIT_ASSERT(C1->getMembre() == Membre);
}

void TestSessionMembre::test_Consulter_ficheAsso() {
    Session_Membre * C1 = new Session_Membre( Membre );
    C1->Consulter_fiche();
    //Taiter le cas ou il n'y a pas de fiche existante
}

/**
 * Test that will fail, used for example purpose
 */
void TestSessionMembre::test_fail() {
    CPPUNIT_ASSERT(0 == 1);
}


/**
 * declare suite of tests
 *
 */
CppUnit::TestSuite * TestSessionMembre::make_suite() {
    CppUnit::TestSuite *suite = new CppUnit::TestSuite(CLASS_NAME_STRING);
    cout << "==============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "==============================================" << endl;

    TEST_ADD(Session_Membre);
    TEST_ADD(Consulter_ficheAsso);
    TEST_ADD(fail);

    return suite;
}