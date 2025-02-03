#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to convert a word to lowercase and remove punctuation
string cleanWord(string word) {
    string cleaned = "";
    for (char c : word) {
        if (isalnum(c)) cleaned += tolower(c);
    }
    return cleaned;
}

// Function to find the most frequent word that is not present in string B
string findMostFrequentWord(string A, string B) {
    unordered_map<string, int> freqMap;
    unordered_map<string, bool> wordInB;

    // Convert string B to a set of words for fast lookup
    stringstream ssB(B);
    string wordB;
    while (ssB >> wordB) {
        wordB = cleanWord(wordB);
        if (!wordB.empty()) wordInB[wordB] = true;
    }

    // Count frequency of words in string A
    stringstream ssA(A);
    string wordA;
    while (ssA >> wordA) {
        wordA = cleanWord(wordA);
        if (!wordA.empty() && wordInB.find(wordA) == wordInB.end()) {
            freqMap[wordA]++;
        }
    }

    // Find the most frequent word that is lexicographically smallest
    int maxFreq = 0;
    string result = "-1";

    for (const auto& entry : freqMap) {
        if (entry.second > maxFreq || (entry.second == maxFreq && entry.first < result)) {
            maxFreq = entry.second;
            result = entry.first;
        }
    }

    return result;
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;
    cin.ignore(); // To ignore the newline after integer input

    while (T--) {
        string A, B;
        
        // Taking input strings A and B
        cout << "Enter string A: ";
        getline(cin, A);
        
        cout << "Enter string B: ";
        getline(cin, B);

        // Output the result of the function
        cout << "Most frequent word: " << findMostFrequentWord(A, B) << endl;
    }

    return 0;
}
