//
// Created by marso on 28/04/2020.
//
#include <stdio.h>
#include <windows.h>
#include <dirent.h>
#include "Gestion_membre.h"
#include <fstream>
#include <vector>
#include <unistd.h>
#include "../Association_class/Association.hpp"

Association Gestion_membre::Load(string NomAsso) {
    //on regarde si l'association éxiste
    DIR * rep = opendir("Gestion_memoire/Assos");
    Association result = Association(NomAsso);
    std::string temp,path;
    int temp2;
    if (rep != NULL)
    {
        struct dirent * ent;
        while ((ent = readdir(rep)) != NULL)
        {
            temp = ent->d_name;
            temp2 = temp.find(NomAsso);
            if(temp2 != -1){
                path = "Gestion_memoire/Assos/"+temp;
            }
        }
        closedir(rep);
        //On effectue le cahregement à aprtir d'ici
        ifstream Fichier(path);
        Membre tMembre = Membre();
        if(Fichier){
            string ligne;
            while( getline(Fichier, ligne) )
            {
                //on trouve le type de Personne
                temp2 = ligne.find(",");
                std::string type  = ligne.substr(0,temp2);
                //on définit les paramètres de personne
                if(type.compare("ADMIN") ==0){
                    Membre tMembre = Membre();
                    int tNotes[NB_NOTES_MEMBRE];

                    //On règle les paramètres de personne

                    ligne = ligne.substr(temp2+1,ligne.length());
                    temp2 = ligne.find(",");
                    tMembre.setNom(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());

                    temp2 = ligne.find(",");
                    tMembre.setPrenom(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());

                    temp2 = ligne.find(",");
                    tMembre.setDepartement(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());

                    temp2 = ligne.find(",");
                    tMembre.setMail(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());


                    //on règle les paramètres de membre

                    temp2 = ligne.find(",");
                    tMembre.setpole(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());

                    for (int i = 0; i < NB_NOTES_MEMBRE  ; ++i) {
                        temp2 = ligne.find(",");
                        temp = ligne.substr(0,temp2);
                        ligne = ligne.substr(temp2+1,ligne.length());
                        tNotes[i] = std::stoi(temp);
                    }
                    tMembre.setNotes(tNotes);
                    result.ajouterMembre(tMembre);
                }else{
                    int tNotes[NB_NOTES_CONSULTANT];
                    Consultant tConsultant = Consultant();

                    //On règle les paramètres de personne

                    ligne = ligne.substr(temp2+1,ligne.length());
                    temp2 = ligne.find(",");
                    tConsultant.setNom(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());

                    temp2 = ligne.find(",");
                    tConsultant.setPrenom(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());

                    temp2 = ligne.find(",");
                    tConsultant.setDepartement(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());

                    temp2 = ligne.find(",");
                    tConsultant.setMail(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());


                    //on règle les paramètres de membre

                    temp2 = ligne.find(",");
                    tConsultant.setMission(ligne.substr(0,temp2));
                    ligne = ligne.substr(temp2+1,ligne.length());

                    for (int i = 0; i < NB_NOTES_CONSULTANT  ; ++i) {
                        temp2 = ligne.find(",");
                        temp = ligne.substr(0,temp2);
                        ligne = ligne.substr(temp2+1,ligne.length());
                        tNotes[i] = std::stoi(temp);
                    }
                    tConsultant.setNotes(tNotes);
                    result.ajouterConsultant(tConsultant);
                }
            }
        }else{
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }
    }
    return result;
}

void Gestion_membre::save(Association pAssociation) {
    ofstream monFichier("Gestion_memoire/Assos/"+pAssociation.getNom()+".txt");
    int* tab;
    Membre tMembre;
    Consultant tConsultant;
    if(monFichier){
        vector<Membre> listMembre =  pAssociation.getMembres();
        vector<Membre>::iterator it;
        for(it = listMembre.begin(); it!=listMembre.end();++it){
            tMembre = *it;
            monFichier << "ADMIN," << tMembre.getNom()+"," << tMembre.getPrenom()+",";
            monFichier<< tMembre.getpole()+",";
            monFichier << tMembre.getDepartement()+"," << tMembre.getMail();
            tab = tMembre.getNotes();
            int i;
            for ( i = 0; i < 10 ; ++i) {
                monFichier << "," << tab[i];
            }
            monFichier << "," << tab[i] << endl;
        }
        vector<Consultant> listConsultant =  pAssociation.getConsultant();
        vector<Consultant>::iterator it2;
        for(it2 = listConsultant.begin(); it2!=listConsultant.end();++it2){
            tConsultant = *it2;
            monFichier << "CONSU," << tConsultant.getNom()+"," << tConsultant.getPrenom()+",";
            monFichier<< tConsultant.getMission()+",";
            monFichier << tConsultant.getDepartement()+"," << tConsultant.getMail();
            tab = tConsultant.getNotes();
            int i;
            for (i = 0; i < 9 ; ++i) {
                monFichier << "," << tab[i];
            }
            monFichier << "," << tab[i]<<endl;
        }
        monFichier.close();
    }else{
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}
