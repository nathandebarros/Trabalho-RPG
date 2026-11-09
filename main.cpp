#include "classes.hpp"
#include <cstdlib>
#include <ctime>
#include "jogo.hpp"

using namespace std;


//std::vector<Player> cretaePlayer(int n){
//    std::vector<Player> jogadores;
//    for(int i = 0; i < n; i++){
//        Player x = Player();
//        jogadores.push_back(x);
//    }
//
//    return jogadores;
//}

int main(){
    std::srand(std::time(0));
   std::vector<Player> jogadores =  createPlayers(3);

   playerStats(jogadores);

   std::vector<Minion> minions = createMinions(3);

   Boss chefe = Boss();


   combat(jogadores, minions, chefe);


   return 0;
}