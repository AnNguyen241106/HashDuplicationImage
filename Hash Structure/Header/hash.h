#ifndef HASH_H
#define HASH_H
#include <vector>
#include <string>
#include <iostream>
#include <iostream>

class hashStructure;
class hashFunction;
class simHash;
class minHash;
class murmurhash;
class bloomFilter;
class hashTable;

class hashStructure {
    protected:
        hashFunction* hashFunc;
    public:

};

class hashFunction {
    friend hashStructure;
    protected:
        std::vector<double> data;
        int bit;
        int seed;
    public:
        hashFunction (std::vector<double>& data, int bit, int seed = 42) : data (data), bit (bit), seed (seed) {}
        ~hashFunction () {} 
        virtual int distance (std::vector<double>& other)=0;
        virtual bool hash () = 0;
        std::vector<int> simpleHash (double);
};

class simHash : public hashFunction {
    private:
        std::vector<int> hashValue;
        (std::vector<double> hasFunc) (double);
    public:
        simHash (std::vector<double>& data, int bit, int seed);
        ~simHash ();
        int distance (std::vector<double>& other) override;
        bool hash () override;
        std::string extractBinary(long long value);
        std::vector<double> computeWeights (std::vector<double>&);
};

class minHash : public hashFunction {

};

#endif