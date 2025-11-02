#ifndef _WebDAV_CardDAV_h_
#define _WebDAV_CardDAV_h_

#include <WebDAV/WebDAV.h>

namespace Upp {

class CardDAVRequest : public WebDAVRequest {
public:
	CardDAVRequest();
	CardDAVRequest(const String& host, int port = 443);
	virtual ~CardDAVRequest();
	
	// Non-blocking initializers (use with Do() method)
	void    StartGetCurrentUserPrincipal();
	void    StartGetAddressBookHomeSet(const String& path);
	void    StartGetAddressBooks(const String& path);
	void    StartGetContacts(const String& path, const String& filter = Null);
	void    StartGetContacts(const String& path, const Vector<String>& urls);
	void    StartAddContact(const String& path, const String& vcard_data);
	void    StartUpdateContact(const String& path, const String& vcard_data, const String& etag = Null);
	void    StartDeleteContact(const String& path);
	void    StartGetContact(const String& path);
	
	// Blocking variants
	String  GetCurrentUserPrincipal();
	String  GetAddressBookHomeSet(const String& path);
	String  GetAddressBooks(const String& path);
	String  GetContacts(const String& path, const String& filter = Null);
	String  GetContacts(const String& path, const Vector<String>& urls);
	bool    AddContact(const String& path, const String& vcard_data);
	bool    UpdateContact(const String& path, const String& vcard_data, const String& etag = Null);
	bool    DeleteContact(const String& path);
	String  GetContact(const String& path);
};

}

#endif