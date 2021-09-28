#include "Archmage.h"
#include <iostream>
Archmage::Archmage(const std::string &name,
                   const int maxMana,
                   const int baseManaRegenRate,
                   const int manaRegenModifier) : Hero(name, maxMana, baseManaRegenRate), _manaRegenModifier(manaRegenModifier)
{
}

void Archmage::castSpell(const SpellType spell)
{
    if (spell == SpellType::BASIC)
    {
        Spell basic_spell = _spells[0];
        if (_currMana < basic_spell.manaCost)
        {
            std::cout << _name << " - not enough mana to cast " << basic_spell.name << std::endl;
        }else{
            std::cout << _name << " casted " << basic_spell.name << " for " << basic_spell.manaCost << " mana" << std::endl;
            _currMana -= basic_spell.manaCost;
        }
    }
    else if (spell == SpellType::ULTIMATE)
    {
        Spell ultimate_spell = _spells[1];
        if (_currMana < ultimate_spell.manaCost)
        {
            std::cout << _name << " - not enough mana to cast " << ultimate_spell.name << std::endl;
        }else{
            std::cout << _name << " casted " << ultimate_spell.name << " for " << ultimate_spell.manaCost << " mana"<< std::endl;
            _currMana -= ultimate_spell.manaCost;
            Archmage::regenerateMana();
        }

    }
}

void Archmage::regenerateMana()
{
    if ((_currMana + (_manaRegenRate *_manaRegenModifier) ) < _maxMana)
    {
        _currMana += (_manaRegenRate *_manaRegenModifier);
    }else{
        _currMana = _maxMana;
    }
}
