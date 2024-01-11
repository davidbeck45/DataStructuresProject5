/*
   CSCI 262 Data Structures, Markov

David Beck
*/

#include "word_model.h"

void word_model::initialize(string text, int order) {

    // TODO: Implement me
    _map.clear();
    _order = order;



    for(int i = 0; i < text.size(); i++){
        string ele = "";
        int ctr = 0;
        int nxt = 0;
        int strt = 0;
        int space = 1;
        string n ="";
        for(int j = i; text.size();j++){
            if(text[j] == _space){
                ctr++;
                if(ctr == 1)
                    nxt = j;
                if (text[j+1] == '\0'){
                    space = 0;
                }
                if (ctr == order){
                    strt = j + 1;
                    break;
                }

            }


            if(text[j] == '\n'){
                ctr++;
                if(ctr == 1)
                    nxt = j;
                if (text[j+1] == '\0'){
                    space = 0;
                }
                if (ctr == order){
                    strt = j + 1;
                    break;
                }
            }


            if(space == 0){
                ele += " ";
                space = 1;
            }

            ele += text[j];
        }

        _map[ele].push_back(n);
        i = nxt;

    }
}


string word_model::generate(int size) {
    // TODO: Implement me
    string key, ans = "";

    int seed = rand() % _map.size(), x =0;

    for(pair<string,vector<string>> i: _map){
        if (x == seed){
            key = i.first;
            x++;
        }
    }


    for(int j = 0; j < size; j++){
        int r = rand() % _map[key].size();
        string word = _map[key][r];
        ans += word;
        ans += " ";
        if (_order != 1){

            for(int l = 0; l < key.length(); l++){
                if (key[l] == ' '){
                    key = key.substr(l + 1, key.length()) + _space + word;
                    break;
                }
            }
        }else
            key = word;

    }

    return ans;
}
