#ifndef THAUMA_TOOLS_NUMINA_H
#define THAUMA_TOOLS_NUMINA_H

#include "Numina/App.h"

#ifndef TTN_EXPORT
#include "Numina/Main.h"
#endif

#include "Numina/Defines.h"

namespace ttn
{
	TTN_API void numina_set_window_title(const char*);
	TTN_API void numina_set_app(App*);

	TTN_API void numina_set_clear_color(f32, f32, f32, f32);
}

#endif //THAUMA_TOOLS_NUMINA_H
