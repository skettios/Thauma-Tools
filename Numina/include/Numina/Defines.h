#ifndef THAUMA_TOOLS_NUMINA_DEFINES_H
#define THAUMA_TOOLS_NUMINA_DEFINES_H

#include <cstdint>

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using f32 = float;
using f64 = double;

#ifdef TTN_PLATFORM_WIN32
#ifdef TTN_EXPORT
#define TTN_API __declspec(dllexport)
#else
#define TTN_API __declspec(dllimport)
#endif
#else
#define TTN_API
#endif

#ifdef TTN_DEBUG
#define TTN_Assert(x) if (!(x)) { *(u64*)0 = 0; }
#else
#define TTN_Assert(x)
#endif

#endif //THAUMA_TOOLS_NUMINA_DEFINES_H
