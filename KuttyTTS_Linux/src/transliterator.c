#include"my_flite_hts.h"
/* if possible move this to header file */
wchar_t utf8[150][10] = {L"!", L"@", L"\"", L"#", L"%", L"'", L"(", L")", L"*", L"+", L",", L"-", L"_", L".", L"/", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L";", L"அ", L"ஆ", L"இ", L"ஈ", L"உ", L"ஊ", L"எ", L"ஏ", L"ஐ", L"ஒ", L"ஓ", L"ஔ", L"க", L"க்", L"ங", L"ங்", L"ச", L"ச்", L"ஜ", L"ஜ்", L"ஞ", L"ஞ்", L"ட", L"ட்", L"த", L"த்", L"ந", L"ந்", L"ண", L"ண்", L"ன", L"ன்", L"ப", L"ப்", L"ம", L"ம்", L"ய", L"ய்", L"ர", L"ர்", L"ற", L"ற்", L"ல", L"ல்", L"ள", L"ள்", L"ழ", L"ழ்", L"வ", L"வ்", L"ஷ", L"ஷ்", L"ஸ", L"ஸ்", L"ஹ", L"ஹ்", L"ஃப", L"ஃப்", L"ா", L"ி", L"ீ", L"ு", L"ூ", L"ெ", L"ே", L"ை", L"ொ", L"ோ", L"ௌ", L"a", L"b", L"c", L"d", L"e", L"f", L"g", L"h", L"i", L"j", L"k", L"l", L"m", L"n", L"o", L"p", L"q", L"r", L"s", L"t", L"u", L"v", L"w", L"x", L"y", L"z", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z"};
wchar_t utf8_map[150][10] = {L"!", L"@", L"\"", L"#", L"%", L"'", L"(", L")", L"*", L"+", L",", L"-", L"_", L".", L"/", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L";", L"a", L"aa", L"i", L"ii", L"u", L"uu", L"e", L"ee", L"ai", L"o", L"oo", L"au", L"k", L"k", L"ng", L"ng", L"c", L"c", L"j", L"j", L"nj", L"nj", L"tx", L"tx", L"t", L"t", L"nd", L"nd", L"nx", L"nx", L"n", L"n", L"p", L"p", L"m", L"m", L"y", L"y", L"r", L"r", L"rx", L"rx", L"l", L"l", L"lx", L"lx", L"zh", L"zh", L"w", L"w", L"sx", L"sx", L"s", L"s", L"h", L"h", L"f", L"f", L"aa", L"i", L"ii", L"u", L"uu", L"e", L"ee", L"ai", L"o", L"oo", L"au", L"a", L"b", L"c", L"d", L"e", L"f", L"g", L"h", L"i", L"j", L"k", L"l", L"m", L"n", L"o", L"p", L"q", L"r", L"s", L"t", L"u", L"v", L"w", L"x", L"y", L"z", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z"};
wchar_t d_v[11];
wchar_t vowels[13];	
/***********************************************************/
/*int is_d_v(wchar_t character, wchar_t *d_v, int num_d_v)
{
	int i;
	for(i = 0; i<num_d_v; i++)
	{
		if(character == d_v[i])
		{
			return 1;
		}
	}
	return 0;
}
int is_non_printable(wchar_t character)
{
	if( (character == L'\n') || (character == L'\r') || (character == L'\t') || (character == L' ') )
	{
		return 1;
	}
	return 0;
}
wchar_t* transliterate(wchar_t *token)
{
	int i;
	for(i=0; i<147; i++)
	{
		if(wcsncmp(token,utf8[i],wcslen(token)) == 0)
		{
			return utf8_map[i];
		}
	}
	return NULL;
}
void trans_tamil(cst_string *in,cst_string **buffer)
{
	//store dpendent vowel signs and virama
	d_v[0] = L'\u0BBE';
	d_v[1] = L'\u0BBF';
	d_v[2] = L'\u0BC0';
	d_v[3] = L'\u0BC1';
	d_v[4] = L'\u0BC2';
	d_v[5] = L'\u0BC6';
	d_v[6] = L'\u0BC7';
	d_v[7] = L'\u0BC8';
	d_v[8] = L'\u0BCA';
	d_v[9] = L'\u0BCB';
	d_v[10] = L'\u0BCC';
	//d_v[11] = L'\u0BCD';
	//Storing Vowels
	vowels[0] = L'\u0B85';
	vowels[1] = L'\u0B86';
	vowels[2] = L'\u0B87';
	vowels[3] = L'\u0B88';
	vowels[4] = L'\u0B89';
	vowels[5] = L'\u0B8A';
	vowels[6] = L'\u0B8E';
	vowels[7] = L'\u0B8F';
	vowels[8] = L'\u0B90';
	vowels[9] = L'\u0B92';
	vowels[10] = L'\u0B93';
	vowels[11] = L'\u0B94';
	vowels[12] = L'\u0B83';
	wchar_t *wsin;
	char *temp;
	size_t mbslen;
	size_t wcslength;
	wchar_t character;
	wchar_t character_next;
	wchar_t token[3];
	wchar_t character_previous;
	wchar_t *character_transliterated;
	wchar_t *word_trans;
	//word_trans=(wchar_t *) malloc(sizeof(wchar_t) * 1000);
	word_trans = calloc(1000,sizeof(wchar_t));
	temp=(char *) malloc(sizeof(char) * 1000);
	int i;
	int j;
	//word_trans[0] = L'\0';
	if (setlocale(LC_ALL,"") == NULL) 
	{
		perror("setlocale");
		exit(EXIT_FAILURE);
	}
	mbslen = mbstowcs(NULL,in, 0);
	wsin = calloc(mbslen + 1, sizeof(wchar_t));
	mbstowcs(wsin, in, mbslen + 1);
	printf("\nWide character string is: %ls (%d characters)\n",wsin, wcslen(wsin));
	j = 0;
	//word_trans = wcscat(word_trans,L"a");
	for(i=0;i<wcslen(wsin);i++)
	{
		character = wsin[i];
		character_next = wsin[i+1];
		//printf("%lc\n",character);
		if(is_d_v(character, vowels, 13))
		{
			//printf("\nVowel");
			if(character == L'\u0B83' && character_next == L'\u0BAA')
			{
				wmemset(token,L'\0',2);
				token[0] = character;
				i++;
				character_transliterated = transliterate(token);
				if(character_transliterated != NULL)
				{
					printf("%ls\n",character_transliterated);
					word_trans = wcscat(word_trans,character_transliterated);
					word_trans = wcscat(word_trans,L"*");
				}
			}
			else
			{
				wmemset(token,L'\0',2);
				token[0] = character;
				character_transliterated = transliterate(token);
				if(character_transliterated != NULL)
				{
					printf("%ls\n",character_transliterated);
					word_trans = wcscat(word_trans,character_transliterated);
					word_trans = wcscat(word_trans,L"*");
				}
			}
		}
		else
		{
			if(character_next == L'\u0BCD')
			{
				wmemset(token,L'\0',3);
				token[0]=character;
				token[1]=character_next;
				i++;
				character_transliterated = transliterate(token);
				if(character_transliterated != NULL)
				{
					printf("%ls\n",character_transliterated);
					word_trans = wcscat(word_trans,character_transliterated);
					word_trans = wcscat(word_trans,L"*");
				}
			}
			else if(is_d_v(character, d_v, 11))
			{
				wmemset(token,L'\0',2);
				token[0]=character;
				character_transliterated = transliterate(token);
				if(character_transliterated != NULL)
				{
					printf("%ls\n",character_transliterated);
					word_trans = wcscat(word_trans,character_transliterated);
					word_trans = wcscat(word_trans,L"*");
				}
			}
			else if(!is_d_v(character_next, d_v, 11))
			{
				wmemset(token,L'\0',2);
				token[0] = character;				
				character_transliterated = transliterate(token);
				if(character_transliterated != NULL)
				{
					
					if(wcsncmp(token,character_transliterated,wcslen(token)) == 0)
                                   	{
                                        	printf("%ls\n",character_transliterated);
                                        	word_trans = wcscat(word_trans,character_transliterated);
                                        	word_trans = wcscat(word_trans,L"*");
					}
                                   	else
					{			
						printf("%lsa\n",character_transliterated);
						word_trans = wcscat(word_trans,character_transliterated);
						word_trans = wcscat(word_trans,L"*");
						word_trans = wcscat(word_trans,L"a");
						word_trans = wcscat(word_trans,L"*");
					}
				}
				
			}
			else if(is_d_v(character_next, d_v, 11))
			{
				wmemset(token,L'\0',2);
				token[0]=character;
				character_transliterated = transliterate(token);
				if(character_transliterated != NULL)
				{
					printf("%ls\n",character_transliterated);
					word_trans = wcscat(word_trans,character_transliterated);
					word_trans = wcscat(word_trans,L"*");
				}
			}
		}
	}
	printf("\n-->Trans :%ls:<--\n",word_trans);
	wcstombs(temp, word_trans,wcslen(word_trans)+1);
	strcpy(*buffer,temp);
	printf("\n-->In Trans buffer :%s:<--\n",*buffer);
	free(word_trans);
	free(temp);
}

int reverse_phn(cst_string*in, cst_string ***phones)
{
	printf("\nIn reverse phn %s",in);
	int i=0,total = 0;
	char *p;
	char *q;
	p = strtok (in,"*");
	while (p != NULL)
  	{
    		printf ("\n<%s>\n", p);
    		strcpy(*phones[i],p);
    		p = strtok (NULL, "*");
    		i++;
  	}
  	total = i;
  	return total;
}
*/
/****************************************************************************/



void trans_tamil_unicode(cst_string *input,cst_string **buffer)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	int temp1 = 0;
	int utf16 = 0;
	int map_count = 108;
	int utf16_array[150] = {2949, 2950, 2951, 2952, 2953, 2954, 2958, 2959, 2960, 2962, 2963, 2964, 2965, 2969, 2970, 2972, 2974, 2975, 2979, 2980, 2984, 2985, 2986, 2990, 2991, 2992, 2993, 2994, 2995, 2996, 2997, 2999, 3000, 3001, 3006, 3007, 3008, 3009, 3010, 3014, 3015, 3016, 3018, 3019, 3020, 2947/**/, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122 /**/, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90/**/, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57/**/};
	char utf8_map[150][30] = {"a", "aa", "i", "ii", "u", "uu", "e", "ee", "ai", "o", "oo", "au", "k", "ng", "c", "j", "nj", "tx", "nx", "t", "nd", "n", "p", "m", "y", "r", "rx", "l", "lx", "zh", "w", "sx", "s", "h", "aa", "i", "ii", "u", "uu", "e", "ee", "ai", "o", "oo", "au", "g"/**/, "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"/**/, "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"/**/, "p*uu*j*j*i*y*a*m*", "o*n*rx*eu*", "i*r*a*nx*dx*eu*", "m*uu*n*rx*eu*", "nd*aa*n*k*eu*", "ai*nd*d*eu*", "aa*rx*eu*", "ee*zh*eu*", "e*tx*tx*eu*", "o*n*b*a*d*eu*"/**/};
	int dv[11] = {3006, 3007, 3008, 3009, 3010, 3014, 3015, 3016, 3018, 3019, 3020};
	int vowel[13] ={2949, 2950, 2951, 2952, 2953, 2954, 2958, 2959, 2960, 2962, 2963, 2964, 2947};
	int cons[22] = {2965, 2969, 2970, 2972, 2974, 2975, 2979, 2980, 2984, 2985, 2986, 2990, 2991, 2992, 2993, 2994, 2995, 2996, 2997, 2999, 3000, 3001};
	int utf16_input[strlen(input)+1];
	int current = 0;
	int next = 0;
	cst_string *word_trans;
	word_trans = (char*) calloc(1024,sizeof(char) );
	for(i=0;i<strlen(input);)
	{
		//printf("%d\n",(unsigned char)input[i]);
		temp1 = numberOfBytesInChar((unsigned char)input[i]);
		temp = i;
		//printf("\nnum of bytes %d\n",temp1);
		if(temp1 == 3)
		{
			utf16_input[j++] = utf8toutf16((unsigned char)input[i],(unsigned char)input[i+1],(unsigned char)input[i+2]);
			//printf("%c%c%c",input[i],input[i+1],input[i+2]);
			i++;
			i++;
			i++;
			printf(" %d\n",utf16_input[j-1]);
		}
		else if(temp1 == 1)
		{
			//printf("%c",input[i]);
			utf16_input[j++] = input[i];
			printf(" %d\n",utf16_input[j-1]);
			i++;
		}
	}
	for(i=0;i<j;i++)
	{
		current = utf16_input[i];
		next = utf16_input[i+1];
		//printf("\n%d %d",current,next);
		if(current <=122 )
		{
			temp = indexof(utf16_array,current,map_count);
			if(temp!=-1)
			{
			//	printf("%s",utf8_map[temp]);
				strcat(word_trans,utf8_map[temp]);
			}
			else
			{
				printf("\nspecial characters\n");
			}
		}
		else if(indexof(vowel,current,13)!=-1)
		{
			if(current == 2947 && next == 2986)
			{
				//printf("%s","f");
				strcat(word_trans,"f");
				strcat(word_trans,"*");
				i++;
			}
			else
			{
				temp = indexof(utf16_array,current,map_count);
				if(temp!=-1)
				{
				//	printf("%s",utf8_map[temp]);
					strcat(word_trans,utf8_map[temp]);
					strcat(word_trans,"*");
				}
			}
		}
		else
		{
			if(next == 3021)
			{
				temp = indexof(utf16_array,current,map_count);
				if(temp!=-1)
				{
				//	printf("%s",utf8_map[temp]);
					strcat(word_trans,utf8_map[temp]);
					strcat(word_trans,"*");
				}
				i++;
			}
			else if(indexof(dv,current,11)!=-1)
			{
				//temp = indexof(dv,current,11);
				//printf("\nTemp %d",temp);
				temp = indexof(utf16_array,current,map_count);
				if(temp!=-1)
				{
				//	printf("%s",utf8_map[temp]);
					strcat(word_trans,utf8_map[temp]);
					strcat(word_trans,"*");
				}
			}
			else if(indexof(dv,next,11)==-1)
			{
				if(indexof(cons,current,22)!=-1)
				{
					temp = indexof(utf16_array,current,map_count);
					if(temp!=-1)
					{
				//		printf("<%sa>",utf8_map[temp]);
						strcat(word_trans,utf8_map[temp]);
						strcat(word_trans,"*");
						strcat(word_trans,"a");
						strcat(word_trans,"*");
					}
				}
				else
				{
					printf("\ny i am here?\n");
					temp = indexof(utf16_array,current,map_count);
					if(temp!=-1)
					{
				//		printf("<%sa>",utf8_map[temp]);
						strcat(word_trans,utf8_map[temp]);
						strcat(word_trans,"*");
					}
				}
			}
			else if(indexof(dv,next,11)!=-1)
			{
				temp = indexof(utf16_array,current,map_count);
				if(temp!=-1)
				{
				//	printf("%s",utf8_map[temp]);
					strcat(word_trans,utf8_map[temp]);
					strcat(word_trans,"*");
				}
				//i++;
			}
			else
			{
				printf("<Else %c>",current);
				strcat(word_trans,current);
				strcat(word_trans,"*");
			}
		}
		
	}
	printf("\nWord_trans %s",word_trans);
	strcpy(*buffer,word_trans);
}
int indexof(int array[], int input_char,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		//printf("\nArray %d",array[i]);
		if(input_char == array[i])
		{
			//printf("\nReturning %d",i);
			return i;
		}
	}
	return -1;
}
int utf8toutf16(int z, int y, int x) 
{
	int unicode=0;
	unicode = (z-224)*4096 + (y-128)*64 + (x-128);
	return unicode;
}
int numberOfBytesInChar(unsigned char val) 
{
    if (val < 128) 
    {
        return 1;
    } 
    else if (val <= 224) 
    {
        return 3;	//i changed to 3 from 2
    } 
    else if (val < 240) 
    {
        return 3;
    } 
    else 
    {
        return 4;
    }
}


int is_true(char vowels[][20],char search[], int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		if(strcmp(vowels[i],search) == 0)
		{
			//printf("\n%s %s",vowels[i],search);
			return 1;
		}
	}
	return 0;
}


void tamil_lts(cst_string *input, cst_string **buffer)
{
	printf("\n//////////////////////////////////////////////////\n");
	printf("\nInput is %s\n",input);
	int i = 0;
	int phn_cnt = 0;
	int prev = 0;
	int next = 0;
	char content[1000][1000]={};
	char *split;
	//char cons[23][20] = {"k", "ng", "c", "j", "nj", "tx", "nx", "t", "n", "nd", "p", "m", "y", "r", "l", "lx", "w", "sx", "s", "h", "f", "rx", "zh"};
	char vowels[13][20] = {"a", "aa", "i", "ii", "u", "eu", "uu", "e", "ee", "ai", "o", "oo", "au"};
	split = strtok(input,"*");
	while (split != NULL)
	{
		//printf ("\n<%s>\n", split);
		strcpy(content[i++],split);
		split = strtok(NULL, "*");
	}
	phn_cnt = i;
	printf("\nPhn_cnt value %d",phn_cnt);
	if(strcmp(content[0],"c") == 0)
	{
		strcpy(content[0],"s");
	}
	for(i=0;i<phn_cnt+5;i++)
	{
		printf("<%s>",content[i]);
	}
	for(i=1;i<phn_cnt;i++)
	{
		//printf("\n%s",content[i]);
		prev = is_true(vowels,content[i-1],13);
		next = is_true(vowels,content[i+1],13);
		if(prev == 1 && next == 1)
		{
			if(strcmp(content[i],"k") == 0)
			{
				strcpy(content[i],"g");
			}
			else if(strcmp(content[i],"p") == 0)
			{
				printf("\nP becomes B %d %d <%s> <%s>\n",prev,next,content[i-1],content[i+1]);
				strcpy(content[i],"b");
			}
			else if(strcmp(content[i],"t") == 0)
			{
				strcpy(content[i],"d");
			}
			else if(strcmp(content[i],"tx") == 0)
			{
				strcpy(content[i],"dx");
			}
		}
		else if(strcmp(content[i-1],"ng") == 0)
		{
			if(strcmp(content[i],"k") == 0)
			{
				strcpy(content[i],"g");
			}
			else if(strcmp(content[i],"p") == 0)
			{
				strcpy(content[i],"b");
			}
			else if(strcmp(content[i],"t") == 0)
			{
				strcpy(content[i],"d");
			}
			else if(strcmp(content[i],"tx") == 0)
			{
				strcpy(content[i],"dx");
			}
		}
		else if(strcmp(content[i-1],"m") == 0)
		{
			if(strcmp(content[i],"k") == 0)
			{
				strcpy(content[i],"g");
			}
			else if(strcmp(content[i],"p") == 0)
			{
				strcpy(content[i],"b");
			}
			else if(strcmp(content[i],"t") == 0)
			{
				strcpy(content[i],"d");
			}
			else if(strcmp(content[i],"tx") == 0)
			{
				strcpy(content[i],"dx");
			}
		}
		else if(strcmp(content[i-1],"nx") == 0)
		{
			if(strcmp(content[i],"k") == 0)
			{
				strcpy(content[i],"g");
			}
			else if(strcmp(content[i],"p") == 0)
			{
				strcpy(content[i],"b");
			}
			else if(strcmp(content[i],"t") == 0)
			{
				strcpy(content[i],"d");
			}
			else if(strcmp(content[i],"tx") == 0)
			{
				strcpy(content[i],"dx");
			}
		}
		else if(strcmp(content[i-1],"nd") == 0)
		{
			if(strcmp(content[i],"k") == 0)
			{
				strcpy(content[i],"g");
			}
			else if(strcmp(content[i],"p") == 0)
			{
				strcpy(content[i],"b");
			}
			else if(strcmp(content[i],"t") == 0)
			{
				strcpy(content[i],"d");
			}
			else if(strcmp(content[i],"tx") == 0)
			{
				strcpy(content[i],"dx");
			}
		}
		else if(strcmp(content[i-1],"y") == 0 || strcmp(content[i-1],"r") == 0 || strcmp(content[i-1],"l") == 0 || strcmp(content[i-1],"w") == 0 || strcmp(content[i-1],"zh") == 0)
		{
			if(strcmp(content[i],"k") == 0)
			{
				strcpy(content[i],"g");
			}
			else if(strcmp(content[i],"t") == 0)
			{
				strcpy(content[i],"d");
			}
			else if(strcmp(content[i],"tx") == 0)
			{
				strcpy(content[i],"dx");
			}
		}
		else if(strcmp(content[i-1],"nj") == 0)
		{
			if(strcmp(content[i],"c") == 0)
			{
				strcpy(content[i],"j");
			}
		}
		else if(strcmp(content[i],"k") == 0 && strcmp(content[i+1],"k") == 0)
		{
			if(strcmp(content[i-1],"u") == 0)
			{
				if(i > 2)
				{
					strcpy(content[i-1],"eu");
				}
			}
		}
	}
	if(strcmp(content[phn_cnt-1],"u") == 0)
	{
		strcpy(content[phn_cnt-1],"eu");
	}
	else if(strcmp(content[phn_cnt-1],"k") == 0 || strcmp(content[phn_cnt-1],"p") == 0 || strcmp(content[phn_cnt-1],"t") == 0 || strcmp(content[phn_cnt-1],"c") == 0)
	{
		if(strcmp(content[phn_cnt-2],"u") == 0)
		{
			strcpy(content[phn_cnt-2],"eu");
		}
	}
	for(i=0;i<phn_cnt;i++)
	{
		//printf("\n<%s>",content[i]);
		strcat(*buffer,content[i]);
		strcat(*buffer,"*");
	}
	printf("\n//////////////////////////////////////////////////\n");
}