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


void combat(std::vector<Player>& jogadores, std::vector<Minion>& inimigos, Boss& chefe) {
    
    std::sort(jogadores.begin(), jogadores.end(), compararPlayer);

    int rodada = 1;
    bool combateAtivo = true;
    bool subiuNivel = false;

    while (combateAtivo) {
        std::cout << "\n=== RODADA " << rodada << " ===" << std::endl;
        if(rodada == 3){
            Assistant assistente = Assistant();
            assistente.cast_a_spell(jogadores, assistente);
        }

        for (int i = 0; i < jogadores.size(); i++) {
            if (jogadores[i].getHp() <= 0) continue; 

            int chance_especial = (std::rand() % 10 + 1);
            if (chance_especial > 3){
                if (chefe.getHp() > 0) {
                    int dano = jogadores[i].Attack();
                    chefe.setHp(chefe.getHp() - dano);

                    std::cout << jogadores[i].getName() << " (Player) atacou " << chefe.getName() << " (Boss) causando " << dano << " de dano!" << std::endl;
                    if(chefe.getHp() <= 0){
                        std::cout << chefe.getName() << "foi derrotado!" << std::endl;
                        chefe.dropLoot(jogadores[i]);
                        jogadores[i].uparXp();
                        if(jogadores[i].uparLevel()){
                            subiuNivel = true;
                            break;
                        }
                    }
                } else {
                    for (int j = 0; j < inimigos.size(); j++) {
                        if (inimigos[j].getHp() > 0) {
                            int dano = jogadores[i].Attack();
                            inimigos[j].setHp(inimigos[j].getHp() - dano);
                            if(inimigos[j].getHp() <= 0){
                                std::cout << jogadores[i].getName() << " (Player) atacou " << inimigos[j].getName() << " " << j+1 << " causando " << dano << " de dano!" << std::endl;
                                if(inimigos[j].getHp() <= 0){
                                    inimigos[j].specialAttack();
                                    if(inimigos[j].getHp() <= 0){
                                        std::cout << inimigos[j].getName() << " " << j+1 << " foi derrotado!" << std::endl;
                                        inimigos[j].dropLoot(jogadores[i]);
                                        jogadores[i].uparXp();
                                        if(jogadores[i].uparLevel()){
                                            subiuNivel = true;
                                            break;
                                        }
                                    }    
                                }
                            }
                            break; 
                        }
                    }
                }
            } else if (chance_especial <= 3){
                if (chefe.getHp() > 0) {
                    if (jogadores[i].getPlayerClass() == "Barbarian"){
                        std::cout << ">> " << jogadores[i].getName() << " usou " << jogadores[i].specialAttack(jogadores[i].getPlayerClass()) << "! <<" << std::endl;
                        int dano = jogadores[i].getWeaponDamage() + 3;
                        chefe.setHp(chefe.getHp() - dano);

                        std::cout << jogadores[i].getName() << " (Player) atacou " << chefe.getName() << " (Boss) causando " << dano << " de dano!" << std::endl;
                        if(chefe.getHp() <= 0){
                            std::cout << chefe.getName() << "foi derrotado!" << std::endl;
                            chefe.dropLoot(jogadores[i]);
                            jogadores[i].uparXp();
                            if(jogadores[i].uparLevel()){
                                subiuNivel = true;
                                break;
                            }
                        }
                    } else if (jogadores[i].getPlayerClass() == "Ranger"){
                        std::cout << ">> " << jogadores[i].getName() << " usou " << jogadores[i].specialAttack(jogadores[i].getPlayerClass()) << "! <<" << std::endl;
                        int dano = jogadores[i].getWeaponDamage() * 2;
                        chefe.setHp(chefe.getHp() - dano);

                        std::cout << jogadores[i].getName() << " (Player) atacou " << chefe.getName() << " (Boss) causando " << dano << " de dano!" << std::endl;
                        if(chefe.getHp() <= 0){
                            std::cout << chefe.getName() << "foi derrotado!" << std::endl;
                            chefe.dropLoot(jogadores[i]);
                            jogadores[i].uparXp();
                            if(jogadores[i].uparLevel()){
                                subiuNivel = true;
                                break;
                            }
                        }
                    } else if (jogadores[i].getPlayerClass() == "Wizard"){
                        std::cout << ">> " << jogadores[i].getName() << " usou " << jogadores[i].specialAttack(jogadores[i].getPlayerClass()) << "! <<" << std::endl;
                        int dano = jogadores[i].getWeaponDamage() + 2;
                        chefe.setHp(chefe.getHp() - dano);

                        std::cout << jogadores[i].getName() << " (Player) atacou " << chefe.getName() << " (Boss) causando " << dano << " de dano!" << std::endl;
                        if(chefe.getHp() <= 0){
                            std::cout << chefe.getName() << "foi derrotado!" << std::endl;
                            chefe.dropLoot(jogadores[i]);
                            jogadores[i].uparXp();
                            if(jogadores[i].uparLevel()){
                                subiuNivel = true;
                                break;
                            }
                        }
                    }
                    else{
                        int dano = jogadores[i].Attack();
                        chefe.setHp(chefe.getHp() - dano);

                        std::cout << jogadores[i].getName() << " (Player) atacou " << chefe.getName() << " (Boss) causando " << dano << " de dano!" << std::endl;
                        if(chefe.getHp() <= 0){
                            std::cout << chefe.getName() << "foi derrotado!" << std::endl;
                            chefe.dropLoot(jogadores[i]);
                            jogadores[i].uparXp();
                            if(jogadores[i].uparLevel()){
                                subiuNivel = true;
                                break;
                            }
                        }
                    }
                } else {
                    for (int j = 0; j < inimigos.size(); j++) {
                        if (inimigos[j].getHp() > 0) {
                            if(jogadores[i].getPlayerClass() == "Barbarian"){
                                std::cout << ">>> " << jogadores[i].getName() << " usou " << jogadores[i].specialAttack(jogadores[i].getPlayerClass()) << "! <<<" << std::endl;
                                int dano = jogadores[i].getWeaponDamage() + 4;
                                inimigos[j].setHp(inimigos[j].getHp() - dano);

                                std::cout << jogadores[i].getName() << " (Player) atacou " << inimigos[j].getName() << " " << j+1 << " causando " << dano << " de dano!" << std::endl;
                                 if(inimigos[j].getHp() <= 0){
                                    inimigos[j].specialAttack();
                                    if(inimigos[j].getHp() <= 0){
                                        std::cout << inimigos[j].getName() << " " << j+1 << " foi derrotado!" << std::endl;
                                        inimigos[j].dropLoot(jogadores[i]);
                                        jogadores[i].uparXp();
                                        if(jogadores[i].uparLevel()){
                                            subiuNivel = true;
                                            break;
                                        }
                                    }    
                                }
                                break;
                            } else if (jogadores[i].getPlayerClass() == "Wizard"){
                                std::cout << ">>> " << jogadores[i].getName() << " usou " << jogadores[i].specialAttack(jogadores[i].getPlayerClass()) << "! <<<" << std::endl;
                                int dano = jogadores[i].getWeaponDamage() + 3;
                                inimigos[j].setHp(inimigos[j].getHp() - dano);

                                std::cout << jogadores[i].getName() << " (Player) atacou " << inimigos[j].getName() << " " << j+1 << " causando " << dano << " de dano!" << std::endl;
                                if(inimigos[j].getHp() <= 0){
                                    inimigos[j].specialAttack();
                                    if(inimigos[j].getHp() <= 0){
                                        std::cout << inimigos[j].getName() << " " << j+1 << " foi derrotado!" << std::endl;
                                        inimigos[j].dropLoot(jogadores[i]);
                                        jogadores[i].uparXp();
                                        if(jogadores[i].uparLevel()){
                                            subiuNivel = true;
                                            break;
                                        }
                                    }    
                                }
                                break;
                            } else if (jogadores[i].getPlayerClass() == "Ranger"){
                                std::cout << ">>> " << jogadores[i].getName() << " usou " << jogadores[i].specialAttack(jogadores[i].getPlayerClass()) << "! <<" << std::endl;
                                int dano = jogadores[i].getWeaponDamage() - 1;
                                for(int k = 0; k < inimigos.size(); k++){
                                    if(inimigos[k].getHp() > 0){ 
                                        inimigos[k].setHp(inimigos[k].getHp() - dano);
                                        std::cout << jogadores[i].getName() << " (Player) atacou " << inimigos[k].getName() << " " << k+1 << " causando " << dano << " de dano!" << std::endl;
                                        if(inimigos[j].getHp() <= 0){
                                            inimigos[j].specialAttack();
                                            if(inimigos[j].getHp() <= 0){
                                                std::cout << inimigos[k].getName() << " " << k+1 << " foi derrotado!" << std::endl;
                                                inimigos[j].dropLoot(jogadores[i]);
                                                jogadores[i].uparXp();
                                                if(jogadores[i].uparLevel()){
                                                    subiuNivel = true;
                                                    break;
                                                }
                                           }
                                        }
                                    }
                                }
                                break;
                            } else {
                                int dano = jogadores[i].Attack();
                                inimigos[j].setHp(inimigos[j].getHp() - dano);

                                std::cout << jogadores[i].getName() << " (Player) atacou " << inimigos[j].getName() << " " << j+1 << " causando " << dano << " de dano!" << std::endl;
                                if(inimigos[j].getHp() <= 0){
                                    inimigos[j].specialAttack();
                                    if(inimigos[j].getHp() <= 0){
                                        std::cout << inimigos[j].getName() << " " << j+1 << " foi derrotado!" << std::endl;
                                        inimigos[j].dropLoot(jogadores[i]);
                                        jogadores[i].uparXp();
                                        if(jogadores[i].uparLevel()){
                                            subiuNivel = true;
                                           break;
                                        }           
                                    }
                                }
                                break;
                            }
                        }

                    }
                }
            }
        }

        if (subiuNivel){
            std::cout << "Jogo encerrado! Um jogador subiu de nivel" << std::endl;
            break;
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
                    
                    if(jogadores[j].getPlayerClass() == "Rogue"){
                        
                        int chance_especial = (std::rand() % 10 + 1);
                        if(chance_especial <= 3){
                            std::cout << ">>> " << jogadores[j].getName() << " usou " << jogadores[j].specialAttack(jogadores[j].getPlayerClass()) << "! <<<" << std::endl;
                            int dano_real = 0;
                            std::cout << inimigos[i].getName() << " " << i+1 << " atacou " << jogadores[j].getName() << " causando " << dano_real << " de dano!" << std::endl;
                            break;
                        } else {
                            int dano_monstro = inimigos[i].getStrenght() / 3;
                            int defesa_player = jogadores[j].getArmorDefense();
                            int dano_real = dano_monstro - defesa_player;

                            if (dano_real < 0) dano_real = 0; 

                            jogadores[j].setHp(jogadores[j].getHp() - dano_real);

                            std::cout << inimigos[i].getName() << " " << i+1 << " atacou " << jogadores[j].getName() << " causando " << dano_real << " de dano!" << std::endl;
                            break; 
                        }
                    }else{

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
        }

        if (chefe.getHp() > 0) {
            for (int j = 0; j < jogadores.size(); j++) {
                if (jogadores[j].getHp() > 0) {
                    if(jogadores[j].getPlayerClass() == "Rogue"){
                        int chance_especial = (std::rand() % 10 + 1);
                        if (chance_especial <= 3){
                            std::cout << ">>> " << jogadores[j].getName() << " usou " << jogadores[j].specialAttack(jogadores[j].getPlayerClass()) << "! <<<" << std::endl;

                            if (std::rand() % 4 == 0) {
                                std::cout << ">>> " << chefe.getName() << " usou " << chefe.specialAttack() << "! <<<" << std::endl;
                                
                            }
                        
                            int dano_real = 0;

                            if (dano_real < 0) dano_real = 0; 
                        
                            jogadores[j].setHp(jogadores[j].getHp() - dano_real);

                            std::cout << chefe.getName() << " (Boss) atacou " << jogadores[j].getName() << " causando " << dano_real << " de dano!" << std::endl;
                            break; 
                        } else {
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