#include <iostream>
#include <string>
#include "classes.hpp"

using namespace std;


int main(){
    Player players[3];
    
    for(int i = 0; i < 3; i++) {
    cout << "\n=== CRIANDO O HEROI " << (i + 1) << " ===" << endl;

    string nomeTemp;
    cout << "Nome: ";
    cin >> ws; 
    getline(cin, nomeTemp);
    players[i].setName(nomeTemp);

    int hpTemp;
    cout << "HP: ";
    cin >> hpTemp;
    players[i].setHp(hpTemp);

    int xpTemp;
    cout << "XP inicial: ";
    cin >> xpTemp;
    players[i].setXp(xpTemp);

    int forcaTemp;
    cout << "Forca: ";
    cin >> forcaTemp;
    players[i].setStrength(forcaTemp);

    int destrezaTemp;
    cout << "Destreza: ";
    cin >> destrezaTemp;
    players[i].setDexterity(destrezaTemp);

    int constTemp;
    cout << "Constituicao: ";
    cin >> constTemp;
    players[i].setConstitution(constTemp);

    int intTemp;
    cout << "Inteligencia: ";
    cin >> intTemp;
    players[i].setIntelligence(intTemp);

    int sabTemp;
    cout << "Sabedoria: ";
    cin >> sabTemp;
    players[i].setWisdom(sabTemp);

    int carismaTemp;
    cout << "Carisma: ";
    cin >> carismaTemp;
    players[i].setCharisma(carismaTemp);
}


cout << "\n=== FICHAS DOS PERSONAGENS ===" << endl;

for(int i = 0; i < 3; i++) {
    cout << "\nNome: " << players[i].getName() << endl;
    cout << "Forca: " << players[i].getStrength() << endl;
    cout << "Destreza: " << players[i].getDexterity() << endl;
    cout << "Constituicao: " << players[i].getConstitution() << endl;
    cout << "Sabedoria: " << players[i].getWisdom() << endl;
    cout << "Inteligencia: " << players[i].getIntelligence() << endl;
    cout << "Carisma: " << players[i].getCharisma() << endl;
    cout << "HP: " << players[i].getHp() << endl;
    cout << "XP: " << players[i].getXp() << endl;
    cout << "------------------------" << endl;
}


    return 0;
}