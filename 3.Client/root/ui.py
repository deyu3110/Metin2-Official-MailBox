# Find in class Window(object) / def __init__(self, layer = "UI")
		self.Hide()

# Add
		if app.BL_MAILBOX:
			self.onMouseLeftButtonUpEventArgs = None
			self.overFunc = None
			self.overArgs = None
			self.overOutFunc = None
			self.overOutArgs = None

# Find
		wndMgr.Destroy(self.hWnd)

# Add
		if app.BL_MAILBOX:
			self.onMouseLeftButtonUpEventArgs = None
			self.overFunc = None
			self.overArgs = None
			self.overOutFunc = None
			self.overOutArgs = None

# Find
	def SetOnMouseLeftButtonUpEvent(self, event):
		self.onMouseLeftButtonUpEvent = event
			
	def OnMouseLeftButtonUp(self):
		if self.onMouseLeftButtonUpEvent:
			self.onMouseLeftButtonUpEvent()

# Change
	if app.BL_MAILBOX:
		def OnMouseOverIn(self):
			if self.overFunc:
				apply(self.overFunc, self.overArgs )
		def OnMouseOverOut(self):
			if self.overOutFunc:
				apply(self.overOutFunc, self.overOutArgs )
		def SetOverEvent(self, func, *args):
			self.overFunc = func
			self.overArgs = args
		def SetOverOutEvent(self, func, *args):
			self.overOutFunc = func
			self.overOutArgs = args

		def SetOnMouseLeftButtonUpEvent(self, event, *args):
			self.onMouseLeftButtonUpEvent		= event
			self.onMouseLeftButtonUpEventArgs	= args
			
		def OnMouseLeftButtonUp(self):
			if self.onMouseLeftButtonUpEvent:
				apply( self.onMouseLeftButtonUpEvent, self.onMouseLeftButtonUpEventArgs )
	else:
		def SetOnMouseLeftButtonUpEvent(self, event):
			self.onMouseLeftButtonUpEvent = event
			
		def OnMouseLeftButtonUp(self):
			if self.onMouseLeftButtonUpEvent:
				self.onMouseLeftButtonUpEvent()

# Find in class ImageBox(Window) / def __init__(self, layer = "UI")
		self.eventDict={}

# Add
		if app.BL_MAILBOX:
			self.eventFunc = {"mouse_click" : None, "mouse_over_in" : None, "mouse_over_out" : None}
			self.eventArgs = {"mouse_click" : None, "mouse_over_in" : None, "mouse_over_out" : None}
			
# Find in same class
		Window.__del__(self)

# Add
		if app.BL_MAILBOX:
			self.eventFunc = None
			self.eventArgs = None

# Find
	def SAFE_SetStringEvent(self, event, func):
		...

# Add
	if app.BL_MAILBOX:
		def SetEvent(self, func, *args) :
			result = self.eventFunc.has_key(args[0])		
			if result :
				self.eventFunc[args[0]] = func
				self.eventArgs[args[0]] = args
			else :
				print "[ERROR] ui.py SetEvent, Can`t Find has_key : %s" % args[0]

		def OnMouseLeftButtonUp(self) :
			if self.eventFunc["mouse_click"] :
				apply(self.eventFunc["mouse_click"], self.eventArgs["mouse_click"])

		def OnMouseOverIn(self) :
			if self.eventFunc["mouse_over_in"] :
				apply(self.eventFunc["mouse_over_in"], self.eventArgs["mouse_over_in"])
			else:
				try:
					self.eventDict["MOUSE_OVER_IN"]()
				except KeyError:
					pass

		def OnMouseOverOut(self) :
			if self.eventFunc["mouse_over_out"] :
				apply(self.eventFunc["mouse_over_out"], self.eventArgs["mouse_over_out"])
			else :
				try:
					self.eventDict["MOUSE_OVER_OUT"]()
				except KeyError:
					pass

# Find
	def SetDelay(self, delay):
		wndMgr.SetDelay(self.hWnd, delay)

# Add
	if app.BL_MAILBOX:
		def ResetFrame(self):
			wndMgr.ResetFrame(self.hWnd)

# Find
	def Flash(self):
		wndMgr.Flash(self.hWnd)

# Add
	if app.BL_MAILBOX:
		def EnableFlash(self):
			wndMgr.EnableFlash(self.hWnd)

		def DisableFlash(self):
			wndMgr.DisableFlash(self.hWnd)

# Find
		self.middleBar.SetPosition(self.MIDDLE_BAR_POS, int(newPos) + self.SCROLLBAR_BUTTON_HEIGHT + self.MIDDLE_BAR_UPPER_PLACE)

# Change
		if app.BL_MAILBOX:
			self.middleBar.SetPosition(self.MIDDLE_BAR_POS, round(float(newPos) + self.SCROLLBAR_BUTTON_HEIGHT + self.MIDDLE_BAR_UPPER_PLACE) )
		else:		
			self.middleBar.SetPosition(self.MIDDLE_BAR_POS, int(newPos) + self.SCROLLBAR_BUTTON_HEIGHT + self.MIDDLE_BAR_UPPER_PLACE)

# Find
	def UnlockScroll(self):
		...

# Add
	if app.BL_MAILBOX:
		def SetUpButtonSizeRefresh(self):
			self.SCROLLBAR_WIDTH			= self.upButton.GetWidth()
			self.SCROLLBAR_BUTTON_WIDTH		= self.upButton.GetWidth()
			self.SCROLLBAR_BUTTON_HEIGHT	= self.upButton.GetHeight()
		
		def SetUpButtonUpVisual(self, img_path):
			if self.upButton:
				self.upButton.SetUpVisual( img_path )
		def SetUpButtonOverVisual(self, img_path):
			if self.upButton:
				self.upButton.SetOverVisual( img_path )
		def SetUpButtonDownVisual(self, img_path):
			if self.upButton:
				self.upButton.SetDownVisual( img_path )
		def SetDownButtonUpVisual(self, img_path):
			if self.downButton:
				self.downButton.SetUpVisual( img_path )
		def SetDownButtonOverVisual(self, img_path):
			if self.downButton:
				self.downButton.SetOverVisual( img_path )
		def SetDownButtonDownVisual(self, img_path):
			if self.downButton:
				self.downButton.SetDownVisual( img_path )

# Find
	LIST_BOX_KEY_LIST = ( "width", "height", )

# Add
	if app.BL_MAILBOX:
		RENDER_BOX_KEY_LIST = ( "color", )

# Find
			elif Type == "listboxex":
				parent.Children[Index] = ListBoxEx()
				parent.Children[Index].SetParent(parent)
				self.LoadElementListBoxEx(parent.Children[Index], ElementValue, parent)

# Add
			elif app.BL_MAILBOX and Type == "renderbox":
				parent.Children[Index] = RenderBox()
				parent.Children[Index].SetParent(parent)
				self.LoadElementRenderBox(parent.Children[Index], ElementValue, parent)

# Find
	def LoadElementListBoxEx(self, window, value, parentWindow):
		...

# Add
	if app.BL_MAILBOX:
		def	LoadElementRenderBox(self, window, value, parentWindow):
			if False == self.CheckKeyList(value["name"], value, self.RENDER_BOX_KEY_LIST):
				return False
			
			window.SetSize(value["width"], value["height"])
			self.LoadDefaultData(window, value, parentWindow)
			
			if value.has_key("color"):
				window.SetColor(int(value["color"]))
				
			return True

# Find
RegisterToolTipWindow("TEXT", TextLine)

# Add
if app.BL_MAILBOX:
	class RenderBox(Window):
		def __init__(self, layer = "UI"):
			Window.__init__(self, layer)
			self.color = 0xFF000000
		def __del__(self):
			Window.__del__(self)
			self.color = 0xFF000000
			
		def RegisterWindow(self, layer):
			self.hWnd = wndMgr.Register(self, layer)
			
		def SetColor(self, color):
			self.color = color
			
		def OnRender(self):
			(x, y, width, height) = self.GetRect()
			grp.SetColor( self.color )
			grp.RenderBar( x, y, width, height )
