////////////////////////////////////////
// stringUtil.cpp

#include "/home/stephen/workspace/assgn4/src/headers/stringUtil.h"
#include "stdlib.h"

using namespace std;

//returns the integer value of a string as passed to it from the functions
//vectStr and vectPtr, which are defined in LinkedListSort.cpp
int stringToInt(const string & s)
{
	return atoi(s.c_str());
}

float stringToFloat(const string & s)
{
    stringstream ss;
    float val;

    ss << s;
    ss >> val;
    ss.clear();
    return val;
}

////////////////////////////////////////
// 'readMultiword' reads a multiword string
// terminated by 'sep' from 'infile' into 's';
// returns true if a multiword string read;
// returns false if the first word is a separator ('sep')
// Example: if 'infile' contains "Los Angeles # California"
// then "Los Angeles" is stored in 's' and
// position of 'infile' is now at "California"

bool readMultiword(string & s, istream & infile,
     const string & sep /* = "#" */)
{
    string w;

    infile >> s;
    if (s == sep)
        return false;
    infile >> w;
    while (w != sep)
    {
        s += " " + w;
        infile >> w;
    }
    return true;
}

//calls readMultiWord, takes each string received and pushes it onto the vector.
//returns true to loop in 'main()' if it is not end of file. other wise it will
//return false when end of file is reached, as indicated from readMultiWord()
bool readMultiwordVector(vector<string> & v, istream & infile,
    const string & sep /* = "#" */)
{
      string s;
      bool did_it_read = false;
      v.clear();
      while (readMultiword(s, infile)){
          v.push_back(s);
          did_it_read = true;
      }

      return did_it_read;
}
