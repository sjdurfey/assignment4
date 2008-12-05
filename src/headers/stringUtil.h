////////////////////////////////////////
// stringUtil.h

#ifndef _STRING_UTIL_H
#define _STRING_UTIL_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

////////////////////////////////////////
// 'readMultiword' reads a multiword string
//     terminated by 'sep' from 'infile' into 's'
// Example: if 'infile' contains "Los Angeles # California"
//     then "Los Angeles" is stored in 's' and
//     position of 'infile' is now at "California"

int stringToInt(const string & s);
float stringToFloat(const string & s);

bool readMultiword(string & s, istream & infile,
    const string & sep = "#");

bool readMultiwordVector(vector<string> & s, istream & infile,
    const string & sep = "#");

#endif

