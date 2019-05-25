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
    vector<string> DBNames;
    vector<int> DBInt;
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
                        DBNames.push_back(x->path().filename().string());
                    }
                    else {
                        NULL;
                    }
                }
            }
            if (DBNames.size() > 0)
            {
                for (int x = 0; x < DBNames.size(); x++)
                {
                    cout << boost::format{"%1%: %2%"} % (x+1) % DBNames[x]<<endl;
                    DBInt.push_back(x+1);
                }
                int ChoosedDB = 0;
                cout << "\nPlease choose a Database by enterring the number corresponding to the Database you want FileReaderDB to load-->";
                cin >> ChoosedDB;
                std::string DBPath = "FileReaderDB/" + DBNames[ChoosedDB-1];
                std::ifstream DB (DBPath);
                if (DB)
                {
                    cout << boost::format{"Loading Database <%1%> please be patient..."} % DBNames[ChoosedDB-1]<<endl;
                    vector<string> DBdata;
                    std::string DB_data;
                    int DBdata_CountedLines = 0;
                    while (getline(DB, DB_data))
                    {
                        DBdata_CountedLines++;
                        DBdata.push_back(DB_data);
                    }
                    cout << "\nDatabase Loaded Successfully !"<<endl;
                    cout << boost::format{"\nDatabase <%1%> contains %2% lines"} % DBNames[ChoosedDB-1] % DBdata_CountedLines <<endl;
                    string DesiredData;
                    cout << "\nData you want to find in the Database -->";
                    cin >> DesiredData;
                    cout << "Looking for the desired data... Please be patient..."<<endl;
                    vector<int> DBdata_ContainingLine;
                    for (int x = 0; x <= DBdata_CountedLines; x++)
                    {
                        if (DesiredData == DBdata[x])
                        {
                            cout << boost::format{"\nLine %1% contains data <%2%>\n"} % (x+1) % DesiredData<<endl;
                            DBdata_ContainingLine.push_back(x+1);
                        }
                        else if ((DBdata_ContainingLine.size()) == 0 && (x == DBdata_CountedLines))
                        {
                            cout << "\nNothing Has Been Found !\n\n"<<endl;
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
