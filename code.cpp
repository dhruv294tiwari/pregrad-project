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

// Function to find the most frequent word in A that is not in B
string findMostFrequentWord(string A, string B) {
    unordered_map<string, int> freqMap;
    unordered_map<string, bool> wordInB;

    // Process words in B and store them in hash map
    stringstream ssB(B);
    string wordB;
    while (ssB >> wordB) {
        wordB = cleanWord(wordB); // Normalize
        if (!wordB.empty()) wordInB[wordB] = true;
    }

    // Count frequency of words in A
    stringstream ssA(A);
    string wordA;
    while (ssA >> wordA) {
        wordA = cleanWord(wordA); // Normalize
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
