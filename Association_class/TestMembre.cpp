#include "TestMembre.h"
/*
#include <algorithm>
#include <iterator>
#include <numeric>
*/
using namespace std;

TestMembre::TestMembre(){

};

// ----------------------------------------------

TestMembre::~TestMembre(){

};


/**
 * setUp: function called before each test
 */
void TestMembre::setUp() {
    pole= "Devco";
    nom = "Fiche";
    prenom = "Guenole";
}

/**
 * setUp: function called after each test
 */
void TestMembre::tearDown() {
}

/**
 * test that all values are present by computing
 * sum i=1,size of v[i] which is supposed to be
 * equal to size*(size+1)/2
 */
void TestMembre::test_Membre() {
    // vector has been filled by method 'setUp'
    Membre *membre = new Membre(pole, nom, prenom);
    CPPUNIT_ASSERT(membre->getNom() == nom);
    CPPUNIT_ASSERT(membre->getpole() == pole);
    CPPUNIT_ASSERT(membre->getPrenom() == prenom);

    CPPUNIT_ASSERT_THROW(Membre *membre2 = new Membre(pole, nom, prenom), exception);

    CPPUNIT_ASSERT_THROW(Membre *membre3 = new Membre(pole, "", prenom), exception);

}

/**
 * Test that will fail, used for example purpose
 */
    void TestMembre::test_fail() {
        CPPUNIT_ASSERT(0 == 1);
    }


/**
 * declare suite of tests
 *
 */
    CppUnit::TestSuite * TestMembre::make_suite() {
        CppUnit::TestSuite *suite = new CppUnit::TestSuite("Membre");
        cout << "==============================================" << endl;
        cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
        cout << "==============================================" << endl;

        TEST_ADD_MEMBRE(Membre);
        TEST_ADD_MEMBRE(fail);

        return suite;
    }


