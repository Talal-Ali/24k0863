#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Hash.h"
using namespace std;

class Graph {
    public:
        vector<string> cityList;
        int adj[100][100];
        int cityCount;
        Hash roadTable;

    
        Graph() {
            cityCount = 0;
            for (int i = 0; i < 100; i++)
                for (int j = 0; j < 100; j++)
                    adj[i][j] = -1;
        }

        void addCity(string c) {
            for (int i = 0; i < cityCount; i++)
                if (cityList[i] == c) return;

            cityList.push_back(c);
            cityCount++;
        }

        int findCity(string c) {
            for (int i = 0; i < cityCount; i++)
                if (cityList[i] == c)
                    return i;
            return -1;
        }

        void addRoad(string a, string b, int dist) {
            addCity(a);
            addCity(b);

            int i = findCity(a);
            int j = findCity(b);

            adj[i][j] = dist;
            adj[j][i] = dist;

            roadTable.insert(unordered(a,b), dist);
        }

        int getDistance(string a, string b) {
            return roadTable.find(unordered(a,b));
        }

        int getCityCount() 
        { 
            return cityCount; 
        }
        string getCityName(int i) 
        { 
            return cityList[i]; 
        }
};
