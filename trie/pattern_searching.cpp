#include<bits/stdc++.h>
using namespace std;
#define CHAR_TO_INDEX(str) (int)str-(int)'a'
struct trienode{
    bool isleaf;
    int index[1000];
    trienode* children[50];
};
