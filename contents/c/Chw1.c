#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define isSkip(c) (c==' '||c=='\n'||c=='\0'||c==',')
#define MAX_SIZE 1000

int main()
{
	printf("������ctrl-z��β.���������ݣ�\n");
	char str[MAX_SIZE],c_before='\n';
	int words=0,lines=0,char_freq[256];
	int line_start,max_line_length=0,max_line=1;
	int word_start,word_length;
	int max_word_length=0,max_word_start=0;
	for(int i=0;i<256;++i)
		char_freq[i]=0;
	str[0]='\0';
	
	for(int i=1;i<MAX_SIZE;++i)
	{
		str[i]=getchar();
		if(str[i]==EOF)break;
		//�ַ�Ƶ��ͳ��
		++char_freq[(unsigned char)str[i]];

		//����ͳ��
		if((isSkip(c_before)||i==0)&&!isSkip(str[i]))
		{
			++words;
			word_start=i;
		}
		else if(isSkip(str[i])&&!isSkip(c_before))
		{
			word_length=i-word_start;
			if(word_length>max_word_length)
			{
				max_word_start=word_start;
				max_word_length=word_length;
				str[i]='\0';
			}
		}

		//����ͳ��
		if(c_before=='\n')
		{
			++lines;
			line_start=i;
		}
		if(str[i]=='\n')
		{
			if((i-line_start+1)>max_line_length)
			{
				max_line_length=i-line_start+1;
				max_line=lines;
			}
		}
		c_before=str[i];
	}

	int max_freq=0;
	char max_freq_char='\0';
	for(int i=0;i<256;++i)
	{
		if(char_freq[i]>max_freq)
		{
			max_freq=char_freq[i];
			max_freq_char=i;
		}
	}

	printf("\n=====================================\nͳ�����!\n");
	bool show_instruction=true;
	while(1)
	{
		if(show_instruction)
			printf("\n����1:��ӡ���������Ϣ; ����2:��ӡ�ַ������Ϣ; ����3: ��ӡ���������Ϣ  ����0:�˳�\n\n");
		show_instruction=true;
		c_before=getchar();
		if(c_before=='0')break;
		switch(c_before)
		{
		case '1':
			printf("����%d  ���:%d\n",lines,max_line);break;
		case '2':
			printf("Ƶ������ַ�%c  ����ascii����10������Ϊ%d\n",max_freq_char,max_freq_char);break;
		case '3':
			printf("������%d  �����%s\n",words,str+max_word_start);break;
		case '\n':
			show_instruction=false;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}