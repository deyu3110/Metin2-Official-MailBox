//Find
	int game_web_mall(lua_State* L)
	{
		...
	}

///Add
#if defined(__BL_MAILBOX__)
	int game_open_mailbox(lua_State* L)
	{
		CMailBox::Open(CQuestManager::instance().GetCurrentCharacterPtr());
		return 0;
	}
#endif

//Find
			{ "open_web_mall",				game_web_mall					},

///Add
#if defined(__BL_MAILBOX__)
			{ "open_mailbox",				game_open_mailbox				},
#endif