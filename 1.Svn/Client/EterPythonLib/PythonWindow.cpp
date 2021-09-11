//Find
			m_isFlash(FALSE)

///Add
#if defined(__BL_MAILBOX__)
			, m_isNewFlash(false)
#endif

//Find
	void CButton::Flash()
	{
		...
	}

///Add
#if defined(__BL_MAILBOX__)
	void CButton::EnableFlash()
	{
		m_isNewFlash = true;
	}
	void CButton::DisableFlash()
	{
		m_isNewFlash = false;
	}
#endif

//Find
			if (m_isFlash)
			if (!IsIn())
			if (int(timeGetTime() / 500)%2)
			{
				return;
			}

///Change
#if defined(__BL_MAILBOX__)
			if ((m_isFlash || m_isNewFlash) && !IsIn() && !IsPressed())
			{
				if (int(timeGetTime() / 500) % 2)
				{
					if (m_isNewFlash && !m_overVisual.IsEmpty())
						SetCurrentVisual(&m_overVisual);
					else
						return;
				}
				else
				{
					if (m_isNewFlash && !m_upVisual.IsEmpty())
						SetCurrentVisual(&m_upVisual);
				}
			}
#else
			if (m_isFlash)
			if (!IsIn())
			if (int(timeGetTime() / 500)%2)
			{
				return;
			}
#endif