#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

char * strtok2(char *str, char *delim){
	static char * ptr_str=NULL;
	if (str!=NULL) ptr_str = str;
	char * ptr_delim;
	int flag = 0;
	if (*ptr_str == '\0') return NULL;
	for (ptr_delim = delim;*ptr_delim != '\0'; ptr_delim++){
		if (*ptr_str == *ptr_delim) flag = 1;
	}
	while (flag){
		ptr_str++;
		if (*ptr_str =='\0') return NULL;
		flag = 0;
		for (ptr_delim = delim; *ptr_delim !='\0';ptr_delim++){
			if (*ptr_str == *ptr_delim) flag = 1;
		}
	}
	char * ptr_res = ptr_str;
	while (!flag){
		ptr_str++;
		if (*ptr_str=='\0') return ptr_res;
		for (ptr_delim = delim; *ptr_delim != '\0';ptr_delim++){
			if (*ptr_str == *ptr_delim)  flag = 1;
		}
	}
	*ptr_str='\0';
	ptr_str++;
	return ptr_res;
}

void memcpy2(char *to, const char *from, const int len){
for (int i = 0; i < len && from[i]; ++i){
to[i] = from [i];
}
}



//strlen
int strlen2(char *ans)
	{
	int i = 0;
	while (ans[i]!='\0' )
		{
		i++;
		}
	return i;
	}



//function ilich
char *readline2()
{
    char buf[81] = {0};  // BUFSIZ - константа для длины буфера
    char *res = NULL;
    int len = 0;
    int n = 0;

    do {
        n = scanf("%80[^\n]", buf);  
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        }
        else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy2(res + len, buf, chunk_len);
            len = str_len;
        }
        else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }

    return res;
}
