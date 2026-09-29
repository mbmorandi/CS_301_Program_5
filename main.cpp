#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"

using namespace std;
int main(){

    ifstream inFile; 
    ofstream outFile;
    string inFileName;
    string outFileName;
    string command;
    string outputLabel;

    char item;
    int numCommands;
    Stack<char> stack;

    //prompting user for file IO info
    cout << "Enter name of input file: ";
    cin >> inFileName;
    inFile.open(inFileName.c_str());

    cout << "Enter name of output file: ";
    cin >> outFileName;
    outFile.open(outFileName.c_str());

    //getting the first sentencd
    string line;

    numCommands = 0;
    //input loop
    while(getline(inFile, line)){
        try{
            for(char character : line){
                stack.push(character);
            }
            while(!stack.isEmpty()){
                outFile << stack.pop();

            }
            outFile << "\n";
        }
        //handling errors
        catch(FullStack) {
            outFile << "Fullstack excpetion thrown." << endl;
        } 
        catch(EmptyStack) {
            outFile << "Emptystack exception thrown." << endl;
        }
        numCommands++;
        cout << "Line number " << numCommands << " completed" << endl;
    }

    cout << "File Output Complete." << endl;
    inFile.close();
    outFile.close();
    return 0;

}

