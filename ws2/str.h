/*--------------------------------------------------------

WorkSheet 2 part 2 (pointers)
Developper : Moshé
Viewer : Tsivia
Status : waiting for aproval

--------------------------------------------------------*/

#ifndef STR_H
#define STR_H

char *StrStr(const char *haystack, const char *needle); 
int Compare_Strings(const char *src, const char *search);
char *StrnCpy(char *dest, const char *src, size_t n);
char *StrCpy(char *dest, const char *src);
char *StrChr(const char *s, int c);
size_t StrSpn(const char *s, const char *accept);
char *StrnCat(char *dest, const char *src, size_t n);
char *StrCat(char *dest, const char *src);
int Strcmp(char *s1, char *s2);
size_t Strlen(const char *s);
int StrCaseCmp(const char *s1, const char *s2);
char *StrDup(const char *s);

#endif 
