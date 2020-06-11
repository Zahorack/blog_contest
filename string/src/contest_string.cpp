#include <contest_string.h>
#include <iostream>

namespace contest
{

        int memcmp(const void *left, const void *right, size_t byteLength)
        {
                const unsigned char *p_src = static_cast<const unsigned char *>(left);
                const unsigned char *p_dest = static_cast<const unsigned char *>(right);

                while(byteLength--) {
                        if(*p_src < *p_dest)
                                return -1;
                        else if(*p_src > *p_dest)
                                return 1;
                        p_src++;
                        p_dest++;
                }
                return 0;
	}

        void *memcpy(void *_Rstr dest, const void *_Rstr src, size_t byteLength)
        {
                if(dest == nullptr || src == nullptr || !byteLength)
                        return  dest;

                const unsigned char *_Rstr p_src = static_cast<const unsigned char *_Rstr>(src);
                unsigned char *_Rstr p_dest = static_cast<unsigned char *_Rstr>(dest);

                while(byteLength--) {
                        *p_dest++ = *p_src++;
                }

                return dest;
        }

        void *memmove(void *dest, const void *src, size_t byteLength)
        {
                const unsigned char *p_src = static_cast<const unsigned char *>(src);
                unsigned char *p_dest = static_cast<unsigned char *>(dest);

                if (p_src > p_dest)
                        memcpy(dest, src, byteLength);
                else
                        for (p_dest += byteLength, p_src += byteLength; byteLength--;)
                                *--p_dest = *--p_src;

                return dest;
        }

        void *memset(void *dest, int value, size_t byteLength)
        {
                if(dest == nullptr || !byteLength)
                        return dest;

                unsigned char *p_dest = static_cast<unsigned char *>(dest);

                while(byteLength--) {
                        *p_dest++ = value;
                }
                return dest;
        }

        char *strcpy(char *_Rstr dest, const char *_Rstr src)
        {
                return strncpy(dest, src, strlen(src));
        }

        char *strncpy(char *_Rstr dest, const char *_Rstr src, size_t length)
        {
                if(dest == nullptr || src == nullptr)
                        return  dest;

                char *_Rstr p_dest = dest;

                while(length--) {
                        *p_dest++ = *src++;
                }
                *p_dest = '\0';

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
                return static_cast<size_t>(str - p_begin);
        }

}
