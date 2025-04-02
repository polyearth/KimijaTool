#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <cctype>
using namespace std;

bool isUpperCase(char c) {
    return isupper(static_cast<unsigned char>(c));
}

int main()
{
    unordered_map<string, string> elements;
    string element, nosaukums;
    int forever=5;

    while(forever == 5){
    int choice;
    cout << "Kimija Tool" << endl;
   
    cout << "----------------------------------------------------------------------------------------------"<<endl;
    cout << "|1. Nosaki viela ir metals vai nemetals                                                      |" << endl;
    cout << "|2. Nosaki oksidesanas pakapi elementam                                                      |" << endl;
    cout << "|3. Nosaki vai ta ir skabe, sals, oksids, hidroksids                                         |" << endl;
    cout << "|4. Elementa elementardalinas                                                                |" << endl;
    cout << "|5. Formulas                                                                                 |" << endl;
    cout << "|6. Savienojuma kimiska ipasiba/ iegusana (oksida, skabes utt. iegusana/ kimiska ipasiba)    |" << endl;
    cout << "----------------------------------------------------------------------------------------------"<<endl;
    cout << "\nIevadi opciju: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            ifstream file("elements.txt");  // Atvērt failu
            
            if (!file.is_open()) {
                cout << "Nepareizs fails vai fails netika atrasts!" << endl;
                return 1;
            }
            while (file >> element >> nosaukums) {
                elements[element] = nosaukums;  // Saglabāt elementus
            }
            file.close();  // Aizvērt failu
            
            string cho;
            cout << "\nIevadi vielas simbolu (piem, Au, N, Cr, Ba): ";
            cin >> cho;

            // Izvade
            cout<<cho<<" is "<<elements[cho];

            // Iztīrīt mapu lai nākamajam case izmantotu
            elements.clear();
            sleep(4);
            system("cls");
            break;
        }

        case 2: {
            ifstream file("elementsOxidation.txt");  // Atvērt failu

            if (!file.is_open()) {
                cout << "Nepareizs fails vai fails netika atrasts!" << endl;
                return 1;
            }
            while (file >> element >> nosaukums) {
                elements[element] = nosaukums;  // Saglabāt elementus
            }
            file.close();  // Aizvērt failu
            
            string chos;
            cout << "\nIevadi vielas simbolu (piem, Au, N, Cr, Ba): ";
            cin >> chos;

            // Izvade + clear
           cout<<chos<<" oksidesanas pakape ir: "<<elements[chos];
           elements.clear();
           sleep(4);
           system("cls");
            break;
        }
        
        case 3: {
            string formula;
            cout<<"Ievadi savienojumu: "<<endl;
            cin >> formula;

            if (formula == "HO") {
                cout << "Savienojums ir: Oksīds" << endl;
            }
            else if (formula.find("OH") != string::npos) {
                cout << "Savienojums ir: Hidroksids" << endl;
            }
            else if (isUpperCase(formula[0]) && formula.back() == 'H') {
                cout << "Savienojums ir: Hidrids" << endl;
            }
            else if (formula[0] == 'H' && formula != "HO") {
                cout << "Savienojums ir: Skabe" << endl;
            }
            else if (formula.find("O") != string::npos) {
                cout << "Savienojums ir: Oksids" << endl;
            }
            else {
                cout << "Savienojums ir: Sals" << endl;
            }
            sleep(4);
            system("cls");
            break;
        }
          
        case 4: {
            ifstream file("elemetardalinas.txt");  // Atvērt failu

            if (!file.is_open()) {
                cout << "Nepareizs fails vai fails netika atrasts!" << endl;
                return 1;
            }
            while (file >> element >> nosaukums) {
                elements[element] = nosaukums;  // Saglabāt elementus
            }
            file.close();  // Aizvērt failu
            
            string chose;
            cout << "\nIevadi vielas simbolu (piem, Au, N, Cr, Ba): ";
            cin >> chose;

            // Izvade + clear
            if (elements.find(chose) != elements.end()) {
                cout << chose << " elementa informacija: " << elements[chose] << endl;
            } else {
                cout << "Sis elements netika atrasts!" << endl;
            }

            elements.clear(); 
            sleep(6);
            system("cls");
            break;
        }

        case 5:
         cout<<"Kimija vispopularakas formulas ir: "<<endl;
          cout<<"m = n * M"<<endl;
          cout<<"V = n * V^0   ---> tikkai gazveida vielam un skidrumam"<<endl;
          cout<<"m = p(blivums) * V"<<endl;
          sleep(5);
          system("cls");
        break;
    }
    }

    system("pause");
    return 0;
}