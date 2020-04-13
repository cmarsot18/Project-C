#ifndef PROJECT_C_TESTASSOCIATION_H
#define PROJECT_C_TESTASSOCIATION_H

/*!
 * \file TestAssociation.h
 * \brief Test d'une association
 * \author Groupe A4
 * \version 0.1
 */

#include <vector>
#include "Personne.hpp"
#include "Association.hpp"

/*!
 * \Class TestAssociation
 * \brief Cette classe teste une association
 * Elle vérifie le bon fonctionnement des méthodes (à l'exception des accesseurs)
 */

class TestAssociation {

public:
    void testAssociation(str,str,int,vector<Membre>,vector<Consultant>);
    void testAjouterMembre(Personne);
    void testSupprimerMembre(Personne);
};





#endif
