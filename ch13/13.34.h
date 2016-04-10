#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <memory>
#include <set>

class Folder;

class Message
{
	friend void swap(Message&, Message&);
public:
	explicit Message(const std::string &s = std::string());
	Message(const Message&);
	Message &operator= (const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	void addFldr(Folder*);
	void remFldr(Folder*);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};

class Folder
{
public:
	Folder();
	Folder(const Folder&);
	Folder &operator= (const Folder&);
	~Folder();
	void addMsg(Message*);
	void remMsg(Message*);
private:
	std::set<Message*> messages;
	void add_to_Message(const Folder&);
	void remove_from_Message();
};

void swap(Message&, Message&);

#endif