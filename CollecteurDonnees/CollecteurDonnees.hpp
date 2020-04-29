#ifndef COLLECTEURDONNEES_H
#define COLLECTEURDONNEES_H

#include <string>

/*!
*\file CollecteurDonnees.hpp
*\brief Definition de l'interface permettant de collecter les donnees
*\author Groupe A4
*\version 0.1
*\date 7 avril 2020

\class CollecteurDonnees
*/

class CollecteurDonnees {

private :
    std::string path1;
    std::string path2;

public :
    /*!
    * \brief Chargement du fichier
    * Permet à partir de son chemin de récupérer le fichier contenant les réponses des membres
    */
    virtual void Chargement(std::string path1) =0;

    /*!
    * \brief Mise à jour des membres
    * Permet de mettre à jour la liste des membres de l'association contenu dans un fichier     */
    virtual void MAJMembres(std::string path2) =0;

};
#endif