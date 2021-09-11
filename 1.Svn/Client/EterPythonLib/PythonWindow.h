///Add
#include "../UserInterface/Locale_inc.h"

//Find
				FLAG_RTL				= (1 << 11),	// Right-to-left

///Add
#if defined(__BL_MAILBOX__)
				NOT_CAPTURE				= (1 << 12),
#endif

//Find
			void Flash();

///Add
#if defined(__BL_MAILBOX__)
			void EnableFlash();
			void DisableFlash();
#endif

//Find
			BOOL m_isFlash;

///Add
#if defined(__BL_MAILBOX__)
			bool m_isNewFlash;
#endif