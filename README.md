"Word Wars: Finding the Most Frequent Survivor!" 🚀
This project identifies the most frequently occurring word in string A that is not present in string B. The goal is to efficiently process and find the most frequent word in string A while ignoring words that appear in string B. The solution leverages multiple algorithms to achieve this functionality.

Project Breakdown:
String Cleaning: Before processing, the words are cleaned by converting them to lowercase and removing any non-alphanumeric characters. This ensures uniformity and prevents mismatches due to case differences or punctuation.

Hashing (unordered_map): The program uses hash maps (unordered_map) for fast lookup. The first hash map tracks words in string B to exclude them from consideration, while the second one counts the frequency of words in string A that are not present in string B.

Tokenization: The program uses stringstream to split both strings into words. Each word is then cleaned and processed for counting its frequency in string A.

Finding the Result: After counting the words, the program finds the most frequent word. If there’s a tie in frequency, it selects the lexicographically smallest word using a comparison within the loop.

This solution is efficient, with a time complexity of O(n) for processing the strings, where n is the total number of words. The use of hash maps ensures quick lookups and counting, while the lexicographical comparison ensures the right result even in case of frequency ties.

Algorithms:
Hashing: For fast lookups and counting.
String Tokenization: Using stringstream for word splitting.
Sorting: Lexicographical comparison to select the smallest word when frequencies match.
