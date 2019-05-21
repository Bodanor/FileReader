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
using namespace std;
using namespace boost::filesystem;
bool Check_for_directory()
{
    if (is_directory("FileReaderDB"))
    {
        cout << "\nDirectory exists, looking for Database inside it ..\n"<<endl;
        return true;
    }
    else{
        cout << "No Directory exists, Creating one...\n";
        create_directory("FileReaderDB");
        return false;
    }
}

int main()
{
    std::string IgnoredFile;
    vector<string> DataBasesNames;
    if (Check_for_directory() == true)
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
        //Ajouter Fonction pour Afficher case du fichier et le nom
    }
}
