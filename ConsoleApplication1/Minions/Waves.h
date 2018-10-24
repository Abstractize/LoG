//
// Created by ferathor on 07/10/18.
//

#include "../ADT/List.h"

#ifndef LEAGUEOFGEMS_WAVES_H
#define LEAGUEOFGEMS_WAVES_H

class Waves {
    struct Node {
        List<Minion> minions;
        Node left;
        Node right;
    };
private:
    Node head;
public:
    Waves();
    Minion getMinion(int);
};

#endif //LEAGUEOFGEMS_WAVES_H
