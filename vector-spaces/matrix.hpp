//
//  matrix.hpp
//  vector-spaces
//
//  Created by Alvaro Nicoli on 9/9/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>
#include <stdio.h>
#include <vector>

namespace matrix
{
    using namespace std;
    
    // Will return a matrix to which the Gauss Method can be applied
    vector<vector<double>> simplifyMatrix(vector<vector<double>> matrix);
    
    vector<vector<double>> exchangeRows(vector<vector<double>> matrix, int row1, int row2);
    int findNonNullRow(vector<vector<double>> matrix, int row, int col);
    vector<vector<double>> subtractRows(vector<vector<double>> matrix, int row1, int row2, double factor);
    
    // Removes all null rows
    vector<vector<double>> cleanMatrix(vector<vector<double>> matrix);
}

#endif /* matrix_hpp */
