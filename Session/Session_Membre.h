//
// Created by marso on 07/04/2020.
//

#ifndef PROJET_C_SESSION_MEMBRE_H
#define PROJET_C_SESSION_MEMBRE_H

/*!
 * \file Association.hpp
 * \brief Définition d'une association
 * \author Groupe A4
 * \version 0.1
 */

#include <iostream>
#include <string>
#include "Session_Consultant.h"

/*!
 * \Class Association
 * \brief Cette classe défini une association
 * Elle contient un certain nombre de renseignements sur l'association (Nom, lieu du siège...)
 */

class Session_Membre ; public {
private :
    Membre personne;
public:
/*!
* \brief Constructeur de la classe association
* Crée une association "vide", avec aucune information
*/
    void Consulter_fiche_asso();
/*!
* \brief Constructeur de la classe association
* Crée une association "vide", avec aucune information
*/
    void setMembre(Membre pPersonne);
};


#endif //PROJET_C_SESSION_MEMBRE_H
