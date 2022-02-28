// Source : https://www.youtube.com/watch?v=d2nxqGAS9xo

#include <iostream>
#include <string>

using namespace std;

class GameSetting {
	static GameSetting* _instance;

	int _brightness;
	int _height;
	int _width;

	GameSetting() : _width(786), _height(1300), _brightness(75) {}

public:
	static GameSetting* getInstance() {
		if(_instance == NULL) {
			_instance = new GameSetting();
		}

		return _instance;
	}

	void setWidth(int width) {
		_width = width;
	}
	void setHeight(int height) {
		_height = height;
	}
	void setBrightness(int brightness) {
		_brightness = brightness;
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
		cout << "Brightness : " << getBrightness() << endl;
		cout << "Width : " << getWidth() << endl;
		cout << "Height : " << getHeight() << endl << endl;
	}

};

GameSetting* GameSetting::_instance = NULL;

void someFunction(void) {
	GameSetting* setting = GameSetting::getInstance();

	setting->displaySetting();
}

int main()
{
	GameSetting* setting = GameSetting::getInstance();

	setting->displaySetting();
	setting->setBrightness(100);

	someFunction();

	return 0;
}