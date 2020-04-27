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




#endif /* TEST_UNIT_H */