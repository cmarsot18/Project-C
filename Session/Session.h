//
// Created by marsot on 31/03/2020.
//

#ifndef PROJET_C_SESSION_H
#define PROJET_C_SESSION_H
#include <iostream>
#include <string>

/*!
*\file Session.hpp
*\brief {Définition d'une session et de ses caractéristiques}
*\author Groupe A4
*\version 0.1
*\date 10 avril 2020

\class Session
*/

class Session {
private:
    std::string ID;
    std::string Pass;
public:
    /*!
     * \brief Permet la gestion de connexion aux sessions
     */
    bool Connection();
};


#endif //PROJET_C_SESSION_H
