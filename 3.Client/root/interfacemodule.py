# Add
if app.BL_MAILBOX:
	import uiMailBox
	import item

# Find in class Interface(object) / def __init__(self)
		self.equipmentDialogDict = {}

# Add
		if app.BL_MAILBOX:
			self.mail_box = None

#Find
			wndDragonSoul = uiDragonSoul.DragonSoulWindow()

# Add
			if app.BL_MAILBOX:
				wndDragonSoul.BindInterfaceClass(self)

# Find
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoul.SetDragonSoulRefineWindow(self.wndDragonSoulRefine)
			self.wndDragonSoulRefine.SetInventoryWindows(self.wndInventory, self.wndDragonSoul)
			self.wndInventory.SetDragonSoulRefineWindow(self.wndDragonSoulRefine)

# Add
		if app.BL_MAILBOX:
			self.mail_box = uiMailBox.MailBox()
			self.mail_box.BindInterface(self)
			self.mail_box.SetInven(self.wndInventory)
			self.mail_box.SetDSWindow(self.wndDragonSoul)

# Find
		self.DRAGON_SOUL_IS_QUALIFIED = False

# Add
		if app.BL_MAILBOX:
			if self.mail_box:
				self.mail_box.SetItemToolTip(self.tooltipItem)

# Find
		if self.wndDragonSoulRefine:
			del self.wndDragonSoulRefine

# Add
		if app.BL_MAILBOX:
			if self.mail_box:
				self.mail_box.Destroy()
				del self.mail_box

# Find
		if self.wndExpandedTaskBar:
			self.wndExpandedTaskBar.Hide()

# Add
		if app.BL_MAILBOX:
			if self.mail_box:
				self.mail_box.Hide()

# Find
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			hideWindows += self.wndDragonSoul,\
				self.wndDragonSoulRefine,

# Add
		if app.BL_MAILBOX:
			if self.mail_box:
				hideWindows += self.mail_box,

# Find
		def RefreshMarkInventoryBag(self):
			self.wndInventory.RefreshMarkSlots()

# Add
			if app.BL_MAILBOX:
				if self.wndDragonSoul and self.wndDragonSoul.IsShow():
					self.wndDragonSoul.RefreshBagSlotWindow()

# Find
if __name__ == "__main__":

# Add Above
	if app.BL_MAILBOX:
		def MailBoxProcess(self, type, data):
			if not self.mail_box:
				return
				
			self.mail_box.MailBoxProcess( type, data )
			
		def MiniMapMailProcess(self, type, data):
			if not self.wndMiniMap:
				return
				
			self.wndMiniMap.MiniMapMailProcess(type, data)

		def MarkUnusableDSInvenSlotOnTopWnd(self, onTopWnd, index, window):
			if onTopWnd == player.ON_TOP_WND_MAILBOX and self.mail_box and self.mail_box.CantPostItemSlot(index, window):
				return True
				
			return False
