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

class Session_Admin : public Session_Membre{
public:
    void Entrer_donnees(std::string path);
    void Consulter_fiche(Personne pMembre);
    void Ajouter_admin(Session pSession);
};


#endif //PROJET_C_SESSION_ADMIN_H
