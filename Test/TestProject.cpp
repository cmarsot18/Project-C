/**
 * main function
 */
#include "../Association_class/TestAssociation.h"
#include "../Session/TestSession.h"
#include "../Session/TestSessionConsultant.h"

int main(int argc, char *argv[]) {
//  TestMembre testMembre;
    TestAssociation testAssociation;
    TestSession testSession;
    TestSessionConsultant testSessionConsultant;
    CppUnit::TextUi::TestRunner runner;

//    CppUnit::TestSuite *membreSuite = testMembre.make_suite();
//    runner.addTest(membreSuite);

    // create suite
    CppUnit::TestSuite *associationSuite = testAssociation.make_suite();
    runner.addTest(associationSuite);

    // create suite
    CppUnit::TestSuite *sessionSuite = testSession.make_suite();
    runner.addTest(sessionSuite);

    // create suite
    //CppUnit::TestSuite *sessionconsultantSuite = testSessionConsultant.make_suite();
    //runner.addTest(sessionconsultantSuite);

    // set output format as text
    runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), cout));

    // run all tests
    runner.run();

    return 0;
}
