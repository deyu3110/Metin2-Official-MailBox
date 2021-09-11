#Add to end

import app
if app.BL_MAILBOX:
	window["children"][0]["children"] = window["children"][0]["children"] + (
					## MailBox
					{
						"name" : "MailBoxButton",
						"type" : "button",

						"x" : 110,
						"y" : 30,

						"default_image" : "d:/ymir work/ui/game/mailbox/post_minimap.sub",
						"over_image" : "d:/ymir work/ui/game/mailbox/post_minimap.sub",
						"down_image" : "d:/ymir work/ui/game/mailbox/post_minimap.sub",
					},
					{
						"name" : "MailBoxEffect",
						"type" : "ani_image",
						
						"x" : 110,
						"y" : 30,
						
						"delay" : 6,

						"images" :
						(
							"d:/ymir work/ui/game/mailbox/minimap_flash/2.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/3.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/4.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/5.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/4.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/3.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/2.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/1.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/1.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/1.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/1.sub",
							"d:/ymir work/ui/game/mailbox/minimap_flash/1.sub",
						),
					},)