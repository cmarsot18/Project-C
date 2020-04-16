#ifndef RENDUPDF_H
#ifdefine RENDUPDF_H
#include "RenduDonnees.hpp"
#include <string>
/*!
 * \file RenduPDF.hpp
 * \brief Création d'une fiche récapitulative pour les membres et l'association
 * \author Groupe A4
 * \version 0.1
 */

/*!
 * \Class RenduPDF
 * \brief Cette classe défini les méthodes nécessaires à la création d'une fiche membre ou association
 */
classe RenduPDF {

    private :
       std:string path;
        
    public :
    /*!
     * \brief Génération de la fiche d'un membre
     * Cette fiche fera apparaitre les indicateurs caractéristiques du membre (satisfaction, motivation...)
     */
        virtual static void Generer_membre(Personne pPersonne) =0;

    /*!
    * \brief Génération de la fiche de l'association
    */
        virtual static void Generer_Association() =0;
}
#endif
