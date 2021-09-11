///Add
#if defined(__BL_MAILBOX__)
#include "MailBox.h"
#endif

//Find
#ifdef __PET_SYSTEM__
	private:
		bool m_bIsPet;
	public:
		void SetPet() { m_bIsPet = true; }
		bool IsPet() { return m_bIsPet; }
#endif

///Add
#if defined(__BL_MAILBOX__)
	public:
		int			GetMyMailBoxTime() const { return m_iMyMailBoxTime; }
		void		SetMyMailBoxTime() { m_iMyMailBoxTime = thecore_pulse(); }
		void		SetMailBox(CMailBox* m);
		void		SetMailBoxLoading(const bool b) { bMailBoxLoading = b; }
		bool		IsMailBoxLoading() const { return bMailBoxLoading; }
		CMailBox*	GetMailBox() const { return m_pkMailBox; }
	private:
		CMailBox*	m_pkMailBox;
		bool		bMailBoxLoading;
		int 		m_iMyMailBoxTime;
#endif