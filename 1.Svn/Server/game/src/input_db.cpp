//Find
void CInputDB::GuildSkillRecharge()
{
	...
}

///Add
#if defined(__BL_MAILBOX__)
#include "MailBox.h"
void CInputDB::MailBoxRespondLoad(LPDESC d, const char* c_pData)
{
	if (!d)
		return;

	const LPCHARACTER ch = d->GetCharacter();
	if (ch == nullptr)
		return;

	WORD size;

	if (decode_2bytes(c_pData) != sizeof(TMailBoxTable))
	{
		sys_err("mailbox table size error");
		return;
	}

	c_pData += 2;
	size = decode_2bytes(c_pData);
	c_pData += 2;

	CMailBox::Create(ch, (TMailBoxTable*)c_pData, size);
}

void CInputDB::MailBoxRespondName(LPDESC d, const char* c_pData)
{
	if (d == nullptr)
		return;

	const LPCHARACTER ch = d->GetCharacter();
	if (ch == nullptr)
		return;

	CMailBox* mail = ch->GetMailBox();
	if (mail == nullptr)
		return;

	mail->CheckPlayerResult((TMailBox*)c_pData);
}

void CInputDB::MailBoxRespondUnreadData(LPDESC d, const char* c_pData)
{
	if (d == nullptr)
		return;

	CMailBox::ResultUnreadData(d->GetCharacter(), (TMailBoxRespondUnreadData*)c_pData);
}
#endif

//Find
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetShopOwner() || ch->GetExchange() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_MAILBOX__)
		|| ch->GetMailBox()
#endif
	)

//Find
	case HEADER_DG_SAFEBOX_LOAD:
		SafeboxLoad(DESC_MANAGER::instance().FindByHandle(m_dwHandle), c_pData);
		break;

///Add
#if defined(__BL_MAILBOX__)
	case HEADER_DG_RESPOND_MAILBOX_LOAD:
		MailBoxRespondLoad(DESC_MANAGER::instance().FindByHandle(m_dwHandle), c_pData);
		break;

	case HEADER_DG_RESPOND_MAILBOX_CHECK_NAME:
		MailBoxRespondName(DESC_MANAGER::instance().FindByHandle(m_dwHandle), c_pData);
		break;

	case HEADER_DG_RESPOND_MAILBOX_UNREAD:
		MailBoxRespondUnreadData(DESC_MANAGER::instance().FindByHandle(m_dwHandle), c_pData);
		break;
#endif