#include "FreeSubscription.h"

namespace CustomerManager
{

FreeSubscription::FreeSubscription() : Subscription(SubscriptionType::free), kmFree(0)
{

}

unsigned short FreeSubscription::getKmFree()
{
	return kmFree;
}


}  // namespace Design Class
