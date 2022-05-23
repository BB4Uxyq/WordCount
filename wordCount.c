#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    // argc 表示参数个数, *argv[]指针数组, 每一个指针指向一个字符串
    FILE *Fp;
    char GetString[100];
    char GetChar;
    int WordNum = 1;//单词数：只要读取了文件就必定有一个单词，所以初始化为1 
    int FhNum = 0;//字符数 

    if ((Fp=fopen(argv[2], "r")) == NULL)
	//只读打开文件，若文件不存在，输出“文件不存在！！” 
    {
        puts("文件不存在！！\n");
        return 0;
    }
    
    if (argv[1][1] == 'w') 
	// 统计单词
    { 
        fgets(GetString,99,Fp); 
        {
        	int i; 
            for(i = 1;i < strlen(GetString) - 1;i++){
			   if (GetString[i] == ',' && GetString[i - 1] != ',' && GetString[i + 1] != ',') 
                    WordNum ++;	
               else if (GetString[i] == ' ' && GetString[i - 1] != ' ' && GetString[i + 1] != ' ')
                    WordNum ++;
			} 
        }
        printf("单词数=%d\n", WordNum);
    }
    else if (argv[1][1] == 'c') 
	// 统计字符
    {
    	int j = 1;
		for(j = 1;j > 0;j++){
			if((GetChar = fgetc(Fp))!= EOF)
			    FhNum++;
		    else
		        break;
		}       
        printf("字符数=%d", FhNum);
    }
    fclose(Fp);
    return 0;
}
