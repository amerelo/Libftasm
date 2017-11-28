#include "libfts.h"

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef __COLOR__
#define __COLOR__

#define C_NO	"\033[00m"
#define C_OK	"\033[35m"
#define C_GOOD	"\033[32m"
#define C_ERROR	"\033[31m"

#endif

static void		txt_error_info(char *s)
{
	puts(" ");
	puts(C_ERROR);
	puts(s);
	puts(" ");
	puts(C_NO);
}

static int		test_memset(void)
{
	int		erreur = 0;
	int		reussi = 0;
	char	s1[9] = ".........";
	char	s2[15] = "......rgrgr...r";
	char	*ss1, *ss2;

	ss1 = ft_memset(s1, '-', 9);
	erreur = memcmp(ss1, "---------", 9);
	if (!erreur)
		reussi++;
	else
		txt_error_info("memcmp(ss1, \"---------\", 9)");
	ss2 = ft_memset(s2, '-', 5);
	erreur = memcmp(ss2, "-----.rgrgr...r", 14);
	if (!erreur)
		reussi++;
	else
		txt_error_info("memcmp(ss2, \"-----.rgrgr...r\", 14)");

	return (reussi);
}

static int		test_bzero(void)
{
	int		erreur = 0;
	int		reussi = 0;
	char	*s1 = malloc(sizeof(char) * 10);
	char	*s2 = malloc(sizeof(char) * 15);
	char	*st1 = malloc(sizeof(char) * 10);
	char	*st2 = malloc(sizeof(char) * 15);

	ft_bzero(s1, 9);
	bzero(st1, 9);
	erreur = memcmp(s1, st1, 9);
	if (!erreur)
		reussi++;
	else
		txt_error_info("bzero(st1, 9)");
	ft_bzero(s2, 9);
	bzero(st2, 9);
	erreur = memcmp(s2, st2, 9);
	if (!erreur)
		reussi++;
	else
		txt_error_info("bzero(st2, 9)");
	return (reussi);
}

static int		test_memcpy(void)
{
	int		erreur = 0;
	int		reussi = 0;
	char	*s1 = malloc(sizeof(char) * 10);
	char	*s2 = malloc(sizeof(char) * 15);
	char	st1[9] = "ijd\0kjdno";
	char	st2[14] = "";

	ft_memcpy(s1, st1, 9);
	erreur = memcmp(s1, st1, 9);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memcpy(s1, \"ijd\\0kjdno\", 9)");
	ft_memcpy(s2, st2, 0);
	erreur = memcmp(s2, st2, 0);
	if (!erreur)
		reussi++;
	else
		txt_error_info("ft_memcpy(s2, \"\", 0);");
	return (reussi);
}

static int		test_strdup(void)
{
	int		reussi = 0;

	if (!strcmp(ft_strdup("lololo"), strdup("lololo")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strdup(\"lololo\"), strdup(\"lololo\"))");
	if (!strcmp(ft_strdup(""), strdup("")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strdup(\"\"), strdup(\"\"))");
	if (!strcmp(ft_strdup("."), strdup(".")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strdup(\".\"), strdup(\".\"))");
	if (!strcmp(ft_strdup(".egrgrhthtjdv\0"), strdup(".egrgrhthtjdv\0")))
		reussi++;
	else
		txt_error_info("!ft_strcmp(ft_strdup(\".egrgrhthtjdv\\0\"), strdup(\".egrgrhthtjdv\\0\"))");
	return (reussi);
}

static int		test_strcat(void)
{
	int		reussi = 0;
	char src[50], dest[50], src2[50], dest2[50];
	bzero(src, 50);
	bzero(dest, 50);
	bzero(src2, 50);
	bzero(dest2, 50);
	strcat(src,  "This is source");
	strcat(dest, "This is destination");
	ft_strcat(src2,  "This is source");
	ft_strcat(dest2, "This is destination");
	if (!strcmp(strcat(dest, src), ft_strcat(dest2, src2)))
  {
		reussi++;
  }
	else
	{
		printf("str :%s\nft_str: %s\n", dest, dest2);
		txt_error_info("!ft_strcmp(strncat(dest, src), strncat(dest2, src2))");
	}
	strcpy(src,  "Ththth");
	strcpy(dest, "Ththth");
	strcpy(src2,  "Ththth");
	strcpy(dest2, "Ththth");
	if (!strcmp(strcat(dest, src), strcat(dest2, src2)))
		reussi++;
	else
		txt_error_info("!ft_strcmp(strncat(dest, src), strncat(dest2, src2))");
	return (reussi);
}

static int		test_strlen(void)
{
	int		reussi = 0;

	if (ft_strlen("") == strlen(""))
		reussi++;
	else
		txt_error_info("ft_strlen(\"\") == strlen(\"\")");
	if (ft_strlen("ppppefefefgeggdvsvs") == strlen("ppppefefefgeggdvsvs"))
		reussi++;
	else
	{
	  printf("ft_:%ld    %ld\n", ft_strlen("ppppefefefgeggdvsvs") , strlen("ppppefefefgeggdvsvs"));
		txt_error_info("ft_strlen(\"ppppefefefgeggdvsvs\") == strlen(\"ppppefefefgeggdvsvs\")");
	}
	if (ft_strlen("ppppefe\0fefgeggdvsvs") == strlen("ppppefe\0fefgeggdvsvs"))
		reussi++;
	else
		txt_error_info("ft_strlen(\"ppppefe\\0fefgeggdvsvs\") == strlen(\"ppppefe\\0fefgeggdvsvs\")");
	if (ft_strlen("ppppefefefgeggdvsvs00jfrjgrgrgrjgjfdgdfgsdgjksjkdgksjhdghshdghsdgjsghsjkdbnvsdkjvkjdsgjdsjgfjdshvhdshgdsgjksdkghdshg") == strlen("ppppefefefgeggdvsvs00jfrjgrgrgrjgjfdgdfgsdgjksjkdgksjhdghshdghsdgjsghsjkdbnvsdkjvkjdsgjdsjgfjdshvhdshgdsgjksdkghdshg"))
		reussi++;
	else
		txt_error_info("ft_strlen(\"ppppefefefgeggdvsvs00jfrjgrgrgrjgjfdgdfgsdgjksjkdgksjhdghshdghsdgjsghsjkdbnvsdkjvkjdsgjdsjgfjdshvhdshgdsgjksdkghdshg\") == strlen(\"ppppefefefgeggdvsvs00jfrjgrgrgrjgjfdgdfgsdgjksjkdgksjhdghshdghsdgjsghsjkdbnvsdkjvkjdsgjdsjgfjdshvhdshgdsgjksdkghdshg\")");
	return (reussi);
}

static int		test_isalpha(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isalpha(i) == ft_isalpha(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_isdigit(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isdigit(i) == ft_isdigit(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_isalnum(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isalnum(i) == ft_isalnum(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_isascii(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isascii(i) == ft_isascii(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_isprint(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (isprint(i) == ft_isprint(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static int		test_toupper(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (toupper(i) == ft_toupper(i))
			reussi++;
		else
		{
			printf("%d toupper:%d ft_toupper:%d\n", i, toupper(i), ft_toupper(i));
		}
		i++;
	}
	return (reussi);
}

static int		test_tolower(void)
{
	int		reussi = 0;
	int		i = -100;
	while (i < 200)
	{
		if (tolower(i) == ft_tolower(i))
			reussi++;
		i++;
	}
	return (reussi);
}

static void		txt_good(char *s, int nbr, int max)
{
  printf("%s%s  [", s, C_GOOD);
	if (nbr < max)
		printf(C_OK);
	printf("%d", nbr);
	if (nbr < max)
		printf(C_GOOD);
	printf("/%d", max);
	printf("]  success%s\n", C_NO);
}

static void		txt_error(char *s)
{
  printf("%s%s%s\n", C_ERROR, s, C_NO);
}

int test_ft_strdup2()
{
	char *str;
	char *dup;
	int success;
	int i;

	i = 1;
	success = 0;

	while (i < 20000)
	{
		str = malloc(i);
		ft_bzero(str, i);
		ft_memset(str, 'h', i-1);

		dup = ft_strdup(str);

		if (memcmp(dup, str, i) == 0)
			success++;
		// else {
		// 	printf("dup i %d \n", i);
		// }
		free(str);
		free(dup);
		i = i + 2;
	}
	return success;
}

static void		Start(void)
{
	int nbr = 0;
	ft_puts("------Started Test Libfts.a------");
	ft_puts("ft_puts.....  \033[32m[2/2] success\033[00m");
	/*******memset*******/
	if ((nbr = test_memset()))
		txt_good("ft_memset...", nbr, 2);
	else
		txt_error("ft_memset...Total Error !");
	/*******bzero*******/
	if ((nbr = test_bzero()))
		txt_good("ft_bzero....", nbr, 2);
	else
		txt_error("ft_bzero....Total Error !");
		/*******memcpy*******/
	if ((nbr = test_memcpy()))
		txt_good("ft_memcpy...", nbr, 2);
	else
		txt_error("ft_memcpy...Total Error !");
	/*******strlen*******/
	if ((nbr = test_strlen()))
		txt_good("ft_strlen...", nbr, 4);
	else
		txt_error("ft_strlen...Total Error !");
		/*******strdup*******/
	if ((nbr = test_strdup()))
		txt_good("ft_strdup...", nbr, 4);
	else
		txt_error("ft_strdup...Total Error !");
		/*******isalpha*******/
	if ((nbr = test_isalpha()))
		txt_good("ft_isalpha..", nbr, 300);
	else
		txt_error("ft_isalpha..Total Error !");
		/*******isdigit*******/
	if ((nbr = test_isdigit()))
		txt_good("ft_isdigit..", nbr, 300);
	else
		txt_error("ft_isdigit..Total Error !");
		/*******isalnum*******/
	if ((nbr = test_isalnum()))
		txt_good("ft_isalnum..", nbr, 300);
	else
		txt_error("ft_isalnum..Total Error !");
		/*******isascii******/
	if ((nbr = test_isascii()))
		txt_good("ft_isascii..", nbr, 300);
	else
		txt_error("ft_isascii...Total Error !");
		/*******isprint******/
	if ((nbr = test_isprint()))
		txt_good("ft_isprint..", nbr, 300);
	else
		txt_error("ft_isprint...Total Error !");
		/*******toupper******/
	if ((nbr = test_toupper()))
		txt_good("ft_toupper..", nbr, 300);
	else
		txt_error("ft_toupper...Total Error !");
		/*******tolower******/
	if ((nbr = test_tolower()))
		txt_good("ft_tolower..", nbr, 300);
	else
		txt_error("ft_tolower...Total Error !");
    /*******strcat*******/
	if ((nbr = test_strcat()))
		txt_good("ft_strcat...", nbr, 2);
	else
		txt_error("ft_strcat...Total Error !");

	if ((nbr = test_ft_strdup2()))
	  txt_good("ft_strdup...", nbr, 10000);
	else
	  txt_error("ft_strdup...Total Error !");

	//	test_ft_strnew();
}

void test_cat()
{
		ft_cat(0);
		int fd = open("maintest.c", O_RDWR);
		ft_cat(fd);
		ft_cat(-42);
}

void test_ft_strdup(char *arg)
{
		ft_puts(ft_strdup(arg));
}


int		main(int argc, char **argv)
{
	if (argc == 1)
		Start();
	else if (argc == 2 && strcmp(argv[1], "cat") == 0)
		test_cat();
	else if (argc == 3 && strcmp(argv[1], "strdup") == 0)
		test_ft_strdup(argv[2]);
	return (0);
}
