#ifndef RENDUPDF_H
#define RENDUPDF_H
#include "RenduDonnees.hpp"
#include <string>
#include "hpdf.h"

#include "Membre.h"
#include "Consultant.h"

#define LOGO "/home/guenole/CLionProjects/Project-C/logo.jpeg"
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
    *  \brief Constructeur
    *
    *  Constructeur de la classe RenduPDF
    *
    *  \param p : Chemin du fichier
    */
    RenduPDF(string p_path);

    /*!
     * \brief Génération de la fiche d'un membre
     * Cette fiche fera apparaitre les indicateurs caractéristiques du membre (satisfaction, motivation...)
     */
        void Generer_membre(Personne *p_Personne);

    /*!
    * \brief Génération de la fiche d'un membre
    * Cette fiche fera apparaitre les indicateurs caractéristiques du membre (satisfaction, motivation...)
    */
        void Fiche(Membre *p_membre);


    /*!
     * \brief Génération de la fiche d'un consultant
     * Cette fiche fera apparaitre les indicateurs caractéristiques du consultant (satisfaction, motivation...)
     */
        void Fiche(Consultant *p_consultant);



    /*!
    * \brief Génération de la fiche de l'association
    */
        static void Generer_Association();
};
#endif
