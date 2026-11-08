#ifndef JOGO_HPP
#define JOGO_HPP

#include "classes.hpp"

std::vector<Player> createPlayers(int n);

void playerStats(std::vector<Player>& x);

std::vector<Minion> createMinions(int n);

bool compararPlayer(const Player &a, const Player &b);

bool compararMinion(const Minion &a, const Minion &b);

void combat(std::vector<Player> &jogadores, std::vector<Minion> &inimigos, Boss &chefe);

#endif