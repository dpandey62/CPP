// find the k-th characterin a string gam
#include <iostream>
#include <vector>
#include <string>
using namespace std;

char kthCharacter(int k)
{
    string sb = "a";
    while (sb.length() < k)
    {
        int size = sb.length();
        for (int i = 0; i < size; ++i)
        {
            char nextChar = 'a' + ((sb[i] - 'a' + 1) % 26);
            sb += nextChar;
        }
    }
    return sb[k - 1];
}
int main()
{
    cout << kthCharacter(1) << endl; // Output: a
    cout << kthCharacter(2) << endl; // Output: b
    cout << kthCharacter(3) << endl; // Output: b
    cout << kthCharacter(4) << endl; // Output: c
    cout << kthCharacter(5) << endl; // Output: b

    return 0;
}

//  ak ya v logic hai asa v
{ /*
     char kthCharacter(int k) {
         string word = "a";

         while (word.length() < k) {
             string nextPart;
             for (char ch : word) {
                 // Shift char with wrap around from 'z' to 'a'
                 nextPart += (ch == 'z') ? 'a' : ch + 1;
             }
             word += nextPart;
         }

         return word[k - 1]; // 1-based indexing
     }
     */
}