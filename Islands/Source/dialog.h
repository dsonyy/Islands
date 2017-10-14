#include <vector>
#include <string>

#include <SFML\Graphics.hpp>

class Dialog
{
public:
	Dialog() {}
	~Dialog() {}

	void AddButton(const std::string & title);
	void AddButton(const std::string & title, int position);

	void AddHeader(const std::string & header);
	void AddHeader(const std::string & header, int position);

	void AddText(const std::string & text);
	void AddText(const std::string & text, int position);

private:
	std::map<sf::Text, int> texts_;
	std::map<sf::Text, int> headers_;
	std::map<sf::Text, int> buttons_;

};