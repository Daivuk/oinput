#pragma once

namespace oinput
{
	int showMessageBox (
		char const * const aTitle , /* NULL or "" */
		char const * const aMessage , /* NULL or ""  may contain \n and \t */
		char const * const aDialogType , /* "ok" "okcancel" "yesno" "yesnocancel" */
		char const * const aIconType , /* "info" "warning" "error" "question" */
		int const aDefaultButton ); /* 0 for cancel/no , 1 for ok/yes , 2 for no in yesnocancel */
}

#if defined(OINPUT_NO_ASSERTS)
#define OINPUT_FATAL(_msg)
#define OINPUT_ASSERT(_cond, _msg)
#else
#if defined(_DEBUG)
#include <cassert>
#define OINPUT_FATAL(_msg) assert(false && _msg)
#define OINPUT_ASSERT(_cond, _msg) assert((_cond) && _msg)
#else
#define OINPUT_FATAL(_msg) \
{ \
    showMessageBox("ASSERT", _msg, "ok", "error", 1); \
    exit(1); \
}
#define OINPUT_ASSERT(_cond, _msg) \
if (!(_cond)) \
{ \
    showMessageBox("ASSERT", _msg, "ok", "error", 1); \
    exit(1); \
}
#endif
#endif
