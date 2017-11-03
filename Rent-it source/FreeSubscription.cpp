#include "FreeSubscription.h"

namespace CustomerManager
{

static unsigned short kmFree = 0;

FreeSubscription::FreeSubscription()  : type(SubscriptionType::free)
{

}

unsigned short FreeSubscription::getKmFree()
{
	return kmFree;
}


}  // namespace Design Class
