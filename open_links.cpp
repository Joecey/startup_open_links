#include <iostream>
#include <fstream>  // library to read txt files
#include <windows.h>
#include <shellapi.h>
#include <string.h>   // string functions

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

    // no options
    // 3 long array, string 100 characters long max
    char arr [4][100] = {"N", "n", "No", "no"};

    char answer[100];
    cout << "Would you like to open default tabs? [Y/n] \n";
    cin >> answer;

    // check arr array for no option 
    int score = 0;
    int i;
    for (i = 0; i < 4; i++){

        if (strcmp(arr[i], answer) == 0){
            score++;
        }


    }
    // check what option is being made (this is such a dumb way of doing it lmao)
    if (score > 0){
   
        cout << "canelling operation... \n";
        system("pause");
    }

    else{
        // run read links function
        read_links();
    }

    return 0;
}
