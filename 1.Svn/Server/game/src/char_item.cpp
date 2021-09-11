//Find
	if (IsCubeOpen() || NULL != DragonSoul_RefineWindow_GetOpener())
		return false;

///Add
#if defined(__BL_MAILBOX__)
	if (GetMailBox())
		return false;
#endif

//Find
		case ITEM_QUEST:
			if (GetArena() != NULL || IsObserverMode() == true)
			{
				if (item->GetVnum() == 50051 || item->GetVnum() == 50052 || item->GetVnum() == 50053)
				{
					ChatPacket(CHAT_TYPE_INFO, LC_TEXT("대련 중에는 이용할 수 없는 물품입니다."));
					return false;
				}
			}

///Add
#if defined(__BL_MAILBOX__)
			if (item->GetVnum() == MOBILE_MAILBOX)
			{
				CMailBox::Open(this);
			}
#endif

//Find
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_MAILBOX__)
			|| GetMailBox()
#endif
		)

//Find
		{
			if (iPulse - GetRefineTime() < PASSES_PER_SEC(g_nPortalLimitTime))
			{
				ChatPacket(CHAT_TYPE_INFO, LC_TEXT("아이템 개량후 %d초 이내에는 귀환부,귀환기억부를 사용할 수 없습니다."), g_nPortalLimitTime);
				return false;
			}
		}

///Add
#if defined(__BL_MAILBOX__)
		{
			if (iPulse - GetMyMailBoxTime() < PASSES_PER_SEC(g_nPortalLimitTime))
			{
				ChatPacket(CHAT_TYPE_INFO, "You cannot use a Return Scroll %d seconds after opening a mailbox.", g_nPortalLimitTime);
				return false;
			}
		}
#endif

//Find
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_MAILBOX__)
			|| GetMailBox()
#endif
		)