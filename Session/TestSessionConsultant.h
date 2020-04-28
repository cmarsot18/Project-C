//
// Created by yasmine on 16/04/2020.
//

#ifndef PROJECT_C_TESTSESSIONCONSULTANT_H
#define PROJECT_C_TESTSESSIONCONSULTANT_H

#include "../Test/TestUnit.h"
#include "Session_Consultant.h"

/*!
 * \file TestSessionConsultant.h
 * \brief Test d'une Session_Consultant
 * \author Groupe A4
 * \version 0.1
 */

using namespace std;
#define TEST_ADD_SESSION_CONSULTANT(name) \
	suite->addTest(new CppUnit::TestCaller<TestSessionConsultant>("test_"#name, \
		&TestSessionConsultant::test_##name));

/*!
 * \Class TestSessionConsultant
 * \brief Cette classe teste le bon fonctionnement d'une session associé à un consultant
 * Elle vérifie les méthodes (à l'exception des accesseurs)
 */

class TestSessionConsultant : public CppUnit::TestFixture {
private:
    Consultant consultant;
public:
    /*!
   *  \brief Constructeur de la classe TestSessionConsultant
   */
    TestSessionConsultant();
    /*!
   *  \brief Destructeur de la classe TestSessionConsultant
   */
    virtual ~TestSessionConsultant();
/*!
   *  \brief Création des éléments nécessaires aux tests
   */
    void setUp();
    /*!
   *  \brief Libération de la mémoire
   */
    void tearDown();

    CppUnit::TestSuite * make_suite();
   /*!
   *  \brief Test de la création d'une session consultant
   */
    TEST_DECL(Session_Consultant);
    /*!
   *  \brief Test de la consultation d'une fiche
   */
    TEST_DECL(Consulter_fiche);
    /*!
   *  \brief Test qui rate à chaque fois
   */
    TEST_DECL(fail);
};

#endif //PROJECT_C_TESTSESSIONCONSULTANT_H
