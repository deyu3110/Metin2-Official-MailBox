//Find
#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EQUIPMENT_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EQUIPMENT_SYSTEM",	0);
#endif

///Add
#if defined(__BL_MAILBOX__)
	PyModule_AddIntConstant(poModule, "BL_MAILBOX", true);
#ifndef ENABLE_CHEQUE_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_CHEQUE_SYSTEM", 0);
#endif
#else
	PyModule_AddIntConstant(poModule, "BL_MAILBOX", false);
#endif