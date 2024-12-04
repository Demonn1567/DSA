#include <ios>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream dataFile;

    dataFile.open("file.txt", ios::binary | ios::out);
    if(dataFile.fail()) {
        cout<<"Error opening file";
    }

    int arr[] = {45,32,1,4,14,5};

    // string s = "krish sharma";
    //     size_t len = s.size();  // Get the length of the string
    //     dataFile.write((char*)&len, sizeof(len)); // Write the length of the string
    //     dataFile.write(s.c_str(), len);          // Write the string content

    dataFile.write((char*) &arr, sizeof(arr));

    dataFile.close();


    dataFile.open("file.txt", ios::in | ios::binary);
    int arr2[6];
    dataFile.read((char*) &arr2, sizeof(arr2));
    for(int i =0;i<6;i++){
        cout<<arr2[i]<<" ";
    }

    return 0;
}
