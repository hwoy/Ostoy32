#include <stdint.h>
#include <boot.h>

extern volatile unsigned char drive_no;
uint8_t get_driveno(void)
{
	return drive_no;
}
