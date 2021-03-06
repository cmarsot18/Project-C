#ifndef TEST_MEMBRE_H
#define TEST_MEMBRE_H


#include <string>
#include <list>
#include "Personne.hpp"
#include "Membre.h"

#include "../Test/TestUnit.h"


using namespace std;

/*!
 * \file TestMembre.h
 * \brief Test de la classe Membre
 * \author Groupe A4
 * \version 0.1
 */

#define TEST_ADD_MEMBRE(name) \
	suite->addTest(new CppUnit::TestCaller<TestMembre>("test_"#name, \
		&TestMembre::test_##name));

/*!
 * \Class TestMembre
 * \brief Cette classe définit les tests de la classe Membre
 */


class TestMembre : public CppUnit::TestFixture {
private:
    string pole;
    string nom;
    string prenom;



public:
    /*!
     * \brief Constructeur de la classe TestMembre
     */
    TestMembre();
    /*!
     * \brief Destructeur de la classe TestMembre
     */
    virtual ~TestMembre();

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
    * \brief Test du constructeur de la classe Membre
    */
    TEST_DECL(Membre);

    TEST_DECL(fail);

};

#endif /* TEST_MEMBRE_H */

