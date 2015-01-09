#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replace_blank(char **str, int len)
{
	int i, n = 0;
	char token[] = {'%', '2', '0'};
	for (i = 0; i < len; i++) {
		if ((*str)[i] == ' ')
			n++;
	}
	char *tmp = (char *)malloc(len + n + 1);
	bzero(tmp, len + n + 1);
	memcpy(tmp, *str, len);

	char *p1, *p2;
	p1 = tmp + len;
	p2 = p1 + 2 * n;

	while (p1 != p2) {
		while (*p1 != ' ') {  
			*p2-- = *p1--;
		}
		p1--;
		p2 -= 3;
		memcpy(p2 + 1, token, 3);
	}
	printf("%s\n", tmp);
	*str = tmp;
}

int main(int argc, const char *argv[])
{
	char *str = "we are happy.";
	printf("%s\n", str);
	replace_blank(&str, strlen(str));
	printf("%s\n", str);
	return 0;
}
