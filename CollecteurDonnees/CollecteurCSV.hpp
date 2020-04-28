#ifndef COLLECTEURCSV_H
#define COLLECTEURCSV_H

#include <string>
#include "CollecteurDonnees.hpp"
#include "../Association_class/Association.hpp"
#include "../Association_class/Membre.h"


/*!
*\file CollecteurCSV.hpp
*\brief Definition de la classe permettant de collecter les donnees a partir d'un fichier CSV
*\author Groupe A4
*\version 0.1
*\date 7 avril 2020

\class CollecteurCSV
*/
class CollecteurCSV {

    private :
    std::string pathCSV;
    std::string pathTxt;
        
    public :
    /*!
    * \brief Chargement du fichier
    * Permet à partir de son chemin de récupérer le fichier CSV contenant les réponses des membres
    */
        static void Chargement(std::string pathCSV);

    /*!
    * \brief Mise à jour des membres
    * Permet de mettre à jour la liste des membres de l'association contenue dans un fichier texte    */
        static void MAJMembres(std::string pathTxt);







};
#endif
