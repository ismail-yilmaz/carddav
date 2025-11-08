topic "CardDAVRequest";
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,2#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[2 $$0,0#00000000000000000000000000000000:Default]
[{_} 
[ {{10000@(113.42.0) [s0;%% [*@7;4 CardDAVRequest]]}}&]
[s2; &]
[s1;:Upp`:`:CardDAVRequest: [@(0.0.255)3 class][3  ][*3 CardDAVRequest][3  
][@(0.0.255)3 :][3  ][@(0.0.255)3 public][3  WebDAVRequest]&]
[s2;%% This class is a CardDAV client implementation that extends 
[^topic`:`/`/WebDAV`/src`/Upp`_WebDAV`_en`-us`#Upp`:`:WebDAVRequest^ WebDAVRequest] 
to provide contact and addressbook management operations following 
RFC 6352. It supports addressbook discovery, contact management, 
and contact queries with both blocking and non`-blocking operation 
modes.&]
[s3;%% &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor detail]]}}&]
[s3; &]
[s5;:Upp`:`:CardDAVRequest`:`:CardDAVRequest`(`): [* CardDAVRequest]()&]
[s2;%% Default constructor&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:CardDAVRequest`(const String`&`,int`): [* CardDAVRequest](
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 host], [@(0.0.255) int] 
[*@3 port] [@(0.0.255) `=] [@3 80])&]
[s2;%% Constructs with the specified [%-*@3 host] and [%-*@3 port]. &]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Non`-Blocking Methods]]}}&]
[s3; &]
[s2; Non`-blocking methods begins with Start prefix and initialize 
the given operation. Use [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:Do`(`)^ D
o()] method to drive the operation to completion. Check [^topic`:`/`/Core`/src`/HttpRequest`_en`-us`#HttpRequest`:`:IsSuccess`(`)const^ I
sSuccess()] after completion to verify the operation succeeded.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:StartGetCurrentUserPrincipal`(`): [@(0.0.255) void] 
[* StartGetCurrentUserPrincipal]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path] [@(0.0.255) `=] Null)&]
[s2;%% Starts discovery of the current user`'s principal URL. [%-*@3 path] 
can be used to specify the path. This is typically the first 
step in CardDAV discovery to determine the authenticated user`'s 
principal resource path. Returns raw XML response that client 
must parse.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:StartGetAddressBookHomeSet`(const String`&`): [@(0.0.255) v
oid] [* StartGetAddressBookHomeSet]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path])&]
[s2;%% Starts discovery of the addressbook home set for a principal. 
The [%-*@3 path] parameter is the principal URL obtained from [^topic`:`/`/CardDAV`/src`/Upp`_CardDAV`_en`-us`#Upp`:`:CardDAVRequest`:`:StartGetCurrentUserPrincipal`(`)^ G
etCurrentUserPrincipal](). Returns raw XML response containing 
the base URL where the user`'s addressbooks are located. Client 
must parse the XML.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:StartGetAddressBooks`(const String`&`): [@(0.0.255) void] 
[* StartGetAddressBooks]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Starts addressbook collection discovery. The [%-*@3 path] parameter 
is the addressbook home set path. Returns raw XML response containing 
available addressbooks with their properties including display 
names, supported address data types, and descriptions. Client 
must parse the XML.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:StartGetContacts`(const String`&`,const String`&`): [@(0.0.255) v
oid] [* StartGetContacts]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path], [@(0.0.255) const] String[@(0.0.255) `&] [*@3 filter] [@(0.0.255) `=] 
Null)&]
[s2;%% Starts addressbook query to retrieve contacts. The [%-*@3 path] 
parameter is the addressbook collection path. The [%-*@3 filter] 
parameter is optional XML text to match against contact names. 
If Null, retrieves all contacts. Returns raw XML response containing 
matching contacts with their vCard data and ETags. Client must 
parse the XML.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:StartGetContacts`(const String`&`,const Vector`&`): [@(0.0.255) v
oid] [* StartGetContacts]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path], [@(0.0.255) const] Vector<String>[@(0.0.255) `&] [*@3 urls])&]
[s2;%% Starts multiget query to retrieve specific contacts by their 
URLs. The [%-*@3 path] parameter is the addressbook collection 
path, and [%-*@3 urls] contains the list of contact resource URLs 
to retrieve. Returns raw XML response containing the requested 
contacts with their vCard data and ETags. Client must parse the 
XML.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:StartAddContact`(const String`&`,const String`&`): [@(0.0.255) v
oid] [* StartAddContact]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 vcard`_data])&]
[s2;%% Starts contact creation in an addressbook collection. The 
[%-*@3 path] parameter is the addressbook collection path, and 
[%-*@3 vcard`_data] contains the contact in vCard format (RFC 6350). 
A unique filename is generated automatically using UUID.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:StartUpdateContact`(const String`&`,const String`&`,const String`&`): [@(0.0.255) v
oid] [* StartUpdateContact]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path], [@(0.0.255) const] String[@(0.0.255) `&] [*@3 vcard`_data], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 etag] [@(0.0.255) `=] Null)&]
[s2;%% Starts contact modification. The [%-*@3 path] parameter is the 
contact resource URL, [%-*@3 vcard`_data] contains the updated 
contact in vCard format, and [%-*@3 etag] is an optional ETag for 
optimistic concurrency control. If provided, the update only 
succeeds if the server`'s ETag matches.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:StartDeleteContact`(const String`&`): [@(0.0.255) void] 
[* StartDeleteContact]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Starts contact deletion. The [%-*@3 path] parameter is the contact 
resource URL to delete.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:StartGetContact`(const String`&`): [@(0.0.255) void] 
[* StartGetContact]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Starts retrieval of a specific contact. The [%-*@3 path] parameter 
is the contact resource URL. Returns the contact in vCard format.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Blocking Methods]]}}&]
[s3; &]
[s2; Blocking methods execute immediately and return when the operation 
completes.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:GetCurrentUserPrincipal`(`): String 
[* GetCurrentUserPrincipal]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path] [@(0.0.255) `=] Null)&]
[s2;%% Discovers the current user`'s principal URL.  [%-*@3 path] can 
be used to specify the path. Returns raw XML response containing 
the principal resource path which is used for subsequent addressbook 
discovery. Client must parse the XML.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:GetAddressBookHomeSet`(const String`&`): String 
[* GetAddressBookHomeSet]([@(0.0.255) const] String[@(0.0.255) `&] 
[*@3 path])&]
[s2;%% Discovers the addressbook home set for a principal. The [%-*@3 path] 
parameter is the principal URL. Returns raw XML response containing 
the addressbook home set URL where addressbooks are located. 
Client must parse the XML.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:GetAddressBooks`(const String`&`): String 
[* GetAddressBooks]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Retrieves available addressbooks. The [%-*@3 path ]parameter 
is the addressbook home set path. Returns raw XML response containing 
addressbook collections with their properties. Client must parse 
the XML. .&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:GetContacts`(const String`&`,const String`&`): String 
[* GetContacts]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 filter] [@(0.0.255) `=] 
Null)&]
[s2;%% Queries contacts. The [%-*@3 path] parameter is the addressbook 
collection path. The [%-*@3 filter] parameter is optional text 
to match against contact names. Returns raw XML response containing 
matching contacts. Client must parse the XML.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:GetContacts`(const String`&`,const Vector`&`): String 
[* GetContacts]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] Vector<String>[@(0.0.255) `&] [*@3 urls])&]
[s2;%% Retrieves specific contacts by URLs. The [%-*@3 path] parameter 
is the addressbook collection path, and [%-*@3 urls] contains contact 
resource URLs. Returns raw XML response containing the requested 
contacts. Client must parse the XML.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:AddContact`(const String`&`,const String`&`): [@(0.0.255) b
ool] [* AddContact]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 vcard`_data])&]
[s2;%% Creates a new contact. The [%-*@3 path] parameter is the addressbook 
collection path, and [%-*@3 vcard`_data] contains the contact in 
vCard format. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:UpdateContact`(const String`&`,const String`&`,const String`&`): [@(0.0.255) b
ool] [* UpdateContact]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path], 
[@(0.0.255) const] String[@(0.0.255) `&] [*@3 vcard`_data], [@(0.0.255) const] 
String[@(0.0.255) `&] [*@3 etag] [@(0.0.255) `=] Null)&]
[s2;%% Updates an existing contact. The [%-*@3 path] parameter is the 
contact resource URL, [%-*@3 vcard`_data] contains the updated 
contact, and [%-*@3 etag] is optional for conditional updates. 
Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:DeleteContact`(const String`&`): [@(0.0.255) bool] 
[* DeleteContact]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Deletes a contact. The [%-*@3 path] parameter is the contact 
resource URL. Returns true if successful.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:CardDAVRequest`:`:GetContact`(const String`&`): String 
[* GetContact]([@(0.0.255) const] String[@(0.0.255) `&] [*@3 path])&]
[s2;%% Retrieves a specific contact. The [%-*@3 path] parameter is 
the contact resource URL. Returns the contact in vCard format.&]
[s3; &]
[s4;%% ]]