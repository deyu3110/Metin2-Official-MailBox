//Find
		void SetMessengerHandler(PyObject* poHandler);

///Add
#if defined(__BL_MAILBOX__)
		TFriendNameMap m_FriendNameMap;
#endif

//Find
	protected:
		TFriendNameMap m_FriendNameMap;

///Change
	protected:
#if !defined(__BL_MAILBOX__)
		TFriendNameMap m_FriendNameMap;
#endif