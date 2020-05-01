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
    mission= "ETUDE-02";
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
void TestConsultant::test_Consultant() {
    // vector has been filled by method 'setUp'
    Consultant *consultant = new Consultant(mission, nom, prenom);
    CPPUNIT_ASSERT(consultant->getMission() == mission);

    CPPUNIT_ASSERT_THROW(Consultant *consultant2 = new Consultant(mission, nom, prenom), exception);

    CPPUNIT_ASSERT_THROW(Consultant *consultant3 = new Consultant("", nom, prenom), exception);

}

/**
 * Test that will fail, used for example purpose
 */
    void TestConsultant::test_fail() {
        CPPUNIT_ASSERT(0 == 1);
    }


/**
 * declare suite of tests
 *
 */
    CppUnit::TestSuite * TestConsultant::make_suite() {
        CppUnit::TestSuite *suite = new CppUnit::TestSuite("Consultant");
        cout << "==============================================" << endl;
        cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
        cout << "==============================================" << endl;

        TEST_ADD_CONSULTANT(Consultant);
        TEST_ADD_CONSULTANT(fail);

        return suite;
    }


