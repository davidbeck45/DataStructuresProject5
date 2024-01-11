/*
   CSCI 262 Data Structures markov

  David Beck
*/
#ifndef _MAP_MODEL_H
#define _MAP_MODEL_H

#include <string>
#include <map>
#include <vector>
#include "model.h"

using namespace std;

class map_model : public markov_model {
public:
    virtual void initialize(string text, int order);

    virtual string generate(int size);

    string to_string();

protected:
    // Add any variables you may need here
    map<string, string> _map;
    int _order;
};

#endif
