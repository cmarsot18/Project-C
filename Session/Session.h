//
// Created by marsot on 31/03/2020.
//

#ifndef PROJET_C_SESSION_H
#define PROJET_C_SESSION_H

/*!
 * \file Session.hpp
 * \brief Définition d'une session
 * \author Groupe A4
 * \version 0.1
 */

#include <iostream>
#include <string>

/*!
 * \Class Session
 * \brief Cette classe défini une session
 * Cette classe contient les information de connection et ne sera jamais implémenter en tant que tel
 */

class Session {
private:
    std::string ID;
    std::string Pass;
public:
    Session(const std::string,const std::string);
    void setID(const std::string);
    void setPass(const std::string);
    std::string getID() const;
    std::string getPass() const;

    /*!
     * \brief Permet de se connecter à sa session
     * Renvoie un booléen décrivant si la connection peut s'établir
     */
    bool Connection(const std::string,const std::string) const;
};


#endif //PROJET_C_SESSION_H
