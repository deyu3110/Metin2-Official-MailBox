if app.BL_MAILBOX:
	import mail
	import uiToolTip

# Find in class MiniMap(ui.ScriptWindow) / def __init__(self)
		self.mapName = ""

# Add
		if app.BL_MAILBOX:
			self.MailBoxGMButton = None
			self.MailBoxButton = None
			self.MailBoxEffect = None
			self.tooltipMailBoxGM = uiToolTip.ToolTip()
			self.tooltipMailBoxGM.Hide()
			self.tooptipMailBox = uiToolTip.ToolTip()
			self.tooptipMailBox.Hide()

# Find
	def __del__(self):
		miniMap.Destroy()
		ui.ScriptWindow.__del__(self)

# Change
	def __del__(self):
		if app.BL_MAILBOX:
			if self.MailBoxGMButton:
				del self.MailBoxGMButton
				self.MailBoxGMButton = None

			if self.tooltipMailBoxGM:
				del self.tooltipMailBoxGM
				self.tooltipMailBoxGM = None

			if self.tooptipMailBox:
				del self.tooptipMailBox
				self.tooptipMailBox = None
		miniMap.Destroy()
		ui.ScriptWindow.__del__(self)

# Find
		self.serverInfo = None

# Add
		if app.BL_MAILBOX:
			self.MailBoxGMButton = None
			self.MailBoxButton = None
			self.MailBoxEffect = None
			self.tooltipMailBoxGM = None
			self.tooptipMailBox = None

# Find
			self.serverInfo = self.GetChild("ServerInfo")

# Add
			if app.BL_MAILBOX:
				self.MakeGmMailButton()
				self.MailBoxButton = self.GetChild("MailBoxButton")
				self.MailBoxButton.Hide()
				self.MailBoxEffect = self.GetChild("MailBoxEffect")
				self.MailBoxEffect.Hide()

				if localeInfo.IsARABIC():
					(mailbox_effect_x, mailbox_effect_y) = self.MailBoxEffect.GetLocalPosition()
					self.MailBoxEffect.SetPosition(mailbox_effect_x+26, mailbox_effect_y)

# Find
		self.tooltipAtlasOpen.SetTooltipPosition(ButtonPosX, ButtonPosY)

# Add
		if app.BL_MAILBOX:
			if self.MailBoxButton and self.tooptipMailBox:
				(ButtonPosX, ButtonPosY) = self.MailBoxButton.GetGlobalPosition()
				self.tooptipMailBox.SetToolTipPosition(ButtonPosX, ButtonPosY)

# Find
		if True == self.AtlasShowButton.IsIn():
			self.tooltipAtlasOpen.Show()
		else:
			self.tooltipAtlasOpen.Hide()

# Add
		if app.BL_MAILBOX:
			if self.MailBoxGMButton:
				if True == self.MailBoxGMButton.IsIn():
					self.tooltipMailBoxGM.Show()
				else:
					self.tooltipMailBoxGM.Hide()

			if self.MailBoxButton:
				if True == self.MailBoxButton.IsIn():
					if self.MailBoxEffect:
						self.MailBoxEffect.Hide()
					self.tooptipMailBox.Show()
				else:
					self.tooptipMailBox.Hide()

# Add to end
	if app.BL_MAILBOX:
		def MiniMapMailProcess(self, type, data):
			if mail.MAILBOX_GC_UNREAD_DATA == type:
				self.MiniMapMailRefresh(data)

			elif mail.MAILBOX_GC_SYSTEM_CLOSE == type:
				self.MiniMapMailSystemClose()

		def MiniMapMailRefresh(self, data):

			(is_flash, total_count, item_count,
				common_count, is_gm_post_visible) = data
			if 0 == total_count:
				if self.MailBoxButton:
					self.MailBoxButton.Hide()
				if self.MailBoxEffect:
					self.MailBoxEffect.Hide()
			else:
				if self.MailBoxButton:
					self.MailBoxButton.Show()
				if True == is_flash and self.MailBoxEffect:
					self.MailBoxEffect.ResetFrame()
					self.MailBoxEffect.Show()
				else:
					self.MailBoxEffect.Hide()

				if self.tooptipMailBox:
					text1 = localeInfo.MAILBOX_POST_NOT_CONFIRM_INFO_1 % (
						total_count)
					text2 = localeInfo.MAILBOX_POST_NOT_CONFIRM_INFO_2 % (
						common_count, item_count)
					self.tooptipMailBox.ClearToolTip()
					self.tooptipMailBox.SetThinBoardSize(11 * len(text1))
					self.tooptipMailBox.AppendTextLine(text1)
					self.tooptipMailBox.AppendTextLine(text2)
			# gm ¿ìÆí Ç¥½Ã
			self.MailBoxGMButtonVisible(is_gm_post_visible)

		def MiniMapMailSystemClose(self):
			if self.MailBoxButton:
				self.MailBoxButton.Hide()
			if self.MailBoxEffect:
				self.MailBoxEffect.Hide()
			if self.tooptipMailBox:
				self.tooptipMailBox.Hide()
			if self.MailBoxGMButton:
				self.MailBoxGMButton.Hide()
			if self.tooltipMailBoxGM:
				self.tooltipMailBoxGM.Hide()

		def MakeGmMailButton(self):
			SCREEN_WIDTH = wndMgr.GetScreenWidth()
			# create button
			self.MailBoxGMButton = ui.ExpandedImageBox()
			self.MailBoxGMButton.LoadImage(
				"d:/ymir work/ui/game/mailbox/mailbox_icon_gm.sub")
			self.MailBoxGMButton.SetScale(0.8, 0.8)
			self.MailBoxGMButton.SetPosition(SCREEN_WIDTH-136-30, 0)
			self.MailBoxGMButton.Hide()
			self.MailBoxGMButton.SetEvent(ui.__mem_func__(
				self.MailBoxGMButtonOverInEvent), "mouse_over_in", 0)
			self.MailBoxGMButton.SetEvent(ui.__mem_func__(
				self.MailBoxGMButtonOverOutEvent), "mouse_over_out", 0)

			if localeInfo.IsARABIC():
				self.MailBoxGMButton.SetPosition(SCREEN_WIDTH-136-30-10, 0)

			# tooltip setting
			text = localeInfo.MAILBOX_POST_GM_ARRIVE
			self.tooltipMailBoxGM.ClearToolTip()
			self.tooltipMailBoxGM.SetThinBoardSize(11 * len(text))
			self.tooltipMailBoxGM.AppendTextLine(text)

		def MailBoxGMButtonOverInEvent(self):
			if self.tooltipMailBoxGM:
				self.tooltipMailBoxGM.Show()

		def MailBoxGMButtonOverOutEvent(self):
			if self.tooltipMailBoxGM:
				self.tooltipMailBoxGM.Hide()

		def MailBoxGMButtonVisible(self, visible):

			if not self.MailBoxGMButton:
				return
			if not self.tooltipMailBoxGM:
				return

			if True == visible:
				self.MailBoxGMButton.Show()
				self.MailBoxGMButton.SetTop()
			else:
				self.MailBoxGMButton.Hide()
				self.tooltipMailBoxGM.Hide()
