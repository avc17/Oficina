#ifndef DICIONARIO
#define DICIONARIO

//Quantidade de palavras no dicionário
#define N_WORDS 275502
#define MAX_WORD_SIZE 30


void ler_dicionario (char dic[][MAX_WORD_SIZE]);


void *pertence (unsigned char *key,char dic[][MAX_WORD_SIZE]);

#endif
