//
// Created by marsot on 20/04/2020.
//

#ifndef PROJECT_C_TESTSESSIONMEMBRE_H
#define PROJECT_C_TESTSESSIONMEMBRE_H

#include "../Test/TestUnit.h"
#include "Session_Membre.h"

/*!
 * \file TestSessionMembre.h
 * \brief Test d'une session Membre
 * \author Groupe A4
 * \version 0.1
 */

using namespace std;
#define CLASS_NAME_STRING "Session_Membre"

/*!
 * \Class TestSessionMembre
 * \brief Cette classe teste le bon fonctionnement d'une session associé à un Membre
 * Elle vérifie les méthodes (à l'exception des accesseurs)
 */

class TestSessionMembre : public CppUnit::TestFixture {
private:
    Personne Membre;
public:
    Session_Membre();
    virtual ~Session_Membre();

    void setUp();
    void tearDown();

    CppUnit::TestSuite * make_suite();

    TEST_DECL(Session_Membre);
    TEST_DECL(Consulter_ficheAsso);
    TEST_DECL(fail);
};

#endif //PROJECT_C_TESTSESSIONMEMBRE_H
