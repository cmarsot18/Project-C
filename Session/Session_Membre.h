//
// Created by marso on 07/04/2020.
//

#ifndef PROJET_C_SESSION_MEMBRE_H
#define PROJET_C_SESSION_MEMBRE_H

/*!
 * \file Session_membre.h
 * \brief Definition d'une session d'un Membre
 * \author Groupe A4
 * \version 0.1
 */

#include <iostream>
#include <string>
#include "../Association_class/Membre.h"
#include "Session_Consultant.h"

/*!
 * \Class Session_membre
 * \brief Definition d'une session d'un membre
 * Elle permet aux membres de consulter leur fiche ainsi que celle de l'association et donc herite de session consultant
 */

class Session_Membre:public Session_Consultant {
private :
    Membre personne;
public:
    void setMembre(const Personne);
    Personne getMembre() const;
    Session_Membre();
    Session_Membre(const Membre);
    virtual ~Session_Membre();
/*!
* \brief affiche la fiche asso
* permet de consulter la fiche de l'association
*/
    void Consulter_fiche_asso();
/*!
* \brief Setter pour l'attribut personne
* permet de renseigner le memebre associe à la session
*/
    void setMembre(Membre pPersonne);
};


#endif //PROJET_C_SESSION_MEMBRE_H
