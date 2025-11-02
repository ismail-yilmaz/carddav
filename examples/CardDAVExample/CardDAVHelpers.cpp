#include "CardDAVExample.h"


using namespace Upp;

static const XmlNode& sFindNode(const XmlNode& node, const String& tag)
{
	if(node.IsTag(tag) && node.GetCount())
		return node[0];

	for(const XmlNode& child : node) {
		if(child.IsTag()) {
			if(const XmlNode& r = sFindNode(child, tag); !r.IsVoid())
				return r;
		}
	}

	return XmlNode::Void();
}

static void sExtractRefs(const XmlNode& n, Vector<String>& hrefs, bool& addr)
{
	if(n.IsTag("response")) {
		addr = false;
		for(const XmlNode& child : n)
			sExtractRefs(child, hrefs, addr);
	}
	else
	if(n.IsTag("CR:addressbook")) {
		addr = true;
	}
	else
	if(n.IsTag("href")) {
		if(addr && n.GetCount()) {
			hrefs.Add(n[0].GetText());
			addr = false;
		}
	}
	
	for(const XmlNode& child : n)
		sExtractRefs(child, hrefs, addr);
}

static void sExtractContacts(const XmlNode& n, VectorMap<String, String>& contacts)
{
    if(n.IsTag("response")) {
        String href;
        String vcardData;
        
         for(const XmlNode& child : n) {
            if(child.IsTag("href") && child.GetCount()) {
                href = child[0].GetText();
            }
            else if(child.IsTag("propstat")) {
                for(const XmlNode& prop : child) {
                    if(prop.IsTag("prop")) {
                        for(const XmlNode& propchild : prop) {
                            if(propchild.IsTag("CR:address-data") && propchild.GetCount()) {
                                vcardData = propchild[0].GetText();
                            }
                        }
                    }
                }
            }
        }
        
        // Only add if we found both href and vCard data
        if(!href.IsEmpty() && !vcardData.IsEmpty()) {
            contacts.FindAdd(href, vcardData);
        }
        return;
    }
    for(const XmlNode& child : n) {
        sExtractContacts(child, contacts);
    }
}
String ExtractPrincipalFromXml(const String& xml)
{
	const XmlNode& node = ParseXML(xml);
	const XmlNode& principal = sFindNode(node, "current-user-principal");
	return sFindNode(principal, "href").GetText();
}

String ExtractAddressBookHomeFromXml(const String& xml)
{
	const XmlNode& node = ParseXML(xml);
	const XmlNode& home_set = sFindNode(node, "C:addressbook-home-set");
	return sFindNode(home_set, "D:href").GetText();
}

Vector<String> ExtractAddressBooksFromXml(const String& xml)
{
	bool addr = false;
	Vector<String> urls;
	sExtractRefs(ParseXML(xml), urls, addr);
	return pick(urls);
}

VectorMap<String, String> ExtractContactsFromXml(const String& xml)
{
	bool ev = false;
	VectorMap<String, String> urls;
	sExtractContacts(ParseXML(xml), urls);
	return pick(urls);
}

String GetFormattedTime(Time t)
{
	return Format("%04d%02d%02dT%02d%02d%02dZ", t.year, t.month, t.day, t.hour, t.minute, t.second);
}

String MakeVCard()
{
	String vcard =
		"BEGIN:VCARD\r\n"
		"VERSION:3.0\r\n"
		"FN:John Doe\r\n"                                      // Full Name
		"N:Doe;John;;;\r\n"                                    // Structured Name (Family;Given;Middle;Prefix;Suffix)
		"ORG:Example Company\r\n"                              // Organization
		"TITLE:Software Developer\r\n"                         // Job Title
		"TEL;TYPE=WORK,VOICE:+1234567890\r\n"                  // Work Phone
		"TEL;TYPE=HOME,VOICE:+0987654321\r\n"                  // Home Phone
		"EMAIL;TYPE=WORK:john.doe@example.com\r\n"             // Email
		"ADR;TYPE=WORK:;;123 Main St;City;State;12345;USA\r\n" // Address
		"URL:https://www.example.com\r\n"                      // Website
		"NOTE:This is a test vCard from U++\r\n"               // Note
		"REV:" + GetFormattedTime(GetSysTime()) + "\r\n"       // Revision timestamp
		"UID:" + AsString(UuidValueGen().Get()) + "\r\n"       // Unique ID
		"END:VCARD\r\n";
	return vcard;
}