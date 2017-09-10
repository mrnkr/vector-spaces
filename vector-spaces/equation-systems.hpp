//
//  equation-systems.hpp
//  vector-spaces
//
//  Created by Alvaro Nicoli on 9/9/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#ifndef equation_systems_hpp
#define equation_systems_hpp

#include <stdio.h>
#include <vector>
#include "matrix.hpp"

namespace equationsystems
{
    using namespace std;
    using namespace matrix;
    
    vector<double> solveSystem(vector<vector<double>> vectors);
}

#endif /* equation_systems_hpp */
