#ifndef __CITYUTILS2_H__
#define __CITYUTILS2_H__

#include "City.h"
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

bool comparePairs(const std::pair<size_t,const  City*>& lhs, const std::pair<size_t,const  City*>& rhs)
{
  return lhs.second->getPopulation() < rhs.second->getPopulation();
}


const City* initCity(std::string name, int population){
    City *test = new City(name, population);
    return  test;
}

std::map<size_t,const City*> groupByPopulation(std::vector<const City*> cities, size_t &totalPopulation){
    std::map<size_t,const City*> population;
    size_t  currPopulation = 0;
    totalPopulation = 0;
    for (const auto city : cities) {
        currPopulation = city->getPopulation();
        population[currPopulation]= city;
        totalPopulation += currPopulation;

    }
    return population;



}

#endif // __CITYUTILS2_H__