//
// Created by marso on 07/04/2020.
//

#ifndef PROJET_C_SESSION_ADMIN_H
#define PROJET_C_SESSION_ADMIN_H
#include <iostream>
#include <string>
#include "Session_Membre.h"
#include "Session.h"
#include "Personne.h"

/*!
*\file Session_Admin.hpp
*\brief {Définition d'une session administrateur et de ses caractéristiques}
*\author Groupe A4
*\version 0.1
*\date 10 avril 2020

\class Session_Admin
*/

class Session_Admin : public Session_Membre{
public:
    /*!
     * \brief Permet l'entrée des données
     */
    void Entrer_donnees(std::string path);

    /*!
     * \brief Permet la consultation des fiches par l'administrateur
     */
    void Consulter_fiche(Personne pMembre);

    /*!
     * \brief Permet la gestion des sessions administrateurs, notamment pour ajouter un nouvel administrateur
     */
    void Ajouter_admin(Session pSession);
};


#endif //PROJET_C_SESSION_ADMIN_H
