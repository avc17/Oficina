#include <stdio.h>
#include "header.h"
#include <stdlib.h>

void load_header (FILE *audio, cabecalho *head)
{
	fread(head->ChunkID, 1, 4, audio);
    fread(&head->ChunkSize, 4, 1, audio);
    fread(head->Format, 1, 4, audio);
    fread(head->SubChunk1ID, 1, 4, audio);
    fread(&head->SubChunk1Size, 4, 1, audio);
    fread(&head->Audio_format, 2, 1, audio);
    fread(&head->NumberOfChannels, 2, 1, audio);
    fread(&head->SampleRate, 4, 1, audio);
    fread(&head->ByteRate, 4, 1, audio);
    fread(&head->Block_align, 2, 1, audio);
    fread(&head->Bits_per_sample, 2, 1, audio);
    fread(head->SubChunk2ID, 1, 4, audio);
    fread(&head->SubChunk2Size, 4, 1, audio);
 
    head->Audio_data = malloc(head->SubChunk2Size);
    fread(head->Audio_data, head->SubChunk2Size, 1, audio);



}
void print_audio (FILE *output, cabecalho *head)
{
long i;
	fwrite(head->ChunkID, 1, 4, output);
	fwrite(&head->ChunkSize, 4, 1, output);
	fwrite(head->Format, 1, 4, output);
	fwrite(head->SubChunk1ID, 1, 4, output);
	fwrite(&head->SubChunk1Size, 4, 1, output);
	fwrite(&head->Audio_format, 2, 1, output);
	fwrite(&head->NumberOfChannels, 2, 1, output);
	fwrite(&head->SampleRate, 4, 1, output);
	fwrite(&head->ByteRate, 4, 1, output);
	fwrite(&head->Block_align, 2, 1, output);
	fwrite(&head->Bits_per_sample, 2, 1, output);
	fwrite(head->SubChunk2ID, 1, 4, output);
	fwrite(&head->SubChunk2Size, 4, 1, output);

	
	
	for (i = 0; i < head->SubChunk2Size/2 ; i++)
	{
		head->Audio_data[i] *= 5;
		fwrite(&head->Audio_data[i], 2, 1, output);
	}
//	for (i = head->SubChunk2Size/2; i > 0; i--)
//	{
//		fwrite(&head->Audio_data[i], 2, 1, output);
	
//	}
	
}
void print_info (FILE *output, cabecalho *head)
{
    head->ChunkID[4] = '\0';
    head->Format[4] = '\0';
    head->SubChunk1ID[4] = '\0';
    head->SubChunk2ID[4] = '\0';

    fprintf(output , "riff tag       : \"%s\"\n", head->ChunkID);
    fprintf(output , "riff size      : %d\n", head->ChunkSize);
    fprintf(output , "wave tag       : \"%s\"\n", head->Format);
    fprintf(output , "form tag       : \"%s\"\n", head->SubChunk1ID);
    fprintf(output , "fmt_size       : %d\n", head->SubChunk1Size);
    fprintf(output , "audio_format   : %d\n", head->Audio_format);
    fprintf(output , "num_channels   : %d\n", head->NumberOfChannels);
    fprintf(output , "sample_rate    : %u\n", head->SampleRate);
    fprintf(output , "byte_rate      : %d\n", head->ByteRate);
    fprintf(output , "block_align    : %d\n", head->Block_align);
    fprintf(output , "bit_per_sample : %d\n", head->Bits_per_sample);
    fprintf(output , "data tag       : \"%s\"\n", head->SubChunk2ID);
    fprintf(output , "data size      : %d\n", head->SubChunk2Size);
    fprintf(output , "samples/channel: %d\n", head->SubChunk2Size/4);

}

