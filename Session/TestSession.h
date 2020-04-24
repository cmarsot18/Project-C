//
// Created by yasmine on 16/04/2020.
//

#ifndef PROJECT_C_TESTSESSION_H
#define PROJECT_C_TESTSESSION_H

#include "../Test/TestUnit.h"
#include "Session.h"

/*!
 * \file TestSession.h
 * \brief Test d'une session
 * \author Groupe A4
 * \version 0.1
 */

using namespace std;
#define CLASS_NAME_STRING "Session"

/*!
 * \Class TestSession
 * \brief Cette classe teste le bon fonctionnement d'une session
 * Elle vérifie les méthodes (à l'exception des accesseurs)
 */

class TestSession : public CppUnit::TestFixture {
private:
    std::string ID;
    std::string Pass;
public:
    //TestSession(const std::string,const std::string);

    void setUp();
    void tearDown();

    CppUnit::TestSuite * make_suite();

    TEST_DECL(Session);
    TEST_DECL(Connection);
    TEST_DECL(fail);

};

#endif //PROJECT_C_TESTSESSION_H