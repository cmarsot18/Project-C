//
// Created by yasmine on 16/04/2020.
//

#include "TestSession.h"

using namespace std;

TestSession::TestSession(){

};

// ----------------------------------------------

TestSession::~TestSession(){

};

/**
 * setUp: function called before each test
 */
void TestSession::setUp() {
    ID1 = "nom.prenom";
    Pass1 = "mdp";
    ID2 = "nom2.prenom2";
    Pass2 = "mdp2";
}

/**
 * setUp: function called after each test
 */
void TestSession::tearDown() {
}

/**
 * test that all values are present by computing
 * sum i=1,size of v[i] which is supposed to be
 * equal to size*(size+1)/2
 */
void TestSession::test_Session() {
    // vector has been filled by method 'setUp'
    Session * S1 = new Session( ID1, Pass1 );

    CPPUNIT_ASSERT(S1->getID() == ID1);
    CPPUNIT_ASSERT(S1->getPass() == Pass1);
}

void TestSession::test_Connection() {
    Session * S1 = new Session( ID1, Pass1 );
    S1->Connection(ID1,Pass1);
    CPPUNIT_ASSERT(S1->Connection(ID1,Pass1) == true);
    CPPUNIT_ASSERT(S1->Connection(ID1,Pass2) == false);
    CPPUNIT_ASSERT(S1->Connection(ID2,Pass1) == false);
    CPPUNIT_ASSERT(S1->Connection(ID2,Pass2) == false);
}

/**
 * Test that will fail, used for example purpose
 */
void TestSession::test_fail() {
    CPPUNIT_ASSERT(0 == 1);
}


/**
 * declare suite of tests
 *
 */
CppUnit::TestSuite * TestSession::make_suite() {
    CppUnit::TestSuite *suite = new CppUnit::TestSuite("Session");
    cout << "==============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "==============================================" << endl;

    TEST_ADD_SESSION(Session);
    TEST_ADD_SESSION(Connection);
    TEST_ADD_SESSION(fail);

    return suite;
}


