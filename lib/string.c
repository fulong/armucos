#include <string.h>

void* memset(void* s, int c, size_t n)
{
    unsigned char* p = (unsigned char*) s;
    while (n > 0) {
    *p++ = (unsigned char) c;
    --n;
    }
    return s;
}

size_t strlen(const char * str){
	size_t count=0;
	while(*str++ != 0){
		count++;
	}
	return count;
}
char   *strcpy(char   *strDest,const   char   *strSrc)
     {
         char   *address   =   strDest;                          //记住目标地址的起始值
         while((*strDest++   =   *strSrc++)!='\0');        //先拷贝,后判断,这样就不用在拷贝完了后,再加一句
            return   address;                     //返回目标首地址值.
      }

