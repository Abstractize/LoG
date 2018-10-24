//
// Created by ferathor on 07/10/18.
//

#ifndef LEAGUEOFGEMS_MINION_H
#define LEAGUEOFGEMS_MINION_H

class Minion {
private:
    int maxHP;
    int hp;
    int atk;
    float def;
public:
    void getDmg(int enemyAtk);
    int[2] getHP();
    void heal(int hp);
};

#endif //LEAGUEOFGEMS_MINION_H
