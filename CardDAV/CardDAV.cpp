#include "CardDAV.h"

namespace Upp {

namespace {

constexpr const char *sPrincipalQuery =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<D:propfind xmlns:D=\"DAV:\">"
	"<D:prop>"
	"<D:current-user-principal/>"
	"</D:prop>"
	"</D:propfind>";

constexpr const char *sAddressBookHomeQuery =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<D:propfind xmlns:D=\"DAV:\" xmlns:C=\"urn:ietf:params:xml:ns:carddav\">"
	"<D:prop>"
	"<C:addressbook-home-set/>"
	"</D:prop>"
	"</D:propfind>";

constexpr const char *sAddressBookPropFind =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<D:propfind xmlns:D=\"DAV:\" xmlns:C=\"urn:ietf:params:xml:ns:carddav\">"
	"<D:prop>"
	"<D:resourcetype/>"
	"<D:displayname/>"
	"<C:supported-address-data/>"
	"<C:addressbook-description/>"
	"</D:prop>"
	"</D:propfind>";

constexpr const char *sAddressBookQuery =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<C:addressbook-query xmlns:C=\"urn:ietf:params:xml:ns:carddav\">"
	"<D:prop xmlns:D=\"DAV:\">"
	"<D:getetag/>"
	"<C:address-data/>"
	"</D:prop>"
	"%s"
	"</C:addressbook-query>";

constexpr const char *sAddressBookMultiget =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<C:addressbook-multiget xmlns:C=\"urn:ietf:params:xml:ns:carddav\" xmlns:D=\"DAV:\">"
	"<D:prop>"
	"<D:getetag/>"
	"<C:address-data/>"
	"</D:prop>"
	"%s"
	"</C:addressbook-multiget>";

constexpr const char *sTextMatchFilter =
	"<C:filter>"
	"<C:prop-filter name=\"FN\">"
	"<C:text-match collation=\"i;unicode-casemap\">%s</C:text-match>"
	"</C:prop-filter>"
	"</C:filter>";

String CardDavGetEventPath(const String& path)
{
	String event_id = (String) UuidValueGen().Get() + ".vcf";
	return AppendFileName(path, event_id);
}

String BuildMultiGetXml(const Vector<String>& event_urls)
{
    String hrefs;
    for(const String& url : event_urls)
        hrefs << "<D:href>" << url << "</D:href>";
    return Format(sAddressBookMultiget, hrefs);
}

}

CardDAVRequest::CardDAVRequest()
 : WebDAVRequest()
{
}

CardDAVRequest::CardDAVRequest(const String& host, int port)
 : WebDAVRequest(host, port)
{
}

CardDAVRequest::~CardDAVRequest()
{
}

void CardDAVRequest::StartGetCurrentUserPrincipal()
{
	StartPropFind("/", 0, sPrincipalQuery);
}

void CardDAVRequest::StartGetAddressBookHomeSet(const String& path)
{
	StartPropFind(path, 0, sAddressBookHomeQuery);
}

void CardDAVRequest::StartGetAddressBooks(const String& path)
{
	StartPropFind(path, 1, sAddressBookPropFind);
}

void CardDAVRequest::StartGetContacts(const String& path, const String& filter)
{
	StartReport(path, Format(sAddressBookQuery, filter));
	Header("Depth", "1");
}

void CardDAVRequest::StartGetContacts(const String& path, const Vector<String>& urls)
{
	StartReport(path, BuildMultiGetXml(urls));
	Header("Depth", "1");
}

void CardDAVRequest::StartAddContact(const String& path, const String& vcard_data)
{
	StartSaveFile(CardDavGetEventPath(path), vcard_data, "text/vcard");
}

void CardDAVRequest::StartUpdateContact(const String& path, const String& vcard_data, const String& etag)
{
	StartSaveFile(path, vcard_data, "text/vcard");
	if(!IsNull(etag))
		Header("If-Match", etag);
}

void CardDAVRequest::StartDeleteContact(const String& path)
{
	StartDelete(path);
}

void CardDAVRequest::StartGetContact(const String& path)
{
	StartLoadFile(path);
}

String CardDAVRequest::GetCurrentUserPrincipal()
{
	StartGetCurrentUserPrincipal();
	return Execute();
}

String CardDAVRequest::GetAddressBookHomeSet(const String& path)
{
	StartGetAddressBookHomeSet(path);
	return Execute();
}

String CardDAVRequest::GetAddressBooks(const String& path)
{
	StartGetAddressBooks(path);
	return Execute();
}

String CardDAVRequest::GetContacts(const String& path, const String& filter)
{
	StartGetContacts(path, filter);
	return Execute();
}

String CardDAVRequest::GetContacts(const String& path, const Vector<String>& urls)
{
	StartGetContacts(path, urls);
	return Execute();
}

bool CardDAVRequest::AddContact(const String& path, const String& vcard_data)
{
	StartAddContact(path, vcard_data);
	Execute();
	return IsSuccess();
}

bool CardDAVRequest::UpdateContact(const String& path, const String& vcard_data, const String& etag)
{
	StartUpdateContact(path, vcard_data, etag);
	Execute();
	return IsSuccess();
}

bool CardDAVRequest::DeleteContact(const String& path)
{
	StartDeleteContact(path);
	Execute();
	return IsSuccess();
}

String CardDAVRequest::GetContact(const String& path)
{
	StartGetContact(path);
	return Execute();
}

}