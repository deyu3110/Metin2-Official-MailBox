quest mailbox begin
	state start begin
        when 30308.chat."Open Mailbox" begin
            setskin(NOWINDOW)
            game.open_mailbox()
        end
    end
end