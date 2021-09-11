# Add to end
	if app.BL_MAILBOX:
		def MailBoxProcess(self, type, data):
			if self.interface:
				self.interface.MailBoxProcess( type, data )