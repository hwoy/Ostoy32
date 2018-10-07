#include <ctype.h>

int toupper(int ch)
{

	return (ch>='a' && ch<='z') ? ch-('a'-'A') :ch;
}

