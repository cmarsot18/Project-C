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
    membre = Membre( "Devco", "Fiche", "Guenole");
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
void TestSessionMembre::test_Session_Membre() {
    // vector has been filled by method 'setUp'
    Session_Membre * C1 = new Session_Membre( membre );

    CPPUNIT_ASSERT(C1->getMembre() == membre);
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
    CppUnit::TestSuite *suite = new CppUnit::TestSuite("SessionMembre");
    cout << "==============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "==============================================" << endl;

    TEST_ADD_SESSION_MEMBRE(Session_Membre);
    TEST_ADD_SESSION_MEMBRE(Consulter_ficheAsso);
    TEST_ADD_SESSION_MEMBRE(fail);

    return suite;
}