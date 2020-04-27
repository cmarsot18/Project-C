#ifndef MEMBRE_H
#define MEMBRE_H

/*!
 * \file Consultant.hpp
 * \brief Gestion d une association
 * \author groupe A4
 */
#include <string>
#include <list>
#include "Personne.hpp"

using namespace std;

/*! \class Membre
   * \brief classe representant la personne membre dans une association
   *
   *  La classe est heritee de la classe Personne qui definit plus prondement les attributs d une personne
   */

class Membre : public Personne {
    string pole;/*!< definition de type de pole*/

public:

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Membre
    *
    *  \param p : nom du pole
    */
    Membre(string p_pole);

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Membre
    *
    *  \param p : nom du pole
    *  \param LA : liste des attributs
    */
    Membre( string p_pole, string p_nom, string p_prenom );

    Membre( string p_pole, string p_nom, string p_prenom,
            string p_mail,string p_departement );
    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Membre
     */
    virtual ~Membre();

    /*!
     *  \brief Donne le nom du pole
     *
     *  Methode qui permet de retourner le nom du pole du membre
     *
     *  \return un str qui est le nom du pole
     */
    string getpole() const;

    /*!
 *  \brief Change le nom du pole
 *
 *  Methode qui permet de modifier et de retourner le nom du pole du membre
 *
 *  \return un str qui est le nom du pole
 */
    void setpole(string p_pole) ;

    /*!
 *  \brief Donne le nom du membre
 *
 *  Methode qui permet de retourner le nom du membre
 *
 *  \return un str qui est le nom du membre
 */
    string getNom() const;


    /*!
     *  \brief Rentre le nom du membre
     *
     *  Methode qui permet de rentrer le nom du membre
     *
     *  \param p : le nom du membre
     */

    void setNom(string p_nom);

    /*!
*  \brief Donne le prénom du membre
*
*  Methode qui permet de retourner le prénom du membre
*
*  \return un str qui est le prénom du membre
*/
    string getPrenom() const;


    /*!
     *  \brief Rentre le prénom du membre
     *
     *  Methode qui permet de rentrer le prénom du membre
     *
     *  \param p : le prénom du membre
     */

    void setPrenom(string p_prenom);

    /*!
   *  \brief Donne le mail du membre
   *
   *  Methode qui permet de retourner le mail du membre
   *
   *  \return un str qui est le mail du membre
   */
    string getMail() const;


    /*!
     *  \brief Rentre le mail du membre
     *
     *  Methode qui permet de rentrer le mail du membre
     *
     *  \param p : le mail du membre
     */

    void setMail(string p_mail);

    /*!
*  \brief Donne le département du membre
*
*  Methode qui permet de retourner le département du membre
*
*  \return un str qui est le département du membre
*/
    string getDepartement() const;


    /*!
     *  \brief Rentre le département du membre
     *
     *  Methode qui permet de rentrer le département du membre
     *
     *  \param p : le département du membre
     */

    void setDepartement(string p_departement);

    bool operator == (const Membre obj1)
    {
        return (this->nom == obj1.nom
                && this->prenom == obj1.prenom);
    }

    bool operator < (const Membre obj1)
    {
        return (this->nom < obj1.nom);
    }

};

#endif // MEMBRE_H