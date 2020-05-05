//
// Created by constance on 26/04/2020.
//

#include "CollecteurCSV.hpp"

void CollecteurCSV::MAJMembres(std::string pathCSV, Association asso) {
    ifstream Fichier(pathCSV);

    int nb = asso.getNombre_Membres() + asso.getNombre_Consultants();
    vector<Membre> vm = asso.getMembres();
    vector<Consultant> vc = asso.getConsultant();


    if(Fichier){
        int count = 0;


        // Read the Data from the file
        // as String Vector
        vector<string> row;
        string line, word, temp;


        while (Fichier.good()) {


            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(Fichier, line);

            // used for breaking words
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ',')) {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }

            // remplit la case vide du pôle des intervenants
            if (row[3] == "Intervenant") {
                row[4] = "Consultant";
            }

            //on convertit la charge de travail
            if ((row[5] == "0-2 h")) {
                row[5] = "0";
            } else if (row[11] == "0-2 h") {
                row[11] = "0";
            } else if ((row[5] == "2-4 h")) {
                row[5] = "1";
            } else if (row[11] == "2-4 h") {
                row[11] = "1";
            } else if ((row[5] == "4-6 h")) {
                row[5] = "3";
            } else if (row[11] == "4-6 h") {
                row[11] = "3";
            } else if ((row[5] == "> 6 h")) {
                row[5] = "4";
            } else if (row[11] == "> 6 h") {
                row[11] = "4";
            }


            for (int i = 0; i < nb; i++) {


                count = 1;

                if (((row[1] == vm[i].getNom()) && (row[2] == vm[i].getPrenom())) ||
                    ((row[1] == vc[i].getNom()) && (row[2] == vc[i].getPrenom())) || (vc[i].getNom() == "Martin")) {
                    if (row[3] == "Administrateur") {
                        cout << "Membre existant" << endl;
                        int saves = vm[i].getsaves();
                        int n1 = (saves * vm[i].getNotes()[0] + stoi(row[5])) / (saves + 1);
                        int n2 = (saves * vm[i].getNotes()[1] + stoi(row[6])) / (saves + 1);
                        int n3 = (saves * vm[i].getNotes()[2] + stoi(row[7])) / (saves + 1);
                        int n4 = (saves * vm[i].getNotes()[3] + stoi(row[8])) / (saves + 1);
                        int n5 = (saves * vm[i].getNotes()[4] + stoi(row[9])) / (saves + 1);
                        int n6 = (saves * vm[i].getNotes()[5] + stoi(row[10])) / (saves + 1);
                        int n7 = (saves * vm[i].getNotes()[6] + stoi(row[16])) / (saves + 1);
                        int n8 = (saves * vm[i].getNotes()[7] + stoi(row[17])) / (saves + 1);
                        int n9 = (saves * vm[i].getNotes()[8] + stoi(row[18])) / (saves + 1);
                        int n10 = (saves * vm[i].getNotes()[9] + stoi(row[19])) / (saves + 1);
                        int n11 = (saves * vm[i].getNotes()[10] + stoi(row[20])) / (saves + 1);

                        int mnotes[NB_NOTES_MEMBRE] = {n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11};

                        vm[i].setsaves(saves + 1);
                        vm[i].setNotes(mnotes);
                        asso.setMembres(vm);
                        break;
                    } else {
                        cout << "Consultant existant" << endl;
                        int saves = vc[i].getsaves();
                        int n1 = (saves * vc[i].getNotes()[0] + stoi(row[11])) / (saves + 1);
                        int n2 = (saves * vc[i].getNotes()[1] + stoi(row[12])) / (saves + 1);
                        int n3 = (saves * vc[i].getNotes()[2] + stoi(row[13])) / (saves + 1);
                        int n4 = (saves * vc[i].getNotes()[3] + stoi(row[14])) / (saves + 1);
                        int n5 = (saves * vc[i].getNotes()[4] + stoi(row[15])) / (saves + 1);
                        int n6 = (saves * vc[i].getNotes()[5] + stoi(row[16])) / (saves + 1);
                        int n7 = (saves * vc[i].getNotes()[6] + stoi(row[17])) / (saves + 1);
                        int n8 = (saves * vc[i].getNotes()[7] + stoi(row[18])) / (saves + 1);
                        int n9 = (saves * vc[i].getNotes()[8] + stoi(row[19])) / (saves + 1);
                        int n10 = (saves * vc[i].getNotes()[9] + stoi(row[20])) / (saves + 1);
                        int cnotes[NB_NOTES_CONSULTANT] = {n1, n2, n3, n4, n5, n6, n7, n8, n9, n10};

                        vc[i].setsaves(saves + 1);
                        vc[i].setNotes(cnotes);
                        asso.setConsultants(vc);
                        break;
                    }
                    break;
                } else {
                    if (row[3] == "Administrateur") {
                        cout << "Membre à ajouter" << endl;
                        //récupération informations du membre
                        string mnom = row[1];
                        string mprenom = row[2];
                        string mpole = row[4];
                        string mmail = row[2] + "." + row[1] + "@insa-rouen.fr";
                        string mdepartement = "GM";
                        int mnotes[NB_NOTES_MEMBRE] = {stoi(row[5]), stoi(row[6]), stoi(row[7]), stoi(row[8]),
                                                       stoi(row[9]), stoi(row[10]), stoi(row[16]), stoi(row[17]),
                                                       stoi(row[18]), stoi(row[19]), stoi(row[20])};
                        Membre mb = Membre(mpole, mnom, mprenom, mmail, mdepartement);
                        mb.setNotes(mnotes);
                        mb.setsaves(1);
                        mb.setID("ID");
                        mb.setpass("PASS");

                        asso.ajouterMembre(mb);
                        vm = asso.getMembres();
                        break;
                    } else {
                        cout << "Consultant à ajouter" << endl;
                        //récupération informations du consultant
                        string cnom = row[1];
                        string cprenom = row[2];
                        string cpole = row[4];
                        string cmail = row[2] + "." + row[1] + "@insa-rouen.fr";
                        string cdepartement = "ASI";
                        int cnotes[NB_NOTES_CONSULTANT] = {stoi(row[11]), stoi(row[12]), stoi(row[13]),
                                                           stoi(row[14]), stoi(row[15]), stoi(row[16]), stoi(row[17]),
                                                           stoi(row[18]), stoi(row[19]), stoi(row[20])};

                        Consultant consu = Consultant(cpole, cnom, cprenom, cmail, cdepartement);
                        consu.setNotes(cnotes);
                        consu.setsaves(1);
                        consu.setID("ID");
                        consu.setpass("PASS");
                        asso.ajouterConsultant(consu);


                        vc = asso.getConsultant();
                        break;

                    }

                }

            }
            vm = asso.getMembres();
            vc = asso.getConsultant();
            nb = asso.getNombre_Membres() + asso.getNombre_Consultants();
            cout << nb << endl;

        }
        if (count == 0)
            cout << "Record not found\n";

        asso.setNom("BIS");
        Gestion_membre::save(asso);

        Fichier.close();

    }
    else {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}

