#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Folder;

class Message
{
public:
	Message(const std::string &s = std::string());
	Message(const Message&);
	Message &operator= (const Message&);
	~Message();
	Message(Message&&) noexcept;
	Message &operator= (Message&&) noexcept;
	void save(Folder*);
	void remove(Folder*);
	void addFldr(const Folder*);
	void remFldf(const Folder*);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message*);
};

class Folder
{
public:
	Folder() = default;
	Folder(const Folder&);
	Folder &operator= (const Folder&);
	~Folder();
	Folder(Folder&&) noexcept;
	Folder &operator= (Folder&&) noexcept;
	void addMsg(Message*);
	void remMsg(Message*);
private:
	std::set<Message*> messages;
	void add_to_Messages(const Folder&);
	void remove_from_Messages();
	void move_Messages(Folder*);
};


#endif