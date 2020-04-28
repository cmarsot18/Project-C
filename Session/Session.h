//
// Created by marsot on 31/03/2020.
//

#ifndef PROJET_C_SESSION_H
#define PROJET_C_SESSION_H

/*!
 * \file Session.h
 * \brief Definition d'une Session
 * \author Groupe A4
 * \version 0.1
 */

#include <iostream>
#include <string>

/*!
 * \Class Session
 * \brief Cette classe defini une session
 * Cette classe contient les information de connection et ne sera jamais implementer en tant que tel
 */

class Session {
private:
    std::string ID;
    std::string Pass;
public:
    Session();
    Session(const std::string,const std::string);
    void setID(const std::string);
    void setPass(const std::string);
    std::string getID() const;
    std::string getPass() const;

    /*!
     * \brief Permet de se connecter à sa session
     * Renvoie un booleen decrivant si la connection peut s'etablir
     */
    bool Connection(const std::string,const std::string) const;
};


#endif //PROJET_C_SESSION_H
