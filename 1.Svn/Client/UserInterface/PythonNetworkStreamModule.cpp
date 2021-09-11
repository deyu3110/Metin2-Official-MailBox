//Find
PyObject* netRegisterErrorLog(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Add
#if defined(__BL_MAILBOX__)
PyObject* netSendPostWriteConfirm(PyObject* poSelf, PyObject* poArgs)
{
	char* szName;
	if (!PyTuple_GetString(poArgs, 0, &szName))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendPostWriteConfirm(szName);
	return Py_BuildNone();
}

PyObject* netSendMailBoxClose(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream::Instance().SendMailBoxClose();
	return Py_BuildNone();
}

PyObject* netSendPostAllDelete(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream::Instance().SendPostAllDelete();
	return Py_BuildNone();
}

PyObject* netSendPostAllGetItems(PyObject* poSelf, PyObject* poArgs)
{
	CPythonNetworkStream::Instance().SendPostAllGetItems();
	return Py_BuildNone();
}

PyObject* netSendPostDelete(PyObject* poSelf, PyObject* poArgs)
{
	BYTE index;
	if (!PyTuple_GetByte(poArgs, 0, &index))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendPostDelete(index);
	return Py_BuildNone();
}

PyObject* netSendPostGetItems(PyObject* poSelf, PyObject* poArgs)
{
	BYTE index;
	if (!PyTuple_GetByte(poArgs, 0, &index))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendPostGetItems(index);
	return Py_BuildNone();
}

PyObject* netSendPostWrite(PyObject* poSelf, PyObject* poArgs)
{
	BYTE Idx = 0;

	char* szName;
	if (!PyTuple_GetString(poArgs, Idx++, &szName))
		return Py_BuildException();

	char* szTitle;
	if (!PyTuple_GetString(poArgs, Idx++, &szTitle))
		return Py_BuildException();

	char* szMessage;
	if (!PyTuple_GetString(poArgs, Idx++, &szMessage))
		return Py_BuildException();

	TItemPos Cell;
	if (!PyTuple_GetByte(poArgs, Idx++, &Cell.window_type))
		return Py_BuildException();
	if (!PyTuple_GetInteger(poArgs, Idx++, &Cell.cell))
		return Py_BuildException();

	int iYang;
	if (!PyTuple_GetInteger(poArgs, Idx++, &iYang))
		return Py_BuildException();

	int iWon;
	if (!PyTuple_GetInteger(poArgs, Idx++, &iWon))
		return Py_BuildException();

	CPythonNetworkStream::Instance().SendPostWrite(szName, szTitle, szMessage, Cell, iYang, iWon);
	return Py_BuildNone();
}

PyObject* netRequestPostAddData(PyObject* poSelf, PyObject* poArgs)
{
	BYTE ButtonIndex;
	if (!PyTuple_GetByte(poArgs, 0, &ButtonIndex))
		return Py_BuildException();

	BYTE DataIndex;
	if (!PyTuple_GetByte(poArgs, 1, &DataIndex))
		return Py_BuildException();

	CPythonNetworkStream::Instance().RequestPostAddData(ButtonIndex, DataIndex);
	return Py_BuildNone();
}
#endif

//Find
		{ "SendSelectItemPacket",					netSendSelectItemPacket,					METH_VARARGS },

///Add
#if defined(__BL_MAILBOX__)
		{ "SendPostDelete",							netSendPostDelete,							METH_VARARGS },
		{ "SendPostGetItems",						netSendPostGetItems,						METH_VARARGS },
		{ "SendPostWriteConfirm",					netSendPostWriteConfirm,					METH_VARARGS },
		{ "SendPostWrite",							netSendPostWrite,							METH_VARARGS },
		{ "SendMailBoxClose",						netSendMailBoxClose,						METH_VARARGS },
		{ "SendPostAllDelete",						netSendPostAllDelete,						METH_VARARGS },
		{ "SendPostAllGetItems",					netSendPostAllGetItems,						METH_VARARGS },
		{ "RequestPostAddData",						netRequestPostAddData,						METH_VARARGS },
#endif