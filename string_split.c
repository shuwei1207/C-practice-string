#include <stdio.h>
#include <stdlib.h>


char **f1(const char *s,char c);
int main(void) {
	char original_str[] = "this is a test";
	char **string = f1(original_str,'s');
	printf("%s \n",string[0]); //thi
	printf("%s \n",string[1]); //i
	printf("%s \n",string[2]); //a te
	printf("%s \n",string[3]); //t
	return 0;
}
char **f1(const char *s, char c){
	int i,ctrl=0,j=0;
	char *strptr, **ptrstore;
	
	ptrstore=(char *)malloc(sizeof(char)*10);
	strptr=(char *)malloc(sizeof(char)*10);
	
	for(i=0; *(s+i) != '\0';i++){
		if(*(s+i)==c){
			*(strptr+j) = '\0';
			j=0;
			*(ptrstore+ctrl) =strptr;
			ctrl++;
			strptr=(char *)malloc(sizeof(char)*10);	
		}
		else{
			*(strptr+j) = *(s+i);
			j++;
		}
	}
	*(strptr+j)= '\0';
	*(ptrstore+ctrl)=strptr;
	return ptrstore;
}
