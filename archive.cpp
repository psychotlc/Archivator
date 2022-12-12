#include <iostream>
#include <fstream>

using namespace std;

void archive(string file_name){

    ofstream output("output.dat", ios_base::binary);

    ifstream input(file_name, ios_base::binary);
    input.seekg(0, ios_base::end);
    int SizeInByte = input.tellg();
    input.seekg(0, ios_base::beg);
    unsigned char tmp;
    unsigned char tmpPrev = 0x81;
    unsigned char CountOfRepeatSymbols = 0x81;
    for (int i = 0; i < SizeInByte; i++){

        input.read((char*)&tmp, sizeof(char));
        
        if (tmpPrev == 0x81){
            tmpPrev = tmp;
            continue;
        }
        if (tmpPrev == tmp) CountOfRepeatSymbols++;
        else if(CountOfRepeatSymbols == 0x81) output.write((char*)&tmpPrev, sizeof(char));
        else {
            output.write((char*)&CountOfRepeatSymbols, sizeof(char));
            output.write((char*)&tmpPrev, sizeof(char));
            CountOfRepeatSymbols = 0x81;
        }
        tmpPrev = tmp;
    }
    if (CountOfRepeatSymbols != 0x81) {
        output.write((char*)&CountOfRepeatSymbols, sizeof(char));
        output.write((char*)&tmp, sizeof(char));
    }
    else output.write((char*)&tmp, sizeof(char));

    input.close();
    output.close();
}