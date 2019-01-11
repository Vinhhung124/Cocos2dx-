#include "sc1.h"
#include"cocos2d.h"
#include"ui\CocosGUI.h"
using namespace std;
USING_NS_CC;
Scene* sc1::createScene()
{
	auto scene = Scene::create();
	auto layer = sc1::create();
	scene->addChild(layer);
	return scene;
}
bool sc1::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto screenSize = Director::getInstance()->getVisibleSize();
	static auto bg = Sprite::create("bgg.jpg");
	bg->setPosition(screenSize.width / 2, screenSize.height / 2);
	bg->setScale(0.5);
	addChild(bg);
	//Creat label with TTF
	auto myLabel = Label::createWithTTF("Hello World!", "fonts/Marker Felt.ttf", 24);
	myLabel->setPosition(screenSize.width / 2, screenSize.height - 50);
	addChild(myLabel);
	//myLabel->enableOutline(Color4B::BLUE, 2); // Set outline
	myLabel->enableGlow(Color4B::RED); //Set 1 color


	// Creat menu
	auto itemPlay = MenuItemFont::create("Play", nullptr);
	auto itemSetting = MenuItemFont::create("Setting", nullptr);
	auto itemMoreGame = MenuItemFont::create("More Game", nullptr);
	auto itemAbout = MenuItemFont::create("About", nullptr);
	itemPlay->setPosition(screenSize.width / 2, screenSize.height - 80);
	itemSetting->setPosition(screenSize.width / 2, screenSize.height - 120);
	itemMoreGame->setPosition(screenSize.width / 2, screenSize.height - 160);
	itemAbout->setPosition(screenSize.width / 2, screenSize.height - 200);
	itemPlay->setFontName("fonts/arial");
	itemSetting->setFontName("fonts/arial");
	itemMoreGame->setFontName("fonts/arial");
	itemAbout->setFontName("fonts/arial");
	itemPlay->setColor(Color3B::GREEN);
	itemSetting->setColor(Color3B::RED);
	itemMoreGame->setColor(Color3B::YELLOW);
	itemAbout->setColor(Color3B::ORANGE);
	auto menuLabel = Menu::create(itemPlay, itemSetting, itemMoreGame, itemAbout, nullptr);
	menuLabel->setPosition(0, 0);
	addChild(menuLabel);
	//Creat button rating

	auto ratingButton = ui::Button::create("rating_normal.png",
		"rating_pressed.png");
	ratingButton->addClickEventListener([&](Ref* event) {
		log("Rating clicked");
	});
	ratingButton->setAnchorPoint(Vec2(1, 0));
	ratingButton->setPosition(Vec2(screenSize.width, 5));
	addChild(ratingButton);
	//Creat button setting
	auto settingButton = ui::Button::create("setting_normal.png",
		"setting_pressed.png");
	settingButton->addClickEventListener([&](Ref* event)
	{
		log("Setting clicked");
	});
	settingButton->setAnchorPoint(Vec2(1, 0));
	settingButton->setPosition(Vec2(screenSize.width - 80, 0));
	addChild(settingButton);


	//Creat Checkbox
	static auto checkbox = ui::CheckBox::create("checkbox_normal.png",
		"checkbox_pressed.png", "checkbox_checked.png",
		"checkbox_normal_disable.png", "checkbox_checked_disable.png");
	checkbox->setSelected(true);
	checkbox->addClickEventListener([&](Ref* event) {
		log("CheckBox state: %d", checkbox->isSelected());
		CCLOG("ab");
	});
	checkbox->setPosition(Vec2(screenSize.width-220,50));
	checkbox->setEnabled(true);
	addChild(checkbox);


	/*Creat LoadingBar
	auto loadingBarGB = Sprite::create("loadingbar_bg.png");
	loadingBarGB->setPosition(Vec2(screenSize.width / 2, 50));
	addChild(loadingBarGB);
	static auto loadingbar = ui::LoadingBar::create("loadingbar.png");
	loadingbar->setPercent(0);
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingbar->setPosition(loadingBarGB->getPosition());
	addChild(loadingbar);
	update Loading Bar
	auto updateLoadingBar = CallFunc::create([]() {
		if (loadingbar->getPercent() < 100)
		{
			loadingbar->setPercent(loadingbar->getPercent() + 1);
		}
	});
	auto sequenceRunUpdateLoadingBar =
		Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.1f));
	auto repeat = Repeat::create(sequenceRunUpdateLoadingBar, 100);
	loadingbar->runAction(repeat);
*/




	//static auto slider = ui::Slider::create();
	//slider->loadBarTexture("slider_bar_bg.png");
	//slider->loadSlidBallTextures("slider_ball_normal.png",
	//	"slider_ball_pressed.png", "slider_ball_disable.png");
	//slider->loadProgressBarTexture("slider_bar_pressed.png");
	//slider->setPercent(10);
	//slider->setPosition(Vec2(screenSize.width / 2, 140));
	//slider->addClickEventListener([](Ref* event) {
	//	log("Slider: %d", slider->getPercent());
	//});
	//addChild(slider);
	
	return true;
}
