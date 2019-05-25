#include "Group.h"
#include "RPGFrameworkCharacter.h"

void UGroup::AddMember(ARPGFrameworkCharacter* memberToAdd)
{
	if (memberToAdd->GetGroup() != NULL && memberToAdd->GetGroup() != this)
		members.Add(memberToAdd);
}

void UGroup::RemoveMember(ARPGFrameworkCharacter* memberToRemove)
{
	members.Remove(memberToRemove);
}
