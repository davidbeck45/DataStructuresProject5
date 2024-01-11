/*
   CSCI 262 Data Structures, Markov

   david beck
*/
#ifndef _WORD_MODEL_H
#define _WORD_MODEL_H

#include "model.h"
#include <map>
#include <vector>
using namespace std;

class word_model : public markov_model {
public:
    virtual void initialize(string text, int order);

    virtual string generate(int size);

    // Add any helper methods you want here

protected:
    // Add any variables you may need here
    map<string, vector<string>> _map;
    int _order;
    char _space = ' ';

};

#endif
