#ifndef RENDUPDF_H
#define RENDUPDF_H
#include "RenduDonnees.hpp"
#include <string>
/*!
 * \file RenduPDF.hpp
 * \brief Création d'une fiche récapitulative pour les membres et l'association sous format PDF
 * \author Groupe A4
 * \version 0.1
 */

/*!
 * \Class RenduPDF
 * \brief Cette classe définit les méthodes nécessaires à la création d'une fiche membre ou association
 */
class RenduPDF {

    private :
       std::string path;
        
    public :
    /*!
     * \brief Génération de la fiche d'un membre
     * Cette fiche fera apparaitre les indicateurs caractéristiques du membre (satisfaction, motivation...)
     */
        static void Generer_membre(Personne pPersonne);

    /*!
    * \brief Génération de la fiche de l'association
    */
        static void Generer_Association();
};
#endif
