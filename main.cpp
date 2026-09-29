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

    int item;
    int numCommands;
    Stack<int> stack;

    //prompting user for file IO info
    cout << "Enter name of input file: ";
    cin >> inFileName;
    inFile.open(inFileName.c_str());

    cout << "Enter name of output file: ";
    cin >> outFileName;
    outFile.open(outFileName.c_str());

    cout << "Enter name of test run; press return: ";
    cin >> outputLabel;
    outFile << outputLabel;

    //getting the first command
    inFile >> command;

    numCommands = 0;
    //input loop
    while(command != "Quit"){
        try{
            if(command == "Push"){
                inFile >> item;
                stack.push(item);
            } else if (command == "Pop"){
                stack.pop();
            } else if (command == "Top"){
                item = stack.top();
                outFile << "Top item is: " << item << endl;
            } else if(command == "IsEmpty"){
                if(stack.isEmpty()){
                    outFile << "Stack is empty." << endl;
                } else {
                    outFile << "Stack is not empty." << endl;
                }
            } else if (command == "IsFull"){
                if(stack.isFull()){
                    outFile << "Stack is full." << endl;
                } else {
                    outFile << "Stack is not full" << endl;
                }
            } else {
                cout << "Command not found." << endl;
            }

        }
        //handling errors
        catch(FullStack) {
            outFile << "Fullstack excpetion thrown." << endl;
        } 
        catch(EmptyStack) {
            outFile << "Emptystack exception thrown." << endl;
        }
        numCommands++;
        cout << "Command number " << numCommands << " completed" << endl;
        inFile >> command;
    }

    cout << "Testing complete." << endl;
    inFile.close();
    outFile.close();
    return 0;


}
