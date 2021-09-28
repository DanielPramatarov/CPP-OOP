#ifndef E6C9B2EB_6C51_4CF9_AA5A_FA579E241B28
#define E6C9B2EB_6C51_4CF9_AA5A_FA579E241B28
#include <vector>
#include <stdlib.h>
#include <memory>


#include "Hero.h"


class BattleField
{

public:
    void createHeroes();

    void createSpells();

    void startBattle();

    void printWinner(const std::unique_ptr<Hero> &hero);

private:

    std::vector<std::unique_ptr<Hero>> _heroes;

};

#endif /* E6C9B2EB_6C51_4CF9_AA5A_FA579E241B28 */
