#include <iostream>

using namespace std;

void archive(string file_name);

int main(int argc, char* argv[]){
    if (argv[1] == string("archive")) archive(string(argv[2]));

    return 0;
}