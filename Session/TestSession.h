//
// Created by yasmine on 16/04/2020.
//

#ifndef PROJECT_C_TESTSESSION_H
#define PROJECT_C_TESTSESSION_H

#include "../Test/TestUnit.h"
#include "Session.h"

/*!
 * \file TestSession.h
 * \brief Test d'une Session
 * \author Groupe A4
 * \version 0.1
 */

using namespace std;
#define CLASS_NAME_STRING "Session"
#define TEST_ADD_SESSION(name) \
	suite->addTest(new CppUnit::TestCaller<TestSession>("test_"#name, \
		&TestSession::test_##name));

/*!
 * \Class TestSession
 * \brief Cette classe teste le bon fonctionnement d'une session
 * Elle vérifie les méthodes (à l'exception des accesseurs)
 */

class TestSession : public CppUnit::TestFixture {
private:
    string ID1;
    string Pass1;
    string ID2;
    string Pass2;
public:

    TestSession();

    virtual ~TestSession();

    void setUp();
    void tearDown();

    CppUnit::TestSuite * make_suite();

    TEST_DECL(Session);
    TEST_DECL(Connection);
    TEST_DECL(fail);

};

#endif //PROJECT_C_TESTSESSION_H
