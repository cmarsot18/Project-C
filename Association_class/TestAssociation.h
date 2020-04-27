#ifndef TEST_ASSOCIATION_H
#define TEST_ASSOCIATION_H


#include <string>
#include <vector>

#include "../Test/TestUnit.h"
#include "Association.hpp"

using namespace std;

#define CLASS_NAME_STRING "Association"
#define TEST_ADD_ASSOCIATION(name) \
	suite->addTest(new CppUnit::TestCaller<TestAssociation>("test_"#name, \
		&TestAssociation::test_##name));

/*!
 * \Class TestAssociation
 * \brief Cette classe définit les tests de la classe Association
 */


class TestAssociation : public CppUnit::TestFixture {
private:
    string nom;
    string lieu;
    vector<Membre> vm;
    vector<Consultant*>vc;

public:
    /*!
     * \brief Constructeur de la classe TestAssociation
     */
    TestAssociation();
    /*!
     * \brief Destructeur de la classe TestAssociation
     */
    virtual ~TestAssociation();

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
     * \brief Test du constructeur de la classe association
     */
    TEST_DECL(Association);
    /*!
    * \brief Test de l'ajout d'un membre
    */
    TEST_DECL(ajouterMembre);
    /*!
    * \brief Test de la suppression
    */
    TEST_DECL(supprimerMembre);
    /*!
     * \brief Ce test vérifie que CppUnit fonctionne correctement
     * Il fait vérifier l'assertion 0==1, pour vérifier qu'il y a bien une erreur
     */
    TEST_DECL(fail);

};

#endif /* TEST_ASSOCIATION_H */