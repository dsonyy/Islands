#include <vector>
#include <string>

#include <SFML\Graphics.hpp>

class Dialog
	: public sf::Drawable
{
public:
	struct Element
	{
		enum { TEXT, HEADER, BUTTON } type;
		std::string content;
	};

	Dialog();
	~Dialog() {}

	// derived from sf::Drawable
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	void AddButton(const std::string & title);
	void AddButton(const std::string & title, int position);

	void AddHeader(const std::string & header);
	void AddHeader(const std::string & header, int position);

	void AddText(const std::string & text);
	void AddText(const std::string & text, int position);

private:
	std::vector<Element> column_;

	sf::RectangleShape dialog_border_;
	sf::RectangleShape dialog_background_;

	sf::RectangleShape button_border_;
	sf::RectangleShape button_background_;

};