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
    Membre * membre = new Membre(pole, nom, prenom );
    CPPUNIT_ASSERT(membre->getNom() == nom);
    CPPUNIT_ASSERT(membre->getpole() == pole);
    CPPUNIT_ASSERT(membre->getPrenom() == prenom);

    CPPUNIT_ASSERT_THROW(Membre * membre2 = new Membre( nom, prenom ) , exception);

    CPPUNIT_ASSERT_THROW(Membre * membre3 = new Membre( "" , prenom ) , exception);



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
        CppUnit::TestSuite *suite = new CppUnit::TestSuite(CLASS_NAME_STRING);
        cout << "==============================================" << endl;
        cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
        cout << "==============================================" << endl;

        TEST_ADD(Membre);
        TEST_ADD(fail);

        return suite;
    }

/**
 * main function
 */

    int main(int argc, char *argv[]) {
        CppUnit::TextUi::TestRunner runner;

        // create suite
        CppUnit::TestSuite *suite = make_suite();
        runner.addTest(suite);

        // set output format as text
        runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), cout));

        // run all tests
        runner.run();

        return 0;
    }

