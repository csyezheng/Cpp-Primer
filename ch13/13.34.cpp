#include <string>
#include <set>
#include <memory>
#include "13.34.h"

using std::string;
using std::set;
using std::shared_ptr;

/*--------------implementation for Message ------------*/
Message::Message(const std::string &s) : contents(s) { }

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

Message &Message::operator= (const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::addFldr(Folder *f)
{
	folders.insert(f);
}

void Message::remFldr(Folder *f)
{
	folders.erase(f);
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

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

/* ---------------implementation for Folder --------*/
Folder::Folder() = default;

Folder::Folder(const Folder &f) : messages(f.messages)
{
	add_to_Message(f);
}

Folder &Folder::operator= (const Folder &f)
{
	remove_from_Message();
	messages = f.messages;
	add_to_Message(*this);
	return *this;
}

Folder::~Folder()
{
	remove_from_Message();
}

void Folder::addMsg(Message *m)
{
	messages.insert(m);
}

void Folder::remMsg(Message *m)
{
	messages.erase(m);
}

void Folder::add_to_Message(const Folder &f)
{
	for (auto m : f.messages)
		m->addFldr(this);
}

void Folder::remove_from_Message()
{
	for (auto m : messages)
		m->remFldr(this);
}

int main()
{

}