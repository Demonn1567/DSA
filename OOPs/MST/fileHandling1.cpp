#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream file("example.txt", ios::out | ios::in | ios::trunc);

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "Hello, this is a test file with some sample text.";
    file.flush();

    streampos writePos = file.tellp();
    cout << "Current write pointer position (tellp): " << writePos << endl;

    file.seekp(0);
    cout << "After seekp(0), write pointer position: " << file.tellp() << endl;

    file << "START";

    file.seekg(0);
    streampos readPos = file.tellg();
    cout << "Current read pointer position (tellg): " << readPos << endl;

    file.seekg(10);
    readPos = file.tellg();
    cout << "After seekg(10), read pointer position: " << readPos << endl;

    char buffer[10];
    file.read(buffer, 9);
    buffer[9] = '\0';
    cout << "Content read from position 10: " << buffer << endl;

    file.seekp(0, ios::end);
    file << " END";

    writePos = file.tellp();
    cout << "Final write pointer position (tellp): " << writePos << endl;

    file.close();
    return 0;
}
