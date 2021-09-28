#ifndef B2B1F6CF_19EA_4626_9905_96846701B6AF
#define B2B1F6CF_19EA_4626_9905_96846701B6AF
#include "Structs.h"
#include "Hero.h"
#include "Defines.h"

#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

class Barbarian : public Hero
{
public:

    Barbarian(VitalData data)
    {
        _vitalData.health = data.health;
        _vitalData.currMana = data.currMana;
        _vitalData.maxMana = data.maxMana;
        _vitalData.manaRegenRate = data.manaRegenRate;
        _name = "Barbarian";
    };

    void readSpellFromInput(SpellType spellType)
    {
        SpellData spellWaek;
        SpellData spellStrong;
        std::string line;
        getline(std::cin, line);
        std::istringstream istr(line);

        if (spellType == SpellType::Weak)
        {
            istr >> spellWaek.name >> spellWaek.damage;
            _spells[0] = spellWaek;
        }
        else if (spellType == SpellType::Strong)
        {
            istr >> spellStrong.name >> spellStrong.damage >> spellStrong.manaCost;
            _spells[1] = spellStrong;
        }
    }

    int castSpell()
    {
        if (_vitalData.currMana >= _spells[1].manaCost)
        {
            _vitalData.currMana -= _spells[1].manaCost;
            std::cout << _name << " casting " << _spells[1].name << " for " << _spells[1].manaCost << " mana" << std::endl;
            return _spells[1].damage;
        }
        else
        {
            _vitalData.currMana -= _spells[0].manaCost;
            std::cout << _name << " casting " << _spells[0].name << " for " << _spells[0].manaCost << " mana" << std::endl;
            return _spells[0].damage;
        }
    }

    void takeDamage(int damage)
    {
        round += 1;
        if (round % 3 == 0)
        {
            _vitalData.health -= (damage / 2);
            std::cout << _name << " took " << damage / 2 << " damage and is left with " << _vitalData.health << " health" << std::endl;
        }
        else
        {
            _vitalData.health -= damage;
            std::cout << _name << " took " << damage << " damage and is left with " << _vitalData.health << " health" << std::endl;
        }
    }

    void regenerate()
    {
        if ((_vitalData.currMana + _vitalData.manaRegenRate) <= _vitalData.maxMana)
        {

            std::cout << _name << " regained " << _vitalData.manaRegenRate << " mana for up to " << _vitalData.currMana + _vitalData.manaRegenRate << std::endl;
            _vitalData.currMana += _vitalData.manaRegenRate;
        }
        else
        {

            int gaind_mana = abs((_vitalData.currMana + _vitalData.manaRegenRate) - _vitalData.maxMana);
            std::cout << _name << " regained " << gaind_mana << " mana for up to " << _vitalData.maxMana << std::endl;
            _vitalData.currMana += _vitalData.maxMana;
        }
    }

    bool isDead() const
    {
        if (_vitalData.health <= 0)
        {
            return true;
        }
        return false;
    }

    // std::string getName() const
    // {
    //     return _name;
    // }

private:
    //   VitalData _vitalData;
    //   std::array<SpellData, SPELLS_COUNT> _spells;
    //   std::string _name;
    int round = 0;
};

#endif /* B2B1F6CF_19EA_4626_9905_96846701B6AF */
