#include "Numina.h"

#include <cstdio>

struct Thaumaturge : public ttn::App
{
	void update(f32 dt) override
	{
		printf("Frame Time: %f ms\n", dt * 1000);
		printf("FPS: %d\n", (i32)(1.f / dt));
	}

	void render() override
	{
	}
};

int main(int argc, char **argv)
{
	static Thaumaturge thaumaturge;

	ttn::numina_set_window_title("Thaumaturge");
	ttn::numina_set_app(&thaumaturge);

	printf("Hello, this is Thaumaturge.\n");
	return 0;
}
