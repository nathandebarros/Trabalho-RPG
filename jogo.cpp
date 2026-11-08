#include "jogo.hpp"
#include <algorithm>
#include <vector>

//FUNCAO RESPONSAVEL POR CRIAR N PERSONAGENS
std::vector<Player> createPlayers(int n){
    std::vector<Player> jogadores;
    for(int i = 0; i < n; i++){
        Player x = Player();
        jogadores.push_back(x);
    }

    return jogadores;
}
//FUNCAO PARA EXIBIR SEUS STATUS
void playerStats(std::vector<Player>& jogadores){
    for(int i = 0; i < 3 ; i++){
    std::cout << "------------------------------" << std::endl;
    std::cout << "--FICHA DE JOGADOR--" << std::endl;
    std::cout << "(" << "" << jogadores[i].getRace() << ")" << " " << jogadores[i].getName() << std::endl;
    std::cout << "Classe: " << jogadores[i].getPlayerClass() << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Forca: " << jogadores[i].getStrenght() << std::endl;
    std::cout << "Destreza:  " << jogadores[i].getDexterity() << std::endl;
    std::cout << "Constituicao: " << jogadores[i].getConstitution() << std::endl;
    std::cout << "Sabedoria: " << jogadores[i].getWisdom() << std::endl;
    std::cout << "Inteligencia: " << jogadores[i].getIntelligence() << std::endl;
    std::cout << "Carisma: " << jogadores[i].getCharisma() << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "HP: " << jogadores[i].getHp() << std::endl;
    std::cout << "Nivel: " << jogadores[i].getLevel() << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Arma: " << jogadores[i].getWeaponName() << " | Dano: " << jogadores[i].getWeaponDamage() << std::endl;
    std::cout << "Tipo: " << jogadores[i].getWeaponType() << std::endl;
    std::cout << "------------------------------"<< std::endl;
    std::cout << " " << jogadores[i].getArmorType() << " | Defesa: " << jogadores[i].getArmorDefense() << std::endl;
    std::cout << "\n\n" << std::endl;
   }
}


//FUNCAO PARA CRIAR OS MINIOS
std::vector<Minion> createMinions(int n){
    std::vector<Minion> minions;
    
    for(int i = 0; i < n; i++){
        Minion x = Minion();
        minions.push_back(x);
    }

    return minions;

}

bool compararPlayer(const Player& a, const Player& b) {
    return a.getDexterity() > b.getDexterity();
}

bool compararMinion(const Minion& a, const Minion& b) {
    return a.getDexterity() > b.getDexterity();
}

void combat(std::vector<Player>& jogadores, std::vector<Minion>& inimigos, Boss& chefe) {
    
    std::sort(jogadores.begin(), jogadores.end(), compararPlayer);
    std::sort(inimigos.begin(), inimigos.end(), compararMinion);

    int rodada = 1;
    bool combateAtivo = true;

    while (combateAtivo) {
        std::cout << "\n=== RODADA " << rodada << " ===" << std::endl;

        for (int i = 0; i < jogadores.size(); i++) {
            if (jogadores[i].getHp() <= 0) continue; 

            if (chefe.getHp() > 0) {
                int dano = jogadores[i].Attack();
                chefe.setHp(chefe.getHp() - dano);
                
                std::cout << jogadores[i].getName() << " (Player) atacou " << chefe.getName() << " (Boss) causando " << dano << " de dano!" << std::endl;
            } else {
                for (int j = 0; j < inimigos.size(); j++) {
                    if (inimigos[j].getHp() > 0) {
                        int dano = jogadores[i].Attack();
                        inimigos[j].setHp(inimigos[j].getHp() - dano);
                        
                        std::cout << jogadores[i].getName() << " (Player) atacou " << inimigos[j].getName() << " " << j+1 << " causando " << dano << " de dano!" << std::endl;
                        break; 
                    }
                }
            }
        }

        bool todosMonstrosMortos = (chefe.getHp() <= 0);
        for (int i = 0; i < inimigos.size(); i++) {
            if (inimigos[i].getHp() > 0) {
                todosMonstrosMortos = false;
            }
        }
        if (todosMonstrosMortos) {
            std::cout << "\nVITÓRIA! Todos os monstros e o Boss foram derrotados!" << std::endl;
            break; 
        }

        for (int i = 0; i < inimigos.size(); i++) {
            if (inimigos[i].getHp() <= 0) continue; 

            for (int j = 0; j < jogadores.size(); j++) {
                if (jogadores[j].getHp() > 0) {
                    
                    int dano_monstro = inimigos[i].getStrenght() / 3;
                    int defesa_player = jogadores[j].getArmorDefense();
                    int dano_real = dano_monstro - defesa_player;
                    
                    if (dano_real < 0) dano_real = 0; 

                    jogadores[j].setHp(jogadores[j].getHp() - dano_real);
                    
                    std::cout << inimigos[i].getName() << " " << i+1 << " atacou " << jogadores[j].getName() << " causando " << dano_real << " de dano!" << std::endl;
                    break; 
                }
            }
        }

        if (chefe.getHp() > 0) {
            for (int j = 0; j < jogadores.size(); j++) {
                if (jogadores[j].getHp() > 0) {
                    
                    int dano_chefe = chefe.getStrenght() / 2; 
                    int defesa_player = jogadores[j].getArmorDefense();
                    
                    if (std::rand() % 4 == 0) {
                        std::cout << ">>> " << chefe.getName() << " usou " << chefe.specialAttack() << "! <<<" << std::endl;
                        dano_chefe += 4; 
                    }

                    int dano_real = dano_chefe - defesa_player;
                    
                    if (dano_real < 0) dano_real = 0; 

                    jogadores[j].setHp(jogadores[j].getHp() - dano_real);
                    
                    std::cout << chefe.getName() << " (Boss) atacou " << jogadores[j].getName() << " causando " << dano_real << " de dano!" << std::endl;
                    break; 
                }
            }
        }

        bool todosJogadoresMortos = true;
        for (int i = 0; i < jogadores.size(); i++) {
            if (jogadores[i].getHp() > 0) {
                todosJogadoresMortos = false;
            }
        }
        if (todosJogadoresMortos) {
            std::cout << "\nGAME OVER! Seu grupo foi aniquilado..." << std::endl;
            break; 
        }

        rodada++;
    }
}