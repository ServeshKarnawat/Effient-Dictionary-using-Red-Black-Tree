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
#include <algorithm>
#include <cctype>
#include "Dictionary.h"

using namespace std;

#define MAX_LEN 300

int main(int argc, char * argv[]){


   size_t begin, end;
   ifstream in;
   ofstream out;
   string line;
   string tokenBuffer;
   string token;
   //string delim = " "; 
   string delim = " \t\\\"\',<.>/?;:[{]}|`~!@#$%^&*()-_=+0123456789";
   string word;
   Dictionary wordFreq;

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

   // read each line of input file, then count and print tokens 
 
   while( getline(in, line) )  {
      transform(line.begin(),line.end(), line.begin(), ::tolower);


      // get first token
      begin = line.find_first_not_of(delim);
      
      while( begin != string::npos ){  // we have a token
         // update token buffer
         end   = line.find_first_of(delim, begin);
         word = line.substr(begin, end-begin);

         if(wordFreq.contains(word)){
            wordFreq.getValue(word)++;
         }
         else{
            wordFreq.setValue(word,1);
         }
      

         // get next token
         begin = line.find_first_not_of(delim, end);
      }

   }
   out<< wordFreq.to_string();
   

   // close files 
   in.close();
   out.close();

   return(EXIT_SUCCESS);
}