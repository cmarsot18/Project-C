#ifndef TEST_CONSULTANT_H
#define TEST_CONSULTANT_H


#include <string>
#include <list>
#include "Personne.hpp"
#include "Consultant.h"

#include "../Test/TestUnit.h"




using namespace std;

/*!
 * \file TestConsultant.h
 * \brief Test de la classe Consultant
 * \author Groupe A4
 * \version 0.1
 */


#define TEST_ADD_CONSULTANT(name) \
	suite->addTest(new CppUnit::TestCaller<TestConsultant>("test_"#name, \
		&TestConsultant::test_##name));

/*!
 * \Class TestConsultant
 * \brief Cette classe définit les tests de la classe Consultant
 */


class TestConsultant : public CppUnit::TestFixture {
private:
    string mission;
    string nom;
    string prenom;


public:
    /*!
     * \brief Constructeur de la classe TestConsultant
     */
    TestConsultant();
    /*!
     * \brief Destructeur de la classe TestConsultant
     */
    virtual ~TestConsultant();

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
    * \brief Test du constructeur de la classe Consultant
    */
    TEST_DECL(Consultant);

    TEST_DECL(fail);

};

#endif /* TEST_CONSULTANT_H */


