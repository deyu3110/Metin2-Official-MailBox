//Find
		int			Messenger(LPCHARACTER ch, const char* c_pData, size_t uiBytes);

///Add
#if defined(__BL_MAILBOX__)
		void		MailboxWrite(LPCHARACTER ch, const char* data);
		void		MailboxConfirm(LPCHARACTER ch, const char* data);
		void		MailboxProcess(LPCHARACTER ch, const char* c_pData);
#endif

//Find
	void		QuestLoad(LPDESC d, const char * c_pData);

///Add
#if defined(__BL_MAILBOX__)
	void		MailBoxRespondLoad(LPDESC d, const char * c_pData);
	void		MailBoxRespondName(LPDESC d, const char * c_pData);
	void		MailBoxRespondUnreadData(LPDESC d, const char * c_pData);
#endif