//Find
PyObject * messengerRemoveFriend(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(__BL_MAILBOX__)
PyObject* messengerGetFriendNames(PyObject* poSelf, PyObject* poArgs)
{
	const CPythonMessenger& messenger = CPythonMessenger::Instance();
	PyObject* Tuple = PyTuple_New(messenger.m_FriendNameMap.size());

	uint16_t i = 0;
	for (const std::string& sFriendName : messenger.m_FriendNameMap)
		PyTuple_SetItem(Tuple, i++, PyString_FromString(sFriendName.c_str()));

	return Tuple;
}
#endif

//Find
		{ "RemoveFriend",				messengerRemoveFriend,				METH_VARARGS },

///Add
#if defined(__BL_MAILBOX__)
		{ "GetFriendNames",				messengerGetFriendNames,			METH_VARARGS },
#endif