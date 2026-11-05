#include <iostream>
#include <string>
#include "classes.hpp"

using namespace std;


int main(){
    std::srand(time(std::nullptr_t(0)));

    std::srand(time(0));

    Player jogador;
    std::cout << "--FICHA DE JOGADOR--\n";
    std::cout << "Nome: " << jogador.getName() << std::endl;
    std::cout << "Classe: " << jogador.getPlayerClass() << std::endl;
    std::cout << "Raca: " << jogador.getRace() << std::endl;
    std::cout << "HP: " << jogador.getHp() << std::endl;
    std::cout << "Level: " << jogador.getLevel() << std::endl;
    std::cout << "Forca : " << jogador.getStrenght() << std::endl;
    std::cout << "Destreza : " << jogador.getDexterity() << std::endl;
    std::cout << "Constituicao : " << jogador.getConstitution() << std::endl;
    std::cout << "Sabedoria : " << jogador.getWisdom() << std::endl;
    std::cout << "Inteligencia : " << jogador.getIntelligence() << std::endl;
    std::cout << "Carisma : " << jogador.getCharisma() << std::endl;

    std::cout << " " << std::endl;

    Enemy inimigo;
    std::cout << " " << inimigo.getName();
    std::cout << "HP: " << inimigo.getHp() << std::endl;
    std::cout << "Level: " << inimigo.getLevel() << std::endl;
    std::cout << "Forca : " << inimigo.getStrenght() << std::endl;
    std::cout << "Destreza : " << inimigo.getDexterity() << std::endl;
    std::cout << "Constituicao : " << inimigo.getConstitution() << std::endl;
    std::cout << "Sabedoria : " << inimigo.getWisdom() << std::endl;
    std::cout << "Inteligencia : " << inimigo.getIntelligence() << std::endl;
    std::cout << "Carisma : " << inimigo.getCharisma() << std::endl;
    //std::cout << "Tipo de Arma: " << jogador.weapon.getEquipType() << std::endl;
    return 0;
}