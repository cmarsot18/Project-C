//
// Created by marso on 07/04/2020.
//

#ifndef PROJET_C_SESSION_ADMIN_H
#define PROJET_C_SESSION_ADMIN_H

/*!
 * \file Session_Admin.h
 * \brief Definition de la session administrateur
 * \author Groupe A4
 * \version 0.1
 */

#include <iostream>
#include <string>
#include "Session_Membre.h"
#include "../Association_class/Personne.hpp"
class Session;
/*!
 * \Class Session_Admin
 * \brief Cette classe defini les session administrateur
 * Les session administrateurs sont celles qui vont permettre de gerer l'application
 */

class Session_Admin : public Session_Membre{
public:
    /*!
     * \brief Affiche une fiche
     * Affiche la fiche du membre cible
     */
    void Consulter_fiche(string p_path , Personne *pMembre);
    /*!
     * \brief Permet l'ajout d'administrateur
     * permet de changer la session choisie en session administrateur
     */
    Session_Admin(Membre pMembre);
    virtual ~Session_Admin();
    void Ajouter_Admin(Membre pMembre);
};


#endif //PROJET_C_SESSION_ADMIN_H
