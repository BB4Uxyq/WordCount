#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    // argc ��ʾ��������, *argv[]ָ������, ÿһ��ָ��ָ��һ���ַ���
    FILE *Fp;
    char GetString[100];
    char GetChar;
    int WordNum = 1;//��������ֻҪ��ȡ���ļ��ͱض���һ�����ʣ����Գ�ʼ��Ϊ1 
    int FhNum = 0;//�ַ��� 

    if ((Fp=fopen(argv[2], "r")) == NULL)
	//ֻ�����ļ������ļ������ڣ�������ļ������ڣ����� 
    {
        puts("�ļ������ڣ���\n");
        return 0;
    }
    
    if (argv[1][1] == 'w') 
	// ͳ�Ƶ���
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
        printf("������=%d\n", WordNum);
    }
    else if (argv[1][1] == 'c') 
	// ͳ���ַ�
    {
    	int j = 1;
		for(j = 1;j > 0;j++){
			if((GetChar = fgetc(Fp))!= EOF)
			    FhNum++;
		    else
		        break;
		}       
        printf("�ַ���=%d", FhNum);
    }
    fclose(Fp);
    return 0;
}
