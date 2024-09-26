#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printLookupTable(vector<vector<int>> &table, string str1, string str2) {
    // Print header row
    cout << "  ";
    for (int j = 0; j <= str2.length(); j++) {
        if (j == 0)
            cout << "   ";
        else
            cout << str2[j-1] << "  ";
    }
    cout << endl;
    
    for (int i = 0; i <= str1.length(); i++) {
        // Print header column
        if (i == 0)
            cout << "   ";
        else
            cout << str1[i-1] << "  ";
        
        for (int j = 0; j <= str2.length(); j++) {
            cout << table[i][j] << "  ";
        }
        cout << endl;
    }
}

string longestCommonSubstring(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    
    // 2D table to store lengths of longest common suffixes
    vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0;  // Length of the longest common substring
    int endIndex = 0;   // Ending index of the longest substring in str1

    // Build the table and find the longest common substring
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                
                // Update maxLength and endIndex if a longer substring is found
                if (table[i][j] > maxLength) {
                    maxLength = table[i][j];
                    endIndex = i;
                }
            }
        }
    }

    // Print the lookup table for visualization
    cout << "Lookup Table:\n";
    printLookupTable(table, str1, str2);

    // Return the longest common substring
    if (maxLength == 0) {
        return "";
    } else {
        return str1.substr(endIndex - maxLength, maxLength);
    }
}

int main() {
    string str1, str2;
    
    // Prompt user to enter the two strings
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    string lcs = longestCommonSubstring(str1, str2);
    cout << "\nLongest Common Substring: " << lcs << endl;

    return 0;
}
