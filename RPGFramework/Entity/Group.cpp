#include "Group.h"
#include "RPGFrameworkCharacter.h"

void UGroup::AddMember(ARPGFrameworkCharacter* memberToAdd)
{
	members.Add(memberToAdd);
}

void UGroup::RemoveMember(ARPGFrameworkCharacter* memberToRemove)
{
	members.Remove(memberToRemove);
}
