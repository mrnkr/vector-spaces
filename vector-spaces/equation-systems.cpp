//
//  equation-systems.cpp
//  vector-spaces
//
//  Created by Alvaro Nicoli on 9/9/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#include "equation-systems.hpp"

namespace equationsystems {
    vector<double> solveSystem(vector<vector<double>> vectors)
    {
        vector<double> retVal;
        
        vectors = simplifyMatrix(vectors);
        
        // Goes vector by vector bottom-up
        for (int i = (int) vectors.size() - 1; i >= 0; --i)
        {
            double factor = 0; // Number multiplying the variable Im trying to find
            double rowResult = vectors[i][(int) (vectors[i].size() - 1)]; // Equation result - Last number in row
            
            // Go number by number in row from end to start without taking the equation result into account
            // Begin in the first factor multiplying a variable
            // End when you reach the factor that will divide your rowSum
            // The -2 is composed by a -1 that represents the index offset and another -1 that represents the ignored index in the end
            for (int j = (int) vectors[i].size() - 2; j >= (int) (vectors[i].size() - 2 - retVal.size()); --j)
            {
                // The first non null position in the vector will become the factor
                if (vectors[i][j] != 0)
                {
                    // The last time an iteration is made get the factor
                    if (j == (int) (vectors[i].size() - 2 - retVal.size()))
                    {
                        factor = vectors[i][j];
                    }
                    else
                    {
                        // All other non null numbers go to the other side of the equation
                        // after being multiplied by the value of their variable
                        rowResult -= (vectors[i][j] * retVal[(int) (vectors[i].size() - j - 2)]);
                    }
                }
            }
            
            if (rowResult == 0 && factor == 0)
            {
                retVal.push_back(0);
            }
            else
            {
                if (factor != 0)
                {
                    retVal.push_back(rowResult / factor);
                }
                else
                {
                    return {-1}; // Incompatible system case
                }
            }
        }
        
        // Mirror the retVal vector!!
        return retVal;
    }
}
