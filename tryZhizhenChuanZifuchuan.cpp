#include <stdio.h>
#include <string.h>

void changeStr(char *p) {
	memset(p, 0, 255);
	sprintf(p, "%s", "change IM here");


}

int main() {
	char str[255];
	memset(str, 0, 255);
	sprintf(str, "%s", "before IM here");

	printf("before:%s\n", str);

	changeStr(str);

	printf("after:%s\n", str);
	getchar();
}