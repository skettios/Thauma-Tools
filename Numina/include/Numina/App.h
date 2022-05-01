#ifndef THAUMA_TOOLS_NUMINA_APP_H
#define THAUMA_TOOLS_NUMINA_APP_H

#include "Defines.h"

namespace ttn
{
	struct App
	{
		virtual void update(f32) = 0;
		virtual void render() = 0;
	};
}

#endif //THAUMA_TOOLS_NUMINA_APP_H
