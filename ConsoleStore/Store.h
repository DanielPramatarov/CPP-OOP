#ifndef A983F666_81DA_4399_A349_750857A6B580
#define A983F666_81DA_4399_A349_750857A6B580
#include "Console.h"
#include "Ps.h"
#include <vector>
#include <iostream>
#include <algorithm>
class Store
{
private:
    std::vector<Console> xboxes;
    std::vector<Ps> pses;

public:
    void addPs(int price, int quality, int generation)
    {
        pses.emplace_back(price, quality, generation);
        std::cout << "Adding: PS with generation " << generation << ", price: " << price << ", quality: " << quality << std::endl;
    }

    void addXbox(int price, int quality)
    {
        xboxes.emplace_back(price, quality);
        std::cout << "Adding: Xbox with price: " << price << ", quality: " << quality << std::endl;
    }

    void remove(ConsoleType consoleType)
    {
        if (consoleType == ConsoleType::XBOX)
        {
            Console xb = xboxes.back();
            std::cout << "Removing: Xbox with price: " << xb.getPrice() << ", quality: " << xb.getQuality() << std::endl;
            xboxes.pop_back();
        }
        else
        {
            Ps ps = pses.back();
            std::cout << "Removing: PS with generation " << ps.getGeneration() << ", price: " << ps.getPrice() << ", quality: " << ps.getQuality() << std::endl;
            pses.pop_back();
        }
    }

    void sortByPrice(ConsoleType consoleType)
    {
        if (consoleType == ConsoleType::XBOX)
        {
            auto sortRuleLambda = [](Console const &s1, Console const &s2) -> bool
            {
                return s1.getPrice() > s2.getPrice();
            };
            std::cout << "Sorting all Xbox by price" << std::endl;
            std::sort(xboxes.begin(), xboxes.end(), sortRuleLambda);
        }
        else
        {
            auto sortRuleLambda = [](Ps const &s1, Ps const &s2) -> bool
            {
                return s1.getPrice() > s2.getPrice();
            };
            std::cout << "Sorting all PS by price" << std::endl;
            std::sort(pses.begin(), pses.end(), sortRuleLambda);
        }
    }

    void sortByQuality(ConsoleType consoleType)
    {
        if (consoleType == ConsoleType::XBOX)
        {
            auto sortRuleLambda = [](Console const &s1, Console const &s2) -> bool
            {
                return s1.getQuality() > s2.getQuality();
            };
            std::cout << "Sorting all Xbox by quality" << std::endl;
            std::sort(xboxes.begin(), xboxes.end(), sortRuleLambda);
        }
        else
        {
            auto sortRuleLambda = [](Ps const &s1, Ps const &s2) -> bool
            {
                return s1.getQuality() > s2.getQuality();
            };
            std::cout << "Sorting all PS by quality" << std::endl;
            std::sort(pses.begin(), pses.end(), sortRuleLambda);
        }
    }

    void print(ConsoleType consoleType)
    {
        if (consoleType == ConsoleType::XBOX)
        {
            std::cout << "Printing all Xbox data" << std::endl;
            for (auto const x : xboxes)
            {
                std::cout << "Xbox with price: " << x.getPrice() << ", quality: " << x.getQuality() << std::endl;
            }
        }
        else
        {
            std::cout << "Printing all PS data" << std::endl;
            for (auto const p : pses)
            {
                std::cout << "PS with generation " << p.getGeneration() << ", price: " << p.getPrice() << ", quality: " << p.getQuality() << std::endl;
            }
        }
    }
};

#endif /* A983F666_81DA_4399_A349_750857A6B580 */
