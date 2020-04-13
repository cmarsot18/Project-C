#ifndef ASSOCIATION_H
#ifdefine ASSOCIATION_H

/*!
 * \file Association.hpp
 * \brief Définition d'une association
 * \author Groupe A4
 * \version 0.1
 */

#include <vector>
#include "Personne.hpp"

/*!
 * \Class Association
 * \brief Cette classe défini une association
 * Elle contient un certain nombre de renseignements sur l'association (Nom, lieu du siège...)
 */

class Association {
    private:
        str Nom;
        str Lieu;
        int Nombre_Membres;
        vector<Membre> Membres;
        vector<Consultant> Consultants;
    
    
    public:
    /*!
     * \brief Constructeur de la classe association
     * Crée une association "vide", avec aucune information
     */
        Association();
        
    /*!
     * \brief Constructeur de la classe association
     * Crée une association ayant un nom mais aucune autre information
     */
        Association(str);
        
    /*!
     * \brief Constructeur de la classe association
     * Crée une association pour laquelle on connait le nom, le lieu du siège et les membres
     */
        Association(str,str,int,vector<Membre>,vector<Consultant>);
        
    /*!
     * \brief Destructeur de la classe association
     */
        virtual ~Association();
        
    /*!
     * \brief Permet d'obtenir le nom d'une association
     */
        str getNom() const;
        
    /*!
     * \brief Permet de modifier le nom d'une association
     */
        str setNom();
        
    /*!
     * \brief Permet d'obtenir le lieu du siège de l'association
     */
        str getLieu() const;
        
    /*!
     * \brief Permet de modifier le lieu d'une association
     */
        str setLieu();
        
        /*!
     * \brief Permet d'obtenir le nombre de membres de l'association
     */
        int getNombre_Membres() const;
        
    /*!
     * \brief Permet d'obtenir la liste des membres de l'association
     */
        vector<Membre> getMembres() const;
        
    /*!
     * \brief Permet d'ajouter un membre dans l'association
     */
        void ajouterMembre(const Personne);
        
    /*!
     * \brief Permet de supprimer un membre de l'association
     */
        void supprimerMembre(Personne);
        
};

#endif