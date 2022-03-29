#include "WeChatDLL.h"
#include "public/WinApi.h"
#include "InlineHook/InlineHook.h"
#include "MinHook/MinHook.h"
#include "Function/��־��ӡ.h"
#include "Function/΢�Ŷ࿪.h"
#include "Function/��Ϣ���.h"
#include "Function/ͨѶ¼.h"
#include "Function/��Ϣ�ϴ�.h"



void test(int a)
{
	a = 1;
}

void WeChatDLL::InitDLL()
{
	m_hWeChatWinDLL = (DWORD)LoadLibraryA("WeChatWin.dll");

	Patch_΢�Ŷ࿪();
	//HOOK_��־��ӡ();
	HOOK_��Ϣ���();
	HOOK_Contact();
	PLUGIN_��Ϣ�ϴ�();
}

WeChatDLL::WeChatDLL()
{
	MH_Initialize();

	m_MsgRecvLoger = spdlog::basic_logger_mt("MsgRecv", "logs/MsgRecv_" + std::to_string(GetCurrentProcessId()) + ".log");
	m_MsgRecvLoger->flush_on(spdlog::level::err);
	m_WechatDLLLoger = spdlog::basic_logger_mt("WeChatDLL", "logs/WeChatDLL_" + std::to_string(GetCurrentProcessId()) + ".log");
	m_WechatDLLLoger->flush_on(spdlog::level::err);
}

WeChatDLL::~WeChatDLL()
{
	MH_Uninitialize();
}

WeChatDLL* WeChatDLL::Instance()
{
	static WeChatDLL Wechat;
	return &Wechat;
}

std::shared_ptr<spdlog::logger>& WeChatDLL::MsgRecvLogger()
{
	return this->m_MsgRecvLoger;
}

std::shared_ptr<spdlog::logger>& WeChatDLL::WeChatLogger()
{
	return this->m_WechatDLLLoger;
}

DWORD WeChatDLL::getWinMoudule()
{
	return m_hWeChatWinDLL;
}

void WeChatDLL::FreeDLL()
{

}