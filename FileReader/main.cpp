//
//  main.cpp
//  FileReader
//
//  Created by Christos Papadopoulos on 20/05/2019.
//  Copyright © 2019 Christos Papadopoulos. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    std::string database_data;
    int database_count = 0;
    std::string database_path;
    std::string desiredDBData;
    std::cout << "Please enter the path to desired the database -->";
    std::cin >> database_path;
    ifstream database (database_path);
    
    if (database)
    {
        cout << "\nDatabase Found !\n"<<endl;
    }
    else {
        cout << "\nAn error occured while trying to open the database. Maybe you have entered a none valid path. Please check and try again !\n"<<endl;
        exit(1);
    }
    cout << "Loading Database please be patient ...\n\n";
    vector<string> DBData;
    while (getline(database,database_data))
    {
        database_count ++;
        DBData.push_back(database_data);
        
    }
    cout << "Database loaded succesfully !\n";
    
    cout << "Database lines -->" << database_count<<"\n\n"<<endl;
    cout << "Enter the desired Data -->";
    cin >> desiredDBData;
    cout << "Looking for the desired Data. Please be patient ...\n"<<endl;
    for (int x = 0; x <= database_count; x++)
    {
        if (desiredDBData == DBData[x])
        {
            cout <<"Data Founded at line "<< x+1 << " and contains data --> "<< DBData[x] <<endl;
            
            
        }
        else{
            if (x == database_count)
            {
                cout << "Nothing has been found !\n";
            }
            else
            {
                NULL;
            }
        }
    }
}

