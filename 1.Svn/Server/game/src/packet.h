//Find
	HEADER_CG_STATE_CHECKER					= 206,

///Add
#if defined(__BL_MAILBOX__)
	HEADER_CG_MAILBOX_WRITE = 219,
	HEADER_CG_MAILBOX_WRITE_CONFIRM = 220,
	HEADER_CG_MAILBOX_PROCESS = 221,
#endif

//Find
	HEADER_GC_RESPOND_CHANNELSTATUS			= 210,

///Add
#if defined(__BL_MAILBOX__)
	HEADER_GC_MAILBOX_PROCESS = 220,
	HEADER_GC_MAILBOX = 221,
	HEADER_GC_MAILBOX_ADD_DATA = 222,
	HEADER_GC_MAILBOX_ALL = 223,
	HEADER_GC_MAILBOX_UNREAD = 224,
#endif

//Find
typedef struct command_on_click
{
	...
} TPacketCGOnClick;

///Add
#if defined(__BL_MAILBOX__)
typedef struct packet_mailbox_process
{
	BYTE							bHeader;
	BYTE							bSubHeader;
	BYTE							bArg1;
	BYTE							bArg2;
} TPacketMailboxProcess;

typedef struct packet_mailbox_process_all
{
	BYTE							Index;
} TPacketGCMailboxProcessAll;

typedef struct packet_mailbox
{
	BYTE							bHeader;
	WORD							wSize;
} TPacketGCMailBox;

typedef struct packet_mailbox_write
{
	BYTE							bHeader;
	char							szName[CHARACTER_NAME_MAX_LEN + 1];
	char							szTitle[25 + 1];
	char							szMessage[100 + 1];
	TItemPos						pos;
	int								iYang;
	int								iWon;
} TPacketCGMailboxWrite;

typedef struct packet_mailbox_write_confirm
{
	BYTE							bHeader;
	char							szName[CHARACTER_NAME_MAX_LEN + 1];
} TPacketCGMailboxWriteConfirm;
#endif