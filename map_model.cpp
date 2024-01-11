/*
   CSCI 262 Data Structures,  Markov
David Beck
*/

#include "map_model.h"

void map_model::initialize(string text, int order) {
    // TODO: Implement me
    _map.clear();
    _order = order;
    for(int i = 0; i < text.size(); i++){
        string word ="";
        int c;
        for (int j = i; j < text.size(); j++) {
            c++;
            word.push_back(text[j]);
            if (text[j+1] = '\0')
                j =0;
            if (c==order)
                break;
        }
        _map[word].push_back(text[i+_order]);

    }
}

string map_model::generate(int size) {
    // TODO: Implement me
    string seed = "";
    int pos = rand()% _map.size();
    int c = 0;
    string key;
    for (auto f: _map){
        if(c == pos){
            key = f.first;
        }
        c++;
    }
    for (int i = 0; i < size; i++) {
        int charpos = rand()%_map[key].size();
        char nxt = _map[key][charpos];
        seed += nxt;
        key = key.substr(key.size()-(_order-1),key.size());
        key+= nxt;

    }

    return seed;
}
