/*****************************************************************************
*                                                                            *
*  ------------------------------ compress.h ------------------------------  *
*                                                                            *
*****************************************************************************/

#ifndef COMPRESS_H
#define COMPRESS_H

#include "bitree.h"

/*****************************************************************************
*                                                                            *
*  Define a structure for nodes of Huffman trees.                            *
*                                                                            *
*****************************************************************************/

typedef struct HuffNode_ {

unsigned char      symbol;
int                freq;

} HuffNode;

/*****************************************************************************
*                                                                            *
*  Define a structure for entries in Huffman code tables.                    *
*                                                                            *
*****************************************************************************/

typedef struct HuffCode_ {

unsigned char      used;
unsigned short     code;
unsigned char      size;

} HuffCode;

/*****************************************************************************
*                                                                            *
*  Define the number of bits required for LZ77 token members.                *
*                                                                            *
*****************************************************************************/

#define            LZ77_TYPE_BITS        1
#define            LZ77_WINOFF_BITS     12
#define            LZ77_BUFLEN_BITS      5
#define            LZ77_NEXT_BITS        8

/*****************************************************************************
*                                                                            *
*  Define the size of the sliding window and the look-ahead buffer for       *
*  LZ77. Each must be less than or equal to 2 raised to LZ77_WINOFF_BITS     *
*  and LZ77_BUFLEN_BITS respectively.                                        *
*                                                                            *
*****************************************************************************/

#define            LZ77_WINDOW_SIZE   4096
#define            LZ77_BUFFER_SIZE     32

/*****************************************************************************
*                                                                            *
*  Define the number of bits for LZ77 phrase tokens.                         *
*                                                                            *
*****************************************************************************/

#define            LZ77_PHRASE_BITS      (LZ77_TYPE_BITS+LZ77_WINOFF_BITS\
                                         +LZ77_NEXT_BITS+LZ77_BUFLEN_BITS)

/*****************************************************************************
*                                                                            *
*  Define the number of bits for LZ77 symbol tokens.                         *
*                                                                            *
*****************************************************************************/

#define            LZ77_SYMBOL_BITS      (LZ77_TYPE_BITS+LZ77_NEXT_BITS)

/*****************************************************************************
*                                                                            *
*  --------------------------- Public Interface ---------------------------  *
*                                                                            *
*****************************************************************************/

int huffman_compress(const unsigned char *original, unsigned char
   **compressed, int size);

int huffman_uncompress(const unsigned char *compressed, unsigned char
   **original);

int lz77_compress(const unsigned char *original, unsigned char **compressed,
   int size);

int lz77_uncompress(const unsigned char *compressed, unsigned char
   **original);

#endif
