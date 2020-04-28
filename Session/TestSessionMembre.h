//
// Created by marsot on 20/04/2020.
//

#ifndef PROJECT_C_TESTSESSIONMEMBRE_H
#define PROJECT_C_TESTSESSIONMEMBRE_H

#include "../Test/TestUnit.h"
#include "Session_Membre.h"

/*!
 * \file TestSessionMembre.h
 * \brief Test d'une Session_Membre
 * \author Groupe A4
 * \version 0.1
 */

using namespace std;
#define TEST_ADD_SESSION_MEMBRE(name) \
	suite->addTest(new CppUnit::TestCaller<TestSessionMembre>("test_"#name, \
		&TestSessionMembre::test_##name));

/*!
 * \Class TestSessionMembre
 * \brief Cette classe teste le bon fonctionnement d'une session associé à un Membre
 * Elle vérifie les méthodes (à l'exception des accesseurs)
 */

class TestSessionMembre : public CppUnit::TestFixture {
private:
    Membre membre;
public:
    /*!
   *  \brief Constructeur de la classe TestSessionMembre
   */
    TestSessionMembre();
    /*!
   *  \brief Destructeur de la classe TestSessionMembre
   */
    virtual ~TestSessionMembre();
/*!
   *  \brief Création des éléments permettant de mettre en place les tests
   */
    void setUp();
    /*!
   *  \brief On libère la mémoire une fois le test fini
   */
    void tearDown();

    CppUnit::TestSuite * make_suite();
/*!
   *  \brief Test du constructeur de la classe Session membre
   */
    TEST_DECL(Session_Membre);
    /*!
   *  \brief Test de la méthode de consultation de la fiche de l'association
   */
    TEST_DECL(Consulter_ficheAsso);
    /*!
   *  \brief Test qui rate tout le temps ("test témoin")
   */
    TEST_DECL(fail);
};

#endif //PROJECT_C_TESTSESSIONMEMBRE_H
