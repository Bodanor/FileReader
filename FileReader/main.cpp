//
//  main.cpp
//  FileReader
//
//  Created by Christos Papadopoulos on 20/05/2019.
//  Copyright © 2019 Christos Papadopoulos. All rights reserved.
//

#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
using namespace boost::filesystem;
bool Check_for_directory()
{
    if (is_directory("FileReaderDB"))
    {
        cout << "\nLooking for Database inside FileReaderDB directory...\n"<<endl;
        return true;
    }
    else{
        create_directory("FileReaderDB");
        cout << "No Directory exists, Creating one...\nPlease add your Databases to the new FileReaderDB Directory.Press ENTER when Finished...\n";
        cin.get();
        return false;
    }
}

int main()
{
    std::string IgnoredFile;
    vector<string> DataBasesNames;
    vector<int> DataBasesInt;
    bool Directory_exist = Check_for_directory();
    do
    {
        Directory_exist = true;
        if (Directory_exist == true)
        {
            path DB ("FileReaderDB/");
            for (auto x = directory_iterator(DB); x != directory_iterator(); x++)
            {
                if (!is_directory(x->path()))
                {
                    IgnoredFile = x->path().filename().string();
                    if (!(IgnoredFile[0] == '.'))
                    {
                        DataBasesNames.push_back(x->path().filename().string());
                    }
                    else {
                        NULL;
                    }
                }
            }
            if (DataBasesNames.size() > 0)
            {
                for (int x = 0; x < DataBasesNames.size(); x++)
                {
                    cout << boost::format{"%1%: %2%"} % (x+1) % DataBasesNames[x]<<endl;
                    DataBasesInt.push_back(x+1);
                }
                int ChoosenDB = 0;
                cout << "\nPlease choose a Database by enterring the number corresponding to the Database you want FileReaderDB to load-->";
                cin >> ChoosenDB;
                std::string path = "FileReaderDB/" + DataBasesNames[ChoosenDB-1];
                std::ifstream Database (path);
                if (Database)
                {
                    cout << boost::format{"Loading Database <%1%> please be patient..."} % DataBasesNames[ChoosenDB-1]<<endl;
                    vector<string> DBdata;
                    std::string database_data;
                    int DBdata_count = 0;
                    while (getline(Database, database_data))
                    {
                        DBdata_count++;
                        DBdata.push_back(database_data);
                    }
                    cout << "\nDatabase Loaded Successfully !"<<endl;
                    cout << boost::format{"\nDatabase <%1%> contains %2% lines"} % DataBasesNames[ChoosenDB-1] % DBdata_count <<endl;
                    string DesiredData;
                    cout << "\nData you want to find in the Database -->";
                    cin >> DesiredData;
                    cout << "Looking for the desired data... Please be patient..."<<endl;
                    for (int x = 0; x <= DBdata_count; x++)
                    {
                        if (DesiredData == DBdata[x])
                        {
                            cout << boost::format{"Line %1% contains data <%2%>"} % x % DesiredData<<endl;
                        }
                        else
                        {
                            cout << "Nothing has been found !\n";
                            cout << "Exit";
                        }
                    }
                }
                else{
                    cout << "\nAn error occured while trying to read the Database.."<<endl;
                }
            }
            else {
                cout << "No Databases Founded !"<<endl;
            }
        }
        else if (Directory_exist == false)
        {
            Directory_exist = false;
        }
    }while ( Directory_exist != true);
}
