#ifndef SYSTEMLIB_DEBUG_H
#define SYSTEMLIB_DEBUG_H

#include <stdio.h>
#include <signal.h>

#define STRINGIZE_DETAIL(x) #x
#define STRINGIZE(x) STRINGIZE_DETAIL(x)

#define BREAK() do { \
	fprintf(stderr, "Break at: %s", __FILE__ "(" STRINGIZE(__LINE__) ") :"); \
	fprintf(stderr, "\n"); \
	raise(SIGTRAP); \
} while (0)

#endif
