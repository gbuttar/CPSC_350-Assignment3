#include <iostream>
#include <fstream>
#include "GenStack.h"

using namespace std;

int main(int argc, char** argv){

 string commandLineFile;
  if (argc != 2){ //checks to make sure user inputted a file
      cout<<"Please enter a file name into the command line!"<<endl;
      exit(1); //restart the program to have user
  }
  else{
      commandLineFile= argv[1]; //the user input of the .txt file //commandLineFile now stores the inputted file name
  }

  GenStack<char> *s = new GenStack<char>[2]; //creating a stack object s with declared size 2
  ifstream inputFile; //commandLine file turns into inputFile
  string line = "";
  int lineNum = 1;
  inputFile.open(commandLineFile,ios::in); // opens the inputted CommandLineFile

  if(inputFile.is_open()){
      cout<<"File was succesfully opened!"<<endl;
      while(getline(inputFile,line)){ //gets the line from file
        for(int i = 0; i < line.size(); ++i){
          if(line[i] == '/' && line[i+1] == '/'){ //checks for comments, ignores
            i = line.size();
          }
          else if(line[i] == '"'){ //checks for strings, ignores
            for(int j = i; j < line.size(); ++j){
              if(line[j] == '"'){
                i = j;
                j = line.size();
              }
            }
          }
          else if(line[i] == '(' || line[i] == '{' || line[i] == '['){ //check delimiters
            s->push(line[i]); //checks at index and pushes to stack if left facing delimiter
          }
          else if(line[i] == ']' && s->pop() != '['){
            cout<< "Line: "<< lineNum <<" expected [ and found "<<endl; //gives line number of error
            exit(1);
          }
          else if(line[i] == '}' && s->pop() != '{'){
            cout<< "Line: "<< lineNum <<" expected { and found "<<endl; //gives line number of error
            exit(1);
          }
          else if(line[i] == ')' && s->pop() != '('){
            cout<< "Line: "<< lineNum <<" expected ( and found "<<endl; //gives line number of error 
            exit(1);
          }
        }
        lineNum++;
      }
      if(s->isEmpty() == false){ //stack is not empty, needs more checking
        cout<< "Reached end of file, missing: "<< s->pop() <<endl;
      }
  }
  else{ //file did not open
    cout<<"Error: file did not open. Please try again."<<endl;
    exit(1);
    }
}
