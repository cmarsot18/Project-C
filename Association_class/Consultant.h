#ifndef CONSULTANT_H
#define CONSULTANT_H

/*!
 * \file Consultant.h
 * \brief Definition d'un consultant
 * \author groupe A4
 */
#include <string>
#include <list>
#include "Personne.hpp"

using namespace std;

/*! \class Consultant
   * \brief classe representant la personne consultant dans une association
   *  La classe est heritee de la classe Personne qui definit plus prondement les attributs d une personne 
   */
class Consultant : public Personne {
    std::string pole = "Consultant";
    int notes[10];
/*!< definition de type de pole*/
/*! * \brief il s agit d un attribut static puisque qu il sera consultant peut importe sa mission
   */
    std::string mission;/*!< Nom de la mission en cours*/

public:

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Consultant

    */
    Consultant();

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Consultant
    *
    *  \param p : nom du pole
    */
    Consultant(string p_mission);

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Consultant
    *
    *  \param p : nom du pole
    *  \param LA : liste des attributs
    */
    Consultant( string p_mission, string p_nom, string p_prenom );

    Consultant( string p_pole, string p_nom, string p_prenom,
    string p_mail, string p_departement );
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Consultant
     */
    virtual ~Consultant();

    /*!
     *  \brief Donne le nom du pole
     *
     *  Methode qui permet de retourner le nom de la mission du Consultant
     *
     *  \return un str qui est le nom de la mission
     */
    string getMission() const;

    /*!
 *  \brief Change le nom de la mission
 *
 *  Methode qui permet de modifier et de retourner le nom de la mission du Consultant
 *
 *  \return un str qui est le nom de la mission
 */
    void setMission(string p_mission) ;

    /*!
 *  \brief Donne le nom du Consultant
 *
 *  Methode qui permet de retourner le nom du Consultant
 *
 *  \return un str qui est le nom du Consultant
 */
    string getNom() const;


    /*!
     *  \brief Rentre le nom du Consultant
     *
     *  Methode qui permet de rentrer le nom du Consultant
     *
     *  \param p : le nom du Consultant
     */

    void setNom(string p_nom);

    /*!
*  \brief Donne le prenom du Consultant
*
*  Methode qui permet de retourner le prenom du Consultant
*
*  \return un str qui est le prenom du Consultant
*/
    string getPrenom() const;


    /*!
     *  \brief Rentre le prenom du Consultant
     *
     *  Methode qui permet de rentrer le prenom du Consultant
     *
     *  \param p : le prenom du Consultant
     */

    void setPrenom(string p_prenom);

    /*!
   *  \brief Donne le mail du Consultant
   *
   *  Methode qui permet de retourner le mail du Consultant
   *
   *  \return un str qui est le mail du Consultant
   */
    string getMail() const;


    /*!
     *  \brief Rentre le mail du Consultant
     *
     *  Methode qui permet de rentrer le mail du Consultant
     *
     *  \param p : le mail du Consultant
     */

    void setMail(string p_mail);

    /*!
*  \brief Donne le departement du Consultant
*
*  Methode qui permet de retourner le departement du Consultant
*
*  \return un str qui est le departement du Consultant
*/
    string getDepartement() const;


    /*!
     *  \brief Rentre le departement du Consultant
     *
     *  Methode qui permet de rentrer le departement du Consultant
     *
     *  \param p : le departement du Consultant
     */

    void setDepartement(string p_departement);

    bool operator == (const Consultant obj1)
    {
        return (this->nom == obj1.nom
                && this->prenom == obj1.prenom);
    }

    void setNotes(int[6]);

    int* getNotes();
};

#endif // CONSULTANT_H