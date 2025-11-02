#ifndef _CardDAVExample_CardDAVExample_h
#define _CardDAVExample_CardDAVExample_h

#include <Core/Core.h>
#include <CardDAV/CardDAV.h>

using namespace Upp;


// Helpers for CardDAV responses.
String ExtractPrincipalFromXml(const String& xml);
String ExtractAddressBookHomeFromXml(const String& xml);
Vector<String> ExtractAddressBooksFromXml(const String& xml);
VectorMap<String, String> ExtractContactsFromXml(const String& xml);
String GetFormattedTime(Time t);
String MakeVCard();

#endif
