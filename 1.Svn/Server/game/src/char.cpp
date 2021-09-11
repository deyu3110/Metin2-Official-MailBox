//Find
	CEntity::Initialize(ENTITY_CHARACTER);

///Add
#if defined(__BL_MAILBOX__)
	m_pkMailBox = nullptr;
	bMailBoxLoading = false;
	m_iMyMailBoxTime = 0;
#endif

//Find
	HorseSummon(false);

///Add
#if defined(__BL_MAILBOX__)
	SetMailBox(nullptr);
#endif

//Find
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen())

///Change
					if ((GetExchange() || IsOpenSafebox() || GetShopOwner()) || IsCubeOpen()
#if defined(__BL_MAILBOX__)
						|| GetMailBox()
#endif
					)

//Find
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen())

///Change
					if ((pkChrCauser->GetExchange() || pkChrCauser->IsOpenSafebox() || pkChrCauser->GetMyShop() || pkChrCauser->GetShopOwner()) || pkChrCauser->IsCubeOpen()
#if defined(__BL_MAILBOX__)
						|| pkChrCauser->GetMailBox()
#endif
					)

//Find
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen()))

///Change
					if ((GetExchange() || IsOpenSafebox() || IsCubeOpen())
#if defined(__BL_MAILBOX__)
						|| GetMailBox()
#endif
					)

//Find
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_MAILBOX__)
			|| GetMailBox()
#endif
		)

//Find
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen())

///Change
		if (GetExchange() || GetMyShop() || IsOpenSafebox() || IsCubeOpen()
#if defined(__BL_MAILBOX__)
			|| GetMailBox()
#endif
		)

//Find
	if (iPulse - GetMyShopTime() < PASSES_PER_SEC(limittime))
	{
		if (bSendMsg)
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("°Е·Ў ИД %dГК АМі»їЎґВ ґЩёҐБцїЄАё·О АМµї ЗТ јц ѕшЅАґПґЩ."), limittime);
		return true;
	}

///Add
#if defined(__BL_MAILBOX__)
	if (iPulse - GetMyMailBoxTime() < PASSES_PER_SEC(limittime))
	{
		if (bSendMsg)
			ChatPacket(CHAT_TYPE_INFO, "You cannot go elsewhere for %d seconds after mailbox.", limittime);
		return true;
	}
#endif

//Find
	if ((iPulse - GetMyShopTime()) < limit_time)
		return false;

///Add
#if defined(__BL_MAILBOX__)
	if ((iPulse - GetMyMailBoxTime()) < limit_time)
		return false;
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
int	CHARACTER::GetSkillPowerByLevel(int level, bool bMob) const
{
	...
}

///Add
#if defined(__BL_MAILBOX__)
void CHARACTER::SetMailBox(CMailBox* m)
{
	if (m_pkMailBox)
		delete m_pkMailBox;

	m_pkMailBox = m;
}
#endif