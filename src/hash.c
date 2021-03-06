/**
 * @file hash.c
 * @author hutusi (hutusi@outlook.com)
 * @brief Refer to hash.h
 * @date 2019-07-26
 *
 * @copyright Copyright (c) 2019, hutusi.com
 *
 */

#include "hash.h"
#include "def.h"
#include "text.h"

unsigned int hash_char(void *pointer)
{
    return *(unsigned char *)pointer;
}

unsigned int hash_int(void *pointer)
{
    return *(unsigned int *)pointer;
}

unsigned int hash_object(void *object)
{
    return (unsigned int)object;
}

/**
 * @brief BKDR hash algorithm.
 *
 * Introduced by Brian Kernighan and Dennis Ritchie in *The C Programming
 * Language*
 *
 * @param string            Input string.
 * @return unsigned int     Return hash.
 */
unsigned int hash_string(void *string)
{
    unsigned int hash = 0;
    char *p = (char *)string;
    while (*p != '\0') {
        /** factor 131 also could be 31、131、1313、13131、131313 ... */
        hash = hash * 131 + (*p);
        ++p;
    }
    return hash;
}

/**
 * @brief Same as string hash.
 * 
 * @param text              Input text.
 * @return unsigned int     Return hash.
 */
unsigned int hash_text(void *text)
{
    unsigned int hash = 0;
    for (unsigned int i =0; i < text_length(text); ++i)  {
        /** factor 131 also could be 31、131、1313、13131、131313 ... */
        hash = hash * 131 + text_char_at(text, i);
    }
    return hash;
}
