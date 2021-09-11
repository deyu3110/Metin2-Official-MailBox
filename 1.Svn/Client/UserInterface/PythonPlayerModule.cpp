//Find
	PyModule_AddIntConstant(poModule, "ON_TOP_WND_PET_FEED", ON_TOP_WND_PET_FEED);

///Add
#if defined(__BL_MAILBOX__)
	PyModule_AddIntConstant(poModule, "ON_TOP_WND_MAILBOX", ON_TOP_WND_MAILBOX);
#endif