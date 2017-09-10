//
//  main.cpp
//  vector-spaces
//
//  Created by Alvaro Nicoli on 9/9/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#include <iostream>
#include <vector>
#include "matrix.hpp"
#include "equation-systems.hpp"
#include "vector-spaces.hpp"

using namespace std;
using namespace matrix;
using namespace equationsystems;
using namespace vectorspaces;

int main(int argc, const char * argv[])
{
    vector<vector<double>> testSystem = {{1, 2, -1}, {2, 3, 0}, {3, 5, -1}};
    vector<vector<double>> toCompare = {{1, 2, -1}, {0, -1, 2}};
    vector<double> testVector = {2, 1, 4};
    
    cout << "The set you're working with is: \n" << endl;
    
    for (int i = 0; i < (int) testSystem.size(); ++i)
    {
        cout << "(";
        for (int j = 0; j < (int) testSystem[i].size(); ++j)
        {
            cout << testSystem[i][j];
            
            if (j < (int) testSystem[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << ")\n";
    }
    cout << "\n";
    
    bool freeAsTheWind = isIndependent(testSystem);
    
    cout << "Is it independent? " << freeAsTheWind << "\n" << endl;
    
    if (!freeAsTheWind)
    {
        cout << "The independent version of the set is the following... \n" << endl;
        
        vector<vector<double>> independentVersion = simplifyMatrix(testSystem);
        
        for (int i = 0; i < (int) independentVersion.size(); ++i)
        {
            cout << "(";
            for (int j = 0; j < (int) independentVersion[i].size(); ++j)
            {
                cout << independentVersion[i][j];
                
                if (j < (int) independentVersion[i].size() - 1)
                {
                    cout << ", ";
                }
            }
            cout << ")\n";
        }
        cout << "\n";
    }
    
    vector<double> coord = getVectorCoordinates(testSystem, testVector);
    
    if ((int) coord.size() > 0 && coord[0] != -1)
    {
        cout << "The coordinates of (";
        
        for (int i = 0; i < (int) testVector.size(); ++i)
        {
            cout << testVector[i];
            
            if (i < (int) testVector.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << ")\n\nAre the following: (";
        
        for (int i = 0; i < (int) coord.size(); ++i)
        {
            cout << coord[i];
            
            if (i < (int) coord.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << ")\n";
    }
    
    cout << "\nThe set to compare with the original one is: \n" << endl;
    
    for (int i = 0; i < (int) toCompare.size(); ++i)
    {
        cout << "(";
        for (int j = 0; j < (int) toCompare[i].size(); ++j)
        {
            cout << toCompare[i][j];
            
            if (j < (int) toCompare[i].size() - 1)
            {
                cout << ", ";
            }
        }
        cout << ")\n";
    }
    cout << "\n";
    
    cout << "Both generate the same set: " << bothGenerateTheSameSet(testSystem, toCompare) << "\n" << endl;
    
    return 0;
}
