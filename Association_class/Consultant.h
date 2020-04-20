#ifndef CONSULTANT_H
#define CONSULTANT_H

/*!
 * \file Consultant.hpp
 * \brief Gestion d une association
 * \author groupe A4
 */
#include <string>
#include <list>
#include "Personne.hpp"

/*! \class Consultant
   * \brief classe representant la personne consultant dans une association
   *
   *  La classe est heritee de la classe Personne qui definit plus prondement les attributs d une personne 
   */
class Consultant : private Personne {
    std::list<std::string> liste_Attribut; /*!< Liste des attributs*/
    static std::string pole;
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
    *  \param m : nom de la mission en cours
    */
    Consultant(std::string m);

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Consultant
    *
    *  \param m : nom de la mission en cours
    *  \param lAttribut : liste des attributs
    */
    Consultant(std::list<std::string> lAttribut, std::string m);

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Consultant
     */
    virtual ~Consultant();

    /*!
     *  \brief Donne le nom de la mission
     *
     *  Methode qui permet de retourner le nom de la mission du consultant
     *
     *  \return un str qui est le nom de la mission
     */
    std::string getMission() const;

    /*!
     *  \brief Rentre le nom de la mission
     *
     *  Methode qui permet de rentrer le nom de la mission du consultant
     *
     *  \param m : le nom de la mission 
     */
    void setMission(std::string m);

    /*!
     *  \brief Donne la liste des attributs
     *
     *  Methode qui permet de retourner la liste des attributs du consultant
     *
     *  \return un std::list<string qui est la liste des attribus du consultant
     */
    std::list<std::string> getAttribut() const;

};

#endif // CONSULTANT_H