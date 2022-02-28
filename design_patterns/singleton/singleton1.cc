// Source : https://www.youtube.com/watch?v=d2nxqGAS9xo

#include <iostream>

using namespace std;

class GameSetting
{
private:
	static GameSetting* _instance;

	int _width;
	int _height;
	int _brightness;

	GameSetting() {
		_width=10;
		_height=20;
		_brightness=30;
	}
public:
	static GameSetting* getInstance(void) {

		if(_instance == NULL) {
			_instance=new GameSetting;
		}

		return _instance;
	}

	void setWidth(int width) {
		_width=width;
	}
	void setHeight(int height) {
		_height=height;
	}
	void setBrightness(int brightness) {
		_brightness=brightness;
	}

	int getWidth(void) {
		return _width;
	}
	int getHeight(void) {
		return _height;
	}
	int getBrightness(void) {
		return _brightness;
	}

	void displaySetting(void) {
		cout<<"Width : "<<_width<<endl;
		cout<<"Height : "<<_height<<endl;
		cout<<"Brightness : "<<_brightness<<endl<<endl;
	}
};

GameSetting* GameSetting::_instance=NULL;

void showSetting(void)
{
	GameSetting* setting1=GameSetting::getInstance();
	setting1->displaySetting();
}

void changeSetting(void)
{
	GameSetting* setting2 = GameSetting::getInstance();
	setting2->setHeight(200);
	setting2->setBrightness(200);
}

int main()
{
	GameSetting* setting = GameSetting::getInstance();
	setting->displaySetting();

	setting->setWidth(100);

	setting->displaySetting();

	setting->setWidth(200);

	showSetting();

	changeSetting();

	showSetting();

	return 0;
}