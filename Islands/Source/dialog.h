#include <vector>
#include <string>

#include <SFML\Graphics.hpp>

class Dialog
{
public:
	struct Element
	{
		enum { TEXT, HEADER, BUTTON } type;
		std::string content;
	};

	Dialog() {}
	~Dialog() {}

	void AddButton(const std::string & title);
	void AddButton(const std::string & title, int position);

	void AddHeader(const std::string & header);
	void AddHeader(const std::string & header, int position);

	void AddText(const std::string & text);
	void AddText(const std::string & text, int position);

private:

	std::vector<Element> column_;

};