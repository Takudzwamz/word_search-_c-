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


//Here's how the code works:
//
//The user is prompted to enter the word to search and the name of the file to search in.
//The program opens the file and checks if it was successfully opened.If not, it prints an error message and exits.
//The program reads each line of the file using a while loop and stores it in the line string.
//For each line, the program checks if the word to search is present by using the find function of the string class.If the word is found, the program extracts the sentence that contains the word and prints it to the console.
//To extract the sentence, the program first finds the position of the last period(.) before the word in the line using the rfind function.If there is no period before the word, the sentence starts from the beginning of the line.If there is a period, the program moves one character past it to skip the period.
//The program then finds the position of the next period after the word using the find function.If there is no period after the word, the sentence ends at the end of the line.If there is a period, the program includes it in the sentence.
//The program extracts the sentence using the substr function and prints it to the console.
//After all lines have been read, the program closes the file and exits.