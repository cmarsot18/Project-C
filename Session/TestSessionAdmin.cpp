//
// Created by marsot on 20/04/2020.
//

#include "TestSessionAdmin.h"
/*
#include <algorithm>
#include <iterator>
#include <numeric>
*/
using namespace std;

TestSessionAdmin::TestSessionAdmin(){

};

// ----------------------------------------------

TestSessionAdmin::~TestSessionAdmin(){

};


/**
 * setUp: function called before each test
 */
void TestSessionAdmin::setUp() {
    Membre membre;
}

/**
 * setUp: function called after each test
 */
void TestSessionAdmin::tearDown() {
}

/**
 * test that all values are present by computing
 * sum i=1,size of v[i] which is supposed to be
 * equal to size*(size+1)/2
 */
void TestSessionAdmin::test_Session_Admin(){
    // vector has been filled by method 'setUp'
    Session_Admin * C1 = new Session_Admin( membre );
    CPPUNIT_ASSERT(C1->getMembre() == membre);
}

void TestSessionAdmin::test_Consulter_fiche() {
    Session_Admin * C1 = new Session_Admin( membre );
    Membre *test = new Membre();
    C1->Consulter_fiche(*test);
    //Taiter le cas ou il n'y a pas de fiche existante
}

/**
 * Test that will fail, used for example purpose
 */
void TestSessionAdmin::test_fail() {
    CPPUNIT_ASSERT(0 == 1);
}


/**
 * declare suite of tests
 *
 */
CppUnit::TestSuite * TestSessionAdmin::make_suite() {
    CppUnit::TestSuite *suite = new CppUnit::TestSuite("SessionAdmin");
    cout << "==============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "==============================================" << endl;

    TEST_ADD_SESSION_ADMIN(Session_Admin);
    TEST_ADD_SESSION_ADMIN(Consulter_fiche);
    TEST_ADD_SESSION_ADMIN(fail);

    return suite;
}