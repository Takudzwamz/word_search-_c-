#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string wordToSearch;
    string fileName = "Source.txt"; // update the file name here
    cout << "Enter the word to search: ";
    getline(cin, wordToSearch);

    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Unable to open file " << fileName << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        size_t pos = line.find(wordToSearch);
        if (pos != string::npos) {
            // Found the word in this line, now extract the sentence
            size_t sentenceStart = line.rfind('.', pos);
            if (sentenceStart == string::npos) {
                sentenceStart = 0;
            }
            else {
                sentenceStart++; // Move past the period
            }
            size_t sentenceEnd = line.find('.', pos);
            if (sentenceEnd == string::npos) {
                sentenceEnd = line.length() - 1;
            }
            string sentence = line.substr(sentenceStart, sentenceEnd - sentenceStart + 1);
            cout << sentence << endl;
        }
    }

    inFile.close();
    return 0;
}
