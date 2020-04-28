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
 * \brief Test d'une Session_Admin
 * \author Groupe A4
 * \version 0.1
 */

using namespace std;
#define TEST_ADD_SESSION_ADMIN(name) \
	suite->addTest(new CppUnit::TestCaller<TestSessionAdmin>("test_"#name, \
		&TestSessionAdmin::test_##name));

/*!
 * \Class TestSessionAdmin
 * \brief Cette classe teste le bon fonctionnement d'une session associe à un Admin
 * Elle verifie les methodes (à l'exception des accesseurs)
 */

class TestSessionAdmin : public CppUnit::TestFixture {
private:
    Membre membre;
public:
    /*!
   *  \brief Constructeur de TestSessionAdmin
   */
    TestSessionAdmin();
    /*!
   *  \brief Destructeur de TestSessionAdmin
   */
    virtual ~TestSessionAdmin();

    /*!
   *  \brief Creation des elements necessaires aux tests
   */
    void setUp();
    /*!
   *  \brief Liberation memoire
   */
    void tearDown();

    CppUnit::TestSuite * make_suite();

    /*!
   *  \brief Test du constructeur de Session admin
   */
    TEST_DECL(Session_Admin);
    /*!
   *  \brief Test de la consultation d'une fiche
   */
    TEST_DECL(Consulter_fiche);
    /*!
   *  \brief Test qui rate tout le temps
   */
    TEST_DECL(fail);
};

#endif //PROJECT_C_TESTSESSIONADMIN_H
