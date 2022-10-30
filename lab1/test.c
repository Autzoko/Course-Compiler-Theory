#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isLetter(char c){
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) return 1;
	else return 0;
}
int isNumber(char c){
	if(c>='0'&&c<='9') return 1;
	else return 0;
}
int getIdentifier_id(char s[]){
	if(strcmp(s,"void")==0){
		return 3;
	}else if(strcmp(s,"int")==0){
		return 4;
	}else if(strcmp(s,"float")==0){
		return 5;
	}else if(strcmp(s,"double")==0){
		return 6;
	}else if(strcmp(s,"if")==0){
		return 7;
	}else if(strcmp(s,"else")==0){
		return 8;
	}else if(strcmp(s,"for")==0){
		return 9;
	}else if(strcmp(s,"do")==0){
		return 10;
	}else if(strcmp(s,"while")==0){
		return 11;
	}else if(strcmp(s,"return")==0){
		return 12;
	}else if(strcmp(s,"break")==0){
		return 13;
	}else{
		return 1;
	}
}
 
int getSinglechar_id(char c){
	if(c==';') return 17;
	else if(c==',') return 18;
	else if(c=='(') return 19;
	else if(c==')') return 20;
	else if(c=='[') return 21;
	else if(c==']') return 22;
	else if(c=='{') return 23;
	else if(c=='}') return 24;
	else if(c=='%') return 34;
	else return 0;
}
 
int main(int argc, char** argv)
{
	char* read_file_path = argv[1];
	char* write_file_path = argv[2];
	FILE *fp=NULL;
	fp=fopen(read_file_path,"r");
	FILE *fw=NULL;
	fw=fopen(write_file_path,"at+");
	char ch;
	ch=fgetc(fp);	
	while(!feof(fp)){
		if(ch==' '||ch=='\t'){
			ch=fgetc(fp);
			continue;
		}else if(ch=='\n'){
			fprintf(fw,"\n");
			ch=fgetc(fp);
			continue;
		}else if(isLetter(ch)==1){
			char s1[32];
			int i=0;
			s1[i++]=ch;
			do{
				ch=fgetc(fp);
				s1[i++]=ch;
			}while(isLetter(ch)==1||isNumber(ch)==1);
			s1[i-1]='\0';
			int id=getIdentifier_id(s1);
			fprintf(fw,"(%d,%s)",id,s1);
		}else if(isNumber(ch)==1){
			char s2[32];
			int i=0;
			s2[i++]=ch;
			do{
				ch=fgetc(fp);
				s2[i++]=ch;
			}while(isNumber(ch)==1);
			s2[i-1]='\0';
			fprintf(fw,"(2,%s)",s2);
		}else if(getSinglechar_id(ch)!=0){
			fprintf(fw,"(%d,%c)",getSinglechar_id(ch),ch);
			ch=fgetc(fp);
		}else if(ch=='>'){
			ch=fgetc(fp);
			if(ch=='='){
				fprintf(fw,"(30,>=)");
				ch=fgetc(fp);
			}else if(ch=='>'){
				fprintf(fw,"(41,>>)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(25,>)");
			}
		}else if(ch=='<'){
			ch=fgetc(fp);
			if(ch=='='){
				fprintf(fw,"(31,<=)");
				ch=fgetc(fp);
			}else if(ch=='<'){
				fprintf(fw,"(42,<<)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(26,<)");
			}
		}else if(ch=='!'){
			ch=fgetc(fp);
			if(ch=='='){
				fprintf(fw,"(32,!=)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(28,!)");
			}
		}else if(ch=='='){
			ch=fgetc(fp);
			if(ch=='='){
				fprintf(fw,"(33,==)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(27,=)");
			}
		}else if(ch=='/'){
			ch=fgetc(fp);
			if(ch=='*'){
				fprintf(fw,"(处理注释,/*)");
				do{
					int flag=0;
					ch=fgetc(fp);
					while(ch=='*'){
						ch=fgetc(fp);
						if(ch=='/'){
							fprintf(fw,"(注释结束,*/)");
							ch=fgetc(fp);
							flag=1;
						}
					}
					if(flag==1) break;
				}while(1);
			}else if(ch=='/'){
				fprintf(fw,"(处理注释,//)");
				do{
					ch=fgetc(fp);
				}while(ch!='\n');
				fprintf(fw,"\n");
				ch=fgetc(fp);
			}else if(ch=='='){
				fprintf(fw,"(40,/=)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(29,/)");
			}
		}else if(ch=='&'){
			ch=fgetc(fp);
			if(ch=='&'){
				fprintf(fw,"(43,&&)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(46,&)");
			}
		}else if(ch=='|'){
			ch=fgetc(fp);
			if(ch=='|'){
				fprintf(fw,"(44,||)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(46,|)");
			}
		}else if(ch=='+'){
			ch=fgetc(fp);
			if(ch=='='){
				fprintf(fw,"(37,+=)");
				ch=fgetc(fp);
			}else if(ch=='+'){
				fprintf(fw,"(35,++)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(14,+)");
			}
		}else if(ch=='-'){
			ch=fgetc(fp);
			if(ch=='='){
				fprintf(fw,"(38,-=)");
				ch=fgetc(fp);
			}else if(ch=='-'){
				fprintf(fw,"(36,--)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(15,-)");
			}
		}else if(ch=='*'){
			ch=fgetc(fp);
			if(ch=='='){
				fprintf(fw,"(39,*=)");
				ch=fgetc(fp);
			}else{
				fprintf(fw,"(16,*)");
			}
		}else{
			fprintf(fw,"error, unrecognized symbol!\n");
			printf("error, unrecognized symbol!\n"); 
			break;
		}
	}
	fclose(fp);
	fclose(fw);
} 