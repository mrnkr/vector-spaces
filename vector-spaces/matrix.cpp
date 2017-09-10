//
//  matrix.cpp
//  vector-spaces
//
//  Created by Alvaro Nicoli on 9/9/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

//
// This code is originally written in Java and can be found in the following repo
// https://github.com/SebastianBandera/Java.git
//

#include "matrix.hpp"

namespace matrix
{
    vector<vector<double>> simplifyMatrix(vector<vector<double>> matrix)
    {
        for (int i = 0; i < (int) matrix.size(); ++i)
        {
            for (int j = i+1; j < (int) matrix[i].size(); ++j)
            {
                if (matrix[i][i] == 0)
                {
                    int nextNonNullRowIndex = findNonNullRow(matrix, j, i);
                    
                    if (nextNonNullRowIndex != -1)
                    {
                        matrix = exchangeRows(matrix, nextNonNullRowIndex, i);
                    }
                }
                
                double factor = 0;
                
                if (j < matrix.size() && matrix[i][i] != 0)
                {
                    factor = matrix[j][i]/matrix[i][i];
                }
                
                if (factor != 0)
                {
                    matrix = subtractRows(matrix, j, i, factor);
                }
            }
        }
        
        return cleanMatrix(matrix);
    }
    
    vector<vector<double>> exchangeRows(vector<vector<double>> matrix, int row1, int row2)
    {
        for (int i = 0; i < (int) matrix.size(); ++i)
        {
            // a = a + b
            // b = a - b
            // a = a - b
            
            matrix[row1][i] = matrix[row1][i] + matrix[row2][i];
            matrix[row2][i] = matrix[row1][i] - matrix[row2][i];
            matrix[row1][i] = matrix[row1][i] - matrix[row2][i];
        }
        
        return matrix;
    }
    
    int findNonNullRow(vector<vector<double>> matrix, int row, int col)
    {
        for (int i = row; i < (int) matrix.size(); ++i)
        {
            if (matrix[i][col] != 0)
            {
                return i;
            }
        }
        
        return -1;
    }
    
    vector<vector<double>> subtractRows(vector<vector<double>> matrix, int row1, int row2, double factor)
    {
        // I use j as the index inside the for in order to recognise it as the column iterator
        for (int j = 0; j < (int) matrix[row1].size(); ++j)
        {
            matrix[row1][j] = matrix[row1][j] - ( factor * matrix[row2][j] );
        }
        
        return matrix;
    }
    
    vector<vector<double>> cleanMatrix(vector<vector<double>> matrix)
    {
        for (int i = 0; i < (int) matrix.size(); ++i)
        {
            // Store the sum of all the elements in the row
            double rowSum = 0;
            
            for (int j = 0; j < (int) matrix[i].size(); ++j)
            {
                rowSum += matrix[i][j];
            }
            
            // If no element was greater than 0 then the row is full of zeroes
            if (rowSum == 0)
            {
                matrix.erase(matrix.begin() + i);
                i--; // Take the index back a step to check the next row which was brought up a position
            }
        }
        
        return matrix;
    }
}
