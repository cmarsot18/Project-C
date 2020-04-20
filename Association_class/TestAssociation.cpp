
#include "TestAssociation.h"
/*
#include <algorithm>
#include <iterator>
#include <numeric>
*/
using namespace std;

TestAssociation::TestAssociation(){

};

// ----------------------------------------------

TestAssociation::~TestAssociation(){

};


/**
 * setUp: function called before each test
 */
void TestAssociation::setUp() {
    nom = "AJIR";
    lieu = "INSA Rouen";

    vm.push_back(  Membre( "Devco", "Fiche", "Guenole") );
    vm.push_back(  Membre( "Com", "Hartmann", "Constance") );
}

/**
 * setUp: function called after each test
 */
void TestAssociation::tearDown() {
    vm.clear();
}

/**
 * test that all values are present by computing
 * sum i=1,size of v[i] which is supposed to be
 * equal to size*(size+1)/2
 */
void TestAssociation::test_Association() {
    // vector has been filled by method 'setUp'
    Association * ajir = new Association( nom, lieu );

    CPPUNIT_ASSERT(ajir->getNom() == nom);
    CPPUNIT_ASSERT(ajir->getLieu() == lieu);

//    Association ajir2 = new Association( nom, lieu );
//    CPPUNIT_ASSERT(ajir.getLieu() == lieu);

//    Association ajir3 = new Association( "" );
//    CPPUNIT_ASSERT(ajir.getLieu() == lieu);
}

void TestAssociation::test_ajouterMembre() {
    Association * ajir = new Association( nom, lieu );
    ajir->setMembres( vm );
    ajir->ajouterMembre( Membre( "Devco", "Marsot", "Corentin"));
    CPPUNIT_ASSERT(ajir->getNombre_Membres() == 3);
}

void TestAssociation::test_supprimerMembre() {
    Association * ajir = new Association( nom, lieu );
    ajir->setMembres( vm );
    ajir->supprimerMembre( Membre( "Devco", "Fiche", "Guenole"));
    CPPUNIT_ASSERT(ajir->getNombre_Membres() == 1);
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
CppUnit::TestSuite * TestAssociation::make_suite() {
    CppUnit::TestSuite *suite = new CppUnit::TestSuite(CLASS_NAME_STRING);
    cout << "==============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "==============================================" << endl;

    TEST_ADD(Association);
    TEST_ADD(ajouterMembre);
    TEST_ADD(supprimerMembre);
    TEST_ADD(fail);

    return suite;
}

/**
 * main function
 */
 /*
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
  */
