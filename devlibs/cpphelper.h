// cpphelper.h
#ifndef CPPHELPER_H
#define CPPHELPER_H

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>

using namespace std;

// ✨ Common Type Shortcuts
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

//// Useful Macros ////
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define yes cout << "YES\n"
#define no cout << "NO\n"

// ANSI Escape Code
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


// Generic Vector Print Function
template<typename T>
void printVec(const vector<T>& vct) {
    cout << "{";
    for (size_t i = 0; i < vct.size(); ++i) {
        cout << vct[i];
        if (i != vct.size() - 1) cout << ", ";
    }
    cout << "}\n";
}


// Generic 2D Vector Print Function
template<typename T>
void printVec2D(const vector<vector<T>>& vct2d) {
    cout << "{\n";
    for (size_t i = 0; i < vct2d.size(); ++i) {
        cout << "  {";
        for (size_t j = 0; j < vct2d[i].size(); ++j) {
            cout << vct2d[i][j];
            if (j != vct2d[i].size() - 1) cout << ", ";
        }
        cout << "}";
        if (i != vct2d.size() - 1) cout << ",";
        cout << "\n";
    }
    cout << "}\n";
}


// Print Set
template<typename T>
void printSet(const set<T>& s) {
    cout << "{";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it;
        if (next(it) != s.end()) cout << ", ";
    }
    cout << "}\n";
}


// Print Array
template<typename T>
void printArray(T arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << ", ";
    }
    cout << "]\n";
}


// Print 2D Array (fixed column size)
template<typename T, size_t M>
void printArray2D(T arr[][M], int n) {
    cout << "[\n";
    for (int i = 0; i < n; ++i) {
        cout << "  [";
        for (int j = 0; j < M; ++j) {
            cout << arr[i][j];
            if (j != M - 1) cout << ", ";
        }
        cout << "]";
        if (i != n - 1) cout << ",";
        cout << "\n";
    }
    cout << "]\n";
}


// Print Map
template<typename K, typename V>
void printMap(const map<K, V>& mp) {
    cout << "{";
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << ": " << it->second;
        if (next(it) != mp.end()) cout << ", ";
    }
    cout << "}\n";
}


// Print Unordered Map
template<typename K, typename V>
void printUnorderedMap(const unordered_map<K, V>& ump) {
    cout << "{";
    for (auto it = ump.begin(); it != ump.end(); ++it) {
        cout << it->first << ": " << it->second;
        if (next(it) != ump.end()) cout << ", ";
    }
    cout << "}\n";
}


// ✨ Red Text Print Function
void printRed(const string& text) { cout << RED << text << RESET << endl; }
// ✨ Green Text Print Function
void printGreen(const string& text) { cout << GREEN << text << RESET << endl; }

// ✨ Yellow Text Print Function
void printYellow(const string& text) { cout << YELLOW << text << RESET << endl; }

// ✨ Blue Text Print Function
void printBlue(const string& text) { cout << BLUE << text << RESET << endl; }

// ✨ Magenta Text Print Function
void printMagenta(const string& text) { cout << MAGENTA << text << RESET << endl; }

// ✨ Cyan Text Print Function
void printCyan(const string& text) { cout << CYAN << text << RESET << endl; }

// ✨ White Text Print Function
void printWhite(const string& text) { cout << WHITE << text << RESET << endl; }


// String Multiplication
string strmul(string s, int n) {
    string ans;
    while (n--) ans += s;
    return ans;
}


// String to Integer Conversion
int strtoint(string s) {
    int ans = 0;
    int d = 1;
    for (int i = s.size()-1; i > -1; i--) {
        ans += (s[i]-'0') * d;
        d *= 10;
    }
    return ans;
}


// decimal To Binary
string decimalToBinary(int n) {
    if (n == 0) return "0";
    string binstr = "";
    while (n > 0) {
        int remainder = n % 2;
        binstr += to_string(remainder);
        n /= 2;
    }
    reverse(binstr.begin(), binstr.end());
    return binstr;
}


// 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLinkList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}


#endif
