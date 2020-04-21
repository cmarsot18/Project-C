//
// Created by yasmine on 16/04/2020.
//

#include "TestConsultant.h"
/*
#include <algorithm>
#include <iterator>
#include <numeric>
*/
using namespace std;

TestConsultant::TestConsultant(){

};

// ----------------------------------------------

TestConsultant::~TestConsultant(){

};


/**
 * setUp: function called before each test
 */
void TestConsultant::setUp() {
    Personne consultant;
}

/**
 * setUp: function called after each test
 */
void TestConsultant::tearDown() {
}

/**
 * test that all values are present by computing
 * sum i=1,size of v[i] which is supposed to be
 * equal to size*(size+1)/2
 */
void TestConsultant::testConsultant() {
    // vector has been filled by method 'setUp'
    Session_Consultant * C1 = new Session_Consultant( consultant );

    CPPUNIT_ASSERT(C1->getConsultant() == consultant);
}

void TestConsultant::test_Consulter_fiche() {
    Session_Consultant * C1 = new Session_Consultant( consultant );
    C1->Consulter_fiche();
    //Taiter le cas ou il n'y a pas de fiche existante
}

/**
 * Test that will fail, used for example purpose
 */
void TestAssociation::test_fail() {
    CPPUNIT_ASSERT(0 == 1);
}


/**
 * declare suite of tests
 *
 */
CppUnit::TestSuite * TestConsultant::make_suite() {
    CppUnit::TestSuite *suite = new CppUnit::TestSuite(CLASS_NAME_STRING);
    cout << "==============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "==============================================" << endl;

    TEST_ADD(Session_Consultant);
    TEST_ADD(Consulter_fiche);
    TEST_ADD(fail);

    return suite;
}