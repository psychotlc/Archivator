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
        if (tmpPrev == tmp) cout << "a";//CountOfRepeatSymbols++;
        else if(CountOfRepeatSymbols == 0x81) output.write((char*)&tmp, sizeof(tmp));
        else {
            output.write((char*)&CountOfRepeatSymbols, sizeof(char));
            output.write((char*)&tmp, sizeof(char));
            CountOfRepeatSymbols = 0x81;
        }
    }
    if (CountOfRepeatSymbols != 0x81) {
        output.write((char*)&CountOfRepeatSymbols, sizeof(char));
        output.write((char*)&tmp, sizeof(char));
    }

    input.close();
    output.close();
}