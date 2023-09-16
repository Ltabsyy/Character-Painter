/*Character Painter Str*/
//#define _CRT_SECURE_NO_WARNINGS//vs专属(doge)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ShowChar(char character,int line);
void Error();
int main()
{
	FILE *fp;
	fp=fopen("Drawing2.txt","w");
	fclose(fp);//创建空输出文件
	char character, endCharacter, c[64]={0};
	int i, screenLength, length, line;
	printf("Character Painter Str\n");
	printf("支持所有小写字母、大写字母、数字、符号！\n");
	printf("支持字符串过长自动换行！(全屏)\n");
	//printf("输入 ` 保存文件\n");
	printf("输入 ` 结束程序，夹杂输入则绘制前面部分\n");
	printf("直接输入指令`/clear清屏并清空文件\n");
	printf("直接输入指令`/set screenLength设置屏幕长度\n");
	printf("输入字符按回车即可显示\n");
	endCharacter='`';//`表示无暂存字符
	screenLength=189-1;//全屏一行像素为189，回车占1格，实际188
	while(1)//逐行操作
	{
		/*--读取并写入temp--*/
		for(i=0;i<=63;i++)
		{
			c[i]=0;
		}//以数组为缓存temp
		length=0;
		for(i=0;i<=63;i++)//读入temp
		{
			character=getchar();
			if(endCharacter!='`')//有暂存字符则输出
			{
				c[i]=endCharacter;
				i++;
				length += ShowChar(endCharacter,0);//首字符一定有空间
				endCharacter='`';//重置暂存字符
			}
			if(character=='\t')
			{
				length += ShowChar(' ',0)*4;//空格宽7格
				if(length>screenLength)
				{
					c[i]='\n';//字符串过长换行
					endCharacter=character;//暂存尾字符
					length=0;
					break;//先绘制该行再读入(为什么不会读入*/空格，我也不懂(doge))
				}
				else
				{
					c[i]=' ';//tab转4空格
					i++;
					c[i]=' ';
					i++;
					c[i]=' ';
					i++;
					c[i]=' ';
				}
			}
			else//其他字符
			{
				length += ShowChar(character,0);//字符宽度，3~9格，一般7格
				if(length>screenLength)
				{
					c[i]='\n';//字符串过长换行
					endCharacter=character;
					length=0;
					break;
				}
				else
				{
					c[i]=character;
				}
			}
			if(character=='\n') break;//写入回车并退出
		}
		/*--指令--*/
		if(c[0]=='`')
		{
			if(c[1]=='/')
			{
				if(strcmp(c+2,"clear\n")==0)
				{
					system("cls");//指令`/clear清屏并清空文件
					fp=fopen("Drawing2.txt","w");
					fclose(fp);
					continue;
				}
				if(strcmp(c+2,"set screenLength\n")==0)//指令`/set screenLength [int]设置屏幕长度
				{
					printf("请输入新屏幕长度（默认188）：");
					scanf("%d", &screenLength);
					printf("成功设置屏幕长度为%d！\n", screenLength);
					continue;
				}
			}
			else
			{
				break;//直接输入 ` 结束程序
			}
		}
		/*--读取temp并输出--*/
		for(line=1;line<=8;line++)//逐行输出
		{
			for(i=0;i<=63;i++)//绘制所有字符该行像素
			{
				character=c[i];
				//printf("%c",character);
				if(character=='`')//读到 ` 不立即结束程序2
				{
					ShowChar('\n',line);
					break;//`为首字符直接退出1
				}
				ShowChar(character,line);
				if(character=='\n') break;//读到回车跳出换行
			}
		}
		if(character=='`') break;//读到 ` 不立即结束程序3
		/*--过时的竖向输出(doge)--*/
		/*character=getchar();
		//printf("character=%c", character);
		if(character=='`') break;//保存
		if(character==10) continue;//回车抗干扰
		for(line=1;line<=8;line++)
		{
			ShowChar(character,line);
			printf("\n");
			fp=fopen("Drawing2.txt","a");
			fprintf(fp,"\n");
			fclose(fp);//保存回车
		}
		//getchar();//防止*读入*/
	}
	printf("已保存\n");
	system("pause");
	return 0;
}
int ShowChar(char character,int line)
{
	FILE *fp;
	fp=fopen("Drawing2.txt","a");
	if(character==' ')//空格
	{
		if(line==0) return 7;//line为0时返回长度
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("       ");
		if(line==4) printf("       ");
		if(line==5) printf("       ");
		if(line==6) printf("       ");
		if(line==7) printf("       ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"       ");
		if(line==4) fprintf(fp,"       ");
		if(line==5) fprintf(fp,"       ");
		if(line==6) fprintf(fp,"       ");
		if(line==7) fprintf(fp,"       ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='a')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("  ***  ");
		if(line==4) printf("     * ");
		if(line==5) printf("  **** ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  **** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"  ***  ");
		if(line==4) fprintf(fp,"     * ");
		if(line==5) fprintf(fp,"  **** ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  **** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='b')
	{
		if(line==0) return 7;
		if(line==1) printf(" *     ");
		if(line==2) printf(" *     ");
		if(line==3) printf(" * **  ");
		if(line==4) printf(" **  * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" ****  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *     ");
		if(line==2) fprintf(fp," *     ");
		if(line==3) fprintf(fp," * **  ");
		if(line==4) fprintf(fp," **  * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," ****  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='c')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("  ***  ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *     ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"  ***  ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *     ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='d')
	{
		if(line==0) return 7;
		if(line==1) printf("     * ");
		if(line==2) printf("     * ");
		if(line==3) printf("  ** * ");
		if(line==4) printf(" *  ** ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  **** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"     * ");
		if(line==2) fprintf(fp,"     * ");
		if(line==3) fprintf(fp,"  ** * ");
		if(line==4) fprintf(fp," *  ** ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  **** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='e')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("  ***  ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" ***** ");
		if(line==6) printf(" *     ");
		if(line==7) printf("  **** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"  ***  ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," ***** ");
		if(line==6) fprintf(fp," *     ");
		if(line==7) fprintf(fp,"  **** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='f')
	{
		if(line==0) return 6;
		if(line==1) printf("   ** ");
		if(line==2) printf("  *   ");
		if(line==3) printf(" **** ");
		if(line==4) printf("  *   ");
		if(line==5) printf("  *   ");
		if(line==6) printf("  *   ");
		if(line==7) printf("  *   ");
		if(line==8) printf("      ");
		if(line==1) fprintf(fp,"   ** ");
		if(line==2) fprintf(fp,"  *   ");
		if(line==3) fprintf(fp," **** ");
		if(line==4) fprintf(fp,"  *   ");
		if(line==5) fprintf(fp,"  *   ");
		if(line==6) fprintf(fp,"  *   ");
		if(line==7) fprintf(fp,"  *   ");
		if(line==8) fprintf(fp,"      ");
	}
	else if(character=='g')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("  **** ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf("  **** ");
		if(line==7) printf("     * ");
		if(line==8) printf(" ****  ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"  **** ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp,"  **** ");
		if(line==7) fprintf(fp,"     * ");
		if(line==8) fprintf(fp," ****  ");
	}
	else if(character=='h')
	{
		if(line==0) return 7;
		if(line==1) printf(" *     ");
		if(line==2) printf(" *     ");
		if(line==3) printf(" * **  ");
		if(line==4) printf(" **  * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *     ");
		if(line==2) fprintf(fp," *     ");
		if(line==3) fprintf(fp," * **  ");
		if(line==4) fprintf(fp," **  * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='i')
	{
		if(line==0) return 3;
		if(line==1) printf(" * ");
		if(line==2) printf("   ");
		if(line==3) printf(" * ");
		if(line==4) printf(" * ");
		if(line==5) printf(" * ");
		if(line==6) printf(" * ");
		if(line==7) printf(" * ");
		if(line==8) printf("   ");
		if(line==1) fprintf(fp," * ");
		if(line==2) fprintf(fp,"   ");
		if(line==3) fprintf(fp," * ");
		if(line==4) fprintf(fp," * ");
		if(line==5) fprintf(fp," * ");
		if(line==6) fprintf(fp," * ");
		if(line==7) fprintf(fp," * ");
		if(line==8) fprintf(fp,"   ");
	}
	else if(character=='j')
	{
		if(line==0) return 7;
		if(line==1) printf("     * ");
		if(line==2) printf("       ");
		if(line==3) printf("     * ");
		if(line==4) printf("     * ");
		if(line==5) printf("     * ");
		if(line==6) printf("     * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("  ***  ");
		if(line==1) fprintf(fp,"     * ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"     * ");
		if(line==4) fprintf(fp,"     * ");
		if(line==5) fprintf(fp,"     * ");
		if(line==6) fprintf(fp,"     * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"  ***  ");
	}
	else if(character=='k')
	{
		if(line==0) return 7;
		if(line==1) printf(" *     ");
		if(line==2) printf(" *     ");
		if(line==3) printf(" *  ** ");
		if(line==4) printf(" * *   ");
		if(line==5) printf(" **    ");
		if(line==6) printf(" * *   ");
		if(line==7) printf(" *  ** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *     ");
		if(line==2) fprintf(fp," *     ");
		if(line==3) fprintf(fp," *  ** ");
		if(line==4) fprintf(fp," * *   ");
		if(line==5) fprintf(fp," **    ");
		if(line==6) fprintf(fp," * *   ");
		if(line==7) fprintf(fp," *  ** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='l')
	{
		if(line==0) return 5;
		if(line==1) printf(" *   ");
		if(line==2) printf(" *   ");
		if(line==3) printf(" *   ");
		if(line==4) printf(" *   ");
		if(line==5) printf(" *   ");
		if(line==6) printf(" *   ");
		if(line==7) printf("  ** ");
		if(line==8) printf("     ");
		if(line==1) fprintf(fp," *   ");
		if(line==2) fprintf(fp," *   ");
		if(line==3) fprintf(fp," *   ");
		if(line==4) fprintf(fp," *   ");
		if(line==5) fprintf(fp," *   ");
		if(line==6) fprintf(fp," *   ");
		if(line==7) fprintf(fp,"  ** ");
		if(line==8) fprintf(fp,"     ");
	}
	else if(character=='m')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" ** *  ");
		if(line==4) printf(" * * * ");
		if(line==5) printf(" * * * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," ** *  ");
		if(line==4) fprintf(fp," * * * ");
		if(line==5) fprintf(fp," * * * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='n')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" ****  ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," ****  ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='o')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("  ***  ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"  ***  ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='p')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" * **  ");
		if(line==4) printf(" **  * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" ****  ");
		if(line==7) printf(" *     ");
		if(line==8) printf(" *     ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," * **  ");
		if(line==4) fprintf(fp," **  * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," ****  ");
		if(line==7) fprintf(fp," *     ");
		if(line==8) fprintf(fp," *     ");
	}
	else if(character=='q')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("  ** * ");
		if(line==4) printf(" *  ** ");
		if(line==5) printf(" *   * ");
		if(line==6) printf("  **** ");
		if(line==7) printf("     * ");
		if(line==8) printf("     * ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"  ** * ");
		if(line==4) fprintf(fp," *  ** ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp,"  **** ");
		if(line==7) fprintf(fp,"     * ");
		if(line==8) fprintf(fp,"     * ");
	}
	else if(character=='r')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" * **  ");
		if(line==4) printf(" **  * ");
		if(line==5) printf(" *     ");
		if(line==6) printf(" *     ");
		if(line==7) printf(" *     ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," * **  ");
		if(line==4) fprintf(fp," **  * ");
		if(line==5) fprintf(fp," *     ");
		if(line==6) fprintf(fp," *     ");
		if(line==7) fprintf(fp," *     ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='s')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("  **** ");
		if(line==4) printf(" *     ");
		if(line==5) printf("  ***  ");
		if(line==6) printf("     * ");
		if(line==7) printf(" ****  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"  **** ");
		if(line==4) fprintf(fp," *     ");
		if(line==5) fprintf(fp,"  ***  ");
		if(line==6) fprintf(fp,"     * ");
		if(line==7) fprintf(fp," ****  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='t')
	{
		if(line==0) return 5;
		if(line==1) printf("  *  ");
		if(line==2) printf("  *  ");
		if(line==3) printf(" *** ");
		if(line==4) printf("  *  ");
		if(line==5) printf("  *  ");
		if(line==6) printf("  *  ");
		if(line==7) printf("   * ");
		if(line==8) printf("     ");
		if(line==1) fprintf(fp,"  *  ");
		if(line==2) fprintf(fp,"  *  ");
		if(line==3) fprintf(fp," *** ");
		if(line==4) fprintf(fp,"  *  ");
		if(line==5) fprintf(fp,"  *  ");
		if(line==6) fprintf(fp,"  *  ");
		if(line==7) fprintf(fp,"   * ");
		if(line==8) fprintf(fp,"     ");
	}
	else if(character=='u')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  **** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  **** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='v')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf("  * *  ");
		if(line==7) printf("   *   ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp,"  * *  ");
		if(line==7) fprintf(fp,"   *   ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='w')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" * * * ");
		if(line==6) printf(" * * * ");
		if(line==7) printf("  **** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," * * * ");
		if(line==6) fprintf(fp," * * * ");
		if(line==7) fprintf(fp,"  **** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='x')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" *   * ");
		if(line==4) printf("  * *  ");
		if(line==5) printf("   *   ");
		if(line==6) printf("  * *  ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp,"  * *  ");
		if(line==5) fprintf(fp,"   *   ");
		if(line==6) fprintf(fp,"  * *  ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='y')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf("  **** ");
		if(line==7) printf("     * ");
		if(line==8) printf(" ****  ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp,"  **** ");
		if(line==7) fprintf(fp,"     * ");
		if(line==8) fprintf(fp," ****  ");
	}
	else if(character=='z')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf(" ***** ");
		if(line==4) printf("    *  ");
		if(line==5) printf("   *   ");
		if(line==6) printf("  *    ");
		if(line==7) printf(" ***** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp," ***** ");
		if(line==4) fprintf(fp,"    *  ");
		if(line==5) fprintf(fp,"   *   ");
		if(line==6) fprintf(fp,"  *    ");
		if(line==7) fprintf(fp," ***** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='A')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" ***** ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," ***** ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='B')
	{
		if(line==0) return 7;
		if(line==1) printf(" ****  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" ****  ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" ****  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ****  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," ****  ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," ****  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='C')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *     ");
		if(line==4) printf(" *     ");
		if(line==5) printf(" *     ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *     ");
		if(line==4) fprintf(fp," *     ");
		if(line==5) fprintf(fp," *     ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='D')
	{
		if(line==0) return 7;
		if(line==1) printf(" ****  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" ****  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ****  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," ****  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='E')
	{
		if(line==0) return 7;
		if(line==1) printf(" ***** ");
		if(line==2) printf(" *     ");
		if(line==3) printf(" ***   ");
		if(line==4) printf(" *     ");
		if(line==5) printf(" *     ");
		if(line==6) printf(" *     ");
		if(line==7) printf(" ***** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ***** ");
		if(line==2) fprintf(fp," *     ");
		if(line==3) fprintf(fp," ***   ");
		if(line==4) fprintf(fp," *     ");
		if(line==5) fprintf(fp," *     ");
		if(line==6) fprintf(fp," *     ");
		if(line==7) fprintf(fp," ***** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='F')
	{
		if(line==0) return 7;
		if(line==1) printf(" ***** ");
		if(line==2) printf(" *     ");
		if(line==3) printf(" ***   ");
		if(line==4) printf(" *     ");
		if(line==5) printf(" *     ");
		if(line==6) printf(" *     ");
		if(line==7) printf(" *     ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ***** ");
		if(line==2) fprintf(fp," *     ");
		if(line==3) fprintf(fp," ***   ");
		if(line==4) fprintf(fp," *     ");
		if(line==5) fprintf(fp," *     ");
		if(line==6) fprintf(fp," *     ");
		if(line==7) fprintf(fp," *     ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='G')
	{
		if(line==0) return 7;
		if(line==1) printf("  **** ");
		if(line==2) printf(" *     ");
		if(line==3) printf(" *  ** ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  **** ");
		if(line==2) fprintf(fp," *     ");
		if(line==3) fprintf(fp," *  ** ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='H')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" ***** ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," ***** ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='I')
	{
		if(line==0) return 5;
		if(line==1) printf(" *** ");
		if(line==2) printf("  *  ");
		if(line==3) printf("  *  ");
		if(line==4) printf("  *  ");
		if(line==5) printf("  *  ");
		if(line==6) printf("  *  ");
		if(line==7) printf(" *** ");
		if(line==8) printf("     ");
		if(line==1) fprintf(fp," *** ");
		if(line==2) fprintf(fp,"  *  ");
		if(line==3) fprintf(fp,"  *  ");
		if(line==4) fprintf(fp,"  *  ");
		if(line==5) fprintf(fp,"  *  ");
		if(line==6) fprintf(fp,"  *  ");
		if(line==7) fprintf(fp," *** ");
		if(line==8) fprintf(fp,"     ");
	}
	else if(character=='J')
	{
		if(line==0) return 7;
		if(line==1) printf("     * ");
		if(line==2) printf("     * ");
		if(line==3) printf("     * ");
		if(line==4) printf("     * ");
		if(line==5) printf("     * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"     * ");
		if(line==2) fprintf(fp,"     * ");
		if(line==3) fprintf(fp,"     * ");
		if(line==4) fprintf(fp,"     * ");
		if(line==5) fprintf(fp,"     * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='K')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf(" *  *  ");
		if(line==3) printf(" ***   ");
		if(line==4) printf(" *  *  ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp," *  *  ");
		if(line==3) fprintf(fp," ***   ");
		if(line==4) fprintf(fp," *  *  ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='L')
	{
		if(line==0) return 7;
		if(line==1) printf(" *     ");
		if(line==2) printf(" *     ");
		if(line==3) printf(" *     ");
		if(line==4) printf(" *     ");
		if(line==5) printf(" *     ");
		if(line==6) printf(" *     ");
		if(line==7) printf(" ***** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *     ");
		if(line==2) fprintf(fp," *     ");
		if(line==3) fprintf(fp," *     ");
		if(line==4) fprintf(fp," *     ");
		if(line==5) fprintf(fp," *     ");
		if(line==6) fprintf(fp," *     ");
		if(line==7) fprintf(fp," ***** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='M')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf(" ** ** ");
		if(line==3) printf(" * * * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp," ** ** ");
		if(line==3) fprintf(fp," * * * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='N')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf(" **  * ");
		if(line==3) printf(" * * * ");
		if(line==4) printf(" *  ** ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp," **  * ");
		if(line==3) fprintf(fp," * * * ");
		if(line==4) fprintf(fp," *  ** ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='O')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='P')
	{
		if(line==0) return 7;
		if(line==1) printf(" ****  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" ****  ");
		if(line==4) printf(" *     ");
		if(line==5) printf(" *     ");
		if(line==6) printf(" *     ");
		if(line==7) printf(" *     ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ****  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," ****  ");
		if(line==4) fprintf(fp," *     ");
		if(line==5) fprintf(fp," *     ");
		if(line==6) fprintf(fp," *     ");
		if(line==7) fprintf(fp," *     ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='Q')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *  *  ");
		if(line==7) printf("  ** * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *  *  ");
		if(line==7) fprintf(fp,"  ** * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='R')
	{
		if(line==0) return 7;
		if(line==1) printf(" ****  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" ****  ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ****  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," ****  ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='S')
	{
		if(line==0) return 7;
		if(line==1) printf("  **** ");
		if(line==2) printf(" *     ");
		if(line==3) printf("  ***  ");
		if(line==4) printf("     * ");
		if(line==5) printf("     * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  **** ");
		if(line==2) fprintf(fp," *     ");
		if(line==3) fprintf(fp,"  ***  ");
		if(line==4) fprintf(fp,"     * ");
		if(line==5) fprintf(fp,"     * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='T')
	{
		if(line==0) return 7;
		if(line==1) printf(" ***** ");
		if(line==2) printf("   *   ");
		if(line==3) printf("   *   ");
		if(line==4) printf("   *   ");
		if(line==5) printf("   *   ");
		if(line==6) printf("   *   ");
		if(line==7) printf("   *   ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ***** ");
		if(line==2) fprintf(fp,"   *   ");
		if(line==3) fprintf(fp,"   *   ");
		if(line==4) fprintf(fp,"   *   ");
		if(line==5) fprintf(fp,"   *   ");
		if(line==6) fprintf(fp,"   *   ");
		if(line==7) fprintf(fp,"   *   ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='U')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='V')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf("  * *  ");
		if(line==6) printf("  * *  ");
		if(line==7) printf("   *   ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp,"  * *  ");
		if(line==6) fprintf(fp,"  * *  ");
		if(line==7) fprintf(fp,"   *   ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='W')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *   * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" * * * ");
		if(line==6) printf(" ** ** ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," * * * ");
		if(line==6) fprintf(fp," ** ** ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='X')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf("  * *  ");
		if(line==3) printf("   *   ");
		if(line==4) printf("  * *  ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp,"  * *  ");
		if(line==3) fprintf(fp,"   *   ");
		if(line==4) fprintf(fp,"  * *  ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='Y')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf("  * *  ");
		if(line==3) printf("   *   ");
		if(line==4) printf("   *   ");
		if(line==5) printf("   *   ");
		if(line==6) printf("   *   ");
		if(line==7) printf("   *   ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp,"  * *  ");
		if(line==3) fprintf(fp,"   *   ");
		if(line==4) fprintf(fp,"   *   ");
		if(line==5) fprintf(fp,"   *   ");
		if(line==6) fprintf(fp,"   *   ");
		if(line==7) fprintf(fp,"   *   ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='Z')
	{
		if(line==0) return 7;
		if(line==1) printf(" ***** ");
		if(line==2) printf("     * ");
		if(line==3) printf("    *  ");
		if(line==4) printf("   *   ");
		if(line==5) printf("  *    ");
		if(line==6) printf(" *     ");
		if(line==7) printf(" ***** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ***** ");
		if(line==2) fprintf(fp,"     * ");
		if(line==3) fprintf(fp,"    *  ");
		if(line==4) fprintf(fp,"   *   ");
		if(line==5) fprintf(fp,"  *    ");
		if(line==6) fprintf(fp," *     ");
		if(line==7) fprintf(fp," ***** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='0')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *  ** ");
		if(line==4) printf(" * * * ");
		if(line==5) printf(" **  * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *  ** ");
		if(line==4) fprintf(fp," * * * ");
		if(line==5) fprintf(fp," **  * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='1')
	{
		if(line==0) return 7;
		if(line==1) printf("   *   ");
		if(line==2) printf("  **   ");
		if(line==3) printf("   *   ");
		if(line==4) printf("   *   ");
		if(line==5) printf("   *   ");
		if(line==6) printf("   *   ");
		if(line==7) printf(" ***** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"   *   ");
		if(line==2) fprintf(fp,"  **   ");
		if(line==3) fprintf(fp,"   *   ");
		if(line==4) fprintf(fp,"   *   ");
		if(line==5) fprintf(fp,"   *   ");
		if(line==6) fprintf(fp,"   *   ");
		if(line==7) fprintf(fp," ***** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='2')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf("     * ");
		if(line==4) printf("   **  ");
		if(line==5) printf("  *    ");
		if(line==6) printf(" *   * ");
		if(line==7) printf(" ***** ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp,"     * ");
		if(line==4) fprintf(fp,"   **  ");
		if(line==5) fprintf(fp,"  *    ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp," ***** ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='3')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf("     * ");
		if(line==4) printf("   **  ");
		if(line==5) printf("     * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp,"     * ");
		if(line==4) fprintf(fp,"   **  ");
		if(line==5) fprintf(fp,"     * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='4')
	{
		if(line==0) return 7;
		if(line==1) printf("    ** ");
		if(line==2) printf("   * * ");
		if(line==3) printf("  *  * ");
		if(line==4) printf(" *   * ");
		if(line==5) printf(" ***** ");
		if(line==6) printf("     * ");
		if(line==7) printf("     * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"    ** ");
		if(line==2) fprintf(fp,"   * * ");
		if(line==3) fprintf(fp,"  *  * ");
		if(line==4) fprintf(fp," *   * ");
		if(line==5) fprintf(fp," ***** ");
		if(line==6) fprintf(fp,"     * ");
		if(line==7) fprintf(fp,"     * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='5')
	{
		if(line==0) return 7;
		if(line==1) printf(" ***** ");
		if(line==2) printf(" *     ");
		if(line==3) printf(" ****  ");
		if(line==4) printf("     * ");
		if(line==5) printf("     * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ***** ");
		if(line==2) fprintf(fp," *     ");
		if(line==3) fprintf(fp," ****  ");
		if(line==4) fprintf(fp,"     * ");
		if(line==5) fprintf(fp,"     * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='6')
	{
		if(line==0) return 7;
		if(line==1) printf("   **  ");
		if(line==2) printf("  *    ");
		if(line==3) printf(" *     ");
		if(line==4) printf(" ****  ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"   **  ");
		if(line==2) fprintf(fp,"  *    ");
		if(line==3) fprintf(fp," *     ");
		if(line==4) fprintf(fp," ****  ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='7')
	{
		if(line==0) return 7;
		if(line==1) printf(" ***** ");
		if(line==2) printf(" *   * ");
		if(line==3) printf("     * ");
		if(line==4) printf("    *  ");
		if(line==5) printf("   *   ");
		if(line==6) printf("   *   ");
		if(line==7) printf("   *   ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," ***** ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp,"     * ");
		if(line==4) fprintf(fp,"    *  ");
		if(line==5) fprintf(fp,"   *   ");
		if(line==6) fprintf(fp,"   *   ");
		if(line==7) fprintf(fp,"   *   ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='8')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *   * ");
		if(line==4) printf("  ***  ");
		if(line==5) printf(" *   * ");
		if(line==6) printf(" *   * ");
		if(line==7) printf("  ***  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp,"  ***  ");
		if(line==5) fprintf(fp," *   * ");
		if(line==6) fprintf(fp," *   * ");
		if(line==7) fprintf(fp,"  ***  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='9')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf(" *   * ");
		if(line==4) printf("  **** ");
		if(line==5) printf("     * ");
		if(line==6) printf("    *  ");
		if(line==7) printf("  **   ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp,"  **** ");
		if(line==5) fprintf(fp,"     * ");
		if(line==6) fprintf(fp,"    *  ");
		if(line==7) fprintf(fp,"  **   ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='.')
	{
		if(line==0) return 3;
		if(line==1) printf("   ");
		if(line==2) printf("   ");
		if(line==3) printf("   ");
		if(line==4) printf("   ");
		if(line==5) printf("   ");
		if(line==6) printf(" * ");
		if(line==7) printf(" * ");
		if(line==8) printf("   ");
		if(line==1) fprintf(fp,"   ");
		if(line==2) fprintf(fp,"   ");
		if(line==3) fprintf(fp,"   ");
		if(line==4) fprintf(fp,"   ");
		if(line==5) fprintf(fp,"   ");
		if(line==6) fprintf(fp," * ");
		if(line==7) fprintf(fp," * ");
		if(line==8) fprintf(fp,"   ");
	}
	else if(character==':')
	{
		if(line==0) return 3;
		if(line==1) printf("   ");
		if(line==2) printf(" * ");
		if(line==3) printf(" * ");
		if(line==4) printf("   ");
		if(line==5) printf("   ");
		if(line==6) printf(" * ");
		if(line==7) printf(" * ");
		if(line==8) printf("   ");
		if(line==1) fprintf(fp,"   ");
		if(line==2) fprintf(fp," * ");
		if(line==3) fprintf(fp," * ");
		if(line==4) fprintf(fp,"   ");
		if(line==5) fprintf(fp,"   ");
		if(line==6) fprintf(fp," * ");
		if(line==7) fprintf(fp," * ");
		if(line==8) fprintf(fp,"   ");
	}
	else if(character==',')
	{
		if(line==0) return 3;
		if(line==1) printf("   ");
		if(line==2) printf("   ");
		if(line==3) printf("   ");
		if(line==4) printf("   ");
		if(line==5) printf("   ");
		if(line==6) printf(" * ");
		if(line==7) printf(" * ");
		if(line==8) printf(" * ");
		if(line==1) fprintf(fp,"   ");
		if(line==2) fprintf(fp,"   ");
		if(line==3) fprintf(fp,"   ");
		if(line==4) fprintf(fp,"   ");
		if(line==5) fprintf(fp,"   ");
		if(line==6) fprintf(fp," * ");
		if(line==7) fprintf(fp," * ");
		if(line==8) fprintf(fp," * ");
	}
	else if(character==';')
	{
		if(line==0) return 3;
		if(line==1) printf("   ");
		if(line==2) printf(" * ");
		if(line==3) printf(" * ");
		if(line==4) printf("   ");
		if(line==5) printf("   ");
		if(line==6) printf(" * ");
		if(line==7) printf(" * ");
		if(line==8) printf(" * ");
		if(line==1) fprintf(fp,"   ");
		if(line==2) fprintf(fp," * ");
		if(line==3) fprintf(fp," * ");
		if(line==4) fprintf(fp,"   ");
		if(line==5) fprintf(fp,"   ");
		if(line==6) fprintf(fp," * ");
		if(line==7) fprintf(fp," * ");
		if(line==8) fprintf(fp," * ");
	}
	else if(character=='\'')//单引号和反斜杠需加反斜杠
	{
		if(line==0) return 4;
		if(line==1) printf("  * ");
		if(line==2) printf("  * ");
		if(line==3) printf(" *  ");
		if(line==4) printf("    ");
		if(line==5) printf("    ");
		if(line==6) printf("    ");
		if(line==7) printf("    ");
		if(line==8) printf("    ");
		if(line==1) fprintf(fp,"  * ");
		if(line==2) fprintf(fp,"  * ");
		if(line==3) fprintf(fp," *  ");
		if(line==4) fprintf(fp,"    ");
		if(line==5) fprintf(fp,"    ");
		if(line==6) fprintf(fp,"    ");
		if(line==7) fprintf(fp,"    ");
		if(line==8) fprintf(fp,"    ");
	}
	else if(character=='"')
	{
		if(line==0) return 5;
		if(line==1) printf(" * * ");
		if(line==2) printf(" * * ");
		if(line==3) printf("     ");
		if(line==4) printf("     ");
		if(line==5) printf("     ");
		if(line==6) printf("     ");
		if(line==7) printf("     ");
		if(line==8) printf("     ");
		if(line==1) fprintf(fp," * * ");
		if(line==2) fprintf(fp," * * ");
		if(line==3) fprintf(fp,"     ");
		if(line==4) fprintf(fp,"     ");
		if(line==5) fprintf(fp,"     ");
		if(line==6) fprintf(fp,"     ");
		if(line==7) fprintf(fp,"     ");
		if(line==8) fprintf(fp,"     ");
	}
	else if(character=='!')
	{
		if(line==0) return 3;
		if(line==1) printf(" * ");
		if(line==2) printf(" * ");
		if(line==3) printf(" * ");
		if(line==4) printf(" * ");
		if(line==5) printf(" * ");
		if(line==6) printf("   ");
		if(line==7) printf(" * ");
		if(line==8) printf("   ");
		if(line==1) fprintf(fp," * ");
		if(line==2) fprintf(fp," * ");
		if(line==3) fprintf(fp," * ");
		if(line==4) fprintf(fp," * ");
		if(line==5) fprintf(fp," * ");
		if(line==6) fprintf(fp,"   ");
		if(line==7) fprintf(fp," * ");
		if(line==8) fprintf(fp,"   ");
	}
	else if(character=='?')
	{
		if(line==0) return 7;
		if(line==1) printf("  ***  ");
		if(line==2) printf(" *   * ");
		if(line==3) printf("     * ");
		if(line==4) printf("    *  ");
		if(line==5) printf("   *   ");
		if(line==6) printf("       ");
		if(line==7) printf("   *   ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  ***  ");
		if(line==2) fprintf(fp," *   * ");
		if(line==3) fprintf(fp,"     * ");
		if(line==4) fprintf(fp,"    *  ");
		if(line==5) fprintf(fp,"   *   ");
		if(line==6) fprintf(fp,"       ");
		if(line==7) fprintf(fp,"   *   ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='+')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("   *   ");
		if(line==3) printf("   *   ");
		if(line==4) printf(" ***** ");
		if(line==5) printf("   *   ");
		if(line==6) printf("   *   ");
		if(line==7) printf("       ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"   *   ");
		if(line==3) fprintf(fp,"   *   ");
		if(line==4) fprintf(fp," ***** ");
		if(line==5) fprintf(fp,"   *   ");
		if(line==6) fprintf(fp,"   *   ");
		if(line==7) fprintf(fp,"       ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='-')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("       ");
		if(line==4) printf(" ***** ");
		if(line==5) printf("       ");
		if(line==6) printf("       ");
		if(line==7) printf("       ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"       ");
		if(line==4) fprintf(fp," ***** ");
		if(line==5) fprintf(fp,"       ");
		if(line==6) fprintf(fp,"       ");
		if(line==7) fprintf(fp,"       ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='*')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("   *   ");
		if(line==3) printf(" * * * ");
		if(line==4) printf("  ***  ");
		if(line==5) printf(" * * * ");
		if(line==6) printf("   *   ");
		if(line==7) printf("       ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"   *   ");
		if(line==3) fprintf(fp," * * * ");
		if(line==4) fprintf(fp,"  ***  ");
		if(line==5) fprintf(fp," * * * ");
		if(line==6) fprintf(fp,"   *   ");
		if(line==7) fprintf(fp,"       ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='/')
	{
		if(line==0) return 7;
		if(line==1) printf("     * ");
		if(line==2) printf("    *  ");
		if(line==3) printf("    *  ");
		if(line==4) printf("   *   ");
		if(line==5) printf("  *    ");
		if(line==6) printf("  *    ");
		if(line==7) printf(" *     ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"     * ");
		if(line==2) fprintf(fp,"    *  ");
		if(line==3) fprintf(fp,"    *  ");
		if(line==4) fprintf(fp,"   *   ");
		if(line==5) fprintf(fp,"  *    ");
		if(line==6) fprintf(fp,"  *    ");
		if(line==7) fprintf(fp," *     ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='%')
	{
		if(line==0) return 7;
		if(line==1) printf(" *   * ");
		if(line==2) printf(" *  *  ");
		if(line==3) printf("    *  ");
		if(line==4) printf("   *   ");
		if(line==5) printf("  *    ");
		if(line==6) printf("  *  * ");
		if(line==7) printf(" *   * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *   * ");
		if(line==2) fprintf(fp," *  *  ");
		if(line==3) fprintf(fp,"    *  ");
		if(line==4) fprintf(fp,"   *   ");
		if(line==5) fprintf(fp,"  *    ");
		if(line==6) fprintf(fp,"  *  * ");
		if(line==7) fprintf(fp," *   * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='=')
	{
		if(line==0) return 7;
		if(line==1) printf("       ");
		if(line==2) printf("       ");
		if(line==3) printf("       ");
		if(line==4) printf(" ***** ");
		if(line==5) printf("       ");
		if(line==6) printf(" ***** ");
		if(line==7) printf("       ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"       ");
		if(line==2) fprintf(fp,"       ");
		if(line==3) fprintf(fp,"       ");
		if(line==4) fprintf(fp," ***** ");
		if(line==5) fprintf(fp,"       ");
		if(line==6) fprintf(fp," ***** ");
		if(line==7) fprintf(fp,"       ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='~')
	{
		if(line==0) return 6;
		if(line==1) printf(" **  *");
		if(line==2) printf("*  ** ");
		if(line==3) printf("      ");
		if(line==4) printf("      ");
		if(line==5) printf("      ");
		if(line==6) printf("      ");
		if(line==7) printf("      ");
		if(line==8) printf("      ");
		if(line==1) fprintf(fp," **  *");
		if(line==2) fprintf(fp,"*  ** ");
		if(line==3) fprintf(fp,"      ");
		if(line==4) fprintf(fp,"      ");
		if(line==5) fprintf(fp,"      ");
		if(line==6) fprintf(fp,"      ");
		if(line==7) fprintf(fp,"      ");
		if(line==8) fprintf(fp,"      ");
	}
	else if(character=='|')
	{
		if(line==0) return 3;
		if(line==1) printf(" * ");
		if(line==2) printf(" * ");
		if(line==3) printf(" * ");
		if(line==4) printf(" * ");
		if(line==5) printf(" * ");
		if(line==6) printf(" * ");
		if(line==7) printf(" * ");
		if(line==8) printf("   ");
		if(line==1) fprintf(fp," * ");
		if(line==2) fprintf(fp," * ");
		if(line==3) fprintf(fp," * ");
		if(line==4) fprintf(fp," * ");
		if(line==5) fprintf(fp," * ");
		if(line==6) fprintf(fp," * ");
		if(line==7) fprintf(fp," * ");
		if(line==8) fprintf(fp,"   ");
	}
	else if(character=='@')
	{
		if(line==0) return 9;//最宽的字符(doge)
		if(line==1) printf("  *****  ");
		if(line==2) printf(" *     * ");
		if(line==3) printf(" * *** * ");
		if(line==4) printf(" * * * * ");
		if(line==5) printf(" * ***** ");
		if(line==6) printf(" *       ");
		if(line==7) printf("  *****  ");
		if(line==8) printf("         ");
		if(line==1) fprintf(fp,"  *****  ");
		if(line==2) fprintf(fp," *     * ");
		if(line==3) fprintf(fp," * *** * ");
		if(line==4) fprintf(fp," * * * * ");
		if(line==5) fprintf(fp," * ***** ");
		if(line==6) fprintf(fp," *       ");
		if(line==7) fprintf(fp,"  *****  ");
		if(line==8) fprintf(fp,"         ");
	}
	else if(character=='#')
	{
		if(line==0) return 7;
		if(line==1) printf("  * *  ");
		if(line==2) printf("  * *  ");
		if(line==3) printf(" ***** ");
		if(line==4) printf("  * *  ");
		if(line==5) printf(" ***** ");
		if(line==6) printf("  * *  ");
		if(line==7) printf("  * *  ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"  * *  ");
		if(line==2) fprintf(fp,"  * *  ");
		if(line==3) fprintf(fp," ***** ");
		if(line==4) fprintf(fp,"  * *  ");
		if(line==5) fprintf(fp," ***** ");
		if(line==6) fprintf(fp,"  * *  ");
		if(line==7) fprintf(fp,"  * *  ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='$')
	{
		if(line==0) return 7;
		if(line==1) printf("   *   ");
		if(line==2) printf("  **** ");
		if(line==3) printf(" *     ");
		if(line==4) printf("  ***  ");
		if(line==5) printf("     * ");
		if(line==6) printf(" ****  ");
		if(line==7) printf("   *   ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"   *   ");
		if(line==2) fprintf(fp,"  **** ");
		if(line==3) fprintf(fp," *     ");
		if(line==4) fprintf(fp,"  ***  ");
		if(line==5) fprintf(fp,"     * ");
		if(line==6) fprintf(fp," ****  ");
		if(line==7) fprintf(fp,"   *   ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='_')
	{
		if(line==0) return 5;
		if(line==1) printf("     ");
		if(line==2) printf("     ");
		if(line==3) printf("     ");
		if(line==4) printf("     ");
		if(line==5) printf("     ");
		if(line==6) printf("     ");
		if(line==7) printf("     ");
		if(line==8) printf("*****");
		if(line==1) fprintf(fp,"     ");
		if(line==2) fprintf(fp,"     ");
		if(line==3) fprintf(fp,"     ");
		if(line==4) fprintf(fp,"     ");
		if(line==5) fprintf(fp,"     ");
		if(line==6) fprintf(fp,"     ");
		if(line==7) fprintf(fp,"     ");
		if(line==8) fprintf(fp,"*****");
	}
	else if(character=='^')
	{
		if(line==0) return 7;
		if(line==1) printf("   *   ");
		if(line==2) printf("  * *  ");
		if(line==3) printf(" *   * ");
		if(line==4) printf("       ");
		if(line==5) printf("       ");
		if(line==6) printf("       ");
		if(line==7) printf("       ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"   *   ");
		if(line==2) fprintf(fp,"  * *  ");
		if(line==3) fprintf(fp," *   * ");
		if(line==4) fprintf(fp,"       ");
		if(line==5) fprintf(fp,"       ");
		if(line==6) fprintf(fp,"       ");
		if(line==7) fprintf(fp,"       ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='\\')//单引号和反斜杠需加反斜杠
	{
		if(line==0) return 7;
		if(line==1) printf(" *     ");
		if(line==2) printf("  *    ");
		if(line==3) printf("  *    ");
		if(line==4) printf("   *   ");
		if(line==5) printf("    *  ");
		if(line==6) printf("    *  ");
		if(line==7) printf("     * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp," *     ");
		if(line==2) fprintf(fp,"  *    ");
		if(line==3) fprintf(fp,"  *    ");
		if(line==4) fprintf(fp,"   *   ");
		if(line==5) fprintf(fp,"    *  ");
		if(line==6) fprintf(fp,"    *  ");
		if(line==7) fprintf(fp,"     * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='&')
	{
		if(line==0) return 7;
		if(line==1) printf("   *   ");
		if(line==2) printf("  * *  ");
		if(line==3) printf("   *   ");
		if(line==4) printf("  ** * ");
		if(line==5) printf(" * **  ");
		if(line==6) printf(" *  *  ");
		if(line==7) printf("  ** * ");
		if(line==8) printf("       ");
		if(line==1) fprintf(fp,"   *   ");
		if(line==2) fprintf(fp,"  * *  ");
		if(line==3) fprintf(fp,"   *   ");
		if(line==4) fprintf(fp,"  ** * ");
		if(line==5) fprintf(fp," * **  ");
		if(line==6) fprintf(fp," *  *  ");
		if(line==7) fprintf(fp,"  ** * ");
		if(line==8) fprintf(fp,"       ");
	}
	else if(character=='<')
	{
		if(line==0) return 6;
		if(line==1) printf("    * ");
		if(line==2) printf("   *  ");
		if(line==3) printf("  *   ");
		if(line==4) printf(" *    ");
		if(line==5) printf("  *   ");
		if(line==6) printf("   *  ");
		if(line==7) printf("    * ");
		if(line==8) printf("      ");
		if(line==1) fprintf(fp,"    * ");
		if(line==2) fprintf(fp,"   *  ");
		if(line==3) fprintf(fp,"  *   ");
		if(line==4) fprintf(fp," *    ");
		if(line==5) fprintf(fp,"  *   ");
		if(line==6) fprintf(fp,"   *  ");
		if(line==7) fprintf(fp,"    * ");
		if(line==8) fprintf(fp,"      ");
	}
	else if(character=='>')
	{
		if(line==0) return 6;
		if(line==1) printf(" *    ");
		if(line==2) printf("  *   ");
		if(line==3) printf("   *  ");
		if(line==4) printf("    * ");
		if(line==5) printf("   *  ");
		if(line==6) printf("  *   ");
		if(line==7) printf(" *    ");
		if(line==8) printf("      ");
		if(line==1) fprintf(fp," *    ");
		if(line==2) fprintf(fp,"  *   ");
		if(line==3) fprintf(fp,"   *  ");
		if(line==4) fprintf(fp,"    * ");
		if(line==5) fprintf(fp,"   *  ");
		if(line==6) fprintf(fp,"  *   ");
		if(line==7) fprintf(fp," *    ");
		if(line==8) fprintf(fp,"      ");
	}
	else if(character=='(')//括号
	{
		if(line==0) return 6;
		if(line==1) printf("   ** ");
		if(line==2) printf("  *   ");
		if(line==3) printf(" *    ");
		if(line==4) printf(" *    ");
		if(line==5) printf(" *    ");
		if(line==6) printf("  *   ");
		if(line==7) printf("   ** ");
		if(line==8) printf("      ");
		if(line==1) fprintf(fp,"   ** ");
		if(line==2) fprintf(fp,"  *   ");
		if(line==3) fprintf(fp," *    ");
		if(line==4) fprintf(fp," *    ");
		if(line==5) fprintf(fp," *    ");
		if(line==6) fprintf(fp,"  *   ");
		if(line==7) fprintf(fp,"   ** ");
		if(line==8) fprintf(fp,"      ");
	}
	else if(character==')')//括回
	{
		if(line==0) return 6;
		if(line==1) printf(" **   ");
		if(line==2) printf("   *  ");
		if(line==3) printf("    * ");
		if(line==4) printf("    * ");
		if(line==5) printf("    * ");
		if(line==6) printf("   *  ");
		if(line==7) printf(" **   ");
		if(line==8) printf("      ");
		if(line==1) fprintf(fp," **   ");
		if(line==2) fprintf(fp,"   *  ");
		if(line==3) fprintf(fp,"    * ");
		if(line==4) fprintf(fp,"    * ");
		if(line==5) fprintf(fp,"    * ");
		if(line==6) fprintf(fp,"   *  ");
		if(line==7) fprintf(fp," **   ");
		if(line==8) fprintf(fp,"      ");
	}
	else if(character=='[')
	{
		if(line==0) return 5;
		if(line==1) printf(" *** ");
		if(line==2) printf(" *   ");
		if(line==3) printf(" *   ");
		if(line==4) printf(" *   ");
		if(line==5) printf(" *   ");
		if(line==6) printf(" *   ");
		if(line==7) printf(" *** ");
		if(line==8) printf("     ");
		if(line==1) fprintf(fp," *** ");
		if(line==2) fprintf(fp," *   ");
		if(line==3) fprintf(fp," *   ");
		if(line==4) fprintf(fp," *   ");
		if(line==5) fprintf(fp," *   ");
		if(line==6) fprintf(fp," *   ");
		if(line==7) fprintf(fp," *** ");
		if(line==8) fprintf(fp,"     ");
	}
	else if(character==']')
	{
		if(line==0) return 5;
		if(line==1) printf(" *** ");
		if(line==2) printf("   * ");
		if(line==3) printf("   * ");
		if(line==4) printf("   * ");
		if(line==5) printf("   * ");
		if(line==6) printf("   * ");
		if(line==7) printf(" *** ");
		if(line==8) printf("     ");
		if(line==1) fprintf(fp," *** ");
		if(line==2) fprintf(fp,"   * ");
		if(line==3) fprintf(fp,"   * ");
		if(line==4) fprintf(fp,"   * ");
		if(line==5) fprintf(fp,"   * ");
		if(line==6) fprintf(fp,"   * ");
		if(line==7) fprintf(fp," *** ");
		if(line==8) fprintf(fp,"     ");
	}
	else if(character=='{')
	{
		if(line==0) return 6;
		if(line==1) printf("   ** ");
		if(line==2) printf("  *   ");
		if(line==3) printf("  *   ");
		if(line==4) printf(" *    ");
		if(line==5) printf("  *   ");
		if(line==6) printf("  *   ");
		if(line==7) printf("   ** ");
		if(line==8) printf("      ");
		if(line==1) fprintf(fp,"   ** ");
		if(line==2) fprintf(fp,"  *   ");
		if(line==3) fprintf(fp,"  *   ");
		if(line==4) fprintf(fp," *    ");
		if(line==5) fprintf(fp,"  *   ");
		if(line==6) fprintf(fp,"  *   ");
		if(line==7) fprintf(fp,"   ** ");
		if(line==8) fprintf(fp,"      ");
	}
	else if(character=='}')
	{
		if(line==0) return 6;
		if(line==1) printf(" **   ");
		if(line==2) printf("   *  ");
		if(line==3) printf("   *  ");
		if(line==4) printf("    * ");
		if(line==5) printf("   *  ");
		if(line==6) printf("   *  ");
		if(line==7) printf(" **   ");
		if(line==8) printf("      ");
		if(line==1) fprintf(fp," **   ");
		if(line==2) fprintf(fp,"   *  ");
		if(line==3) fprintf(fp,"   *  ");
		if(line==4) fprintf(fp,"    * ");
		if(line==5) fprintf(fp,"   *  ");
		if(line==6) fprintf(fp,"   *  ");
		if(line==7) fprintf(fp," **   ");
		if(line==8) fprintf(fp,"      ");
	}
	else if(character=='\n')//每行读到回车换行
	{
		if(line==0) return 1;//实测回车会占1格
		printf("\n");
		fprintf(fp,"\n");
	}
	else
	{
		if(line==0) return 0;//其他字符不输出
		printf("暂不支持该字符！");
	}
	fclose(fp);
	return 0;//line!=0时绘制并结束
}
void Error()//指令错误时启动(doge)
{
	int i;
	printf(":(\n"
		"你的设备遇到问题，需要重启。\n"
		"我们只收集某些错误信息，然后你可以重新启动。\n\n");
	for(i=0;i<=4;i++)
	{
		printf("\r%3d%% 完成", i*25);
		sleep(1);
	}
	printf("\n");
	system("cls");
	main();
}
/*-------------------------------------------
更新日志：
Character Painter - Continue Edition
——新增 连续读入功能
Character Painter Duo
——优化 字体宽度和位置
Character Painter File
——新增 输出文件功能
——优化 字符显示函数
Character Painter Line
——新增 字符横向输出
Character Painter Line - Break
——新增 tab输出
——修复 夹杂输入`绘制残片，现在立即退出而不绘制
Character Painter R
——新增 只输入`立即退出，夹杂输入`绘制其前面内容
——优化 正式放弃ANSI编码选择UTF-8编码
——优化 代码在各编辑器下表现
Character Painter Return Alpha
——新增 字符串过长自动换行
Character Painter Return Beta
——优化 自动换行适应各种宽度字符
Character Painter Return Delta
——优化 自动换行加入宽度预测算法，可在下一字符较窄时自动挤入上一行
Character Painter Rf
——优化 以stdlib.h代替windows.h优化程序体积
——修复 f字体偏短
Character Painter Rs
//——新增 指令/clear清屏并清空文件
——优化 删除旧代码中文注释末尾空格
——修复 未知字符影响正常字符显示
Character Painter Rt
——优化 不再生成temp.txt
Character Painter Set
——新增 指令`/clear清屏并清空文件
——新增 指令`/set screenLength [int]设置屏幕长度
——优化 删除代码中无效部分
Character Painter Str
——优化 基于字符串数组和指针简化代码
-------------------------------------------*/
