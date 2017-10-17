#ifndef HEADER
#define HEADER
#include <stdio.h>




typedef struct cabecalho
{
	char ChunkID[5];
	int ChunkSize;
	char Format[5];
	char SubChunk1ID[5];
	int SubChunk1Size;
	short Audio_format;
	short NumberOfChannels;
	unsigned int SampleRate;
	int ByteRate;
	short Block_align;
	short Bits_per_sample;
	char SubChunk2ID[5];
	int SubChunk2Size;
    short *Audio_data;
}cabecalho;

void load_header (FILE *audio, cabecalho *head);
void print_info (FILE *output, cabecalho *head);
void print_audio (FILE *output, cabecalho *head);

#endif
