//Find
		bool SendSelectItemPacket(DWORD dwItemPos);

///Add
#if defined(__BL_MAILBOX__)
		bool RecvMailboxProcess();
		bool RecvMailbox();
		bool RecvMailboxAddData();
		bool RecvMailboxAll();
		bool RecvMailboxUnread();
		bool SendPostDelete(const BYTE Index);
		bool SendPostGetItems(const BYTE Index);
		bool SendPostWriteConfirm(const char* szName);
		bool SendPostWrite(const char* szName, const char* szTitle, const char* szMessage, const TItemPos& pos, const int iYang, const int iWon);
		bool SendMailBoxClose();
		bool SendPostAllDelete();
		bool SendPostAllGetItems();
		bool RequestPostAddData(const BYTE ButtonIndex, const BYTE DataIndex);
#endif