//Find
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
					if (ch->GetMyShop() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_MAILBOX__)
						|| ch->GetMailBox()
#endif
					)

//Find
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->IsCubeOpen()
#if defined(__BL_MAILBOX__)
		|| ch->GetMailBox()
#endif
	)

//Find
void CInputMain::Fishing(LPCHARACTER ch, const char* c_pData)
{
	...
}

///Add
#if defined(__BL_MAILBOX__)
void CInputMain::MailboxWrite(LPCHARACTER ch, const char* c_pData)
{
	const auto* p = reinterpret_cast<const TPacketCGMailboxWrite*>(c_pData);
	if (p == nullptr)
		return;
	
	CMailBox* mail = ch->GetMailBox();
	if (mail == nullptr)
		return;

	mail->Write(p->szName, p->szTitle, p->szMessage, p->pos, p->iYang, p->iWon);
}

void CInputMain::MailboxConfirm(LPCHARACTER ch, const char* c_pData)
{
	const auto* p = reinterpret_cast<const TPacketCGMailboxWriteConfirm*>(c_pData);
	if (p == nullptr)
		return;
	
	CMailBox* mail = ch->GetMailBox();
	if (mail == nullptr)
		return;

	mail->CheckPlayer(p->szName);
}

void CInputMain::MailboxProcess(LPCHARACTER ch, const char* c_pData)
{
	const auto* p = reinterpret_cast<const TPacketMailboxProcess*>(c_pData);
	if (p == nullptr)
		return;
	
	CMailBox* mail = ch->GetMailBox();
	if (mail == nullptr)
		return;

	switch (p->bSubHeader)
	{
	case CMailBox::EMAILBOX_CG::MAILBOX_CG_CLOSE:
		ch->SetMailBox(nullptr);
		break;
	case CMailBox::EMAILBOX_CG::MAILBOX_CG_DELETE:
		mail->DeleteMail(p->bArg1, false);
		break;
	case CMailBox::EMAILBOX_CG::MAILBOX_CG_ALL_DELETE:
		mail->DeleteAllMails();
		break;
	case CMailBox::EMAILBOX_CG::MAILBOX_CG_GET_ITEMS:
		mail->GetItem(p->bArg1, false);
		break;
	case CMailBox::EMAILBOX_CG::MAILBOX_CG_ALL_GET_ITEMS:
		mail->GetAllItems();
		break;
	case CMailBox::EMAILBOX_CG::MAILBOX_CG_ADD_DATA:
		mail->AddData(p->bArg1, p->bArg2);
		break;
	default:
		sys_err("CInputMain::MailboxProcess Unknown SubHeader (ch: %s) (%d)", ch->GetName(), p->bSubHeader);
		break;
	}
}
#endif

//Find
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen())

///Change
	if (ch->GetExchange() || ch->IsOpenSafebox() || ch->GetShopOwner() || ch->GetMyShop() || ch->IsCubeOpen()
#if defined(__BL_MAILBOX__)
		|| ch->GetMailBox()
#endif
	)

//Find
		case HEADER_CG_MALL_CHECKOUT:
			SafeboxCheckout(ch, c_pData, true);
			break;

///Add
#if defined(__BL_MAILBOX__)
		case HEADER_CG_MAILBOX_WRITE:
			MailboxWrite(ch, c_pData);
			break;
		
		case HEADER_CG_MAILBOX_WRITE_CONFIRM:
			MailboxConfirm(ch, c_pData);
			break;

		case HEADER_CG_MAILBOX_PROCESS:
			MailboxProcess(ch, c_pData);
			break;
#endif