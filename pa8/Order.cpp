
//Servesh Karnawat
//skarnawa
//pa8

//-----------------------------------------------------------------------------
// FileIO.cpp
// Illustrates file input-output commands and text processing using the
// string functions find_first_of(), find_first_not_of() and substr().
// 
// compile:
//
//      g++ -std=c++17 -Wall -o FileIO FileIO.cpp
//
//-----------------------------------------------------------------------------
#include<iostream>
#include<fstream>
#include<string>
#include "Dictionary.h"

using namespace std;

#define MAX_LEN 300

int main(int argc, char * argv[]){

   int line_count;
   ifstream in;
   ofstream out;
   string line;
   string tokenBuffer;
   string token;
   string delim = " "; 
   //string delim = " \t\\\"\',<.>/?;:[{]}|`~!@#$^&*()-_=+0123456789";

   // check command line for correct number of arguments
   if( argc != 3 ){
      cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
      return(EXIT_FAILURE);
   }

   // open files for reading and writing 
   in.open(argv[1]);
   if( !in.is_open() ){
      cerr << "Unable to open file " << argv[1] << " for reading" << endl;
      return(EXIT_FAILURE);
   }

   out.open(argv[2]);
   if( !out.is_open() ){
      cerr << "Unable to open file " << argv[2] << " for writing" << endl;
      return(EXIT_FAILURE);
   }

   Dictionary D = Dictionary();
   std::cout << "working\n";
   // read each line of input file, then count and print tokens 
   line_count = 1;
   while( getline(in, line) )  {

      D.setValue(line, line_count );
      line_count++;
      //std::cout << D.pre_string()<< "\n\n\n";

   }
   //std::cout << "working1\n";
   out << D ;
   //std::cout << "working2\n";
   out << endl;
   //std::cout << "working3\n";
   out << D.pre_string();
   //std::cout << "working4\n";
   

   // close files 
   in.close();
   out.close();

   return(EXIT_SUCCESS);
}

