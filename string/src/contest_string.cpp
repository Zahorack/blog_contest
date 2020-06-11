#include <contest_string.h>
#include <iostream>

namespace contest
{

        int memcmp(const void *left, const void *right, size_t byteLength)
        {
                const unsigned char *p_src = static_cast<const unsigned char *>(left);
                const unsigned char *p_dest = static_cast<const unsigned char *>(right);

                if(left == nullptr || right == nullptr)
                        return -2;

                for(; byteLength--; p_src++, p_dest++) {
                        if(*p_src < *p_dest)
                                return -1;
                        else if(*p_src > *p_dest)
                                return 1;
                }
                return 0;
	}

        void *memcpy(void *_Rstr dest, const void *_Rstr src, size_t byteLength)
        {
                if(dest == nullptr || src == nullptr || byteLength == 0)
                        return  dest;

                const unsigned char *p_src = (const unsigned char *)src;
                unsigned char *p_dest = (unsigned char *)dest;

                for(int i = 0; i < byteLength; i++) {
                        *(p_dest + i) = *(p_src + i);
                }

                return dest;
        }

        void *memmove(void *dest, const void *src, size_t byteLength)
        {
                const unsigned char *p_src = (const unsigned char *)src;
                unsigned char *p_dest = (unsigned char *)dest;

                if (p_src > p_dest)
                        memcpy(dest, src, byteLength);
                else
                        for (p_dest += byteLength, p_src += byteLength; byteLength--;)
                                *--p_dest = *--p_src;

                return dest;
        }

        void *memset(void *dest, int value, size_t byteLength)
        {
                if(dest == nullptr ||  byteLength == 0)
                        return dest;

                unsigned char *p_dest = (unsigned char *)dest;

                for(int i = 0; i < byteLength; i++) {
                        *(p_dest + i) = value;
                }

                return dest;
        }

        char *strcpy(char *_Rstr dest, const char *_Rstr src)
        {
                if(dest == nullptr || src == nullptr)
                return  dest;

                size_t length = strlen(src);

                const char *p_src = (const char *)src;
                char *p_dest = (char *)dest;

                for(int i = 0; i < length; i++) {
                        *(p_dest + i) = *(p_src + i);
                }
                *(p_dest + length) = '\0';

                return dest;
        }

        char *strncpy(char *_Rstr dest, const char *_Rstr src, size_t length)
        {
                if(dest == nullptr || src == nullptr)
                        return  dest;

                const char *p_src = (const char *)src;
                char *p_dest = (char *)dest;

                for(int i = 0; i < length; i++) {
                        *(p_dest + i) = *(p_src + i);
                }
                *(p_dest + length) = '\0';

                return dest;
        }

        size_t strlen(const char *str)
        {
                if(str == nullptr)
                        return 0;

                const char *p_begin = str;
                while(*str != '\0') {
                        str++;
                }
                
                return size_t(str - p_begin);
        }

}
