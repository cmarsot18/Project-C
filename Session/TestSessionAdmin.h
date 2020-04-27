//
// Created by marsot on 20/04/2020.
//

#ifndef PROJECT_C_TESTSESSIONADMIN_H
#define PROJECT_C_TESTSESSIONADMIN_H

#include "../Test/TestUnit.h"
#include "Session_Admin.h"
#include "Session_Membre.h"

/*!
 * \file TestSessionAdmin.h
 * \brief Test d'une session Admin
 * \author Groupe A4
 * \version 0.1
 */

using namespace std;
#define CLASS_NAME_STRING "Session_Admin"

/*!
 * \Class TestSessionAdmin
 * \brief Cette classe teste le bon fonctionnement d'une session associé à un Admin
 * Elle vérifie les méthodes (à l'exception des accesseurs)
 */

class TestSessionAdmin : public CppUnit::TestFixture {
private:
    Personne Membre;
public:
    Session_Admin();
    virtual ~Session_Admin();

    void setUp();
    void tearDown();

    CppUnit::TestSuite * make_suite();

    TEST_DECL(Session_Admin);
    TEST_DECL(Consulter_fiche);
    TEST_DECL(fail);
};

#endif //PROJECT_C_TESTSESSIONADMIN_H
