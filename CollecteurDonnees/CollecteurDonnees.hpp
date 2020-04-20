#ifndef COLLECTEURDONNEES_H
#define COLLECTEURDONNEES_H

#include <string>

/*!
*\file CollecteurDonnees.hpp
*\brief {Définition de l'interface permettant de collecter les données}
*\author Groupe A4
*\version 0.1
*\date 7 avril 2020

\class CollecteurDonnees
*/

class CollecteurDonnees {
    public :

    /*!
     * \brief Génération d'un membre
     * Permet de collecter les données d'un membre à partir de son nom et de son prénom
     */
        virtual void Generer_membre(std::string Nom, std::string Prenom) =0;


    /*!
    * \brief Génération des membres
    * Permet de collecter les données de tous les membres
    */
        virtual void Generer_membres() =0;

    /*!
    * \brief Génération de l'association
    * Permet de collecter les données de l'association en général
    */
        virtual void Generer_Association() =0;
};
#endif