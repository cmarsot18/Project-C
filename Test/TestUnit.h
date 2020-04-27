#ifndef TEST_UNIT_H
#define TEST_UNIT_H

#include "cppunit/TestCase.h"
#include "cppunit/TestFixture.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestSuite.h"
#include "cppunit/CompilerOutputter.h"
#include "cppunit/XmlOutputter.h"
#include "cppunit/ui/text/TestRunner.h"

using namespace std;

#define OUTPUT_XML_FILE "output.xml"


#define TEST_DECL(x) void test_##x()


#define TEST_ADD(name) \
	suite->addTest(new CppUnit::TestCaller<TestAssociation>("test_"#name, \
		&TestAssociation::test_##name));
    suite->addTest(new CppUnit::TestCaller<TestSession>("test_"#name, \
		&TestSession::test_##name));
    suite->addTest(new CppUnit::TestCaller<TestCollecteurCSV>("test_"#name, \
		&TestCollecteurCSV::test_##name));
    suite->addTest(new CppUnit::TestCaller<TestSessionAdmin>("test_"#name, \
		&TestSessionAdmin::test_##name));
    suite->addTest(new CppUnit::TestCaller<TestSessionMembre>("test_"#name, \
		&TestSessionMembre::test_##name));
    //suite->addTest(new CppUnit::TestCaller<TestSessionConsultant>("test_"#name, \
		&TestConsultantSession::test_##name));


#endif /* TEST_UNIT_H */