// #include "git_ver.h"
#include <Common.h>

#define ETAHEN_PATH "/data/etaHEN"

#define u8  uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t
#define s8  int8_t
#define s16 int16_t
#define s32 int32_t
#define s64 int64_t
#define f32 float
#define f64 double
#define TEX_ICON_SYSTEM "cxml://psnotification/tex_icon_system"
#define MAX_PATH_ 260

#define attr_module_hidden __attribute__((weak)) __attribute__((visibility("hidden")))
#define attr_public __attribute__((visibility("default")))

#if (__FINAL__) == 1
#define BUILD_TYPE "(Release)"
#define debug_printf(a, args...)
#else
#define BUILD_TYPE "(Debug)"
#define debug_printf(a, args...) klog("[%s] (%s:%d) " a,  __func__,__FILE__, __LINE__, ##args)
#endif

#define final_printf(a, args...) klog("(%s:%d) " a, __FILE__, __LINE__, ##args)
#define boot_ver() {}\
//     final_printf("Commit: %s Branch: %s Build: %i %s\n", GIT_COMMIT, GIT_VER, GIT_NUM, BUILD_TYPE);\
//     final_printf("Built: %s\n", BUILD_DATE);\
//     final_printf("GoldHEN SDK Ver: 0x%08x\n", GOLDHEN_SDK_VERSION);\
//     final_printf("GoldHEN System SDK Ver: 0x%08x\n", sys_sdk_version());\
// }

#define print_proc_info() {\
    final_printf("process info\n");\
    final_printf("pid: %d\n", procInfo.pid);\
    final_printf("name: %s\n", procInfo.name);\
    final_printf("path: %s\n", procInfo.path);\
    final_printf("titleid: %s\n", procInfo.titleid);\
    final_printf("contentid: %s\n", procInfo.contentid);\
    final_printf("version: %s\n", procInfo.version);\
    final_printf("base_address: 0x%lx\n", procInfo.base_address);\
}

void NotifyStatic(const char* IconUri, const char *text);
void Notify(const char* IconUri, const char *FMT, ...);
// Takes hardcoded input string 2 to strlen against during compile time.
// startsWith(input_1, "input 2");
#define startsWith(str1, str2) (strncmp(str1, str2, __builtin_strlen(str2)) == 0)

// Enum Credits - OSM-Made
enum OrbisNotificationRequestType
{
	NotificationRequest = 0,
	SystemNotification = 1,
	SystemNotificationWithUserId = 2,
	SystemNotificationWithDeviceId = 3,
	SystemNotificationWithDeviceIdRelatedToUser = 4,
	SystemNotificationWithText = 5,
	SystemNotificationWithTextRelatedToUser = 6,
	SystemNotificationWithErrorCode = 7,
	SystemNotificationWithAppId = 8,
	SystemNotificationWithAppName = 9,
	SystemNotificationWithAppInfo = 9,
	SystemNotificationWithAppNameRelatedToUser = 10,
	SystemNotificationWithParams = 11,
	SendSystemNotificationWithUserName = 12,
	SystemNotificationWithUserNameInfo = 13,
	SendAddressingSystemNotification = 14,
	AddressingSystemNotificationWithDeviceId = 15,
	AddressingSystemNotificationWithUserName = 16,
	AddressingSystemNotificationWithUserId = 17,

	UNK_1 = 100,
	TrcCheckNotificationRequest = 101,
	NpDebugNotificationRequest = 102,
	UNK_2 = 102,
};

// Struct Credits - OSM-Made
typedef struct
{
	enum OrbisNotificationRequestType type;
	int32_t reqId;
	int32_t priority;
	int32_t msgId;
	int32_t targetId;
	int32_t userId;
	int32_t unk1;
	int32_t unk2;
	int32_t appId;
	int32_t errorNum;
	int32_t unk3;
	unsigned char useIconImageUri;
	char message[1024];
	char iconUri[1024];
	char unk[1024];
} OrbisNotificationRequest;

int32_t sceKernelSendNotificationRequest(int32_t device, OrbisNotificationRequest* req, size_t size, int32_t blocking);
