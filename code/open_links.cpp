#include <iostream>
#include <fstream>  // library to read txt files
#include <windows.h>
#include <shellapi.h>

using namespace std;

// read from custom link text file
void read_links(){

    // define variable
    ifstream links_file ;

    // open path (relative)
    links_file.open("custom_links.txt");

    // check if file opened successfully 
    if (!links_file) {
        cout << "ERROR: Unable to open file datafile.txt \n";
        // cout << "Press any key to continue";
        system("pause");
            exit(1);   // call system to stop
    }

    // if file was opened succesfully 
    else{
        cout << "File opened successfully \n";

        // read each line from custom link text file
        string link;

        while (links_file >> link){
            // cout << link << endl; // print links test
            
            // open links (convert string to a c_str())
            ShellExecute(NULL, "open", link.c_str(), NULL, NULL, SW_SHOWNORMAL);
            // system(std::string("start " + link).c_str()); 
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