//
// Created by marso on 31/03/2020.
//
#include <algorithm>
#include <string>
#include <iostream>
#include "Session.h"


Session::Session() {

}

Session::Session(const std::string p_ID, const std::string p_Pass) {
    ID = p_ID;
    Pass = p_Pass;
}

bool Session::Connection(const std::string p_Nom, const std::string p_Prenom, Association asso)const{
    vector<Membre> vm = asso.getMembres();
    Membre m;
    std::string identifiant;
    std::string mdp;
    bool res;
    int i=0;
    while (i<=vm.size()){
        if (vm[i].getNom() == p_Nom && vm[i].getPrenom() == p_Prenom){
            m = vm[i];
            i=vm.size()+1;
        }
        else{
            i=i+1;
        }
    }
    std::cout << "Entrez votre identifiant" << std::endl;
    std::cin >> identifiant;
    std::cout << "Entrez votre mot de passe" << std::endl;
    std::cin >> mdp;
    if (m.getID() != identifiant){
        std::cout << "Identifiant incorrect" << std::endl;
        res = false;
    }
    if (m.getpass() != mdp){
        std::cout << "Mot de passe incorrect" << std::endl;
        res = false;
    }
    if (m.getID() != identifiant && m.getpass() != mdp){
        std::cout << "Identifiant et mot de passe incorrect" << std::endl;
        res = false;
    }
    else{
        std::cout << "Connexion reussie" << std::endl;
        res = true;
    }
    return res;
}

std::string Session::getID() const {
    return ID;
}

std::string Session::getPass() const {
    return Pass;
}

void Session::setID(const std::string p_ID) {
    ID = p_ID;
}

void Session::setPass(const std::string p_Pass) {
    Pass = p_Pass;
}