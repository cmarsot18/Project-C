#ifndef PROJECT_C_TESTCOLLECTEURCSV_H
#define PROJECT_C_TESTCOLLECTEURCSV_H

#include <string>
#include "CollecteurCSV.hpp"
/*!
 * \file TestCollecteurCSV.h
 * \brief Test de la classe CollecteurCSV
 * \author Groupe A4
 * \version 0.1
 */

class TestCollecteurCSV {
    bool testGenerer_membre( std::string  Nom,  std::string  Prenom);
    bool testGenerer_membres();
    bool testGenerer_Association();

};


#endif
