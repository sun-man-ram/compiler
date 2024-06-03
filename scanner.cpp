#include<bits/stdc++.h>
// #include<token.h>
#include "parser.h"
using namespace std;
char* token;
static bool isNum(char b){
    int a=b-'0';
    if(a>=0 && a<=9){
        return true;
    }
    else{
        return false;
    }
}
static bool isAlphabet(char a){
    if((a>='a' && a<='z')||(a>='A' && a<='Z')||a=='_'){
        return true;
    }
    else{
        return false;
    }
}
static bool end_of_file(){
    if(token[0]=='\0'){
        return true;
    };
    return false;
}
static void skipToken(char a){
    while((!end_of_file())&&!(token[0]==A)){
        token++;
    }

    if(end_of_file()){
        error("unexpected end of line ",line);
    }
}
static void skipToken(char a,char b){
  while((!end_of_file())&&!((token[0]==A)&&(token[1]==B))){
   token++;
  }token++;
  if(end_of_file()){
    error("unexpected end of file on line",line);
  }
  else{
    token=token+2;
  }

}
static bool end_of_file(){
if(token[0]='/0'){
    return true;
}
return false;
}
void skip_whitespace(){
    switch(*token){
        case '':
        token++;
        skip_whitespace();
        break;
        case '\r':
        token++;
        skip_whitespace();
        break;
        case '\t':
        token++;
        skip_whitespace();
        break;
        case '\n':
        token++;
        line++;
        skip_whitespace();
        break;
        case '/':
        if(token[1]=='/'){
            token ++;
            skipToken('\n');
            line++;
        }
        else if(token[1]=='*'){
            token++;
            skipToken('*','/');
            line++;
        }
        else{
            makeToken(TOKEN_SLASH);
            token++:
         };
      skip_whitespace();
        break;
    default:
        break;
    }
}
void generateToken(TokenType type);
// bool isNum(char A);
void keywordToken();
void charToken();
// bool isAlphabet(char a);
void makeToken(TokenType type);
int line=1;

void scanner(char *buffer){
    token=buffer;
    while(!end_of_file()){
        skip_whitespace();
        if(isNum(*token)){
            generateToken(TOKEN_NUMBER);
        }
        else{
            if(isAlphabet(*token)){
                keywordToken();
            }
            else{
                charToken();
            }
            token++;
        }
if(end_of_file()){
    makeToken(TOKEN_EOF);
}
    }
}