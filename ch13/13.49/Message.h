#ifndef MESSAGE_H
#define MESSAGE_H

class Folder;

class Message
{
public:
	Message(const std::string &s = std::string());
	Message(const Message&);
	Message &operator= (const Message&);
	~Message();
	Message(Message&&);
	Message &operator= (Message&&);
	void save();
	void remove(Folder&);
private:
	std::string contents;
	std::shared_ptr<std::set<Folder*>> folders;
	void add_to_folders(const Message&);
	void remove_from_folders();
};

#endif