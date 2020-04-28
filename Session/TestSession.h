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

    /*!
    * \brief Constructeur de la classe TestSession
    */
    TestSession();

    /*!
     * \brief Destructeur de la classe TestSession
     */
    virtual ~TestSession();


    /*!
     * \brief Création des éléments permettant de mettre en place les tests
     */
    void setUp();

    /*!
     * \brief Libère la mémoire qui contenait les éléments de test
     */
    void tearDown();

    CppUnit::TestSuite * make_suite();

    /*!
     * \brief Test du constructeur de la classe Session
     */
    TEST_DECL(Session);
    /*!
    * \brief Test de connexion
    */
    TEST_DECL(Connection);
    /*!
     * \brief Ce test vérifie que CppUnit fonctionne correctement
     * Il fait vérifier l'assertion 0==1, pour vérifier qu'il y a bien une erreur
     */
    TEST_DECL(fail);

};

#endif //PROJECT_C_TESTSESSION_H
