#include <stdio.h>
//#define ENABLE_DEBUG 1
#define LOG(level, text, ...) do {\
    printf("%s[%d] - %s: " text, __FUNCTION__, __LINE__, level, ##__VA_ARGS__);}while(0);

#define ERROR(text, ...) do {\
    printf("%s[%d] - %s: " text, __FUNCTION__, __LINE__, "ERROR", ##__VA_ARGS__);}while(0);
#define WARN(text, ...) do {\
    printf("%s[%d] - %s: " text, __FUNCTION__, __LINE__, "ERROR", ##__VA_ARGS__);}while(0);
#define INFO(text, ...) do {\
    printf("%s[%d] - %s: " text, __FUNCTION__, __LINE__, "INFO", ##__VA_ARGS__);}while(0);

#ifdef ENABLE_DEBUG
#define DEBUG(text, ...) do {\
    printf("%s[%d] - %s: " text, __FUNCTION__, __LINE__, "DEBUG", ##__VA_ARGS__);}while(0);
#else
#define DEBUG(text, ...)
#endif


#define REPORT_IF_UNEQUAL(lhs, rhs) do { \
    if((lhs) != (rhs)) ERROR("Unexpected error!\n");}while(0);

typedef struct
{
    unsigned int bits_per_sample;
    unsigned int sample_rate;
    unsigned int num_channels;
	unsigned int format;
}audio_properties_t;

typedef enum
{
	AUDIO_SETTINGS_CHANGE_EVENT = 0
}audio_capture_events_t;