#ifndef H_CRYPTER
#define H_CRYPTER


 void decCirculaire(char  string[]  , char result[]);
  void decCirculaireg(char  string[]  , char result[]);
void xorop(char * word1 , char * word2 , char  result[]);
 void addkey(char  word1[] , char  key[] , char  result[]);
  void minuskey(char  word1[] , char  key[] , char  result[]);
  int crypter(char * FILENAME, char * NEW_FILENAME , char *key);
  int decrypter(char *FILENAME, char *NEW_FILENAME , char *key);
  int comparer(char * FILENAME, char * NEW_FILENAME);    


 #endif
