#ifndef TEST_MEMBRE_H
#define TEST_MEMBRE_H


#include <string>
#include <list>
#include "Personne.hpp"
#include "Membre.h"

#include "../Test/TestUnit.h"


using namespace std;

#define CLASS_NAME_STRING "Membre"

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

