
#include "BSTree.cpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;

// Function to clean and extract words
string cleanWord(const string &word) {
    string cleaned = "";
    for (char ch : word) {
        if (isalpha(ch)) cleaned += tolower(ch);
    }
    return cleaned;
}

int main() {
    BSTree<string> wordTree;
    string filename, word;
    int totalWords = 0, totalSentences = 0, totalUniqueWordsMore3 = 0;
    double totalWordLength = 0;

    // Ask for file input
    cout << "Enter file name: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Reading file and populating BST
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        while (iss >> word) {
            string cleaned = cleanWord(word);
            if (!cleaned.empty()) {
                wordTree.insertItem(cleaned); // Insert word into BST
                totalWords++;
                totalWordLength += cleaned.length();
                if (cleaned.length() > 3) totalUniqueWordsMore3++;
            }
            // Check for sentence endings
            if (word.find('.') != string::npos || word.find('!') != string::npos || word.find('?') != string::npos)
                totalSentences++;
        }
    }
    inputFile.close();

    // Calculating averages
    double avgWordLength = totalWordLength / totalWords;
    double avgSentenceLength = static_cast<double>(totalWords) / totalSentences;

    // Display statistics
    ofstream outFile("output.txt");
    outFile << "FILE NAME: " << filename << "\n\nSTATISTICAL SUMMARY\n\n";
    outFile << "TOTAL NUMBER OF WORDS: " << totalWords << "\n";
    outFile << "TOTAL NUMBER OF UNIQUE WORDS: " << wordTree.countUniqueWords() << "\n";
    outFile << "TOTAL NUMBER OF UNIQUE WORDS OF MORE THAN THREE LETTERS: " << totalUniqueWordsMore3 << "\n";
    outFile << "AVERAGE WORD LENGTH: " << fixed << setprecision(2) << avgWordLength << " characters\n";
    outFile << "AVERAGE SENTENCE LENGTH: " << avgSentenceLength << " words\n\n";

    // Style warnings
    outFile << "STYLE WARNINGS\n\n";
    if (avgSentenceLength > 10)
        outFile << "AVERAGE SENTENCE LENGTH TOO LONG - " << avgSentenceLength << " words\n";
    if (avgWordLength > 5)
        outFile << "AVERAGE WORD LENGTH TOO LONG - " << avgWordLength << " characters\n";

    outFile << "WORDS USED TOO OFTEN:\n";
    wordTree.printOverusedWords(0.05 * totalUniqueWordsMore3, outFile); // Print words >5%

    // Index of unique words
    outFile << "\nINDEX OF UNIQUE WORDS\n\n";
    wordTree.printIndex(outFile);

    outFile.close();
    cout << "Analysis completed. Results saved to 'output.txt'.\n";
    return 0;
}
