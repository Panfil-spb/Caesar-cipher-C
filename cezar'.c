#include <stdio.h>
#define LEN 10000
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
int main()
{
  setlocale(LC_ALL, "RUSSIAN");
  srand(time(NULL));
  int an, i, error, key1, key2, len, max = 0, maxi;
  char s[LEN], text[LEN];
  int num[26];
  FILE *f;
  for(i = 0; i < 26; i++) num[i] = 0;
  do
  {
  	printf("1.Зашифровка\n2.Расшифровка\n3.Выйти\n");
  	do
  	{
  		printf("\nВаш выбор: ");
  		error = scanf("%d", &an);
  		if(error != 1) printf("\n!!!Ошибка ввода!!!\n");
  		fflush(stdin);
    }while(error != 1);
  	if(an != 1 && an != 2 && an != 3)
  	{
  		printf("\nТаких номеров нет!\n\n");
	}
  	if(an == 1)
  	{
  		system("cls");
  		printf("Зашифровано\n\n");
  		f = fopen("text.txt", "r");
  		for(i = 0; (s[i] = getc(f)) != EOF; i++);
  		fclose(f);
  		key1 = rand() % 26 + 1;
  		f = fopen("shifr.txt", "w");
  		s[i] = '\0';
  		len = strlen(s);
  		for(i = 0; i < len; i++)
  		{
  			if(s[i] == ' ')
  			{
  				fprintf(f, " ");
  				continue;
			}
			if(ispunct(s[i]))
			{
				fprintf(f, "%c", s[i]);
				continue;
			}
    		fprintf(f, "%c", (tolower(s[i]) - 'a' + key1) % 26 +'a');
  		}
  		fclose(f);
  	}
  	if(an == 2)
  	{
  		system("cls");
  		printf("Расшифровано\n\n");
  		f = fopen("shifr.txt", "r");
  		for(i = 0; (s[i] = getc(f)) != EOF; i++)
  		{
  			if(isalpha(s[i]) != 0) num[s[i] - 'a']++;	
		}
		
		for(i = 0; i < 26; i++)
		{
			if(num[i] > max)
			{
				max = num[i];
				maxi = i;
			}
		}
		key2 = maxi + 'a' - 'e';
		for(i = 0; s[i] != '\0'; i++)
  		{
  			if(isalpha(s[i]) != 0) 
			{
				s[i] = (s[i] - 'a' - key2 + 26) % 26 + 'a';
			}	
		}
		s[i] = '\0';
		fclose(f);
		f = fopen("rasshifr.txt", "w");
		for(i = 0; i < strlen(s); i++)
		{
			fprintf(f, "%c", s[i]);
		}
		fclose(f);
	}
	if(an == 3)
	{
		system("cls");
		printf("До свидания...\n");
		return 0;
	}
  }while(an != 3);
  return 0;
}
