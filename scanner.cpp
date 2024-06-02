#include<bits/stdc++.h>
#include "parser.h"
using namespace std;
char* token;
bool end_of_file();
void skip_whitespace();
void generateToken(TokenType type);
bool isNum(char A);
void keywordToken();
void charToken();
bool isAlphabet(char a);
void makeToken(TokenType type);
