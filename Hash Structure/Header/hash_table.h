#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
using namespace std;

class HashTable
{
private:
    size_t bucket;
    size_t numPlanes;
    size_t dimension;
    vector<list<vector<double>>> table;
    vector<vector<double>> randomHyperplanes;
    void generateRandomHyperplanes();
    

public:
    HashTable(size_t bucket, size_t numPlanes, size_t dimension);
    size_t hashFunction(const vector<double> &featureVector);
    void addItem(const vector<double>& featureVector);
    list<vector<double>> search(const vector<double>& featureVector);
    void print();
};

#endif // HASHTABLE_H