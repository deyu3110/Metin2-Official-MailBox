# Find in class DragonSoulWindow(ui.ScriptWindow) / def __init__(self):
		self.tabButtonDict = None

# Add
		if app.BL_MAILBOX:
			self.interface = None

#Add in same class
	if app.BL_MAILBOX:
		def BindInterfaceClass(self, interface):
			from _weakref import proxy
			self.interface = proxy(interface)

# Find in same class
		ui.ScriptWindow.Show(self)

# Add
		if app.BL_MAILBOX:
			self.RefreshItemSlot()

# Find
		setItemVnum = self.wndItem.SetItemSlot

# Add
		if app.BL_MAILBOX:
			if self.interface:
				onTopWindow = self.interface.GetOnTopWindow()

# Find
		self.__HighlightSlot_RefreshCurrentPage()

# Add Above
			if app.BL_MAILBOX:
				if itemVnum and self.interface and onTopWindow:
					if self.interface.MarkUnusableDSInvenSlotOnTopWnd(onTopWindow, slotNumber, player.DRAGON_SOUL_INVENTORY):
						self.wndItem.SetUnusableSlotOnTopWnd(i)
					else:
						self.wndItem.SetUsableSlotOnTopWnd(i)
				else:
					self.wndItem.SetUsableSlotOnTopWnd(i)

# Find
	def SellItem(self):
		...

# Add
	if app.BL_MAILBOX:
		def SetCantMouseEventSlot(self, index):
			slot_index = index - (self.DSKindIndex * 5 * player.DRAGON_SOUL_PAGE_SIZE) - \
				self.inventoryPageIndex * player.DRAGON_SOUL_PAGE_SIZE

			if slot_index < 0 or slot_index >= player.DRAGON_SOUL_PAGE_SIZE:
				return

			self.wndItem.SetCantMouseEventSlot(slot_index)