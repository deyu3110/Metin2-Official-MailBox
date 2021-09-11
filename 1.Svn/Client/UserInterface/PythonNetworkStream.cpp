//Find
			Set(HEADER_GC_MOTION,				CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCMotion), STATIC_SIZE_PACKET));

///Add
#if defined(__BL_MAILBOX__)
			Set(HEADER_GC_MAILBOX_PROCESS, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketMailboxProcess), STATIC_SIZE_PACKET));
			Set(HEADER_GC_MAILBOX, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCMailBox), DYNAMIC_SIZE_PACKET));
			Set(HEADER_GC_MAILBOX_ADD_DATA, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCMailBoxAddData), STATIC_SIZE_PACKET));
			Set(HEADER_GC_MAILBOX_ALL, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCMailBox), DYNAMIC_SIZE_PACKET));
			Set(HEADER_GC_MAILBOX_UNREAD, CNetworkPacketHeaderMap::TPacketType(sizeof(TMailBoxRespondUnreadData), STATIC_SIZE_PACKET));
#endif