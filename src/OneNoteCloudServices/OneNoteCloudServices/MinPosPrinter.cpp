#include "MinPosPrinter.h"

void MinPosPrinter::PrintReceipt(_In_ Platform::String^ contentStr)
{
	try
	{
		Platform::String^ str = PosPrinter::GetDeviceSelector();
		LogLine("GetDeviceSelector() returned:" + str);

		//----- open -----
		_printer = nullptr;
		create_task(_printer->GetDefaultAsync()).then([this](PosPrinter^ posp)
		{
			_printer = posp;
		}).wait(); // wait for reply - designed to block calling task - not meant for UI threads

		if (_printer == nullptr)
		{
			LogLine("PrintReceipt() ERR: Cannot Open printer.");
			return;
		}
		LogLine("PrintReceipt() OK: Got a printer. ID='" + _printer->DeviceId);


		//----- claim -----
		_claimedPrinter = nullptr;
		create_task(_printer->ClaimPrinterAsync()).then([this](ClaimedPosPrinter^ claim)
		{
			_claimedPrinter = claim;
		}).wait();

		if (_claimedPrinter == nullptr)
		{
			LogLine("PrintReceipt() ERR: Cannot Claim printer.");
			return;
		}
		LogLine("PrintReceipt() OK: Claimed printer. ID='" + _printer->DeviceId);

		//----- enable -----
		create_task(_claimedPrinter->EnableAsync()).then([this](bool isEnabled)
		{
			LogLine(isEnabled ? "PrintReceipt() OK: Enabled" : "PrintReceipt() ERR: Cannot Enable.");
		}).wait();

		//----- establish receipt area -----
		ClaimedReceiptPrinter^ receipt = _claimedPrinter->Receipt;
		if (receipt == nullptr)
		{
			LogLine("PrintReceipt() ERR: Cannot established Receipt area.");
			return;
		}

		//----- create print job -----
		ReceiptPrintJob^ job = receipt->CreateJob();
		if (job == nullptr)
		{
			LogLine("PrintReceipt() ERR: Cannot start print Job.");
			return;
		}
		LogLine("PrintReceipt() OK: starting print Job..");
		job->Print(contentStr);

		//----- end of receipt -----
		job->PrintLine("");
		job->PrintLine("--------------------");
		unsigned int linesBeforeCut = receipt->LinesToPaperCut;
		for (unsigned int i = 0; i < linesBeforeCut + 3; ++i) job->PrintLine("");
		job->CutPaper();

		//----- ececute print job -----
		create_task(job->ExecuteAsync()).then([this](bool succeeded)
		{
			LogLine(succeeded ? "PrintReceipt() OK: ExecuteAsync successful." : "PrintReceipt() ERR: Could not Execute job.");
		});

	}
	catch (Exception^ ex)
	{
		LogLine("PrintReceipt() EXCEPTION: err=" + ex->Message);
	}
}


void MinPosPrinter::LogLine(_In_ Platform::String^ str)
{
	if (IsDebuggerPresent()) {
		OutputDebugStringW(str->Data());
		OutputDebugStringW(L"\n");
	}
}