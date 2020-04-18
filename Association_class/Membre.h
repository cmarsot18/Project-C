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

/*! \class Membre
   * \brief classe representant la personne membre dans une association
   *
   *  La classe est heritee de la classe Personne qui definit plus prondement les attributs d une personne
   */

class Membre : private Personne {
    std::list<std::string> liste_Attribut; /*!< Liste des attributs*/
    std::string pole;/*!< definition de type de pole*/

public:
    /*!
        *  \brief Constructeur
        *
        *  Constructeur de la classe Membre
        */
    Membre();

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Membre
    *
    *  \param p : nom du pole
    */
    Membre(std::string p);

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Membre
    *
    *  \param p : nom du pole
    *  \param LA : liste des attributs
    */
    Membre(std::list<std::string> LA, std::string p);

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
    std::string getpole() const;

    /*!
     *  \brief Rentre le nom du pole
     *
     *  Methode qui permet de rentrer le nom du pole du membre
     *
     *  \param p : le nom du pole
     */

    void setNom(std::string p);

    /*!
     *  \brief Donne la liste des attributs
     *
     *  Methode qui permet de retourner la liste des attributs du consultant
     *
     *  \return un std::list<string qui est la liste des attribus du consultant
     */
    std::list<std::string> getAttribut() const;

};

#endif // MEMBRE_H