#include <iostream>

using namespace std;

void archive(string file_name);
void unarchive(string file_name);

int main(int argc, char* argv[]){
    if (argc == 3) {
        if (argv[1] == string("archive")) archive(string(argv[2]));
        else if (argv[1] == string("unarchive")) unarchive(string(argv[2]));
        else cout << "Uncorrect opperation" << endl;
    }

    else cout << "Uncorrect opperation" << endl;

    return 0;
}