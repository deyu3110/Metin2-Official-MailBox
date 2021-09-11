//Find
	if (pkChr->IsOpenSafebox() || pkChr->GetExchange() || pkChr->GetMyShop() || pkChr->IsCubeOpen())

///Change
	if (pkChr->IsOpenSafebox() || pkChr->GetExchange() || pkChr->GetMyShop() || pkChr->IsCubeOpen()
#if defined(__BL_MAILBOX__)
		|| pkChr->GetMailBox()
#endif
	)