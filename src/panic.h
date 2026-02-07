#ifdef __GNUC__
#define NORETURN __attribute__((noreturn))
#else
#define NORETURN
#endif

// Panic with an error message.
// The error message should not have a newline.
NORETURN void panic(char *message);
