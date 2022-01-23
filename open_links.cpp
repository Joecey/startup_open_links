#include <iostream>
#include <fstream>  // library to read txt files
#include <windows.h>
#include <shellapi.h>

using namespace std;

// read from custom link text file
void read_links(){

    // define variable
    ifstream links_file;

    // open path (relative)
    links_file.open("../start_tabs_project/custom_links.txt");

    // check if file opened successfully 
    if (!links_file) {
        cout << "ERROR: Unable to open file datafile.txt \n";
            exit(1);   // call system to stop
    }

    // if file was opened succesfully 
    else{
        cout << "File opened successfully \n";

        // read each line from custom link text file
        string link;

        while (links_file >> link){
            // cout << link << endl; // print links test
            
            ShellExecute(0, 0, link, 0, 0 , SW_SHOW );  
        }

        // close file
        links_file.close();
    }

}

// run main code here
int main(){

    read_links();
    
    return 0;
}