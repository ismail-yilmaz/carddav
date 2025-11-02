# CardDAV Package for U++

A lightweight, RFC 6352-compliant **CardDAV client** for U++.
Implements address book discovery, contact management, and vCard operations over HTTP/WebDAV protocol.

## Features

- **Full CardDAV coverage**: discovery, contact retrieval, creation, update, and deletion
- **Dual operation modes**: blocking and non-blocking
- **Built on WebDAV**: extends `WebDAVRequest`, inheriting all HTTP functionality, including SSL, authentication, and redirection
- **Simple U++ API**: clean, self-contained interface using familiar U++ conventions

## Supported Operations

- **Principal and home discovery**: `GetCurrentUserPrincipal`, `GetAddressBookHomeSet`
- **Address book collection discovery**: `GetAddressBooks`
- **Contact retrieval**: `GetContacts`, `GetContact`
- **Contact modification**: `AddContact`, `UpdateContact`, `DeleteContact`
- **Non-blocking variants**: all `Start*` methods correspond to blocking calls

## Examples

| Name               | Description                                                                         |
| ------------------ | ----------------------------------------------------------------------------------- |
| **CardDAVExample** | Demonstrates connecting to a CardDAV server, listing address books, and adding contacts |
