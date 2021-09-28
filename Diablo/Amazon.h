#ifndef F58E3785_1BA2_4F4F_97A7_C0ACF4D462A2
#define F58E3785_1BA2_4F4F_97A7_C0ACF4D462A2

#include "Structs.h"
#include "Hero.h"
#include "Defines.h"

#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
class Amazon : public Hero
{
public:
    Amazon(VitalData data)
    {
        _vitalData.health = data.health;
        _vitalData.currMana = data.currMana;
        _vitalData.maxMana = data.maxMana;
        _vitalData.manaRegenRate = data.manaRegenRate;
        _name = "Amazon";
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
        round += 1;
        if (_vitalData.currMana >= _spells[1].manaCost)
        {
            _vitalData.currMana -= _spells[1].manaCost;
            std::cout << _name << " casting " << _spells[1].name << " for " << _spells[1].manaCost << " mana" << std::endl;

            if (round % 2 == 0)
            {
                return _spells[1].damage * 1.25;
            }
            return _spells[1].damage;

        }
        else
        {
            _vitalData.currMana -= _spells[0].manaCost;
            std::cout << _name << " casting " << _spells[0].name << " for " << _spells[0].manaCost << " mana" << std::endl;
            if (round % 2 == 0)
            {
                return _spells[0].damage * 1.25;
            }

            return _spells[0].damage;
        }
    }

    void takeDamage(int damage)
    {
        _vitalData.health -= damage;
        std::cout << _name << " took " << damage << " damage and is left with " << _vitalData.health << " health" << std::endl;
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
#endif /* F58E3785_1BA2_4F4F_97A7_C0ACF4D462A2 */
