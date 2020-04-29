#ifndef ASSOCIATION_H
#define ASSOCIATION_H

/*!
 * \file Association.hpp
 * \brief Definition d'une association
 * \author Groupe A4
 * \version 0.1
 */

#include <string>
#include <vector>
#include "Membre.h"
#include "Consultant.h"

using namespace std;

/*!
 * \Class Association
 * \brief Cette classe defini une association
 * Elle contient un certain nombre de renseignements sur l'association (Nom, lieu du siege...)
 */

class Association {
private:
    string nom;
    string lieu;
    vector<Membre> membres;
    vector<Consultant> consultants;


public:
    /*!
     * \brief Constructeur de la classe association
     * Cree une association "vide", sans aucune information.
     */
    Association();

    /*!
     * \brief Constructeur de la classe association
     * Cree une association ayec un nom seulement.
     */
    Association(string p_nom);

    /*!
     * \brief Constructeur de la classe association
     * Cree une association pour laquelle on connait le nom et le lieu du siege.
     */
    Association(string p_nom, string p_lieu);

    /*!
     * \brief Destructeur de la classe association
     */
    virtual ~Association();

    /*!
     * \brief Permet d'obtenir le nom d'une association
     */
    string getNom() const;

    /*!
     * \brief Permet de modifier le nom d'une association
     */
    string setNom(string p_nom);

    /*!
     * \brief Permet d'obtenir le lieu du siege de l'association
     */
    string getLieu() const;

    /*!
     * \brief Permet de modifier le lieu d'une association
     */
    string setLieu(string p_lieu);

    /*!
    * \brief Permet d'obtenir le nombre de membres de l'association
    */
    int getNombre_Membres() const;

    /*!
     * \brief Permet d'obtenir la liste des membres de l'association
     */
    vector<Membre> getMembres() const;
    vector<Consultant> getConsultant() const;

    /*!
     * \brief Permet de modifier la liste des membres de l'association
     */
    vector<Membre> setMembres(vector<Membre> p_listeMembres);

    /*!
     * \brief Permet d'ajouter un membre dans l'association
     */
    void ajouterMembre(Membre p_membre);
    void ajouterConsultant(Consultant p_consultant);
    /*!
     * \brief Permet de supprimer un membre de l'association
     */
    void supprimerMembre(Membre p_membre);

};

#endif