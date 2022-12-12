#include <iostream>
#include <fstream>

using namespace std;

void unarchive(string file_name){
    ifstream input(file_name, ios_base::binary);
    ofstream output("output.txt", ios_base::binary);

    input.seekg(0, ios_base::end);
    int sizeInByte = input.tellg();
    input.seekg(0, ios_base::beg);
    
    unsigned char tmp1;
    unsigned char tmp2;

    for (int i  = 0; i < sizeInByte; i++){
        input.read((char*)&tmp1, sizeof(char));
        if (tmp1 > 0x81){
            input.read((char*)&tmp2, sizeof(char));
            for (int j = 0; j < (tmp1 - 0x80); j++)output.write((char*)&tmp2, sizeof(char));
            continue;
        }
        output.write((char*)&tmp1, sizeof(char));
    }

}