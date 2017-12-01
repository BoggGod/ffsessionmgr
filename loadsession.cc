#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//int main(int argc, char *argv[])
    //need error handling with too many variables
    // need if statement for direct interaction
int main (int argc, char *argv[]) //should be a function with paramters that declares file
{
    //declare where to get file from
    //argv[1] will be the weblist file
    vector<string> weblist;
    string filename;
    string line;
    string temp_line;
    stringstream bash_beater;
    filename = argv[1];
    // replaced by callin paramter method
    //cout << "Enter location of session-list file" << endl;
    //getline(cin,filename);
    ifstream myfile(filename);
    cout << "Loading " << filename << " ..." << endl;
    while (getline(myfile, temp_line)) {
        weblist.push_back(temp_line);
    }
    if (weblist.size() == 1)
        cout << "found only one website: " << weblist[0] << endl;
        // implementation for 1 website here
    bash_beater << "firefox -new-window " << weblist[0] << " && sleep 2;"    // start filling buffer
     << " firefox -new-tab";
    for (auto i = (weblist.begin() + 1); i != weblist.end(); i++) {
        bash_beater << " " << *i; // fille buffer with every entry
    }
    bash_beater << " > /dev/null 2>&1 &disown"; // clean ending
    cout << bash_beater << endl;
    system(bash_beater.str().c_str());
    bash_beater.str(""); //even cleaner
    return 0;
}
