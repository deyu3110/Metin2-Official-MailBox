//Find
	if ( IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen() )

///Change
	if ( IsOpenSafebox() || GetShopOwner() || GetMyShop() || IsCubeOpen()
#if defined(__BL_MAILBOX__)
		|| GetMailBox()
#endif
	)

//Find
	if ( victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen() )

///Change
	if ( victim->IsOpenSafebox() || victim->GetShopOwner() || victim->GetMyShop() || victim->IsCubeOpen()
#if defined(__BL_MAILBOX__)
		|| victim->GetMailBox()
#endif
	)