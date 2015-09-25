#pragma once
#include <string>
#include <list>

using namespace concurrency;
using namespace Platform;
using namespace Windows::Devices::PointOfService;

class MinPosPrinter {
private:
	void LogLine(_In_ Platform::String^ str);
	Windows::Devices::PointOfService::PosPrinter^ _printer;
	Windows::Devices::PointOfService::ClaimedPosPrinter^ _claimedPrinter;

public:
	void PrintReceipt(_In_ Platform::String^ str);
};
