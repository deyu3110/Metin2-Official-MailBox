//Find
	Set(HEADER_CG_SAFEBOX_ITEM_MOVE, sizeof(TPacketCGItemMove), "SafeboxItemMove", true);

///Add
#if defined(__BL_MAILBOX__)
	Set(HEADER_CG_MAILBOX_WRITE, sizeof(TPacketCGMailboxWrite), "MailboxWrite", true);
	Set(HEADER_CG_MAILBOX_WRITE_CONFIRM, sizeof(TPacketCGMailboxWriteConfirm), "MailboxConfirm", true);
	Set(HEADER_CG_MAILBOX_PROCESS, sizeof(TPacketMailboxProcess), "MailboxProcess", true);
#endif