#ifndef TEST_COLLECTEURCSV_H
#define TEST_COLLECTEURCSV_H

#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <list>

#include "../Test/TestUnit.h"
#include "CollecteurCSV.hpp"
#include "Membre.h"
#include "../Association_class/Association.hpp"

using namespace std;

#define CLASS_NAME_STRING "CollecteurCSV"
#define TEST_ADD_COLLECTEURCSV(name) \
	suite->addTest(new CppUnit::TestCaller<TestCollecteurCSV>("test_"#name, \
		&TestCollecteurCSV::test_##name));


/*!
 * \file TestCollecteurCSV.h
 * \brief Test de la classe CollecteurCSV
 * \author Groupe A4
 * \version 0.1
 */


class TestCollecteurCSV : public CppUnit::TestFixture {
private:
    string path;

public:
    /*!
    * \brief Constructeur de la classe TestCollecteurCSV
    */
    TestCollecteurCSV();
    /*!
     * \brief Destructeur de la classe TestCollecteurCSV
     */
    virtual ~TestCollecteurCSV();

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
     * \brief Test du chargement d'un fichier CSV
     */
    TEST_DECL(Chargement);

    /*!
    * \brief Test de la mise à jour de la liste des membres
    */
    TEST_DECL(MAJMembres);

    /*!
    * \brief Ce test vérifie que CppUnit fonctionne correctement
    * Il fait vérifier l'assertion 0==1, pour vérifier qu'il y a bien une erreur
    */
    TEST_DECL(fail);


};



#endif
