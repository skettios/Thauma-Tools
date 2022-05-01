#include "SDL.h"

#include <cstdio>

extern int TTN_Main(int, char**);

extern void _ttn_initialize_numina(void);

extern void _ttn_run_numina(void);

extern void _ttn_quit_numina(void);

int main(int argc, char** argv)
{
	printf("Hello, this is Numina.\n");

	_ttn_initialize_numina();
	TTN_Main(argc, argv);
	_ttn_run_numina();
	_ttn_quit_numina();

	return 0;
}
