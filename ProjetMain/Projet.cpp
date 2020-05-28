//
// Created by guenole on 03/05/2020.
//

#include "Projet.h"


int main(int argc, char *argv[]) {
    /*Consultant * pConsultant = new Consultant( "Renault", "Fiche", "Guenole");
    Membre * pMembre = new Membre("Devco" , "Marsot", "Corentin");

    RenduPDF rendu1 = RenduPDF( "/tmp/testConsultant.pdf");
    rendu1.Generer_membre(pConsultant);
    RenduPDF rendu2 = RenduPDF("/tmp/testMembre.pdf");
    rendu2.Generer_membre(pMembre);*/


   /*Association aj = Gestion_membre::Load("AJIR");
   string path = "QS.csv";

   CollecteurCSV::MAJMembres(path,aj);*/

   cout << "Bonsôar! Voulez vous créer (1) ou charger (2) une association ? "<< endl;
   int a;
   cin >> a;
   if (a==1)
   {
      cout << "Nom : "<< endl;
      string nom;
      cin >> nom;
      cout << "Lieu : "<< endl;
      string lieu;
      cin >> lieu;
      Association asso = Association(nom,lieu);
      cout << "Vous avez créé une association, nous allons donc supposer que vous êtes l'administrateur!"<< endl;
      cout << "Création du compte administrateur : "<< endl;
      cout << "Nom :"<< endl;
      cin >> nom;
      cout << "Prénom :"<< endl;
      string prenom;
      cin >> prenom;
      cout << "Pôle :"<< endl;
      string pole;
      cin >> pole;
      Membre createur = Membre(pole,nom,prenom);
      createur.setAdmin();
      asso.ajouterMembre(createur);
      Session_Admin Session_Admin(createur);
      Gestion_membre::save(asso);
   }
   else if (a==2)
   {
       cout << "Entrez le nom de l'association"<< endl;
       string nom;
       cin >> nom;
       Association asso = Gestion_membre::Load(nom);
       cout<<"Vous pouvez maintenant vous connecter!"<<endl;
       cout<<"Etes vous membre (1) ou consultant (2) ?"<< endl;
       int a;
       cin>>a;
       if (a==1)
       {
           cout<<"Voici la liste des membres existants"<<endl;
           cout<<"Sélectionnez votre numéro :"<<endl;
           vector<Membre> membres = asso.getMembres();
           for (int i=0; i<asso.getNombre_Membres(); i++)
           {
               cout << i << ": " << membres[i].getPrenom() << membres[i].getNom()<<endl;
           }
           int a;
           cin>>a;
           if (membres[a].getAdmin())
           {
               Session_Admin sessionA = Session_Admin(membres[a]);
               bool connecte = sessionA.Connection(membres[a].getNom(),membres[a].getPrenom(),asso);
               if (connecte)
               {
                   cout<<"Charger le questionnaire (1), Consulter la fiche d'un membre (2), consulter la fiche de l'association (3) :"<<endl;
                   int b;
                   cin>>b;
                   if (b==1)
                   {
                       cout << "Entrez le chemin menant au réponses :" << endl;
                       string path;
                       cin>>path;
                       CollecteurCSV::MAJMembres(path,asso);
                   }
                   else if (b==2)
                   {
                       cout<<"Sélectionnez le membre dont vous voulez vor la fiche :"<<endl;
                       vector<Membre> membres1 = asso.getMembres();
                       for (int i=0; i<asso.getNombre_Membres(); i++)
                       {
                           cout << i << ": " << membres1[i].getPrenom() << membres1[i].getNom()<<endl;
                       }
                       int a;
                       cin>>a;
                       Membre* membre = new Membre(membres1[a].getpole(),membres1[a].getNom(),membres1[a].getPrenom());
                       int* notes = membres1[a].getNotes();
                       membre->setNotes(notes);
                       RenduPDF rendu1 = RenduPDF( "/tmp/" + membre->getPrenom() + membre->getNom() + ".pdf");
                       rendu1.Generer_membre(membre);
                       cout<<"La fiche est disponible dans le dossier tmp"<<endl;
                   }
               }

           }
           else
           {
               Session_Membre sessionM = Session_Membre(membres[a]);
           }

       }


   }
   else
       cout<<"Option invalide"<< endl;





    return 0;
}