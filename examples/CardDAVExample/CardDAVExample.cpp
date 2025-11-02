#include "CardDAVExample.h"

using namespace Upp;

String DiscoverPrincipal(CardDAVRequest& card)
{
	String xml = card.GetCurrentUserPrincipal();
	if(!card.IsSuccess()) {
		LOG("ERROR: Failed to discover principal - " << card.GetErrorDesc());
		return Null;
	}
	
	String principal = ExtractPrincipalFromXml(xml);
	LOG("Principal: " << principal);
	return principal;
}

String DiscoverAddressbookHome(CardDAVRequest& card, const String& principal)
{
	String xml = card.GetAddressBookHomeSet(principal);
	if(!card.IsSuccess()) {
		LOG("ERROR: Failed to get addressbook home - " << card.GetErrorDesc());
		return Null;
	}
	
	String homeset = ExtractAddressBookHomeFromXml(xml);
	LOG("Addressbook home: " << Nvl(homeset, principal));
	return Nvl(homeset, principal);
}

Vector<String> DiscoverAddressbooks(CardDAVRequest& card, const String& homeset)
{
	String xml = card.GetAddressBooks(homeset);
	if(!card.IsSuccess()) {
		LOG("ERROR: Failed to get addressbooks - " << card.GetErrorDesc());
		return {};
	}
	
	Vector<String> addressbooks = ExtractAddressBooksFromXml(xml);
	LOG("Found " << addressbooks.GetCount() << " addressbook(s):");
	for(const String& path : addressbooks)
		LOG("  " << path);
	
	return addressbooks;
}

bool CreateContact(CardDAVRequest& card, const String& addressbook_path)
{
	String vcard = MakeVCard();
	bool success = card.AddContact(addressbook_path, vcard);
	
	if(success)
		LOG("Contact created in: " << addressbook_path);
	else
		LOG("ERROR: Failed to create contact - " << card.GetErrorDesc());
	
	return success;
}

VectorMap<String, String> QueryContacts(CardDAVRequest& card, const String& addressbook_path, 
                                         const String& filter = Null)
{
	String xml = card.GetContacts(addressbook_path, filter);
	if(!card.IsSuccess()) {
		LOG("ERROR: Failed to query contacts - " << card.GetErrorDesc());
		return {};
	}
	
	VectorMap<String, String> contacts = ExtractContactsFromXml(xml);
	if(!IsNull(filter))
		LOG("Found " << contacts.GetCount() << " contact(s) matching '" << filter << "'");
	else
		LOG("Found " << contacts.GetCount() << " contact(s)");
	
	return contacts;
}

void DisplayContacts(const VectorMap<String, String>& contacts)
{
	for(int i = 0; i < contacts.GetCount(); i++) {
		LOG("\n--- Contact " << (i + 1) << " ---");
		LOG("URL: " << contacts.GetKey(i));
		LOG("vCard:\n" << contacts[i]);
	}
}

CONSOLE_APP_MAIN
{
	// Note that this example requires a running CardDAV service.
	// In order to test locally, radical CardDAV server can be used.
	// E.g.: radicale --storage-filesystem-folder=~/.radicale/collections --auth-type=none
	// Change the username and port accordingly.

	StdLogSetup(LOG_FILE | LOG_COUT);
	
	CardDAVRequest card("localhost", 5232);
	card.User("username", Null);

	// Discovery flow
	String principal = DiscoverPrincipal(card);
	if(IsNull(principal))
		return;
	

	String homeset = DiscoverAddressbookHome(card, principal);
	if(IsNull(homeset))
		return;
	
	Vector<String> addressbooks = DiscoverAddressbooks(card, homeset);
	if(addressbooks.IsEmpty()) {
		LOG("No addressbooks found");
		return;
	}

	// Work with first addressbook
	String addressbook = addressbooks[0];
	
	// Create a contact
	CreateContact(card, addressbook);
		
	// Query all contacts
	VectorMap<String, String> contacts = QueryContacts(card, addressbook);
	
	// Query contacts by name
	VectorMap<String, String> filtered = QueryContacts(card, addressbook, "John");
	
	// Display results
	DisplayContacts(contacts);
}