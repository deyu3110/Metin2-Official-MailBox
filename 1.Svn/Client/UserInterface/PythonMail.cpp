/*
* blackdragonx61 / Mali
* 06.09.2021
*/

#include "StdAfx.h"
#include "PythonMail.h"

// CPythonMail:

CPythonMail::CPythonMail()
{
}

CPythonMail::~CPythonMail()
{
	Destroy();
}

void CPythonMail::Destroy()
{
	if (vecMail.empty())
		return;
	
	for (SMailBox* mail : vecMail)
		delete mail;

	vecMail.clear();
}

const CPythonMail::MailVec& CPythonMail::GetMailVec() const
{
	return vecMail;
}

void CPythonMail::ResetAddData(const BYTE Index)
{
	CPythonMail::SMailBox* mail = GetMail(Index);
	if (mail == nullptr)
		return;

	mail->bIsConfirm = true;
	mail->ResetAddData();
}

void CPythonMail::AddMail(CPythonMail::SMailBox* mail)
{
	vecMail.emplace_back(mail);
}

// SMailBox:

CPythonMail::SMailBox::SMailBox(const __time32_t _SendTime, const __time32_t _DeleteTime, const char* _Title,
	const bool _IsGM, const bool _IsItem, const bool _IsConfirm) :
	Sendtime(_SendTime),
	Deletetime(_DeleteTime),
	sTitle(_Title),
	bIsGMPost(_IsGM),
	bIsItemExist(_IsItem),
	bIsConfirm(_IsConfirm),
	AddData(nullptr)
{
}

CPythonMail::SMailBox::~SMailBox()
{
	ResetAddData();
}

void CPythonMail::SMailBox::ResetAddData()
{
	if (AddData == nullptr)
		return;

	delete AddData;
	AddData = nullptr;
}

CPythonMail::SMailBox* CPythonMail::GetMail(const BYTE Index)
{
	const MailVec& mail = GetMailVec();
	if (Index >= mail.size())
		return nullptr;

	return mail.at(Index);
}

// SMailBoxAddData:

CPythonMail::SMailBoxAddData::SMailBoxAddData(const char* _From, const char* _Message, const int _Yang, const int _Won, 
	const DWORD _ItemVnum, const DWORD _ItemCount, const long* _Sockets, const TPlayerItemAttribute* _Attrs) :
	sFrom(_From),
	sMessage(_Message),
	iYang(_Yang),
	iWon(_Won),
	ItemVnum(_ItemVnum),
	ItemCount(_ItemCount)
{
	std::memcpy(alSockets, _Sockets, sizeof(alSockets));
	std::memcpy(aAttr, _Attrs, sizeof(aAttr));
}

CPythonMail::SMailBoxAddData::~SMailBoxAddData()
{
}

CPythonMail::SMailBoxAddData* CPythonMail::GetMailAddData(const BYTE Index)
{
	const CPythonMail::SMailBox* mail = GetMail(Index);
	if (mail == nullptr)
		return nullptr;

	return mail->AddData;
}

// Methods
PyObject* mailGetMailAddData(PyObject* poSelf, PyObject* poArgs)
{
	// (from_name, message, yang, cheque)

	BYTE Index;
	if (!PyTuple_GetByte(poArgs, 0, &Index))
		return Py_BadArgument();

	const CPythonMail::SMailBoxAddData* addData = CPythonMail::Instance().GetMailAddData(Index);
	if (addData == nullptr)
		return Py_BuildNone();

	return Py_BuildValue("ssii", addData->sFrom.c_str(), addData->sMessage.c_str(), addData->iYang, addData->iWon);
}

PyObject* mailGetMailData(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildNone();
}

PyObject* mailGetMailDict(PyObject* poSelf, PyObject* poArgs)
{
	// (index, send_time, delete_time, title, is_gm_post, is_item_exist, is_confirm)
	
	PyObject* dict = PyDict_New();

	BYTE idx = 0;
	for (CPythonMail::SMailBox* mail : CPythonMail::Instance().GetMailVec())
	{
		PyDict_SetItem(dict, Py_BuildValue("i", idx), Py_BuildValue("illsiii", idx, mail->Sendtime, mail->Deletetime, mail->sTitle.c_str(),
			mail->bIsGMPost, mail->bIsItemExist, mail->bIsConfirm));

		idx++;
	}
	
	return dict;
}

PyObject* mailGetMailItemData(PyObject* poSelf, PyObject* poArgs)
{
	BYTE Index;
	if (!PyTuple_GetByte(poArgs, 0, &Index))
		return Py_BadArgument();

	const CPythonMail::SMailBoxAddData* addData = CPythonMail::Instance().GetMailAddData(Index);
	if (addData == nullptr || addData->ItemVnum == 0)
		return Py_BuildNone();

	return Py_BuildValue("ii", addData->ItemVnum, addData->ItemCount);
}

PyObject* mailGetMailItemAttribute(PyObject* poSelf, PyObject* poArgs)
{
	BYTE Index;
	if (!PyTuple_GetByte(poArgs, 0, &Index))
		return Py_BadArgument();
	BYTE AttrSlotIndex;
	if (!PyTuple_GetByte(poArgs, 1, &AttrSlotIndex))
		return Py_BadArgument();

	if ((AttrSlotIndex >= 0 && AttrSlotIndex < ITEM_ATTRIBUTE_SLOT_MAX_NUM) == false)
		return Py_BuildException();

	const CPythonMail::SMailBoxAddData* addData = CPythonMail::Instance().GetMailAddData(Index);
	if (addData == nullptr || addData->ItemVnum == 0)
		return Py_BuildNone();

	return Py_BuildValue("ii", addData->aAttr[AttrSlotIndex].bType, addData->aAttr[AttrSlotIndex].sValue);
}

PyObject* mailGetMailItemMetinSocket(PyObject* poSelf, PyObject* poArgs)
{
	BYTE Index;
	if (!PyTuple_GetByte(poArgs, 0, &Index))
		return Py_BadArgument();
	BYTE SocketIndex;
	if (!PyTuple_GetByte(poArgs, 1, &SocketIndex))
		return Py_BadArgument();

	if (SocketIndex >= ITEM_SOCKET_SLOT_MAX_NUM)
		return Py_BuildException();

	const CPythonMail::SMailBoxAddData* addData = CPythonMail::Instance().GetMailAddData(Index);
	if (addData == nullptr || addData->ItemVnum == 0)
		return Py_BuildNone();

	return Py_BuildValue("i", addData->alSockets[SocketIndex]);
}

void initmail()
{
	static PyMethodDef s_methods[] =
	{
		{ "GetMailAddData",				mailGetMailAddData,						METH_VARARGS },
		{ "GetMailData",				mailGetMailData,						METH_VARARGS },
		{ "GetMailDict",				mailGetMailDict,						METH_VARARGS },
		{ "GetMailItemAttribute",		mailGetMailItemAttribute,				METH_VARARGS },
		{ "GetMailItemData",			mailGetMailItemData,					METH_VARARGS },
		{ "GetMailItemMetinSocket",		mailGetMailItemMetinSocket,				METH_VARARGS },
		{ NULL,							NULL,									NULL		 },
	};

	PyObject* poModule = Py_InitModule("mail", s_methods);

	/*GC*/
	using enum CPythonMail::EMAILBOX_GC;
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_OPEN", MAILBOX_GC_OPEN);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_POST_WRITE_CONFIRM", MAILBOX_GC_POST_WRITE_CONFIRM);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_POST_WRITE", MAILBOX_GC_POST_WRITE);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_SET", MAILBOX_GC_SET);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_ADD_DATA", MAILBOX_GC_ADD_DATA);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_POST_GET_ITEMS", MAILBOX_GC_POST_GET_ITEMS);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_POST_DELETE", MAILBOX_GC_POST_DELETE);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_POST_ALL_DELETE", MAILBOX_GC_POST_ALL_DELETE);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_POST_ALL_GET_ITEMS", MAILBOX_GC_POST_ALL_GET_ITEMS);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_UNREAD_DATA", MAILBOX_GC_UNREAD_DATA);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_ITEM_EXPIRE", MAILBOX_GC_ITEM_EXPIRE);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_CLOSE", MAILBOX_GC_CLOSE);
	PyModule_AddIntConstant(poModule, "MAILBOX_GC_SYSTEM_CLOSE", MAILBOX_GC_SYSTEM_CLOSE);
	/*GC END*/

	/*POST_ALL_DELETE*/
	using enum CPythonMail::EMAILBOX_POST_ALL_DELETE;
	PyModule_AddIntConstant(poModule, "POST_ALL_DELETE_FAIL", POST_ALL_DELETE_FAIL);
	PyModule_AddIntConstant(poModule, "POST_ALL_DELETE_OK", POST_ALL_DELETE_OK);
	PyModule_AddIntConstant(poModule, "POST_ALL_DELETE_FAIL_EMPTY", POST_ALL_DELETE_FAIL_EMPTY);
	PyModule_AddIntConstant(poModule, "POST_ALL_DELETE_FAIL_DONT_EXIST", POST_ALL_DELETE_FAIL_DONT_EXIST);
	/*POST_ALL_DELETE END*/
	
	/*POST_ALL_GET_ITEMS*/
	using enum CPythonMail::EMAILBOX_POST_ALL_GET_ITEMS;
	PyModule_AddIntConstant(poModule, "POST_ALL_GET_ITEMS_FAIL", POST_ALL_GET_ITEMS_FAIL);
	PyModule_AddIntConstant(poModule, "POST_ALL_GET_ITEMS_OK", POST_ALL_GET_ITEMS_OK);
	PyModule_AddIntConstant(poModule, "POST_ALL_GET_ITEMS_EMPTY", POST_ALL_GET_ITEMS_EMPTY);
	PyModule_AddIntConstant(poModule, "POST_ALL_GET_ITEMS_FAIL_DONT_EXIST", POST_ALL_GET_ITEMS_FAIL_DONT_EXIST);
	PyModule_AddIntConstant(poModule, "POST_ALL_GET_ITEMS_FAIL_CANT_GET", POST_ALL_GET_ITEMS_FAIL_CANT_GET);
	PyModule_AddIntConstant(poModule, "POST_ALL_GET_ITEMS_FAIL_USE_TIME_LIMIT", POST_ALL_GET_ITEMS_FAIL_USE_TIME_LIMIT);
	/*POST_ALL_GET_ITEMS END*/

	/*POST_DELETE_FAIL*/
	using enum CPythonMail::EMAILBOX_POST_DELETE_FAIL;
	PyModule_AddIntConstant(poModule, "POST_DELETE_FAIL", POST_DELETE_FAIL);
	PyModule_AddIntConstant(poModule, "POST_DELETE_OK", POST_DELETE_OK);
	PyModule_AddIntConstant(poModule, "POST_DELETE_FAIL_EXIST_ITEMS", POST_DELETE_FAIL_EXIST_ITEMS);
	PyModule_AddIntConstant(poModule, "POST_TIME_OUT_DELETE", POST_TIME_OUT_DELETE);
	/*POST_DELETE_FAIL END*/

	/*POST_GET_ITEMS*/
	using enum CPythonMail::EMAILBOX_POST_GET_ITEMS;
	PyModule_AddIntConstant(poModule, "POST_GET_ITEMS_FAIL", POST_GET_ITEMS_FAIL);
	PyModule_AddIntConstant(poModule, "POST_GET_ITEMS_OK", POST_GET_ITEMS_OK);
	PyModule_AddIntConstant(poModule, "POST_GET_ITEMS_NONE", POST_GET_ITEMS_NONE);
	PyModule_AddIntConstant(poModule, "POST_GET_ITEMS_NOT_ENOUGHT_INVENTORY", POST_GET_ITEMS_NOT_ENOUGHT_INVENTORY);
	PyModule_AddIntConstant(poModule, "POST_GET_ITEMS_YANG_OVERFLOW", POST_GET_ITEMS_YANG_OVERFLOW);
	PyModule_AddIntConstant(poModule, "POST_GET_ITEMS_WON_OVERFLOW", POST_GET_ITEMS_WON_OVERFLOW);
	PyModule_AddIntConstant(poModule, "POST_GET_ITEMS_FAIL_BLOCK_CHAR", POST_GET_ITEMS_FAIL_BLOCK_CHAR);
	PyModule_AddIntConstant(poModule, "POST_GET_ITEMS_USE_TIME_LIMIT", POST_GET_ITEMS_USE_TIME_LIMIT);
	PyModule_AddIntConstant(poModule, "POST_GET_ITEMS_RESULT_MAX", POST_GET_ITEMS_RESULT_MAX);
	/*POST_GET_ITEMS END*/
	
	/*POST_WRITE*/
	using enum CPythonMail::EMAILBOX_POST_WRITE;
	PyModule_AddIntConstant(poModule, "POST_WRITE_FAIL", POST_WRITE_FAIL);
	PyModule_AddIntConstant(poModule, "POST_WRITE_OK", POST_WRITE_OK);
	PyModule_AddIntConstant(poModule, "POST_WRITE_INVALID_NAME", POST_WRITE_INVALID_NAME);
	PyModule_AddIntConstant(poModule, "POST_WRITE_TARGET_BLOCKED", POST_WRITE_TARGET_BLOCKED);
	PyModule_AddIntConstant(poModule, "POST_WRITE_BLOCKED_ME", POST_WRITE_BLOCKED_ME);
	PyModule_AddIntConstant(poModule, "POST_WRITE_FULL_MAILBOX", POST_WRITE_FULL_MAILBOX);
	PyModule_AddIntConstant(poModule, "POST_WRITE_WRONG_TITLE", POST_WRITE_WRONG_TITLE);
	PyModule_AddIntConstant(poModule, "POST_WRITE_YANG_NOT_ENOUGHT", POST_WRITE_YANG_NOT_ENOUGHT);
	PyModule_AddIntConstant(poModule, "POST_WRITE_WON_NOT_ENOUGHT", POST_WRITE_WON_NOT_ENOUGHT);
	PyModule_AddIntConstant(poModule, "POST_WRITE_WRONG_MESSAGE", POST_WRITE_WRONG_MESSAGE);
	PyModule_AddIntConstant(poModule, "POST_WRITE_WRONG_ITEM", POST_WRITE_WRONG_ITEM);
	PyModule_AddIntConstant(poModule, "POST_WRITE_LEVEL_NOT_ENOUGHT", POST_WRITE_LEVEL_NOT_ENOUGHT);
	PyModule_AddIntConstant(poModule, "POST_WRITE_USE_TIME_LIMIT", POST_WRITE_USE_TIME_LIMIT);
	/*POST_WRITE END*/
}
