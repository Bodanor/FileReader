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
#include <boost/filesystem.hpp>
using namespace std;
int main(int argc, const char * argv[]) {
    std::string database_data;
    int database_count = 0;
    int choice = 0;
    while (choice !=1){
        std::string database_path;
        std::string desiredDBData;
        std::cout << "Please enter the path where your Databse is -->";
        std::cin >> database_path;
        boost::filesystem::path database_1(database_path);
        ifstream database (database_path);
        if (database)
        {
            choice = 1;
            cout << "\nDatabase Found !\n"<<endl;
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
        else {
            
            cout << "\nAn error occured while trying to open the database. Maybe you have entered a none valid path. Please check and try again !\n\nWould you like to:\n\n(1)Retry\n(2)Exit"<<endl;
            int error = 0;
            while (error != 1)
            {
                cin >> choice;
                if (choice == 1)
                {
                    error = 1;
                    choice = 0;
                }
                else if (choice == 2)
                {
                    exit(1);
                }
                else{
                    cout << "Please use a correct option !";
                    error = 0;
                }
            }
        }
    }
}

