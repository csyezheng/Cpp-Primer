#include <string>
#include <set>
#include "Message.h"

using std::string;
using std::set;


Message::Message(const string &s) : contents(s) { }

Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message &Message::operator= (const Message &m)
{
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
	folders.clear();
}

Message::Message(Message &&m) noexcept : contents(std::move(m.contents))
{
	folders = std::move(m.folders);
	move_Folders(&m);
	m.folders.clear();
}

Message &Message::operator= (Message &&m) noexcept
{
	if (this != &m)
	{
		remove_from_Folders();
		contents = std::move(m.contents);
		move_Folders(&m);
	}
	return *this;
}

void Message::save(Folder *f)
{
	folders.insert(f);
	f->addMsg(this);
}

void Message::remove(Folder *f)
{
	folders.erase(f);
	f->remMsg(this);
}

void Message::addFldr(const Folder *f)
{
	folders.insert(const_cast<Folder*>(f));
}

void Message::remFldf(const Folder *f)
{
	folders.erase(const_cast<Folder*>(f));
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void Message::move_Folders(Message *m)
{
	folders = std::move(m->folders);
	for (auto f : m->folders)
	{
		f->addMsg(this);
		f->remMsg(m);
	}
	m->folders.clear();
}

Folder::Folder(const Folder &f) : messages(f.messages)
{
	add_to_Messages(f);
}

Folder &Folder::operator= (const Folder &f)
{
	remove_from_Messages();
	messages = f.messages;
	add_to_Messages(f);
	return *this;
}

Folder::~Folder()
{
	remove_from_Messages();
	messages.clear();
}

Folder::Folder(Folder &&f) noexcept
{
	move_Messages(&f);
}

Folder &Folder::operator= (Folder &&f) noexcept
{
	if (this != &f)
	{
		remove_from_Messages();
		move_Messages(&f);
	}
	return *this;
}

void Folder::addMsg(Message *m)
{
	messages.insert(m);
}

void Folder::remMsg(Message *m)
{
	messages.erase(m);
}

void Folder::add_to_Messages(const Folder &f)
{
	for (auto m : f.messages)
		m->addFldr(&f);
}

void Folder::move_Messages(Folder *f)
{
	messages = std::move(f->messages);
	for (auto m : messages)
	{
		m->addFldr(this);
		m->remFldf(f);
	}
	f->messages.clear();
}

void Folder::remove_from_Messages()
{
	for (auto m : messages)
		m->remFldf(this);
}