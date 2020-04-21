//
// Created by yasmine on 16/04/2020.
//

#ifndef PROJECT_C_TESTCONSULTANT_H
#define PROJECT_C_TESTCONSULTANT_H

#include "../Test/TestUnit.h"
#include "Session_Consultant.h"

/*!
 * \file TestConsultant.h
 * \brief Test d'une session consultant
 * \author Groupe A4
 * \version 0.1
 */

using namespace std;
#define CLASS_NAME_STRING "Session_Consultant"

/*!
 * \Class TestConsultant
 * \brief Cette classe teste le bon fonctionnement d'une session associé à un consultant
 * Elle vérifie les méthodes (à l'exception des accesseurs)
 */

class TestConsultant : public CppUnit::TestFixture {
private:
    Personne consultant;
public:
    Session_Consultant();
    virtual ~Session_Consultant();

    void setUp();
    void tearDown();

    CppUnit::TestSuite * make_suite();

    TEST_DECL(Session_Consultant);
    TEST_DECL(Consulter_fiche);
    TEST_DECL(fail);
};

#endif //PROJECT_C_TESTCONSULTANT_H
