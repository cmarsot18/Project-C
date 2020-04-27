#include <string>

#include "TestCollecteurCSV.h"

using namespace std;

TestCollecteurCSV::TestCollecteurCSV(){

};

// ----------------------------------------------

TestCollecteurCSV::~TestCollecteurCSV(){

};


/**
 * setUp: function called before each test
 */
void TestCollecteurCSV::setUp() {
}

/**
 * tearDown: function called after each test
 */
void TestCollecteurCSV::tearDown() {

}




void TestCollecteurCSV::test_Chargement() {

    ifstream file1("../QS.csv");  //Ouverture d'un fichier en lecture existant au bon format
    ifstream file2("../QS.pdf");  //Ouverture d'un fichier en lecture existant au MAUVAIS format
    ifstream file3("../QSS.csv");  //Ouverture d'un fichier en lecture INEXISTANT au bon format

    CPPUNIT_ASSERT_THROW( ifstream file2("../QS.pdf");  , exception);
    CPPUNIT_ASSERT_THROW( ifstream file3("../QSS.pdf");  , exception);


}


void TestCollecteurCSV::test_MAJMembres() {

    fstream csv; // pointeur de fichier sur le CSV
    csv.open("../QS.csv", ios::in); // avec le test précédent, on est sûr de pouvoir ouvrir ce fichier

    vector<Membre> vm1;

    // Read the Data from the file as String Vector
    int roll, count=0;
    vector<string> row;
    string line, word, temp;

    while (csv >> temp) {

        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(csv, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and store it in a string variable, 'word'
        while (getline(s, word, ',')) {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // convert string to integer for comparision
        roll = stoi(row[0]);

        // on remplit le vecteur membre
        count = 1;
        vm1.push_back(Membre(row[3],row[1],row[2]));
        }
    CPPUNIT_ASSERT_THROW(count=0, exception); //si le fichier est vide

    csv.close();
    sort(vm1.begin(),vm1.end());

    ifstream txt("../liste.txt"); // ouverture TXT qui contient la liste des membres mise à jour
    vector<Membre> vm2;

    string ligne;
    int i=0;
    while(getline(txt,ligne)) {
        CPPUNIT_ASSERT(ligne.find(vm1[i].getNom()) != string::npos
         && ligne.find(vm1[i].getPrenom()) != string::npos
         && ligne.find(vm1[i].getpole())  != string::npos);
        i++;
        // à revoir
    };
    //sort(vm2.begin(),vm2.end());

    //CPPUNIT_ASSERT(vm1 == vm2); // compare les 2 vecteurs
    }


void TestCollecteurCSV::test_fail() {
        CPPUNIT_ASSERT(0 == 1); }


CppUnit::TestSuite * TestCollecteurCSV::make_suite() {
    CppUnit::TestSuite *suite = new CppUnit::TestSuite("CollecteurCSV");
    cout << "==============================================" << endl;
    cout << "TEST " << suite->getName() << " (" << __FILE__ << ")" << endl;
    cout << "==============================================" << endl;

    TEST_ADD_COLLECTEURCSV(Chargement);
    TEST_ADD_COLLECTEURCSV(MAJMembres);
    TEST_ADD_COLLECTEURCSV(fail);

    return suite;
}

