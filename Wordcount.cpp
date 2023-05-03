#include<stdio.h>
#include<string.h>
int main(int a, char *b[]){
	FILE *file;
	int count=0;
	file=fopen(b[2],"r");
	if(file==NULL){
		puts("error!\n");
		return 0;
	}
	if(b[1][1]=='w'){
		char c[1024];
		while(fscanf(file,"%s",c)!=EOF){
			count++;
			for(int i=1;i<strlen(c)-1;i++){
				if(c[i]==','&&c[i-1]!=','&&c[i+1]!=',')
				count++;
			}
		}
		printf("µ¥´ÊÊý=%d\n",count);
	} 
	else if(b[1][1]=='c'){
		char c;
		while((c=fgetc(file))!=EOF)count++;
		printf("×Ö·ûÊý=%d",count);
	}
	fclose(file);
	return 0; 
} 
