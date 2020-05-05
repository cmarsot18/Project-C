#ifndef COLLECTEURCSV_H
#define COLLECTEURCSV_H

#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "../Gestion_memoire/Gestion_membre.h"


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
    * \brief Mise à jour des membres
    * Permet de mettre à jour la liste des membres de l'association contenue dans un fichier texte    */
    static void MAJMembres(std::string path, Association asso);







};
#endif
