#include "Numina.h"
#include "SDL.h"

#include "glad/glad.h"

namespace ttn
{
	struct Numina
	{
		struct Platform
		{
			SDL_Window *window;
			SDL_GLContext opengl;
		} platform;

		ttn::App* application;
	};
}

static ttn::Numina* _TTN_NUMINA = nullptr;

void ttn::numina_set_window_title(const char* title)
{
	SDL_SetWindowTitle(_TTN_NUMINA->platform.window, title);
}

void ttn::numina_set_app(ttn::App* app)
{
	_TTN_NUMINA->application = app;
}

void ttn::numina_set_clear_color(f32 r, f32 g, f32 b, f32 a)
{
	glClearColor(r, g, b, a);
}

bool _ttn_initialize_opengl()
{
	SDL_GLContext dummy = SDL_GL_CreateContext(_TTN_NUMINA->platform.window);
	if (!dummy)
		return false;

	SDL_GL_MakeCurrent(_TTN_NUMINA->platform.window, dummy);
	gladLoadGL();

	i32 major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	_TTN_NUMINA->platform.opengl = SDL_GL_CreateContext(_TTN_NUMINA->platform.window);
	if (!_TTN_NUMINA->platform.opengl)
		return false;

	SDL_GL_MakeCurrent(_TTN_NUMINA->platform.window, _TTN_NUMINA->platform.opengl);
	SDL_GL_DeleteContext(dummy);

	gladLoadGLLoader(SDL_GL_GetProcAddress);

	return true;
}

TTN_API void _ttn_initialize_numina()
{
	static ttn::Numina numina;
	_TTN_NUMINA = &numina;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return;

	_TTN_NUMINA->platform.window = SDL_CreateWindow("Numina",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			1280, 720,
			SDL_WINDOW_OPENGL);
	if (!_TTN_NUMINA->platform.window)
		return;

	if (!_ttn_initialize_opengl())
		return;
}

TTN_API void _ttn_run_numina()
{
	ttn::numina_set_clear_color(0.f, 0.f, 0.f, 1.f);

	u64 now = SDL_GetPerformanceCounter();
	u64 last = 0;

	float delta_time = 0.f;

	bool running = true;
	while (running)
	{
		SDL_Event window_event;
		while (SDL_PollEvent(&window_event))
		{
			switch (window_event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
			}
		}

		last = now;
		now = SDL_GetPerformanceCounter();

		delta_time = (float)((now - last) / (float)SDL_GetPerformanceFrequency());

		_TTN_NUMINA->application->update(delta_time);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		SDL_GL_SwapWindow(_TTN_NUMINA->platform.window);
	}
}

TTN_API void _ttn_quit_numina()
{
	if (_TTN_NUMINA->platform.opengl)
	{
		SDL_GL_MakeCurrent(_TTN_NUMINA->platform.window, nullptr);
		SDL_GL_DeleteContext(_TTN_NUMINA->platform.opengl);
	}

	if (_TTN_NUMINA->platform.window)
	{
		SDL_DestroyWindow(_TTN_NUMINA->platform.window);
	}

	SDL_Quit();
}
