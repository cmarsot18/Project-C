//
// Created by marso on 28/04/2020.
//

#ifndef UNTITLED_GESTION_MEMBRE_H
#define UNTITLED_GESTION_MEMBRE_H

#include<string>
#include<iostream>
#include "../Association_class/Association.hpp"
#include "../Association_class/Membre.h"
#include "../Association_class/Personne.hpp"
#include "../Association_class/Consultant.h"
#include "../Session/Session.h"
#include "../Session/Session_Admin.h"
#include "../Session/Session_Consultant.h"
#include "../Session/Session_Membre.h"

using namespace std;



class Gestion_membre {
public :
    Association static Load(string);
    void static save(Association);
};


#endif //UNTITLED_GESTION_MEMBRE_H
