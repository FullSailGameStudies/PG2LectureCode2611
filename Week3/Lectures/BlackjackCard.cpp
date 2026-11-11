#include "BlackjackCard.h"

int BlackjackCard::Value() const
{
    if (face_ == "J" || face_ == "Q" || face_ == "K") return 10;
    return Card::Value();
}
