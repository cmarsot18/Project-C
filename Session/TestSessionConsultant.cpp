//
// Created by yasmine on 16/04/2020.
//

#include "TestSessionConsultant.h"
/*
#include <algorithm>
#include <iterator>
#include <numeric>
*/
using namespace std;

TestSessionConsultant::TestSessionConsultant(){

};

// ----------------------------------------------

TestSessionConsultant::~TestSessionConsultant(){

};


/**
 * setUp: function called before each test
 */
void TestSessionConsultant::setUp() {
    Personne consultant;
}

/**
 * setUp: function called after each test
 */
void TestSessionConsultant::tearDown() {
}

/**
 * test that all values are present by computing
 * sum i=1,size of v[i] which is supposed to be
 * equal to size*(size+1)/2
 */
void TestSessionConsultant::test_Session_Consultant() {
    // vector has been filled by method 'setUp'
    Session_Consultant * C1 = new Session_Consultant( consultant );

    CPPUNIT_ASSERT(C1->getConsultant() == consultant);
}

void TestSessionConsultant::test_Consulter_fiche() {
    Session_Consultant * C1 = new Session_Consultant( consultant );
    C1->Consulter_fiche();
    //Taiter le cas ou il n'y a pas de fiche existante
}

/**
 * Test that will fail, used for example purpose
 */
void TestSessionConsultant::test_fail() {
    CPPUNIT_ASSERT(0 == 1);
}


/**
 * declare suite of tests
 *
 */
CppUnit::TestSuite * TestSessionConsultant::make_suite() {
    CppUnit::TestSuite *suite = new CppUnit::TestSuite("Session_Consultant");
    cout << "==============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "==============================================" << endl;

    TEST_ADD_SESSION_CONSULTANT(Session_Consultant);
    TEST_ADD_SESSION_CONSULTANT(Consulter_fiche);
    TEST_ADD_SESSION_CONSULTANT(fail);

    return suite;
}